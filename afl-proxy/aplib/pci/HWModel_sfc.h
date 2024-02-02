///
/// hardware model for sfc
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// 5.15 not working

#include "HWModel.h"

class HWModel_sfc : public HWModel {
public:
  HWModel_sfc() : HWModel("sfc", 0x1924, 0x0a03), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_sfc(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 7)
      return 0;
    switch (addr) {
    case (0x10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xb0b0f8b0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0707074f;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0707074f;
      if (cnt == 3)
        *((uint32_t *)dest) = 0xb0b0f8b0;
      if (cnt == 4)
        *((uint32_t *)dest) = 0xb0f8b0b0;
      if (cnt == 5)
        *((uint32_t *)dest) = 0x4f070707;
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
