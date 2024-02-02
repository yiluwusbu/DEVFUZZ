///
/// hardware model for ne2k
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ne2k : public HWModel {
public:
  HWModel_ne2k()
      : HWModel("ne2k", 0x10ec, 0x8029, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 0x100}});
  }
  virtual ~HWModel_ne2k(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 183)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xd): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
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
      if (cnt == 13)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 32)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 33)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 34)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 35)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 36)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 37)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 38)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 39)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 40)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 41)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 42)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 43)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 44)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 45)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 46)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 47)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 48)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 49)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 50)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 51)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 52)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 53)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 54)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 55)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 56)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 57)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 58)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 59)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 60)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 61)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 62)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 63)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 64)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 65)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 66)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 67)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 68)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 69)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 70)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 71)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 72)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 73)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 74)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 75)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 76)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 77)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 78)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 79)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 80)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 81)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 82)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 83)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 84)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 85)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 86)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 87)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 88)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 89)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 90)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 91)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 92)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 93)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 94)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 95)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 96)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 97)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 98)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 99)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 100)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 101)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 102)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 103)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 104)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 105)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 106)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 107)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 108)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 109)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 110)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 111)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 112)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 113)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 114)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 115)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 116)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 117)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 118)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 119)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 120)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 121)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 122)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 123)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 124)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 125)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 126)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 127)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 128)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 129)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 130)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 131)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 132)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 133)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 134)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 135)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 136)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 137)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 138)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 139)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 140)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 141)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 142)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 143)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 144)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 145)
        *((uint8_t *)dest) = 0x80;
      cnt++;
      break;
    }
    case (0x10): {
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
      if (cnt == 13)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)dest) = 0;
        break;
      case (2):
        *((uint16_t *)dest) = 0;
        break;
      case (4):
        *((uint32_t *)dest) = 0;
        break;
      default:
        break;
      }
    }
    };
    probe_len++;
    return size;
  }
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};

Stage2HWModel * new_stage2_model_ne2k() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {13 ,       HWInput(13, 1,
                {},
                {0x0, 0xf},
                {})
  },
  {0 ,      HWInput(0, 1,
              {0x4, },
              {0xff, 0x0},
              {})
  },
  {4 ,      HWInput(4, 1,
              {0x1, 0x4, 0x8, 0x10, 0x20, 0x28, 0x40, 0x80, },
              {},
              {})
  },
  {7 ,      HWInput(7, 1,
              {0x2, 0x5, 0x8, 0xa, 0x10, 0x20, 0x40, 0x80, },
              {0x0, 0xff, },
              {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
