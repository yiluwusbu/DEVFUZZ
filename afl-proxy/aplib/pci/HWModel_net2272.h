///
/// hardware model for net2272
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_net2272 : public HWModel {
public:
  HWModel_net2272() : HWModel("net2272", 0x10b5, 0x9054), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_net2272(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 761)
      return 0;
    switch (addr) {
    case (0x02): {
      *((uint32_t *)dest) = 0x40;
      break;
    }
    case (0x32): {
      *((uint32_t *)dest) = 0x40;
      break;
    }
    case (0xf8): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x68): {
      *((uint32_t *)dest) = 0x00;
      break;
    }
    case (0x800): {
      *((uint8_t *)dest) = 0x0;
      break;
    }
    case (0x3a): {
      *((uint8_t *)dest) = data_0x30;
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
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    switch (addr) {
    case (0x3a): {
      data_0x30 = data;
      break;
    }
    default:
      break;
    }
  };

private:
  int probe_len;
  uint8_t data_0x30;
};
