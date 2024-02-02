///
/// hardware model for hpsa
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_hpsa : public HWModel {
public:
  HWModel_hpsa()
      : HWModel("hpsa", 0x103c, 0x323a, 0x103c, 0x3245), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_hpsa(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
    switch (addr) {
    case (0x0): {
      *((uint8_t *)dest) = 'C';
      break;
    }
    case (0x1): {
      *((uint8_t *)dest) = 'I';
      break;
    }
    case (0x2): {
      *((uint8_t *)dest) = 'S';
      break;
    }
    case (0x3): {
      *((uint8_t *)dest) = 'S';
      break;
    }
    case (0x8): {
      *((uint32_t *)dest) = 0xffffffff;
      break;
    }
    case (0xc): {
      *((uint32_t *)dest) = 0x00000006l;
      break;
    }
    case (0x20): {
      *((uint32_t *)dest) = 0x2;
      break;
    }
    case (0x34): {
      *((uint32_t *)dest) = 0x8;
      break;
    }
    case (0x40): {
      *((uint32_t *)dest) = 0x1;
      break;
    }
    case (0x44): {
      *((uint32_t *)dest) = 0x10;
      break;
    }
    case (0x54): {
      *((uint32_t *)dest) = 0x10;
      break;
    }
    case (0xb0): {
      *((uint32_t *)dest) = 0xffff0000;
      break;
    }
    case (0xb4): {
      *((uint32_t *)dest) = 0x10;
      break;
    }
    case (0xb8): {
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
