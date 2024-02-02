///
/// hardware model for rtw88_8822ce
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_rtw88_8822ce : public HWModel {
public:
  HWModel_rtw88_8822ce()
      : HWModel("rtw88_8822ce", 0x10ec, 0xc822), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_rtw88_8822ce(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 8)
      return 0;
    switch (addr) {
    case (0x80): {
      *((uint32_t *)dest) = 0xc078;
      break;
    }
    case (0x3): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x30): {
      *((uint32_t *)dest) = 0xffffffff;
      break;
    }
    case (0x10fc): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x01a0): {
      *((uint32_t *)dest) = 0x19;
      break;
    }
    case (0x100): {
      *((uint32_t *)dest) = 0xea;
      break;
    }
    case (0x3d9): {
      *((uint32_t *)dest) = 0xea;
      break;
    }
    case (0x1208): {
      *((uint32_t *)dest) = 0x0;
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
