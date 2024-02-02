///
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// afl proxy
/// - provide fuzz filename to s2e
/// - receive and feed coverage info to AFL
/// - exit or crash when directed by s2e
///
#include "aflclient.h"
#include "logutil.h"
#include "shm.h"
#include <fcntl.h>
#include <fstream>
#include <iostream>
#include <semaphore.h>
#include <signal.h>
#include <sys/stat.h>
#include <unistd.h>

// TODO: should implement a lock free queue here ...
struct XXX {
  sem_t semr;
  sem_t semw;
  sem_t sem_irq;
  char path[128]; // the input data path
  uint8_t type;
  union {
    uint8_t data[128];
    struct {
      uint8_t req_type; // request type 0 read 1 write
      uint64_t address; // requested address
      uint64_t size;    // requested size;
    } rwreq; // for requesting data directly from us instead of using file
  };
  // 0 - irq deasserted, 1 - irq asserted
  volatile uint8_t irq_assert;
  volatile uint8_t ready;
};

AFLClient *aflClient;

// inject coverage information to AFL
void inject_cov(uint64_t addr) { aflClient->AFLMaybeLog(addr); }

void handle_type_cov(struct XXX *sm) {
  uint64_t addr;
  memcpy(&addr, &(sm->data), sizeof(uint64_t));
  // LOG_TO_FILE("afl.log", " pc@" << (uint64_t)(addr));
  inject_cov(addr);
}

void start_pt(struct XXX *sm, int core_id) {
  pid_t tid;
  memcpy(&tid, &(sm->data), sizeof(pid_t));
  LOG_TO_FILE("afl.log", "start PT for tid..." << tid);
  aflClient->startPT(core_id);
}

bool hasStamp(const std::string fname) {
  return access(fname.c_str(), F_OK) == 0;
}
//
#define RETRY 8
void skip_dry_run() {
  char buff[128];
  for (int i = 0; i < RETRY; i++) {
    snprintf(buff, 128, "dry_run_stamp%d", i);
    if (!hasStamp(buff)) {
      LOG_TO_FILE(buff, i);
      exit(0);
    }
  }
}

int main(int argc, char **argv) {
  aflClient = new AFLClient;
  if (aflClient->isAFLAlive()) {
    // LOG_TO_FILE("afl.log", "AFLClient is alive");
  }
  skip_dry_run();
  std::string shmname = "/afl-proxy-";
  char core_id_str[8];
  char shm_id_str[8];
  int core_id;

  if (argc > 3) {
    strncpy(core_id_str, argv[2], 7);
    strncpy(shm_id_str, argv[3], 7);
    core_id = atoi(core_id_str);
    shmname += std::string(shm_id_str);
    LOG_TO_FILE("afl.log", "Using shm: " << shmname);
  } else {
    LOG_TO_FILE("afl.log", "usage: ap @@ qemu_cpu shm_id");
  }
 
  SHM<struct XXX> shm(shmname.c_str());
  if (shm.open(SHMOpenType::CREATE)) {
    auto *sm = shm.getMem();
    // LOG_TO_FILE("afl.log", "SHM created @ " << sm);
    if (sem_init(&(sm->semr), 1, 0) == -1)
      unreachable("failed to init semaphore r");
    if (sem_init(&(sm->semw), 1, 0) == -1)
      unreachable("failed to init semaphore w");
  } else {
    LOG_TO_FILE("afl.log", "SHM creation failed");
  }
  auto *sm = shm.getMem();
  // set input file path
  INFO("setting input file path: " << argv[1]);
  strncpy(sm->path, argv[1], 128);
  // LOG_TO_FILE("afl.log", "entering event loop");
  bool run = true;
  __sync_lock_test_and_set(&(sm->ready), 1);
  // event loop
  while (run) {
    if (sem_wait(&sm->semw) == -1) {
      unreachable("error wait semw");
    }
    // LOG_TO_FILE("afl.log", "received type " << hexval((uint64_t)sm->type) << " msg");
    switch (sm->type) {
    case (1):
      handle_type_cov(sm);
      break;
    case (2):
      start_pt(sm, core_id);
      break;
    case (0xFF):
      run = false;
      break;
    default:
      unreachable("unhandled type");
      break;
    }
    if (sem_post(&sm->semr) == -1) {
      unreachable("error post semr");
    }
  }
  shm.close();
  shm_unlink(shmname.c_str());
  return 0;
}
