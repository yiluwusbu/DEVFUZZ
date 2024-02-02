///
/// afl proxy library
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2020-2022 Tong Zhang<ztong0001@gmail.com>
///
#include "aplib.h"
#include "shm.h"

#include <assert.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <time.h>
#include <chrono>

#include <map>
#include <set>
#include <string>
#include <thread>
#include <vector>

#include "EnvKnob.h"

#include "hw_model.h"

using namespace std;

// a list of dma addresses -- those are physical addresses
set<uint64_t> dma_addrs;

extern "C" {
#define MMIO_SIZE (1024)
// #define DMA_SIZE (4096 * 10)
// for serializing qemu thread calling IPC
static pthread_mutex_t shm_ipc_lock;

// function inside hw/sfp/sfp-pci.c
extern void sfp_set_irq(int isset);
// function inside include/exec/cpu-common.h
extern void cpu_physical_memory_rw(uint64_t addr, void *buf, uint64_t len,
                                   bool is_write);

// shared memory
struct XXX *sm = nullptr;
SHM<struct XXX> *shm = nullptr;

size_t fuzzdatasize;
uint8_t *fuzzdata;

static pid_t kvm_tid;

int fuzz_file_fd;

static int gdb_attached;
// 0-not set 1-r 2-w 3-rw
static int dump_rw_addr;
#define IS_DUMP_R (dump_rw_addr & 1)
#define IS_DUMP_W (dump_rw_addr & 2)
#define IS_DUMP_RW (IS_DUMP_R || IS_DUMP_W)

// dump address to file
static bool dump_rw_addr_to_file;
static string dump_rw_addr_filename;

// whether should we use DMA
static int use_dma;
static bool use_stage2;
// How long an AFL fuzzing epoch lasts
static int64_t afl_epoch;
static  bool test_probe;
static  bool model_probe_fuzz;
static  int model_mutate_prob = 10; // prob of mutating the value of the probing model
static int model_reset_time = 3;
static uint64_t model_delay=0;
// TODO: need to figure out the address of IRQ register
// stores the milliseconds interval between triggering each IRQ,
// This knob can be overriden by upper-level model
static int use_irq;
static std::chrono::_V2::steady_clock::time_point afl_last_epoch_end = chrono::steady_clock::now();

void real_ap_init(void) {
  
  if (sm)
    return;
  fuzz_file_fd = -1;
again:
  srand(time(NULL));
  string shmname = "/afl-proxy-";
  shmname += string(getenv("SFP_SHMID"));
  shm = new SHM<struct XXX>(shmname.c_str());
  if (!shm->open(SHMOpenType::CONNECT)) {
    WARN("cannot connect tp" + shmname + " retry.. ");
    usleep(100);
    delete shm;
    goto again;
  }
  sm = shm->getMem();
  INFO("connected " << shmname);

  // wait till this is ready
  if (!sm->ready) {
    shm->close();
    delete shm;
    goto again;
  };

  int sval;
  sem_getvalue(&sm->semr, &sval);
  // INFO("==>semr value=" << sval << " ready?" << (int)sm->ready);
  INFO("path name: " << sm->path);
  std::ifstream is(sm->path, std::ifstream::binary);
  is.seekg(0, is.end);
  fuzzdatasize = is.tellg();
  is.close();
  fuzz_file_fd = open(sm->path, O_RDWR);
  fuzzdata = (uint8_t *)mmap(0, fuzzdatasize, PROT_READ | PROT_WRITE,
                             MAP_PRIVATE, fuzz_file_fd, 0);
  if (fuzzdata == MAP_FAILED) {
    fuzzdata = nullptr;
    fuzzdatasize = 0;
  }
  INFO("fuzz data size: " << fuzzdatasize);
  ap_reattach_pt();
  pthread_mutex_init(&shm_ipc_lock, NULL);
};

///
/// Trigger IRQ Thread
///
thread *trigger_irq_thread;
void ti_worker() {
  // add a little bit delay here since QEMU need some time to fully initialized,
  // before that sending IRQ does not make sense
  sleep(5);
  while (1) {
    // INFO("Inject IRQ");
    if (use_irq < 1000)
      usleep(use_irq * 1000);
    else
      sleep(use_irq / 1000);
    ap_trigger_irq();
  }
}

///
/// WatchDog Thread
/// If the Kernel Panics, we terminate the QEMU and restart it
thread *watchdog_thread;
void watch_dog() {
  sleep(130);
  while (1) {
    auto cur_time = chrono::steady_clock::now();
    auto elapsed_secs = chrono::duration_cast<chrono::seconds>(cur_time - afl_last_epoch_end).count();
    if (elapsed_secs > 60) {
      exit(0);
    }
    sleep(5);
  }
}

static bool isEnabled=false;
void ap_init(void) {
  static bool initialized;
  if (!initialized) {
    srand(time(0));
    hw_model_internal_init();
    initialized = true;
    EnvKnob knob0("SFP_DEV_MODEL");
    assert(knob0.isPresented() && "SFP_DEV_MODEL is not set");
    init_hw_instance(knob0.getStringValue());
    init_stage2_hw_instance(knob0.getStringValue());
    
    EnvKnob knob1("WAITGDB");
    if (knob1.isSet()) {
      outs() << "wait gdb, pid=" << getpid() << "\n";
      getchar();
      gdb_attached = 1;
    }

    EnvKnob knob2("AP_DUMP_RW");
    dump_rw_addr = knob2.getIntValue();

    EnvKnob knob3("AP_DUMP_FILE");
    if (knob3.isPresented() && knob3.isSet()) {
      dump_rw_addr_to_file = true;
      dump_rw_addr_filename = knob3.getStringValue();
    }

    EnvKnob knob4("USE_IRQ");
    //////////////////////////
    if (knob4.isSet()) {
      use_irq = knob4.getIntValue();
      trigger_irq_thread = new thread(ti_worker);
    }
    /////////////////////////
    EnvKnob knob5("USE_DMA");
    use_dma = knob5.isSet();

    /////////////////////////
    EnvKnob knob_afl("AFL_EPOCH");
    if (knob_afl.isPresented() && knob_afl.isSet()) {
      afl_epoch = knob_afl.getIntValue();
    } else {
      afl_epoch = INT64_MAX;
    }

    ////////////////////////
    EnvKnob knob_stage2("USE_STAGE2");
    if (knob_stage2.isPresented() && knob_stage2.isSet()) {
      use_stage2 = true;
    }
    
    EnvKnob knob_model_prob("USE_MODEL_PROB");
    if (knob_model_prob.isPresented() && use_stage2) {
      assert(get_stage2_hw_instance());
      int prob = knob_model_prob.getIntValue();
      get_stage2_hw_instance()->setProb(prob);
    }

    if (use_stage2) {
      assert(knob_model_prob.isPresented());
    }

    EnvKnob knob_mdl_delay("MODEL_DELAY");
    if (knob_mdl_delay.isPresented() && knob_mdl_delay.isSet()) {
      model_delay = knob_mdl_delay.getIntValue();
    }

    /////////////////////////
    EnvKnob knob_test_probe("TEST_PROBE");
    if (knob_test_probe.isPresented() && knob_test_probe.isSet()) {
      test_probe = true;
    }


    /////////////////////////
    EnvKnob knob_mpf("MODEL_PROBE_FUZZ");
    if (knob_mpf.isPresented() && knob_mpf.isSet()) {
      model_probe_fuzz = true;
    }


    ////////////////////////////
    EnvKnob knob_mdl_reset_time("MODEL_RESET_TIME");
    if (knob_mdl_reset_time.isPresented()
       && knob_mdl_reset_time.isSet()) {
      model_reset_time = knob_mdl_reset_time.getIntValue();
    }

    ////////////////////////////
    EnvKnob knob_mutate_prob("MODEL_MUTATE_PROB");
    if (knob_mutate_prob.isPresented()) {
      model_mutate_prob = knob_mutate_prob.getIntValue();
      INFO("Model Mutation Probability Set As: " << model_mutate_prob);
    }
    

    // export device memory through shared memory
    EnvKnob knob6("EXPORT_DEVMEM");
    if (knob6.isPresented() && knob6.isSet()) {
      string shmname = "/afl-proxy-";
      shmname += string(getenv("SFP_SHMID"));
      hw_instance_export_devmem(shmname);
    }

    EnvKnob knob7("AP_DISABLED");
    if (knob7.isPresented() && knob7.isSet())
      return;
    isEnabled = true;

    if (use_stage2) {
      assert(get_stage2_hw_instance());
    }
    watchdog_thread = new thread(watch_dog);
  }
  
  if (isEnabled)
    real_ap_init();
}

const char *ap_get_fuzz_file(void) {
  assert(sm);
  return sm->path;
}

int ap_fetch_fuzz_data_rand(char *dest, uint64_t addr, size_t size) {
  uint64_t rand = random() | (random() << 16) | (random() << 24);
  memcpy(dest, &rand, sizeof(uint64_t));
  return size;
}

int ap_get_fuzz_data(uint8_t *dest, uint64_t addr, size_t size, int bar) {
  static int counter;
  static uint64_t delay_counter = 0;
  static std::chrono::_V2::steady_clock::time_point last_dev_restart = chrono::steady_clock::now();
  uint64_t zero = 0;
  uint64_t wrapped_addr;
  auto cur_time = chrono::steady_clock::now();
  auto elapsed_secs = chrono::duration_cast<chrono::seconds>(cur_time - afl_last_epoch_end).count();
  auto secs_since_last_restart = chrono::duration_cast<chrono::seconds>(cur_time - last_dev_restart).count();
  Stage2HWModel * stage2 = get_stage2_hw_instance();
  uint64_t probe_mdl_input;
  uint64_t probe_input;
  // for probing
  if (!test_probe) {
    if (get_hw_instance()->read(dest, addr, size, bar))
      goto end;
  } else {
    // fuzz probing
    // try to reset model
    assert(ap_get_fuzz_file()[0]);
    counter++;
    if (counter % 100 == 0 || elapsed_secs >= afl_epoch) {
      counter = 0;
      INFO("epoch ended");
      ap_exit();
      afl_last_epoch_end = chrono::steady_clock::now();
    }
    ap_init();
    if (model_probe_fuzz) {
      if (secs_since_last_restart > model_reset_time) {
        get_hw_instance()->restart_device();
        INFO("Device model resetted..");
        last_dev_restart = cur_time;
      }
      get_hw_instance()->read((uint8_t*)&probe_mdl_input, addr, size, bar);
      if (yes(model_mutate_prob) && fuzzdatasize) { //&& get_hw_instance()->getRestartCnt() > 0) {
        wrapped_addr = addr % fuzzdatasize;
        memcpy(dest, fuzzdata + wrapped_addr, size);
      } else {
        // use symbolic model
        memcpy(dest, &probe_mdl_input, size);
      }
    } else if (fuzzdatasize) {
      // pure AFL based probing, very dumb baseline
      if (addr < fuzzdatasize)
        memcpy(dest, fuzzdata + addr, size);
    }
    goto end;
  }
  // probing testing logic end
  if (!sm) {
    for (int i = 0; i < size; i++)
      dest[i] = rand();
    goto end;
  }
  if (ap_get_fuzz_file()[0] == 0) {
    // read data using IPC
    shm_ipc_read_data(dest, addr, size);
    goto end;
  }
  counter++;
  delay_counter++;
  if (counter % 100 == 0 || elapsed_secs >= afl_epoch) {
    counter = 0;
    INFO("epoch ended");
    ap_exit();
    afl_last_epoch_end = chrono::steady_clock::now();
  }
  ap_init();
  if (!fuzzdatasize)
    goto end;
  wrapped_addr = addr % fuzzdatasize;
  if (wrapped_addr >= fuzzdatasize)
    goto end;
  
  if (stage2 && use_stage2 && delay_counter > model_delay) {
    stage2->feedFuzzMMIOData(addr, dest, size, (fuzzdata + wrapped_addr));
  } else if (addr + size <= fuzzdatasize) {
    memcpy(dest, fuzzdata + wrapped_addr, size);
  } else {
    memcpy(dest, &zero, size);
  }
end:
  if (IS_DUMP_R) {
    if (dump_rw_addr_to_file) {
      LOG_TO_FILE(dump_rw_addr_filename, "read "
                                             << size << " byte, bar " << bar
                                             << " @ " << hexval(addr) << "="
                                             << hexval(*(uint64_t *)(dest)));

    } else {
      INFO("read " << size << " byte, bar " << bar << " @ " << hexval(addr)
                   << "=" << hexval(*(uint64_t *)(dest)));
    }
  }
  return size;
}

void ap_set_fuzz_data(uint64_t data, uint64_t addr, size_t size, int bar) {
  if (IS_DUMP_W) {
    if (dump_rw_addr_to_file) {
      LOG_TO_FILE(dump_rw_addr_filename,
                  "write " << size << " byte, bar " << bar << " @ "
                           << hexval(addr) << "=" << hexval(data));
    } else {
      INFO("write " << size << " byte, bar " << bar << " @ " << hexval(addr)
                    << "=" << hexval(data));
    }
  }
  // for probing
  get_hw_instance()->write(data, addr, size, bar);
  // intercept writes of DMA address
  Stage2HWModel * stage2 = get_stage2_hw_instance();
  if (stage2 && use_stage2) {
    stage2->captureDMARegistration(addr, data);
  }
  if (!sm)
    return;
  if (ap_get_fuzz_file()[0] == 0) {
    // write data using IPC
    shm_ipc_write_data(data, addr, size);
    return;
  }

  if (!fuzzdatasize)
    return;
  
  addr = addr % fuzzdatasize;
  if (addr >= fuzzdatasize)
    return;
  memcpy(fuzzdata + addr, &data, size);
}

void ap_log_pc(uint64_t rip) {
  if (!sm)
    ap_init();
  if (!sm)
    return;
  // INFO("ap_log_pc"<<hexval(rip));
  sm->type = 0x01;
  memcpy(sm->data, &rip, sizeof(uint64_t));
  if (sem_post(&sm->semw) == -1) {
    unreachable("error post semw");
  }
again:
  if (sem_wait(&sm->semr) == -1) {
    if (errno == EINTR)
      goto again;
    unreachable("error wait semr");
  }
}

void ap_exit(void) {
  if (shm) {
    // close
    close(fuzz_file_fd);
    fuzz_file_fd = -1;

    int sval;
    sem_getvalue(&sm->semr, &sval);
    sm->type = 0xff;
    // reset the flag
    sm->ready = 0;
    if (sem_post(&sm->semw) == -1) {
      unreachable("error post semw");
    }
    // AP will exit anyway ... so why bother waiting?
//     if (sem_wait(&sm->semr) == -1) {
//       if (errno == EINTR) {        
//         goto close;
//       }
//       unreachable("error wait semr");
//     }
// close:
    shm->close();
    delete shm;
  }
  sm = nullptr;
  shm = nullptr;
}

#ifdef __linux__
// call this from KVM thread to start coverage collection using PT
void ap_attach_pt(void) {
  if (!sm)
    ap_init();
  if (!sm)
    return;
  kvm_tid = gettid();
  sm->type = 0x02;
  memcpy(sm->data, &kvm_tid, sizeof(pid_t));
  if (sem_post(&sm->semw) == -1) {
    unreachable("error post semw");
  }
  // TODO: need to wait proxy ack back here
again:
  if (sem_wait(&sm->semr) == -1) {
    if (errno == EINTR)
      goto again;
    unreachable("error wait semr");
  }
}
#else
void ap_attach_pt(void) {
  static int print_once;
  if (!print_once) {
    print_once = 1;
    fprintf(stderr, "PT is not supported\n");
  }
}
#endif
void ap_reattach_pt(void) {
  kvm_tid = gettid();
  assert(sm);
  INFO("ap_reattach_pt:" << kvm_tid);
  sm->type = 0x02;
  memcpy(sm->data, &kvm_tid, sizeof(pid_t));
  if (sem_post(&sm->semw) == -1)
    unreachable("error post semw");
again:
  if (sem_wait(&sm->semr) == -1) {
    if (errno == EINTR)
      goto again;
    unreachable("error wait semr");
  }
}

///
/// called by QEMU to trigger DMA data buffer fill -- through ML model or random
/// data
///
void ap_qemu_fuzz_dma_generic(uint8_t * buffer, int size) {
  // INFO("QEMU DMA FUZZ");
  Stage2HWModel * stage2 = get_stage2_hw_instance();
  static uint64_t cnt;
  cnt++;
  // if (cnt < 100)
  //   return;
  if (fuzzdatasize == 0) {
    for (int i=0; i<size; i++) {
      buffer[i] = yes(model_mutate_prob) ? (uint8_t)rand() : buffer[i];
    }
    return;
  }
  if (use_stage2 && stage2) {
    stage2->fuzzQEMU_DMABuffer(buffer, size, fuzzdata, fuzzdatasize, model_mutate_prob);
    for (int i=0; i<size; i++) {
      buffer[i] = yes(model_mutate_prob) ? fuzzdata[i % fuzzdatasize] : buffer[i];
    }
  } else {
    for (int i=0; i<size; i++) {
      buffer[i] = yes(model_mutate_prob) ? fuzzdata[i % fuzzdatasize] : buffer[i];
    }
  }
}

void ap_fill_dma_buffer() {
  static bool secondary_dma_scanned =  true; // false;
  if (!use_dma)
    return;
#if 0
  // system("logger ap_fill_dma_buffer");
  ///
  /// write random data in the DMA region --
  /// DMA region is expected to be synchronized(visible) after the interrupt
  /// so we can safely assume we need to write DMA first then do IRQ
  uint8_t *buffer = (uint8_t *)malloc(4096);
  for (auto addr : dma_addrs) {
    // we dont know the size of the dma region
    // -- assuming 4k since even with IOMMU it won't protect anything less
    // than 1 page
    for (int i = 0; i < 4096; i++)
      buffer[i] = rand();
    // should get buffer data from ML model
    // for (int i = 0; i < 2064; i += 8)
    //  shm_ipc_read_data(&buffer[i], addr + i, 8);
    // INFO("DMA to " << hexval(addr));
    // write back to QEMU
    cpu_physical_memory_rw(addr, buffer, 4096, true);
  }
  free(buffer);
#elif 0
  get_hw_instance()->lockDMASG();
  const auto &dmasg = get_hw_instance()->getDMASG();
  for (auto &p : dmasg) {
    uint64_t addr = p.first;
    uint64_t size = p.second;
    uint8_t *buffer = (uint8_t *)malloc(size);
    for (int i = 0; i < size; i++)
      buffer[i] = rand();
    cpu_physical_memory_rw(addr, buffer, size, true);
    free(buffer);
  }
  get_hw_instance()->unlockDMASG();
#else
  Stage2HWModel * stage2 = get_stage2_hw_instance();
  int dma_fuzz_sz = fuzzdatasize - MMIO_SIZE;
  if (dma_fuzz_sz < 0) {
    dma_fuzz_sz = 0;
  }
  auto cur_time = chrono::steady_clock::now();
  
  if (stage2 && use_stage2) {
    if (!stage2->isLevel1DMASet()) {
      return;
    } else if (!secondary_dma_scanned) {
      secondary_dma_scanned = true;
      stage2->scanSecondaryDMABuffer();
    }
    stage2->feedFuzzDMAData(fuzzdata + MMIO_SIZE, dma_fuzz_sz, true);
  } 
  // else if (stage2) {
  //   stage2->feedFuzzDMAData(fuzzdata + MMIO_SIZE, dma_fuzz_sz, false);
  // } 
  else {
    get_hw_instance()->feedRandomDMAData();
  }
  auto end_time = chrono::steady_clock::now();
  auto elapsed_secs = chrono::duration_cast<chrono::microseconds>(end_time - cur_time).count();
  // cerr << "DMA fill time: " << elapsed_secs << " us\n";
#endif
}

int ap_qemu_mmio_read(uint8_t *dest, uint64_t addr, size_t size, int bar) {
  static int counter;
  static uint64_t cnt;
  uint64_t wrapped_addr;
  auto cur_time = chrono::steady_clock::now();
  auto elapsed_secs = chrono::duration_cast<chrono::seconds>(cur_time - afl_last_epoch_end).count();
  Stage2HWModel * stage2 = get_stage2_hw_instance();
  // fuzz probing
  // try to reset model
  assert(ap_get_fuzz_file()[0]);
  counter++;
  cnt++;
  if (counter % 100 == 0 || elapsed_secs >= afl_epoch) {
    counter = 0;
    INFO("epoch ended");
    ap_exit();
    afl_last_epoch_end = chrono::steady_clock::now();
  }
  ap_init();

  // Within Probing Phase, Use the Expert Model
  if (!fuzzdatasize || get_hw_instance()->read(dest, addr, size, bar) != 0) {
    return -1;
  }
  // Fuzz with some probability 
  if (yes(model_mutate_prob)) { //&& get_hw_instance()->getRestartCnt() > 0) {
    wrapped_addr = addr % fuzzdatasize;
    if (stage2 && use_stage2) {
      stage2->feedFuzzMMIOData(addr, dest, size, (fuzzdata + wrapped_addr));
    } else {
      memcpy(dest, fuzzdata + wrapped_addr, size);
    }
    return 0;
  } 
  return -1;
}

///
/// trigger one-shot irq
///
void ap_trigger_irq() {
  // if (!use_irq)
  //   return;

  ap_fill_dma_buffer();
  // trigger irq
  if (!use_irq)
    return;
  sfp_set_irq(1);
}

bool ap_check_irq_request(void) {
again:
  if (!sm) {
    sleep(1);
    goto again;
  }
again_wait:
  if (sem_wait(&sm->sem_irq) == -1) {
    if (errno == EINTR)
      goto again_wait;
    unreachable("error wait sem_irq");
  }
  return sm->irq_assert;
}

const char *ap_get_dev_name() { return get_hw_instance()->getName().c_str(); }
///
/// device generic information
///
uint16_t ap_get_pci_vid() { return get_hw_instance()->getVid(); }
uint16_t ap_get_pci_pid() { return get_hw_instance()->getPid(); }
uint16_t ap_get_pci_subvid() { return get_hw_instance()->getSubVid(); }
uint16_t ap_get_pci_subpid() { return get_hw_instance()->getSubPid(); }
uint32_t ap_get_pci_class() { return get_hw_instance()->getClass(); }
uint16_t ap_get_pci_rev() { return get_hw_instance()->getRev(); }

///
/// for usb devices
///
uint16_t ap_get_usb_vid(void) { return get_hw_instance()->getVid(); }
uint16_t ap_get_usb_pid(void) { return get_hw_instance()->getPid(); }

///
/// PCI configuration
///
int ap_get_pci_bar_cnt() { return get_hw_instance()->getPCIBarCnt(); }

int ap_get_pci_bar_type(int idx) {
  return get_hw_instance()->getPCIBarType(idx);
}

int ap_get_pci_bar_size(int idx) {
  return get_hw_instance()->getPCIBarSize(idx);
}

int ap_get_pci_msix_bar_idx() { return get_hw_instance()->getMSIXBarIdx(); }

const char *ap_get_rom_path() {
#ifdef DEV_MODEL_EXPANSION_ROM
  return DEV_MODEL_EXPANSION_ROM;
#else
  return NULL;
#endif
}

// void *ap_get_usb_desc(void) { return HW_MODEL_USB_DESC; }
void *ap_get_usb_desc(void) { return get_hw_instance()->getUSBDesc(); }
}

// shared memory IPC stuff
void shm_ipc_read_data(uint8_t *dest, uint64_t addr, size_t size) {
  pthread_mutex_lock(&shm_ipc_lock);
  sm->type = 0x03;
  sm->rwreq.req_type = 0;
  sm->rwreq.address = addr;
  sm->rwreq.size = size;
  if (sem_post(&sm->semw) == -1) {
    unreachable("error post semw");
  }
again1:
  if (sem_wait(&sm->semr) == -1) {
    // Interrupted System Calls
    if (errno == EINTR)
      goto again1;
    unreachable("error wait semr");
  }
  memcpy(dest, sm->data, size);
  pthread_mutex_unlock(&shm_ipc_lock);
}

void shm_ipc_write_data(uint64_t data, uint64_t addr, size_t size) {
  pthread_mutex_lock(&shm_ipc_lock);
  sm->type = 0x03;
  sm->rwreq.req_type = 1;
  sm->rwreq.address = addr;
  sm->rwreq.size = size;
  if (sem_post(&sm->semw) == -1) {
    unreachable("error post semw");
  }
again1:
  if (sem_wait(&sm->semr) == -1) {
    if (errno == EINTR)
      goto again1;
    unreachable("error wait semr");
  }
  pthread_mutex_unlock(&shm_ipc_lock);
}

// get some idea of the system memory layout
#define E820_RAM 1
struct e820_entry {
  uint64_t addr;
  uint64_t len;
  uint32_t type;
} __attribute__((__packed__)) __attribute((__aligned__(4)));

static struct e820_entry *e820_table;
int e820_table_cnt;

void ap_set_e820(void *_e, int count) {
  e820_table_cnt = count;
  if (!e820_table)
    free(e820_table);
  e820_table = (struct e820_entry *)malloc(sizeof(struct e820_entry) * count);
  memcpy(e820_table, _e, sizeof(struct e820_entry) * count);

  for (int i = 0; i < count; i++)
    INFO(ANSI_COLOR_RED << "e820: "
                        << " type " << e820_table[i].type << " - addr "
                        << hexval(e820_table[i].addr) << " - "
                        << hexval((e820_table[i].len)) << ANSI_COLOR_RESET);
}

bool ap_is_ram(uintptr_t addr) {
  for (int i = 0; i < e820_table_cnt; i++)
    if ((addr >= e820_table[i].addr) &&
        (addr < (e820_table[i].addr + e820_table[i].len)))
      return e820_table[i].type == E820_RAM;
  return false;
}
