///
/// hardware model for eni
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_eni : public HWModel {
public:
  HWModel_eni() : HWModel("eni", 0x111a, 0x0000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_eni(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 58)
      return 0;
    switch (addr) {
    case (0xfff8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xa54b872d;
      cnt++;
      break;
    }
    case (0x3e0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55555555;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xaaaaaaaa;
      cnt++;
      break;
    }
    case (0x3c0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55aa5555;
      cnt++;
      break;
    }
    case (0x3a0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x5555aa55;
      cnt++;
      break;
    }
    case (0x380000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xaa555555;
      cnt++;
      break;
    }
    case (0x360000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x5555aa55;
      cnt++;
      break;
    }
    case (0x340000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55aa5555;
      cnt++;
      break;
    }
    case (0x320000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55aa5555;
      cnt++;
      break;
    }
    case (0x300000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xaa555555;
      cnt++;
      break;
    }
    case (0x2e0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x555555aa;
      cnt++;
      break;
    }
    case (0x2c0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x5555aa55;
      cnt++;
      break;
    }
    case (0x2a0000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55aa5555;
      cnt++;
      break;
    }
    case (0x280000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x555555aa;
      cnt++;
      break;
    }
    case (0x260000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x555555aa;
      cnt++;
      break;
    }
    case (0x240000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x555555aa;
      cnt++;
      break;
    }
    case (0x220000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55aa5555;
      cnt++;
      break;
    }
    case (0x200000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x55555555;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xaaaaaaaa;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40000): {
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
    case (0xffc3): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc1): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc0): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc7): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xffc6): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20200): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20118): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20184): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40018): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20040): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20044): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20048): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2004c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20068): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2006c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20070): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x200e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x200e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20074): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20078): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2007c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x200e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x200ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20150): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20154): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20158): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2015c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20160): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20190): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20194): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x20198): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40010): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40004): {
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

private:
  int probe_len;
};
