///
/// hardware model for zatm
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_zatm : public HWModel {
public:
  HWModel_zatm() : HWModel("zatm", 0x1193, 0x0002), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_zatm(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100000)
      return 0;
    if (addr == 0x4)
      *((uint32_t *)dest) = 0x01000000;
    else if (addr == 0x20)
      *((uint32_t *)dest) = data_0x20;
    else if (addr == 0x28)
      *((uint32_t *)dest) = data_0x28;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    if (addr == 0x20)
      data_0x20 = data & 0xffffffff;
    else if (addr == 0x28)
      data_0x28 = data & 0xffffffff;
  };

private:
  int probe_len;
  uint32_t data_0x20, data_0x28;
};
