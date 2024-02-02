///
/// hardware model for rtsx_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_rtsx_pci : public HWModel {
public:
  HWModel_rtsx_pci()
      : HWModel("rtsx_pci", 0x10ec, 0x5209, 0, 0, 0xff0000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_rtsx_pci(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
    switch (addr) {
    case (0x1c): {
      *((uint8_t *)dest) = 0x0;
      break;
    }
    case (0x10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 4)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 5)
        *((uint32_t *)dest) = 0x80808000;
      if (cnt == 6)
        *((uint32_t *)dest) = 0x80808000;
      if (cnt == 7)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 8)
        *((uint32_t *)dest) = 0x80000000;
      if (cnt == 9)
        *((uint32_t *)dest) = 0x80000000;
      cnt++;
      break;
    }
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)dest) = rand();
        break;
      case (2):
        *((uint16_t *)dest) = rand();
        break;
      case (4):
        *((uint32_t *)dest) = rand();
        break;
      default:
        break;
      }
    }
    }

    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
