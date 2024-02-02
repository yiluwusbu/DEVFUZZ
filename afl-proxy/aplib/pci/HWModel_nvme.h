///
/// hardware model for nvme
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_nvme : public HWModel {
public:
  HWModel_nvme()
      : HWModel("nvme", 0x106b, 0x2001, 0, 0, 0x010802), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 16384},
              {PCI_BAR_TYPE_MMIO, 0},
              {PCI_BAR_TYPE_MMIO, 0},
              {PCI_BAR_TYPE_MMIO, 0},
              {PCI_BAR_TYPE_MMIO, 256},
              {PCI_BAR_TYPE_MMIO, 0}});
  }
  virtual ~HWModel_nvme(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 7)
      return 0;
    switch (addr) {
    case (0x1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffffff;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0xffffff00;
      cnt++;
      break;
    }
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x30303ff;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x101010;
      cnt++;
      break;
    }
    case (0x3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x18000;
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
