///
/// hardware model for s2io
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_s2io : public HWModel {
public:
  HWModel_s2io() : HWModel("s2io", 0x17d5, 0x5731), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x4000},
              {PCI_BAR_TYPE_PIO, 8},
              {PCI_BAR_TYPE_MMIO, 4096}});
    //              {PCI_BAR_TYPE_MMIO, 0x100000}});
  }
  virtual ~HWModel_s2io(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 171)
      return 0;
    switch (addr) {
    case (0x910): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x123456789abcdef;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x123456789abcdef;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x123456789abcd10;
      if (cnt == 3)
        *((uint64_t *)dest) = 0xfe23456789abcdef;
      if (cnt == 4)
        *((uint64_t *)dest) = 0x12345678954cdef;
      if (cnt == 5)
        *((uint64_t *)dest) = 0x123456789abcd10;
      if (cnt == 6)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x914): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x1234567;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x1234567;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x1234567;
      if (cnt == 3)
        *((uint64_t *)dest) = 0xfe234567;
      if (cnt == 4)
        *((uint64_t *)dest) = 0x1234567;
      if (cnt == 5)
        *((uint64_t *)dest) = 0x1234567;
      if (cnt == 6)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x908): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x960): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x1dc456789abcdef;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x123456789abcdef;
      cnt++;
      break;
    }
    case (0x964): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x1dc4567;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x1234567;
      cnt++;
      break;
    }
    case (0x9f8): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2128): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 32)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 33)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 34)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 35)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 36)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 37)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 38)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 39)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 40)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 41)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 42)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 43)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 44)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 45)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 46)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 47)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 48)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 49)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 50)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 51)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 52)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 53)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 54)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 55)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 56)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 57)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 58)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 59)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 60)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 61)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 62)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 63)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 64)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2130): {
      static int cnt;
      if (cnt == 0)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 32)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 33)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 34)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 35)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 36)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 37)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 38)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 39)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 40)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 41)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 42)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 43)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 44)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 45)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 46)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 47)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 48)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 49)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 50)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 51)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 52)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 53)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 54)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 55)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 56)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 57)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 58)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 59)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 60)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 61)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 62)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 63)
        *((uint64_t *)dest) = 0x0;
      if (cnt == 64)
        *((uint64_t *)dest) = 0x0;
      cnt++;
      break;
    }
    }
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
