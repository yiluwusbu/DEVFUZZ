///
/// hardware model for lanai
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// 5.15 not working

#include "HWModel.h"

class HWModel_lanai : public HWModel {
public:
  HWModel_lanai() : HWModel("lanai", 0x14c1, 0x0008), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_lanai(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 761)
      return 0;
    switch (addr) {
    case (0): {
      *((uint32_t *)dest) = 0x00;
      break;
    }
    case (0x2c): {
      *((uint32_t *)dest) = 0x00;
      break;
    }
    case 0x20000 ... 0x40000: {
      *((uint32_t *)dest) = *((uint32_t *)&device_ram[addr]);
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
    case 0x20000 ... 0x40000: {
      *((uint32_t *)&device_ram[addr]) = data;
      break;
    }
    default:
      break;
    }
  };

private:
  int probe_len;

  uint8_t device_ram[1024000];
};
