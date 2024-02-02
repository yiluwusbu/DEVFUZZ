///
/// hardware model for iphase
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_iphase : public HWModel {
public:
  HWModel_iphase() : HWModel("iphase", 0x107e, 0x0008), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x100000},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_iphase(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 142)
      return 0;
    switch (addr) {
    case (0x1008): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x100c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1028): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
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
        *((uint32_t *)dest) = 0x0;
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
        *((uint32_t *)dest) = 0xff00;
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
        *((uint32_t *)dest) = 0x0;
      if (cnt == 56)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 57)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 58)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 59)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 60)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 61)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 62)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 63)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 64)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 65)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 66)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 67)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 68)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 69)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 70)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 71)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 72)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 73)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 74)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 75)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 76)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 77)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 78)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 79)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 80)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 81)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 82)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 83)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 84)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 85)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 86)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 87)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 88)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 89)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 90)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 91)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20d0): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20c0): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20c4): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20cc): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20d4): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20d8): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x211c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3090): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3094): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3098): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x309c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30a0): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30a4): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30a8): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30ac): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x300c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4200): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4118): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4184): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4040): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4044): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4048): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x404c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4068): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x406c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4070): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4074): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4078): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x407c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4150): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4154): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4158): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x415c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4160): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4190): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4194): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4198): {
      static int cnt;
      if (cnt == 0)
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
  virtual void write(uint64_t data, uint64_t addr, size_t size, int bar) {
    bars[bar]->write(data, addr, size);
    // assuming page aligned though not true
    if ((addr == 0x4c00) || (addr == 0x4e00)) {
      auto p = std::make_pair(data, 32 * 4 * 4);
      dmasgLock.lock();
      // dmasg.clear();
      dmasg.push_back(p);
      dmasgLock.unlock();
    }
  }

private:
  int probe_len;
};
