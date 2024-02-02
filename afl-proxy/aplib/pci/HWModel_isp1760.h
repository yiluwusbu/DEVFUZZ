///
/// hardware model for isp1760
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_isp1760 : public HWModel {
public:
  HWModel_isp1760()
      : HWModel("isp1760", 0x10b5, 0x5406, 0x10b5, 0x9054, 0x68000),
        probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_isp1760(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 440)
      return 0;
    switch (addr) {
    case (0x308): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 2)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 3)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 4)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 5)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 6)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 7)
        *((uint32_t *)dest) = 0xcece05ce;
      if (cnt == 8)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 9)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 10)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 11)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 12)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 13)
        *((uint32_t *)dest) = 0xcece05ce;
      if (cnt == 14)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 15)
        *((uint32_t *)dest) = 0xcece05ce;
      if (cnt == 16)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 17)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 18)
        *((uint32_t *)dest) = 0xfafafa31;
      if (cnt == 19)
        *((uint32_t *)dest) = 0xfafaface;
      if (cnt == 20)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint32_t *)dest) = 0xdeadcafe;
      cnt++;
      break;
    }
    case (0x68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x4000;
      cnt++;
      break;
    }
    case (0x30c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x20;
      cnt++;
      break;
    }
    case (0x374): {
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
    case (0x304): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x334): {
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
      cnt++;
      break;
    }
    case (0x154): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffffff;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xffff00ff;
      cnt++;
      break;
    }
    case (0x144): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xff00ffff;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xffff00ff;
      cnt++;
      break;
    }
    case (0x134): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffff00ff;
      if (cnt == 1)
        *((uint32_t *)dest) = 0xffff00ff;
      cnt++;
      break;
    }
    case (0x20): {
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
        *((uint32_t *)dest) = 0x1010101;
      cnt++;
      break;
    }
    case (0x300): {
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
    case (0x314): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x32c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x328): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x324): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x320): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffffff00;
      cnt++;
      break;
    }
    case (0x31c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffffff00;
      cnt++;
      break;
    }
    case (0x318): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xffff00ff;
      cnt++;
      break;
    }
    case (0x60): {
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
      if (cnt == 92)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 93)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 94)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 95)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 96)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 97)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 98)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 99)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 100)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 101)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 102)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 103)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 104)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 105)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 106)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 107)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 108)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 109)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 110)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 111)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 112)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 113)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 114)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 115)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 116)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 117)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 118)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 119)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 120)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 121)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 122)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 123)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 124)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 125)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 126)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 127)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 128)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 129)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 130)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 131)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 132)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 133)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 134)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 135)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 136)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 137)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 138)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 139)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 140)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 141)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 142)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 143)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 144)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 145)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 146)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 147)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 148)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 149)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 150)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 151)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 152)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 153)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 154)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 155)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 156)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 157)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 158)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 159)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 160)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 161)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 162)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 163)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 164)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 165)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 166)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 167)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 168)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 169)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 170)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 171)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 172)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 173)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 174)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 175)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 176)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 177)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 178)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 179)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 180)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 181)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 182)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 183)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 184)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 185)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 186)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 187)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 188)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 189)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 190)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 191)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 192)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 193)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 194)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 195)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 196)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 197)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 198)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 199)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 200)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 201)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 202)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 203)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 204)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 205)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 206)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 207)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 208)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 209)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 210)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 211)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 212)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 213)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 214)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 215)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 216)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 217)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 218)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 219)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 220)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 221)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 222)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 223)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 224)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 225)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 226)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 227)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 228)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 229)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 230)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 231)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 232)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 233)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 234)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 235)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 236)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 237)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 238)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 239)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 240)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 241)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 242)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 243)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 244)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 245)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 246)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 247)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 248)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 249)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 250)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 251)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 252)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 253)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 254)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 255)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 256)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 257)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 258)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 259)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 260)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 261)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 262)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 263)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 264)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 265)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 266)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 267)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 268)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 269)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 270)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 271)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 272)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 273)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 274)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 275)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 276)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 277)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 278)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 279)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 280)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 281)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 282)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 283)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 284)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 285)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 286)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 287)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 288)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 289)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 290)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 291)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 292)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 293)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 294)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 295)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 296)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 297)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 298)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 299)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 300)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 301)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 302)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 303)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 304)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 305)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 306)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 307)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 308)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 309)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 310)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 311)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 312)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 313)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 314)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 315)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 316)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 317)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 318)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 319)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 320)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 321)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 322)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 323)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 324)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 325)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 326)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 327)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 328)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 329)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 330)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 331)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 332)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 333)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 334)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 335)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 336)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 337)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 338)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 339)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 340)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 341)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 342)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 343)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 344)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 345)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 346)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 347)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 348)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 349)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 350)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 351)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 352)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 353)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 354)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 355)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 356)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 357)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 358)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 359)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 360)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 361)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 362)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 363)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 364)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 365)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 366)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 367)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 368)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 369)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 370)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 371)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 372)
        *((uint32_t *)dest) = 0x1010101;
      cnt++;
      break;
    }
    case (0x158): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x148): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x138): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x10101010;
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
