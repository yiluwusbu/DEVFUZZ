/*
 * standalone program to setup perf subsystem and receive perf data for pt
 * 2018 Tong Zhang<ztong@vt.edu>
 * 2021 Tong Zhang<ztong0001@gmail.com>
 * -- IA32_RTIT_STATUS
 * sudo rdmsr --processor 0 0x571
 * -- IA32_RTIT_CTRL
 * sudo rdmsr --processor 0 0x571
 *
 */
#ifdef __linux__
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/syscall.h> /* For SYS_xxx definitions */
#include <time.h>
#include <unistd.h>

#include <linux/perf_event.h>

#include <assert.h>

#include "PTDecoder.h"
#include "PerfAuxBuffer.h"

#include "color.h"
#include "logutil.h"

// should be 1 + (2^n), real data start from page 1
#define REGULAR_RING_DATA_PAGES 4
#define REGULAR_RING_PAGES (1 + REGULAR_RING_DATA_PAGES)
#define AUX_RING_PAGES 1024
// check /sys/devices/intel_pt/type
#define PERF_TYPE_PT 9

struct sample_id {
  uint32_t pid, tid;  /* if PERF_SAMPLE_TID set */
  uint64_t time;      /* if PERF_SAMPLE_TIME set */
  uint64_t id;        /* if PERF_SAMPLE_ID set */
  uint64_t stream_id; /* if PERF_SAMPLE_STREAM_ID set  */
  uint32_t cpu, res;  /* if PERF_SAMPLE_CPU set */
  uint64_t id2;       /* if PERF_SAMPLE_IDENTIFIER set */
};

struct perf_event_record_aux {
  struct perf_event_header header;
  uint64_t aux_offset;
  uint64_t aux_size;
  uint64_t flags;
  struct sample_id sample_id;
};

struct pref_event_itrace_start {
  struct perf_event_header header;
  uint32_t pid;
  uint32_t tid;
  struct sample_id sample_id;
};

static long perf_event_open(struct perf_event_attr *hw_event, pid_t pid,
                            int cpu, int group_fd, unsigned long flags) {
  int ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd, flags);
  return ret;
}

uint8_t *regularRingBuffer;
// aux buffer
uint8_t *auxRingBuffer;

/*
 * ring buffer stuff to receive data
 */
int setup_mmap(struct perf_event_attr *attr, int fd) {
  int ret;
  int output = fd;
  size_t regular_ring_size = REGULAR_RING_PAGES * 4096;
  regularRingBuffer = (uint8_t *)mmap(
      NULL, regular_ring_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (regularRingBuffer == MAP_FAILED) {
    ERROR("mmap regular ring failed : " << errno);
    return -1;
  }
  INFO("mmap regular ring @" << hexval(regularRingBuffer));

  // must set this before do aux mapping
  struct perf_event_mmap_page *pmap =
      (struct perf_event_mmap_page *)regularRingBuffer;
  pmap->aux_offset = regular_ring_size;
  size_t aux_ring_size = AUX_RING_PAGES * 4096;
  pmap->aux_size = aux_ring_size;

  // create aux mmap
  auxRingBuffer = (uint8_t *)mmap(NULL, pmap->aux_size, PROT_READ | PROT_WRITE,
                                  MAP_SHARED, fd, pmap->aux_offset);

  if (auxRingBuffer == MAP_FAILED) {
    ERROR("mmap auxRingBuffer failed @" << hexval(errno));
    return -1;
  }
  INFO("mmap auxRingBuffer @" << hexval(auxRingBuffer));
  return 0;
}

static void perf_event_handler(int signum, siginfo_t *info, void *uctx) {
  if (info->si_code != POLL_HUP)
    exit(EXIT_FAILURE);
  ioctl(info->si_fd, PERF_EVENT_IOC_REFRESH, 1);
}

template <class T> T *get_event(uint8_t *ring, int ring_size, int tail) {
  static uint8_t *buffer;
  if (!buffer)
    buffer = (uint8_t *)malloc(256);
  auto size = sizeof(T);
  int real_tail = tail % ring_size;
  if (real_tail + size < ring_size)
    return (T *)&ring[real_tail];
  auto size1 = ring_size - real_tail;
  auto size2 = size - size1;
  memcpy(buffer, &ring[real_tail], size1);
  memcpy(&buffer[size1], ring, size2);
  return (T *)buffer;
}

void check_buffer(int fd) {
  // real data start from page 1
  struct perf_event_mmap_page *pmap =
      (struct perf_event_mmap_page *)regularRingBuffer;
  uint8_t *ring_data = &regularRingBuffer[4096];
  uint64_t data_head = pmap->data_head;
  uint64_t data_tail = pmap->data_tail;
  uint64_t aux_head = pmap->aux_head;
  uint64_t aux_tail = pmap->aux_tail;
  // outs() << "PTRS:" << data_head << "/" << data_tail << "   " << aux_head <<
  // "/"
  //       << aux_tail << "\r";
  if (data_head == data_tail)
    return;
  size_t regular_ring_data_size = REGULAR_RING_DATA_PAGES * 4096;
  // ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
  while (data_head != data_tail) {
    auto *header = get_event<struct perf_event_header>(
        ring_data, regular_ring_data_size, data_tail);
    if (header->type == PERF_RECORD_AUX) {
      auto *record = get_event<struct perf_event_record_aux>(
          ring_data, regular_ring_data_size, data_tail);
      uint64_t auxOffset = record->aux_offset;
      uint64_t auxSize = record->aux_size;
      size_t auxRingSize = AUX_RING_PAGES * 4096;
      // LOG_TO_FILE("afl.log", "AUX offset " << hexval(auxOffset) << ", size "
      //                                     << hexval(auxSize) << ", flags "
      //                                     << hexval(record->flags));
      switch (record->flags) {
      case (PERF_AUX_FLAG_TRUNCATED):
        INFO("aux record truncated");
        break;
      case (PERF_AUX_FLAG_OVERWRITE):
        INFO("aux record was overwritten");
        break;
      case (0):
        break;
      default:
        INFO("unknown flag");
        break;
      }
      if (auxSize != 0) {
        PerfAuxBuffer ptrecord(auxRingBuffer, auxRingSize, auxOffset, auxSize);
        // decode_buffer(ptrecord.data(), ptrecord.size());
        PTDecoder decoder;
        decoder.decode(ptrecord.data(), ptrecord.size());
        // INFO("++ adjust aux_tail from " << hexval(pmap->aux_tail) << " to "
        //                                 << hexval(pmap->aux_tail + auxSize));
        assert(pmap->aux_tail + auxSize <= pmap->aux_head);
        __sync_fetch_and_add((uint64_t *)&(pmap->aux_tail), auxSize);
      }
    }
    switch (header->type) {
    case (PERF_RECORD_MMAP):
    case (PERF_RECORD_LOST):
    case (PERF_RECORD_COMM):
    case (PERF_RECORD_EXIT):
    case (PERF_RECORD_THROTTLE):
    case (PERF_RECORD_UNTHROTTLE):
    case (PERF_RECORD_FORK):
    case (PERF_RECORD_READ):
    case (PERF_RECORD_SAMPLE):
    case (PERF_RECORD_MMAP2):
      unreachable("unhandled record " << header->type);
    case (PERF_RECORD_AUX):
      break;
    case (PERF_RECORD_ITRACE_START): {
      auto *record = get_event<struct pref_event_itrace_start>(
          ring_data, regular_ring_data_size, data_tail);
      INFO("start trace PID" << record->pid << " TID " << record->tid);
      break;
    }
    case (PERF_RECORD_LOST_SAMPLES):
    case (PERF_RECORD_SWITCH):
    case (PERF_RECORD_SWITCH_CPU_WIDE):
    case (PERF_RECORD_NAMESPACES):
    case (PERF_RECORD_KSYMBOL):
    case (PERF_RECORD_BPF_EVENT):
      unreachable("unhandled record " << header->type);
      break;
    default:
      ERROR("unknown type " << header->type);
      exit(-1);
    }
    data_tail += header->size;
  }
  while (!__sync_bool_compare_and_swap(&(pmap->data_tail), pmap->data_tail,
                                       pmap->data_head)) {
  };
  ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
}

void ptWorker(int core_id) {
  pid_t pid;
  int cpu = core_id; // measure on cpu 6
  LOG_TO_FILE("afl.log", "Measuring on core " << core_id); 
  // setup signal handler for receiving perf data signal
  pid = -1;
  struct sigaction sa;
  memset(&sa, 0, sizeof(struct sigaction));
  sa.sa_sigaction = perf_event_handler;
  sa.sa_flags = SA_SIGINFO;

  if (sigaction(SIGIO, &sa, NULL) < 0) {
    LOG_TO_FILE("afl.log", "Ooops, failed to set signal handler for perf"); 
    ERROR("failed to set signal handler for perf\n");
    exit(-1);
  }
  ////////////////////////////////////////////////////////////////
  long long count = 0;
  struct perf_event_attr attr;
  memset(&attr, 0, sizeof(struct perf_event_attr));
  attr.type = PERF_TYPE_PT;
  attr.size = sizeof(struct perf_event_attr);
  /*
   * findout all configurations using following command
   * grep -H . /sys/bus/event_source/devices/intel_pt/format/\*
   */
  attr.config = 0x300e601;
  attr.sample_period = 1;
  attr.sample_type = PERF_SAMPLE_IP | PERF_SAMPLE_TID | PERF_SAMPLE_TIME |
                     PERF_SAMPLE_CPU | PERF_SAMPLE_IDENTIFIER;
  attr.read_format = PERF_FORMAT_ID;
  attr.disabled = 1;
  attr.inherit = 1;
  attr.sample_id_all = 1;
  attr.exclude_user = 1;
  attr.exclude_kernel = 0;
  attr.exclude_hv = 0;
  attr.exclude_host = 1;
  attr.exclude_guest = 0;
  attr.exclude_idle = 0;
  attr.watermark = 0;
  attr.wakeup_events = 0;
  // attr.aux_watermark = 0;
  // attr.exclude_idle = 1;

  int group_fd = -1;
  unsigned long flags = 0;
  LOG_TO_FILE("afl.log", "Setting up PT...!"); 
  int fd = perf_event_open(&attr, pid, cpu, group_fd, flags);
  if (fd < 0) {
    LOG_TO_FILE("afl.log", "perf_event_open failed!");
    ERROR("Error opening leader event "
          << hexval(attr.config) << "\n"
          << "try run as root or set /proc/sys/kernel/perf_event_paranoid\n"
          << "also check /sys/devices/intel_pt/type\n"
          << "run perf record -e intel_pt// -vvv to confirm event type\n");
    exit(EXIT_FAILURE);
  }
 
  // LOG_TO_FILE("afl.log", "> perf fd =" << fd);
  if (setup_mmap(&attr, fd) < 0) {
    LOG_TO_FILE("afl.log", "Error setting up mmap");
    return;
  }

  fcntl(fd, F_SETFL, O_RDWR | O_NONBLOCK | O_ASYNC);
  fcntl(fd, F_SETSIG, SIGIO);
  fcntl(fd, F_SETOWN, getpid());
  fcntl(fd, F_SETOWN_EX, getpid());

  ioctl(fd, PERF_EVENT_IOC_RESET, 0);
  if (ioctl(fd, PERF_EVENT_IOC_ENABLE, 0) < 0) {
    LOG_TO_FILE("afl.log", "Error enabling PT");
  }
  LOG_TO_FILE("afl.log", "PT Set up finished!");
  outs() << "====================================================\n";
  // start to poll buffer
  while (1) {
    check_buffer(fd);
    fflush(stdout);
  }

  ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
  close(fd);
}
#endif
