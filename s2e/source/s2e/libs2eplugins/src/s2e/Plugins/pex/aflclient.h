///
/// setup afl client
///
#ifndef _AFL_CLIENT_
#define _AFL_CLIENT_

#include <stdlib.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "logutil.h"
#define SHM_ENV_VAR "__AFL_SHM_ID"
#define PERSIST_ENV_VAR "__AFL_PERSISTENT"
#define MAP_SIZE_POW2 16
#define MAP_SIZE (1 << MAP_SIZE_POW2)
#define FORKSRV_FD 198
#define TSL_FD (FORKSRV_FD - 1)

struct afl_tsl {
    uint64_t pc;
    uint64_t cs_base;
    uint64_t flags;
};

class AFLClient {
public:
    AFLClient() : afl_area_ptr(nullptr), shm_id(-1) {
        is_persistent = !!getenv(PERSIST_ENV_VAR);
        AFLSetup();
        AFLForkServer();
        // -- should mark this 1 to let AFL know we are valid
        afl_area_ptr[0] = 1;
    };
    ~AFLClient(){};
    // call this to inject coverage information to AFL
    void AFLMaybeLog(uintptr_t cur_loc) {
        if (!afl_area_ptr)
            return;
        cur_loc = (cur_loc >> 4) ^ (cur_loc << 8);
        cur_loc &= MAP_SIZE - 1;
        if (cur_loc >= afl_inst_rms)
            return;
        afl_area_ptr[cur_loc ^ prev_loc]++;
        prev_loc = cur_loc >> 1;
    };
    bool isAFLAlive() {
        return afl_area_ptr != nullptr;
    }
    uint8_t *getAFLArea() {
        return afl_area_ptr;
    }

private:
    void AFLSetup() {
        char *id_str = getenv(SHM_ENV_VAR);
        if (id_str) {
            shm_id = atoi(id_str);
            afl_area_ptr = (uint8_t *) shmat(shm_id, NULL, 0);
            if (afl_area_ptr == (void *) -1)
                exit(1);
            afl_area_ptr[0] = 1;
        }
    };
    void AFLForkServer() {
        uint8_t tmp[4];
        int child_pid;
        uint8_t child_stopped = 0;
        /* Phone home and tell the parent that we're OK. If parent isn't there,
           assume we're not running in forkserver mode and just execute program. */
        if (write(FORKSRV_FD + 1, tmp, 4) != 4)
            return;
        while (1) {
            uint32_t was_killed;
            int status;
            /* Wait for parent by reading from the pipe. Abort if read fails. */
            if (read(FORKSRV_FD, &was_killed, 4) != 4)
                exit(1);
            /* If we stopped the child in persistent mode, but there was a race
               condition and afl-fuzz already issued SIGKILL, write off the old
               process. */
            if (child_stopped && was_killed) {
                child_stopped = 0;
                if (waitpid(child_pid, &status, 0) < 0)
                    exit(1);
            }
            if (!child_stopped) {
                /* Once woken up, create a clone of our process. */
                child_pid = fork();
                if (child_pid < 0)
                    exit(1);
                /* In child process: close fds, resume execution. */
                if (!child_pid) {
                    close(FORKSRV_FD);
                    close(FORKSRV_FD + 1);
                    return;
                }
            } else {
                /* Special handling for persistent mode: if the child is alive but
                   currently stopped, simply restart it with SIGCONT. */
                kill(child_pid, SIGCONT);
                child_stopped = 0;
            }
            /* In parent process: write PID to pipe, then wait for child. */
            if (write(FORKSRV_FD + 1, &child_pid, 4) != 4)
                exit(1);
            if (waitpid(child_pid, &status, is_persistent ? WUNTRACED : 0) < 0)
                exit(1);
            /* In persistent mode, the child stops itself with SIGSTOP to indicate
               a successful run. In this case, we want to wake it up without forking
               again. */
            if (WIFSTOPPED(status))
                child_stopped = 1;
            /* Relay wait status to pipe, then loop back. */
            if (write(FORKSRV_FD + 1, &status, 4) != 4)
                exit(1);
        }
    };
    unsigned int afl_inst_rms = MAP_SIZE;
    uint8_t *afl_area_ptr;
    uint64_t prev_loc;
    unsigned int afl_forksrv_pid;
    unsigned char afl_fork_child;
    int shm_id;
    bool is_persistent;
};

#endif
