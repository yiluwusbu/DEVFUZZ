///
/// hardware model for pata_pdc202xx_old
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_pata_pdc202xx_old : public HWModel {
public:
  HWModel_pata_pdc202xx_old()
      : HWModel("pata_pdc202xx_old", 0x105a, 0x0d30), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_pata_pdc202xx_old(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 52)
      return 0;
    switch (addr) {
    case (0x2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0xaa;
      if (cnt == 5)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint8_t *)dest) = 0xaa;
      if (cnt == 7)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint8_t *)dest) = 0xaa;
      if (cnt == 17)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint8_t *)dest) = 0xaa;
      if (cnt == 19)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xa): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0xff;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1f): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x7): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x27): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x55;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x55;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x55;
      if (cnt == 5)
        *((uint8_t *)dest) = 0x55;
      cnt++;
      break;
    }
    case (0x1): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x5): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x6): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
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
