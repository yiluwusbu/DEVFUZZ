///
/// hardware model for vme_tsi148
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_vme_tsi148 : public HWModel {
public:
  HWModel_vme_tsi148() : HWModel("vme_tsi148", 0x10e3, 0x0148), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_vme_tsi148(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 7)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x101010e3;
      cnt++;
      break;
    }
    case (0x23c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x420): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)dest) = 0;
        break;
      case (2):
        *((uint16_t *)dest) = 0;
        break;
      case (4):
        *((uint32_t *)dest) = 0;
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
