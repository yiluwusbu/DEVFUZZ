///
/// hardware model for iwlwifi
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// - need MSI

#include "HWModel.h"

class HWModel_iwlwifi : public HWModel {
public:
  HWModel_iwlwifi()
      : HWModel("iwlwifi", 0x8086, 0x0082, 0x8086, 0x1301, 0x028000, 0x0),
        probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_iwlwifi(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
    switch (addr) {
    case (0): {
      static int cnt;
      if (cnt < 2)
        *((uint32_t *)dest) = 0x00400000;
      else if (cnt < 10)
        *((uint32_t *)dest) = 0x00200000;
      else
        *((uint32_t *)dest) = 0x00400000;
      cnt++;
      break;
    }
    case (0x30): {
      static int cnt;
      if (cnt < 2)
        *((uint32_t *)dest) = 0x00000002;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x00000001;
      cnt++;
      break;
    }
    case (0x34): {
      *((uint32_t *)dest) = 0x00000000;
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
