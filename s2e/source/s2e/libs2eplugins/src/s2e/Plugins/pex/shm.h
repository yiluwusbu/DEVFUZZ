#ifndef _X_SHM_
#define _X_SHM_
#include <fcntl.h> /* For O_* constants */
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h> /* For mode constants */
#include <sys/types.h>
#include <unistd.h>
#include "color.h"
#include "logutil.h"

enum class SHMOpenType { CREATE, CONNECT };
template <typename T> class SHM {
public:
    SHM(const std::string shmPath) : shmPath(shmPath), fd(0), smem(nullptr) {
    }
    ~SHM() {
        close();
    };

    bool isOpen() {
        return fd > 0;
    }
    bool open(SHMOpenType t) {
        mode = t;
        switch (t) {
            case (SHMOpenType::CREATE):
                return createOpen();
            case (SHMOpenType::CONNECT):
                return connectOpen();
            default:
                return false;
        }
    }

    void close() {
        if (smem)
            munmap(smem, sizeof(T));
        smem = nullptr;
        if ((fd > 0) && (mode == SHMOpenType::CREATE)) {
            shm_unlink(shmPath.c_str());
        }
        fd = 0;
    }

    T *getMem() {
        return (T *) smem;
    }

private:
    const std::string shmPath;
    int fd;
    void *smem;
    SHMOpenType mode;

    bool createOpen() {
        fd = shm_open(shmPath.c_str(), O_CREAT | O_RDWR | O_TRUNC, S_IRUSR | S_IWUSR);
        if (fd < 0) {
            WARN("cannot open shm " << shmPath);
            return false;
        }
        constexpr size_t size = sizeof(T);
        if (ftruncate(fd, size) < 0) {
            WARN("ftruncate failed!");
            close();
        }
        INFO("mmap @fd " << fd << " object size = " << size);
        smem = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        if (smem == MAP_FAILED) {
            WARN("cannot mmap shm " << shmPath);
            smem = nullptr;
            close();
            return false;
        }
        return true;
    }
    bool connectOpen() {
        fd = shm_open(shmPath.c_str(), O_RDWR, S_IRUSR | S_IWUSR);
        if (fd < 0) {
            WARN("cannot open shm " << shmPath);
            return false;
        }
        smem = (uint8_t *) mmap(nullptr, sizeof(T), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

        if (smem == MAP_FAILED) {
            WARN("cannot mmap shm " << shmPath);
            smem = nullptr;
            close();
            return false;
        }
        return true;
    }
};
#endif
