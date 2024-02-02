///
/// hardware model for megaraid_sas
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// need IRQ

#include "HWModel.h"

class HWModel_megaraid_sas : public HWModel {
public:
  HWModel_megaraid_sas()
      : HWModel("megaraid_sas", 0x1000, 0x005b, 0, 0, 0x010000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_megaraid_sas(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 1000)
      return 0;
    switch (addr) {
    case (0x0): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x34): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0xb0): {
      static int cnt;
      if (cnt == 0) {
        *((uint32_t *)dest) = 0xB0000000;
      } else if (cnt >= 1) {
        *((uint32_t *)dest) = 0xC0000000;
      }
      cnt = (cnt + 1) % 10;
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
