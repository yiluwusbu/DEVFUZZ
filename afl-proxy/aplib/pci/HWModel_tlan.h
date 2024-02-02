///
/// hardware model for tlan
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_tlan : public HWModel {
public:
  HWModel_tlan()
      : HWModel("tlan", 0x0e11, 0xae32, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_tlan(){};
  virtual void restart_device() final { probe_len = 0; };

  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    uint8_t *ptr = &(device_ram[addr]);
    switch (size) {
    case (1):
      *((uint8_t *)dest) = *(uint8_t *)(ptr);
      break;
    case (2):
      *((uint16_t *)dest) = *(uint16_t *)(ptr);
      break;
    case (4):
      *((uint32_t *)dest) = *(uint32_t *)(ptr);
      break;
    case (8):
      *((uint64_t *)ptr) = *(uint64_t *)(ptr);
      break;
    default:
      assert(0);
    }
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    uint8_t *ptr = &device_ram[addr];
    switch (size) {
    case (1):
      *ptr = (uint8_t)((data)&0xff);
      break;
    case (2):
      *((uint16_t *)ptr) = (uint16_t)((data)&0xffff);
      break;
    case (4):
      *((uint32_t *)ptr) = (uint32_t)((data)&0xffffffff);
      break;
    case (8):
      *((uint64_t *)ptr) = (uint64_t)(data);
      break;
    default:
      assert(0);
    }
  };

private:
  int probe_len;
  uint8_t device_ram[1024000];
};
