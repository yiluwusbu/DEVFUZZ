///
/// QEMU definitions
/// 2022 Tong Zhang<ztong0001@gmail.com>
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
///
#ifndef _QEMU_DEFS_
#define _QEMU_DEFS_

#if defined(__cplusplus)
extern "C" {
#endif

// function inside hw/sfp/sfp-pci.c
extern void sfp_set_irq(int isset);
// function inside include/exec/cpu-common.h
extern void cpu_physical_memory_rw(uint64_t addr, void *buf, uint64_t len,
                                   bool is_write);
#if defined(__cplusplus)
}
#endif
#endif
