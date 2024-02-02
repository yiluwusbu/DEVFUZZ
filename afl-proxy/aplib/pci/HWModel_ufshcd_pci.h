///
/// hardware model for ufshcd_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ufshcd_pci : public HWModel {
public:
  HWModel_ufshcd_pci()
      : HWModel("ufshcd_pci", 0x144d, 0xc00c, 0, 0, 0x0), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_ufshcd_pci(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 66)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x400100;
      cnt++;
      break;
    }
    case (0x20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x1010101;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint32_t *)dest) = 0x1010101;
      if (cnt == 18)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 32)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 33)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 34)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 35)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 36)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 37)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 38)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 39)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 40)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 41)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 42)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 43)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 44)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 45)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 46)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 47)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 48)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 49)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 50)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 51)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 52)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 53)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 54)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 55)
        *((uint32_t *)dest) = 0x1010101;
      if (cnt == 56)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x8000;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
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
