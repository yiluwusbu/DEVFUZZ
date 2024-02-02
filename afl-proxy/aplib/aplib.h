///
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
///
#ifndef _AFL_PROXY_LIB_H_
#define _AFL_PROXY_LIB_H_

#include <fcntl.h>
#include <semaphore.h>
#include <stdint.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

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

#if defined(__cplusplus)
extern "C" {
#endif
// this is a c library for afl-proxy's client
void ap_init(void);
const char *ap_get_fuzz_file(void);
int ap_get_fuzz_data(uint8_t *dest, uint64_t addr, size_t size, int bar);
void ap_set_fuzz_data(uint64_t data, uint64_t addr, size_t size, int bar);
void ap_qemu_fuzz_dma_generic(uint8_t * buffer, int size);
int ap_qemu_mmio_read(uint8_t *dest, uint64_t addr, size_t size, int bar);
void ap_log_pc(uint64_t);
void ap_exit(void);
void ap_attach_pt(void);
void ap_reattach_pt(void);
void ap_trigger_irq(void);
void ap_fill_dma_buffer(void);

// this is a blocking function, QEMU will call this function to check if it
// need to assert/de-assert IRQ
bool ap_check_irq_request(void);

// set system memory map -- called by qemu
void ap_set_e820(void *qemu_e820_table, int count);
// our utility function
bool ap_is_ram(uintptr_t addr);

// SHM IPC stuff
void shm_ipc_read_data(uint8_t *dest, uint64_t addr, size_t size);
void shm_ipc_write_data(uint64_t data, uint64_t addr, size_t size);

const char *ap_get_dev_name(void);
// device generic information
uint16_t ap_get_pci_vid(void);
uint16_t ap_get_pci_pid(void);
uint16_t ap_get_pci_subvid(void);
uint16_t ap_get_pci_subpid(void);
uint32_t ap_get_pci_class(void);
uint16_t ap_get_pci_rev(void);
// for PCI devices
int ap_get_pci_bar_cnt(void);
int ap_get_pci_bar_type(int idx);
int ap_get_pci_bar_size(int idx);
int ap_get_pci_msix_bar_idx(void);
const char *ap_get_rom_path(void);
// for USB devices
uint16_t ap_get_usb_vid(void);
uint16_t ap_get_usb_pid(void);

// specialized for USB devices
void *ap_get_usb_desc(void);

#if defined(__cplusplus)
}
#endif

#endif
