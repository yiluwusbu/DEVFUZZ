///
/// hardware model for aic7xxx
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_aic7xxx : public HWModel {
public:
  HWModel_aic7xxx()
      : HWModel("aic7xxx", 0x9004, 0x0078, 0, 0, 0x010000, 0), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 0x100},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_aic7xxx(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 505)
      return 0;
    switch (addr) {
    case (0x87): {
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
        *((uint8_t *)dest) = 0x0;
      if (cnt == 146)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 147)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 148)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 149)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 150)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 151)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 152)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 153)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 154)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 155)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 156)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 157)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 158)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 159)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 160)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 161)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 162)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 163)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 164)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 165)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 166)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 167)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 168)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 169)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 170)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 171)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 172)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 173)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 174)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 175)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 176)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 177)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 178)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 179)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 180)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 181)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 182)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 183)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 184)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 185)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 186)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 187)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 188)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 189)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 190)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 191)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 192)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 193)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 194)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 195)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 196)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 197)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 198)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 199)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 200)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 201)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 202)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 203)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 204)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 205)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 206)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 207)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 208)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 209)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 210)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 211)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 212)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 213)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 214)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 215)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 216)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 217)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 218)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 219)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 220)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 221)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 222)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 223)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 224)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 225)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 226)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 227)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 228)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 229)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 230)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 231)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 232)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 233)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 234)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 235)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 236)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 237)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 238)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 239)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 240)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 241)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 242)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 243)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 244)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 245)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 246)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 247)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 248)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 249)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 250)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 251)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 252)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 253)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 254)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 255)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 256)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 257)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 258)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 259)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 260)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 261)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 262)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 263)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 264)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 265)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 266)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 267)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 268)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 269)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 270)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 271)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 272)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 273)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 274)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 275)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 276)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 277)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 278)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 279)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 280)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 281)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 282)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 283)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 284)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 285)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 286)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 287)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 288)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 289)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 290)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 291)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 292)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 293)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 294)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 295)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 296)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 297)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 298)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 299)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 300)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 301)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 302)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 303)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 304)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 305)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 306)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 307)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 308)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 309)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 310)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 311)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 312)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 313)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 314)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 315)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 316)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 317)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 318)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 319)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 320)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 321)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 322)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 323)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 324)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 325)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 326)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 327)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 328)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 329)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 330)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 331)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 332)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 333)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 334)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 335)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 336)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 337)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 338)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 339)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 340)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 341)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 342)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 343)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 344)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 345)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 346)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 347)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 348)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 349)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 350)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 351)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 352)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 353)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 354)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 355)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 356)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 357)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 358)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 359)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 360)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 361)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 362)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 363)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 364)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 365)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 366)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 367)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 368)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 369)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 370)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 371)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 372)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 373)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 374)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 375)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 376)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 377)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 378)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 379)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 380)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 381)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 382)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 383)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 384)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 385)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 386)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 387)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 388)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 389)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 390)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 391)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 392)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 393)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 394)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 395)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 396)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 397)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 398)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 399)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 400)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 401)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 402)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 403)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 404)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 405)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 406)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 407)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 408)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 409)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 410)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 411)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 412)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 413)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 414)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 415)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 416)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 417)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 418)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 419)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 420)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 421)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 422)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 423)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 424)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 425)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 426)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 427)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 428)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 429)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 430)
        *((uint8_t *)dest) = 0x4;
      if (cnt == 431)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 432)
        *((uint8_t *)dest) = 0x40;
      if (cnt == 433)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 434)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 435)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 436)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 437)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 438)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 439)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 440)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 441)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 442)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 443)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 444)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 445)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 446)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 447)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 448)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 449)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 450)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 451)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 452)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 453)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 454)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 455)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 456)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 457)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 458)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 459)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 460)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 461)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 462)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 463)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 464)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 465)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 466)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 467)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 468)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 469)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 470)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 471)
        *((uint8_t *)dest) = 0x4;
      if (cnt == 472)
        *((uint8_t *)dest) = 0x1;
      if (cnt == 473)
        *((uint8_t *)dest) = 0x4;
      if (cnt == 474)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xa0): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x55;
      if (cnt == 1)
        *((uint8_t *)dest) = 0xbe;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0xfe;
      cnt++;
      break;
    }
    case (0xa1): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x55;
      cnt++;
      break;
    }
    case (0xa2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0xa5;
      cnt++;
      break;
    }
    case (0xa3): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x5a;
      cnt++;
      break;
    }
    case (0x2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1f): {
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
    case (0x84): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x91): {
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
    case (0x1e): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x10;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x86): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x5a): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x57): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x1;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x54): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x42): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x90): {
      static int cnt;
      if (cnt == 0)
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
