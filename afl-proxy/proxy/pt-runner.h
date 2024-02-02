///
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
///
#ifndef _PT_RUNNER_H_
#define _PT_RUNNER_H_

#ifdef __linux__

#include <fcntl.h>
#include <semaphore.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void ptWorker(pid_t tid);
#else
static void ptWorker(pid_t tid) {}
#endif

#endif
