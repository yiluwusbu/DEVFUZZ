///
/// hardware model for solo6x10
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// 5.15 not working?

#include "HWModel.h"

class HWModel_solo6x10 : public HWModel {
public:
  HWModel_solo6x10() : HWModel("solo6x10", 0x1bb3, 0x4304), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_solo6x10(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 1000)
      return 0;
    switch (addr) {
    case (0x0): {
      *((uint32_t *)dest) = 0x70707070;
      break;
    }
    case (0xa): {
      static int cnt;
      if (cnt++ == 63)
        *((uint16_t *)dest) = 0x8080;
      else
        *((uint16_t *)dest) = 0x0;
      break;
    }
    case (0xc): {
      *((uint16_t *)dest) = 0x0;
      break;
    }
    case (0x6): {
      *((uint8_t *)dest) = 0x0;
      break;
    }
    case (0x8): {
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
