///
/// hardware model for snd_ad1889
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_snd_ad1889 : public HWModel {
public:
  HWModel_snd_ad1889() : HWModel("snd_ad1889", 0x11d4, 0x1889), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_snd_ad1889(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 120)
      return 0;
    switch (addr) {
    case (0xc): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x180): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x8080;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x17c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint16_t *)dest) = 0x4;
      cnt++;
      break;
    }
    case (0x17e): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint16_t *)dest) = 0x142;
      cnt++;
      break;
    }
    case (0x100): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x11c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x7505;
      if (cnt == 2)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 3)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 4)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 5)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 6)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 7)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 8)
        *((uint16_t *)dest) = 0xafa;
      if (cnt == 9)
        *((uint16_t *)dest) = 0xa06;
      if (cnt == 10)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x13c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 1)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 2)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 3)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 4)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 5)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 6)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 7)
        *((uint16_t *)dest) = 0xff00;
      if (cnt == 8)
        *((uint16_t *)dest) = 0xff00;
      cnt++;
      break;
    }
    case (0x128): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0xc100;
      cnt++;
      break;
    }
    case (0x126): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0xf0f;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x12a): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x130): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0xd5f8;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x1fbf;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x2bee;
      if (cnt == 4)
        *((uint16_t *)dest) = 0xc180;
      if (cnt == 5)
        *((uint16_t *)dest) = 0xa922;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x7dff;
      if (cnt == 7)
        *((uint16_t *)dest) = 0xacbb;
      if (cnt == 8)
        *((uint16_t *)dest) = 0xbb7f;
      cnt++;
      break;
    }
    case (0x102): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x136): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x106): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x10a): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x10c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x10e): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x110): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x112): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x114): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x116): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x118): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x80ff;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x5f5f;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x6f6f;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x7e7e;
      cnt++;
      break;
    }
    case (0x120): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x0;
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
