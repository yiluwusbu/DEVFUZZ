///
/// hardware model for pc300too
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_pc300too : public HWModel {
public:
  HWModel_pc300too()
      : HWModel("pc300too", 0x120e, 0x0301, 0, 0, 0x0280), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x80},
              {PCI_BAR_TYPE_MMIO, 0x8},
              {PCI_BAR_TYPE_MMIO, 0x400},
              {PCI_BAR_TYPE_MMIO, 0x8000}});
  }
  virtual ~HWModel_pc300too(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 813)
      return 0;
    switch (addr) {
    case (0x50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xff00b700;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint32_t *)dest) = 0x12345628;
      cnt++;
      break;
    }
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345678;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234567c;
      cnt++;
      break;
    }
    case (0x8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345670;
      cnt++;
      break;
    }
    case (0xc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345674;
      cnt++;
      break;
    }
    case (0x10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345668;
      cnt++;
      break;
    }
    case (0x14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234566c;
      cnt++;
      break;
    }
    case (0x18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345660;
      cnt++;
      break;
    }
    case (0x1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345664;
      cnt++;
      break;
    }
    case (0x20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345658;
      cnt++;
      break;
    }
    case (0x24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234565c;
      cnt++;
      break;
    }
    case (0x28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345650;
      cnt++;
      break;
    }
    case (0x2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345654;
      cnt++;
      break;
    }
    case (0x30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345648;
      cnt++;
      break;
    }
    case (0x34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234564c;
      cnt++;
      break;
    }
    case (0x38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345640;
      cnt++;
      break;
    }
    case (0x3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345644;
      cnt++;
      break;
    }
    case (0x40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345638;
      cnt++;
      break;
    }
    case (0x44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234563c;
      cnt++;
      break;
    }
    case (0x48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345630;
      cnt++;
      break;
    }
    case (0x4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345634;
      cnt++;
      break;
    }
    case (0x54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234562c;
      cnt++;
      break;
    }
    case (0x58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345620;
      cnt++;
      break;
    }
    case (0x5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345624;
      cnt++;
      break;
    }
    case (0x60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345618;
      cnt++;
      break;
    }
    case (0x64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234561c;
      cnt++;
      break;
    }
    case (0x68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345610;
      cnt++;
      break;
    }
    case (0x6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345614;
      cnt++;
      break;
    }
    case (0x70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345608;
      cnt++;
      break;
    }
    case (0x74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234560c;
      cnt++;
      break;
    }
    case (0x78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345600;
      cnt++;
      break;
    }
    case (0x7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345604;
      cnt++;
      break;
    }
    case (0x80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456f8;
      cnt++;
      break;
    }
    case (0x84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456fc;
      cnt++;
      break;
    }
    case (0x88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456f0;
      cnt++;
      break;
    }
    case (0x8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456f4;
      cnt++;
      break;
    }
    case (0x90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456e8;
      cnt++;
      break;
    }
    case (0x94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456ec;
      cnt++;
      break;
    }
    case (0x98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456e0;
      cnt++;
      break;
    }
    case (0x9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456e4;
      cnt++;
      break;
    }
    case (0xa0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456d8;
      cnt++;
      break;
    }
    case (0xa4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456dc;
      cnt++;
      break;
    }
    case (0xa8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456d0;
      cnt++;
      break;
    }
    case (0xac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456d4;
      cnt++;
      break;
    }
    case (0xb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456c8;
      cnt++;
      break;
    }
    case (0xb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456cc;
      cnt++;
      break;
    }
    case (0xb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456c0;
      cnt++;
      break;
    }
    case (0xbc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456c4;
      cnt++;
      break;
    }
    case (0xc0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456b8;
      cnt++;
      break;
    }
    case (0xc4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456bc;
      cnt++;
      break;
    }
    case (0xc8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456b0;
      cnt++;
      break;
    }
    case (0xcc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456b4;
      cnt++;
      break;
    }
    case (0xd0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456a8;
      cnt++;
      break;
    }
    case (0xd4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456ac;
      cnt++;
      break;
    }
    case (0xd8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456a0;
      cnt++;
      break;
    }
    case (0xdc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123456a4;
      cnt++;
      break;
    }
    case (0xe0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345698;
      cnt++;
      break;
    }
    case (0xe4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234569c;
      cnt++;
      break;
    }
    case (0xe8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345690;
      cnt++;
      break;
    }
    case (0xec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345694;
      cnt++;
      break;
    }
    case (0xf0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345688;
      cnt++;
      break;
    }
    case (0xf4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234568c;
      cnt++;
      break;
    }
    case (0xf8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345680;
      cnt++;
      break;
    }
    case (0xfc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345684;
      cnt++;
      break;
    }
    case (0x100): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345778;
      cnt++;
      break;
    }
    case (0x104): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234577c;
      cnt++;
      break;
    }
    case (0x108): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345770;
      cnt++;
      break;
    }
    case (0x10c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345774;
      cnt++;
      break;
    }
    case (0x110): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345768;
      cnt++;
      break;
    }
    case (0x114): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234576c;
      cnt++;
      break;
    }
    case (0x118): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345760;
      cnt++;
      break;
    }
    case (0x11c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345764;
      cnt++;
      break;
    }
    case (0x120): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345758;
      cnt++;
      break;
    }
    case (0x124): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234575c;
      cnt++;
      break;
    }
    case (0x128): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345750;
      cnt++;
      break;
    }
    case (0x12c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345754;
      cnt++;
      break;
    }
    case (0x130): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345748;
      cnt++;
      break;
    }
    case (0x134): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234574c;
      cnt++;
      break;
    }
    case (0x138): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345740;
      cnt++;
      break;
    }
    case (0x13c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345744;
      cnt++;
      break;
    }
    case (0x140): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345738;
      cnt++;
      break;
    }
    case (0x144): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234573c;
      cnt++;
      break;
    }
    case (0x148): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345730;
      cnt++;
      break;
    }
    case (0x14c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345734;
      cnt++;
      break;
    }
    case (0x150): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345728;
      cnt++;
      break;
    }
    case (0x154): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234572c;
      cnt++;
      break;
    }
    case (0x158): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345720;
      cnt++;
      break;
    }
    case (0x15c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345724;
      cnt++;
      break;
    }
    case (0x160): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345718;
      cnt++;
      break;
    }
    case (0x164): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234571c;
      cnt++;
      break;
    }
    case (0x168): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345710;
      cnt++;
      break;
    }
    case (0x16c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345714;
      cnt++;
      break;
    }
    case (0x170): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345708;
      cnt++;
      break;
    }
    case (0x174): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234570c;
      cnt++;
      break;
    }
    case (0x178): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345700;
      cnt++;
      break;
    }
    case (0x17c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345704;
      cnt++;
      break;
    }
    case (0x180): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457f8;
      cnt++;
      break;
    }
    case (0x184): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457fc;
      cnt++;
      break;
    }
    case (0x188): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457f0;
      cnt++;
      break;
    }
    case (0x18c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457f4;
      cnt++;
      break;
    }
    case (0x190): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457e8;
      cnt++;
      break;
    }
    case (0x194): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457ec;
      cnt++;
      break;
    }
    case (0x198): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457e0;
      cnt++;
      break;
    }
    case (0x19c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457e4;
      cnt++;
      break;
    }
    case (0x1a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457d8;
      cnt++;
      break;
    }
    case (0x1a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457dc;
      cnt++;
      break;
    }
    case (0x1a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457d0;
      cnt++;
      break;
    }
    case (0x1ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457d4;
      cnt++;
      break;
    }
    case (0x1b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457c8;
      cnt++;
      break;
    }
    case (0x1b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457cc;
      cnt++;
      break;
    }
    case (0x1b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457c0;
      cnt++;
      break;
    }
    case (0x1bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457c4;
      cnt++;
      break;
    }
    case (0x1c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457b8;
      cnt++;
      break;
    }
    case (0x1c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457bc;
      cnt++;
      break;
    }
    case (0x1c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457b0;
      cnt++;
      break;
    }
    case (0x1cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457b4;
      cnt++;
      break;
    }
    case (0x1d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457a8;
      cnt++;
      break;
    }
    case (0x1d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457ac;
      cnt++;
      break;
    }
    case (0x1d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457a0;
      cnt++;
      break;
    }
    case (0x1dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123457a4;
      cnt++;
      break;
    }
    case (0x1e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345798;
      cnt++;
      break;
    }
    case (0x1e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234579c;
      cnt++;
      break;
    }
    case (0x1e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345790;
      cnt++;
      break;
    }
    case (0x1ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345794;
      cnt++;
      break;
    }
    case (0x1f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345788;
      cnt++;
      break;
    }
    case (0x1f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234578c;
      cnt++;
      break;
    }
    case (0x1f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345780;
      cnt++;
      break;
    }
    case (0x1fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345784;
      cnt++;
      break;
    }
    case (0x200): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345478;
      cnt++;
      break;
    }
    case (0x204): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234547c;
      cnt++;
      break;
    }
    case (0x208): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345470;
      cnt++;
      break;
    }
    case (0x20c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345474;
      cnt++;
      break;
    }
    case (0x210): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345468;
      cnt++;
      break;
    }
    case (0x214): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234546c;
      cnt++;
      break;
    }
    case (0x218): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345460;
      cnt++;
      break;
    }
    case (0x21c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345464;
      cnt++;
      break;
    }
    case (0x220): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345458;
      cnt++;
      break;
    }
    case (0x224): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234545c;
      cnt++;
      break;
    }
    case (0x228): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345450;
      cnt++;
      break;
    }
    case (0x22c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345454;
      cnt++;
      break;
    }
    case (0x230): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345448;
      cnt++;
      break;
    }
    case (0x234): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234544c;
      cnt++;
      break;
    }
    case (0x238): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345440;
      cnt++;
      break;
    }
    case (0x23c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345444;
      cnt++;
      break;
    }
    case (0x240): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345438;
      cnt++;
      break;
    }
    case (0x244): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234543c;
      cnt++;
      break;
    }
    case (0x248): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345430;
      cnt++;
      break;
    }
    case (0x24c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345434;
      cnt++;
      break;
    }
    case (0x250): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345428;
      cnt++;
      break;
    }
    case (0x254): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234542c;
      cnt++;
      break;
    }
    case (0x258): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345420;
      cnt++;
      break;
    }
    case (0x25c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345424;
      cnt++;
      break;
    }
    case (0x260): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345418;
      cnt++;
      break;
    }
    case (0x264): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234541c;
      cnt++;
      break;
    }
    case (0x268): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345410;
      cnt++;
      break;
    }
    case (0x26c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345414;
      cnt++;
      break;
    }
    case (0x270): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345408;
      cnt++;
      break;
    }
    case (0x274): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234540c;
      cnt++;
      break;
    }
    case (0x278): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345400;
      cnt++;
      break;
    }
    case (0x27c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345404;
      cnt++;
      break;
    }
    case (0x280): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454f8;
      cnt++;
      break;
    }
    case (0x284): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454fc;
      cnt++;
      break;
    }
    case (0x288): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454f0;
      cnt++;
      break;
    }
    case (0x28c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454f4;
      cnt++;
      break;
    }
    case (0x290): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454e8;
      cnt++;
      break;
    }
    case (0x294): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454ec;
      cnt++;
      break;
    }
    case (0x298): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454e0;
      cnt++;
      break;
    }
    case (0x29c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454e4;
      cnt++;
      break;
    }
    case (0x2a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454d8;
      cnt++;
      break;
    }
    case (0x2a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454dc;
      cnt++;
      break;
    }
    case (0x2a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454d0;
      cnt++;
      break;
    }
    case (0x2ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454d4;
      cnt++;
      break;
    }
    case (0x2b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454c8;
      cnt++;
      break;
    }
    case (0x2b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454cc;
      cnt++;
      break;
    }
    case (0x2b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454c0;
      cnt++;
      break;
    }
    case (0x2bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454c4;
      cnt++;
      break;
    }
    case (0x2c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454b8;
      cnt++;
      break;
    }
    case (0x2c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454bc;
      cnt++;
      break;
    }
    case (0x2c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454b0;
      cnt++;
      break;
    }
    case (0x2cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454b4;
      cnt++;
      break;
    }
    case (0x2d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454a8;
      cnt++;
      break;
    }
    case (0x2d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454ac;
      cnt++;
      break;
    }
    case (0x2d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454a0;
      cnt++;
      break;
    }
    case (0x2dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123454a4;
      cnt++;
      break;
    }
    case (0x2e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345498;
      cnt++;
      break;
    }
    case (0x2e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234549c;
      cnt++;
      break;
    }
    case (0x2e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345490;
      cnt++;
      break;
    }
    case (0x2ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345494;
      cnt++;
      break;
    }
    case (0x2f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345488;
      cnt++;
      break;
    }
    case (0x2f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234548c;
      cnt++;
      break;
    }
    case (0x2f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345480;
      cnt++;
      break;
    }
    case (0x2fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345484;
      cnt++;
      break;
    }
    case (0x300): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345578;
      cnt++;
      break;
    }
    case (0x304): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234557c;
      cnt++;
      break;
    }
    case (0x308): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345570;
      cnt++;
      break;
    }
    case (0x30c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345574;
      cnt++;
      break;
    }
    case (0x310): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345568;
      cnt++;
      break;
    }
    case (0x314): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234556c;
      cnt++;
      break;
    }
    case (0x318): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345560;
      cnt++;
      break;
    }
    case (0x31c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345564;
      cnt++;
      break;
    }
    case (0x320): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345558;
      cnt++;
      break;
    }
    case (0x324): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234555c;
      cnt++;
      break;
    }
    case (0x328): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345550;
      cnt++;
      break;
    }
    case (0x32c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345554;
      cnt++;
      break;
    }
    case (0x330): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345548;
      cnt++;
      break;
    }
    case (0x334): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234554c;
      cnt++;
      break;
    }
    case (0x338): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345540;
      cnt++;
      break;
    }
    case (0x33c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345544;
      cnt++;
      break;
    }
    case (0x340): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345538;
      cnt++;
      break;
    }
    case (0x344): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234553c;
      cnt++;
      break;
    }
    case (0x348): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345530;
      cnt++;
      break;
    }
    case (0x34c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345534;
      cnt++;
      break;
    }
    case (0x350): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345528;
      cnt++;
      break;
    }
    case (0x354): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234552c;
      cnt++;
      break;
    }
    case (0x358): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345520;
      cnt++;
      break;
    }
    case (0x35c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345524;
      cnt++;
      break;
    }
    case (0x360): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345518;
      cnt++;
      break;
    }
    case (0x364): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234551c;
      cnt++;
      break;
    }
    case (0x368): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345510;
      cnt++;
      break;
    }
    case (0x36c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345514;
      cnt++;
      break;
    }
    case (0x370): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345508;
      cnt++;
      break;
    }
    case (0x374): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234550c;
      cnt++;
      break;
    }
    case (0x378): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345500;
      cnt++;
      break;
    }
    case (0x37c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345504;
      cnt++;
      break;
    }
    case (0x380): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455f8;
      cnt++;
      break;
    }
    case (0x384): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455fc;
      cnt++;
      break;
    }
    case (0x388): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455f0;
      cnt++;
      break;
    }
    case (0x38c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455f4;
      cnt++;
      break;
    }
    case (0x390): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455e8;
      cnt++;
      break;
    }
    case (0x394): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455ec;
      cnt++;
      break;
    }
    case (0x398): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455e0;
      cnt++;
      break;
    }
    case (0x39c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455e4;
      cnt++;
      break;
    }
    case (0x3a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455d8;
      cnt++;
      break;
    }
    case (0x3a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455dc;
      cnt++;
      break;
    }
    case (0x3a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455d0;
      cnt++;
      break;
    }
    case (0x3ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455d4;
      cnt++;
      break;
    }
    case (0x3b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455c8;
      cnt++;
      break;
    }
    case (0x3b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455cc;
      cnt++;
      break;
    }
    case (0x3b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455c0;
      cnt++;
      break;
    }
    case (0x3bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455c4;
      cnt++;
      break;
    }
    case (0x3c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455b8;
      cnt++;
      break;
    }
    case (0x3c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455bc;
      cnt++;
      break;
    }
    case (0x3c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455b0;
      cnt++;
      break;
    }
    case (0x3cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455b4;
      cnt++;
      break;
    }
    case (0x3d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455a8;
      cnt++;
      break;
    }
    case (0x3d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455ac;
      cnt++;
      break;
    }
    case (0x3d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455a0;
      cnt++;
      break;
    }
    case (0x3dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123455a4;
      cnt++;
      break;
    }
    case (0x3e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345598;
      cnt++;
      break;
    }
    case (0x3e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234559c;
      cnt++;
      break;
    }
    case (0x3e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345590;
      cnt++;
      break;
    }
    case (0x3ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345594;
      cnt++;
      break;
    }
    case (0x3f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345588;
      cnt++;
      break;
    }
    case (0x3f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234558c;
      cnt++;
      break;
    }
    case (0x3f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345580;
      cnt++;
      break;
    }
    case (0x3fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345584;
      cnt++;
      break;
    }
    case (0x400): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345278;
      cnt++;
      break;
    }
    case (0x404): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234527c;
      cnt++;
      break;
    }
    case (0x408): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345270;
      cnt++;
      break;
    }
    case (0x40c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345274;
      cnt++;
      break;
    }
    case (0x410): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345268;
      cnt++;
      break;
    }
    case (0x414): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234526c;
      cnt++;
      break;
    }
    case (0x418): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345260;
      cnt++;
      break;
    }
    case (0x41c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345264;
      cnt++;
      break;
    }
    case (0x420): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345258;
      cnt++;
      break;
    }
    case (0x424): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234525c;
      cnt++;
      break;
    }
    case (0x428): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345250;
      cnt++;
      break;
    }
    case (0x42c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345254;
      cnt++;
      break;
    }
    case (0x430): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345248;
      cnt++;
      break;
    }
    case (0x434): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234524c;
      cnt++;
      break;
    }
    case (0x438): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345240;
      cnt++;
      break;
    }
    case (0x43c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345244;
      cnt++;
      break;
    }
    case (0x440): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345238;
      cnt++;
      break;
    }
    case (0x444): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234523c;
      cnt++;
      break;
    }
    case (0x448): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345230;
      cnt++;
      break;
    }
    case (0x44c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345234;
      cnt++;
      break;
    }
    case (0x450): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345228;
      cnt++;
      break;
    }
    case (0x454): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234522c;
      cnt++;
      break;
    }
    case (0x458): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345220;
      cnt++;
      break;
    }
    case (0x45c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345224;
      cnt++;
      break;
    }
    case (0x460): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345218;
      cnt++;
      break;
    }
    case (0x464): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234521c;
      cnt++;
      break;
    }
    case (0x468): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345210;
      cnt++;
      break;
    }
    case (0x46c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345214;
      cnt++;
      break;
    }
    case (0x470): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345208;
      cnt++;
      break;
    }
    case (0x474): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234520c;
      cnt++;
      break;
    }
    case (0x478): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345200;
      cnt++;
      break;
    }
    case (0x47c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345204;
      cnt++;
      break;
    }
    case (0x480): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452f8;
      cnt++;
      break;
    }
    case (0x484): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452fc;
      cnt++;
      break;
    }
    case (0x488): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452f0;
      cnt++;
      break;
    }
    case (0x48c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452f4;
      cnt++;
      break;
    }
    case (0x490): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452e8;
      cnt++;
      break;
    }
    case (0x494): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452ec;
      cnt++;
      break;
    }
    case (0x498): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452e0;
      cnt++;
      break;
    }
    case (0x49c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452e4;
      cnt++;
      break;
    }
    case (0x4a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452d8;
      cnt++;
      break;
    }
    case (0x4a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452dc;
      cnt++;
      break;
    }
    case (0x4a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452d0;
      cnt++;
      break;
    }
    case (0x4ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452d4;
      cnt++;
      break;
    }
    case (0x4b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452c8;
      cnt++;
      break;
    }
    case (0x4b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452cc;
      cnt++;
      break;
    }
    case (0x4b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452c0;
      cnt++;
      break;
    }
    case (0x4bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452c4;
      cnt++;
      break;
    }
    case (0x4c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452b8;
      cnt++;
      break;
    }
    case (0x4c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452bc;
      cnt++;
      break;
    }
    case (0x4c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452b0;
      cnt++;
      break;
    }
    case (0x4cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452b4;
      cnt++;
      break;
    }
    case (0x4d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452a8;
      cnt++;
      break;
    }
    case (0x4d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452ac;
      cnt++;
      break;
    }
    case (0x4d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452a0;
      cnt++;
      break;
    }
    case (0x4dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123452a4;
      cnt++;
      break;
    }
    case (0x4e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345298;
      cnt++;
      break;
    }
    case (0x4e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234529c;
      cnt++;
      break;
    }
    case (0x4e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345290;
      cnt++;
      break;
    }
    case (0x4ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345294;
      cnt++;
      break;
    }
    case (0x4f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345288;
      cnt++;
      break;
    }
    case (0x4f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234528c;
      cnt++;
      break;
    }
    case (0x4f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345280;
      cnt++;
      break;
    }
    case (0x4fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345284;
      cnt++;
      break;
    }
    case (0x500): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345378;
      cnt++;
      break;
    }
    case (0x504): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234537c;
      cnt++;
      break;
    }
    case (0x508): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345370;
      cnt++;
      break;
    }
    case (0x50c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345374;
      cnt++;
      break;
    }
    case (0x510): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345368;
      cnt++;
      break;
    }
    case (0x514): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234536c;
      cnt++;
      break;
    }
    case (0x518): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345360;
      cnt++;
      break;
    }
    case (0x51c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345364;
      cnt++;
      break;
    }
    case (0x520): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345358;
      cnt++;
      break;
    }
    case (0x524): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234535c;
      cnt++;
      break;
    }
    case (0x528): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345350;
      cnt++;
      break;
    }
    case (0x52c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345354;
      cnt++;
      break;
    }
    case (0x530): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345348;
      cnt++;
      break;
    }
    case (0x534): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234534c;
      cnt++;
      break;
    }
    case (0x538): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345340;
      cnt++;
      break;
    }
    case (0x53c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345344;
      cnt++;
      break;
    }
    case (0x540): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345338;
      cnt++;
      break;
    }
    case (0x544): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234533c;
      cnt++;
      break;
    }
    case (0x548): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345330;
      cnt++;
      break;
    }
    case (0x54c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345334;
      cnt++;
      break;
    }
    case (0x550): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345328;
      cnt++;
      break;
    }
    case (0x554): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234532c;
      cnt++;
      break;
    }
    case (0x558): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345320;
      cnt++;
      break;
    }
    case (0x55c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345324;
      cnt++;
      break;
    }
    case (0x560): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345318;
      cnt++;
      break;
    }
    case (0x564): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234531c;
      cnt++;
      break;
    }
    case (0x568): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345310;
      cnt++;
      break;
    }
    case (0x56c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345314;
      cnt++;
      break;
    }
    case (0x570): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345308;
      cnt++;
      break;
    }
    case (0x574): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234530c;
      cnt++;
      break;
    }
    case (0x578): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345300;
      cnt++;
      break;
    }
    case (0x57c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345304;
      cnt++;
      break;
    }
    case (0x580): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453f8;
      cnt++;
      break;
    }
    case (0x584): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453fc;
      cnt++;
      break;
    }
    case (0x588): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453f0;
      cnt++;
      break;
    }
    case (0x58c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453f4;
      cnt++;
      break;
    }
    case (0x590): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453e8;
      cnt++;
      break;
    }
    case (0x594): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453ec;
      cnt++;
      break;
    }
    case (0x598): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453e0;
      cnt++;
      break;
    }
    case (0x59c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453e4;
      cnt++;
      break;
    }
    case (0x5a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453d8;
      cnt++;
      break;
    }
    case (0x5a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453dc;
      cnt++;
      break;
    }
    case (0x5a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453d0;
      cnt++;
      break;
    }
    case (0x5ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453d4;
      cnt++;
      break;
    }
    case (0x5b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453c8;
      cnt++;
      break;
    }
    case (0x5b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453cc;
      cnt++;
      break;
    }
    case (0x5b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453c0;
      cnt++;
      break;
    }
    case (0x5bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453c4;
      cnt++;
      break;
    }
    case (0x5c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453b8;
      cnt++;
      break;
    }
    case (0x5c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453bc;
      cnt++;
      break;
    }
    case (0x5c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453b0;
      cnt++;
      break;
    }
    case (0x5cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453b4;
      cnt++;
      break;
    }
    case (0x5d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453a8;
      cnt++;
      break;
    }
    case (0x5d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453ac;
      cnt++;
      break;
    }
    case (0x5d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453a0;
      cnt++;
      break;
    }
    case (0x5dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123453a4;
      cnt++;
      break;
    }
    case (0x5e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345398;
      cnt++;
      break;
    }
    case (0x5e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234539c;
      cnt++;
      break;
    }
    case (0x5e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345390;
      cnt++;
      break;
    }
    case (0x5ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345394;
      cnt++;
      break;
    }
    case (0x5f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345388;
      cnt++;
      break;
    }
    case (0x5f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234538c;
      cnt++;
      break;
    }
    case (0x5f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345380;
      cnt++;
      break;
    }
    case (0x5fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345384;
      cnt++;
      break;
    }
    case (0x600): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345078;
      cnt++;
      break;
    }
    case (0x604): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234507c;
      cnt++;
      break;
    }
    case (0x608): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345070;
      cnt++;
      break;
    }
    case (0x60c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345074;
      cnt++;
      break;
    }
    case (0x610): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345068;
      cnt++;
      break;
    }
    case (0x614): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234506c;
      cnt++;
      break;
    }
    case (0x618): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345060;
      cnt++;
      break;
    }
    case (0x61c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345064;
      cnt++;
      break;
    }
    case (0x620): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345058;
      cnt++;
      break;
    }
    case (0x624): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234505c;
      cnt++;
      break;
    }
    case (0x628): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345050;
      cnt++;
      break;
    }
    case (0x62c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345054;
      cnt++;
      break;
    }
    case (0x630): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345048;
      cnt++;
      break;
    }
    case (0x634): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234504c;
      cnt++;
      break;
    }
    case (0x638): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345040;
      cnt++;
      break;
    }
    case (0x63c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345044;
      cnt++;
      break;
    }
    case (0x640): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345038;
      cnt++;
      break;
    }
    case (0x644): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234503c;
      cnt++;
      break;
    }
    case (0x648): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345030;
      cnt++;
      break;
    }
    case (0x64c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345034;
      cnt++;
      break;
    }
    case (0x650): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345028;
      cnt++;
      break;
    }
    case (0x654): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234502c;
      cnt++;
      break;
    }
    case (0x658): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345020;
      cnt++;
      break;
    }
    case (0x65c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345024;
      cnt++;
      break;
    }
    case (0x660): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345018;
      cnt++;
      break;
    }
    case (0x664): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234501c;
      cnt++;
      break;
    }
    case (0x668): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345010;
      cnt++;
      break;
    }
    case (0x66c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345014;
      cnt++;
      break;
    }
    case (0x670): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345008;
      cnt++;
      break;
    }
    case (0x674): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234500c;
      cnt++;
      break;
    }
    case (0x678): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345000;
      cnt++;
      break;
    }
    case (0x67c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345004;
      cnt++;
      break;
    }
    case (0x680): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450f8;
      cnt++;
      break;
    }
    case (0x684): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450fc;
      cnt++;
      break;
    }
    case (0x688): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450f0;
      cnt++;
      break;
    }
    case (0x68c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450f4;
      cnt++;
      break;
    }
    case (0x690): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450e8;
      cnt++;
      break;
    }
    case (0x694): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450ec;
      cnt++;
      break;
    }
    case (0x698): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450e0;
      cnt++;
      break;
    }
    case (0x69c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450e4;
      cnt++;
      break;
    }
    case (0x6a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450d8;
      cnt++;
      break;
    }
    case (0x6a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450dc;
      cnt++;
      break;
    }
    case (0x6a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450d0;
      cnt++;
      break;
    }
    case (0x6ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450d4;
      cnt++;
      break;
    }
    case (0x6b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450c8;
      cnt++;
      break;
    }
    case (0x6b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450cc;
      cnt++;
      break;
    }
    case (0x6b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450c0;
      cnt++;
      break;
    }
    case (0x6bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450c4;
      cnt++;
      break;
    }
    case (0x6c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450b8;
      cnt++;
      break;
    }
    case (0x6c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450bc;
      cnt++;
      break;
    }
    case (0x6c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450b0;
      cnt++;
      break;
    }
    case (0x6cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450b4;
      cnt++;
      break;
    }
    case (0x6d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450a8;
      cnt++;
      break;
    }
    case (0x6d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450ac;
      cnt++;
      break;
    }
    case (0x6d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450a0;
      cnt++;
      break;
    }
    case (0x6dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123450a4;
      cnt++;
      break;
    }
    case (0x6e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345098;
      cnt++;
      break;
    }
    case (0x6e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234509c;
      cnt++;
      break;
    }
    case (0x6e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345090;
      cnt++;
      break;
    }
    case (0x6ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345094;
      cnt++;
      break;
    }
    case (0x6f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345088;
      cnt++;
      break;
    }
    case (0x6f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234508c;
      cnt++;
      break;
    }
    case (0x6f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345080;
      cnt++;
      break;
    }
    case (0x6fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345084;
      cnt++;
      break;
    }
    case (0x700): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345178;
      cnt++;
      break;
    }
    case (0x704): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234517c;
      cnt++;
      break;
    }
    case (0x708): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345170;
      cnt++;
      break;
    }
    case (0x70c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345174;
      cnt++;
      break;
    }
    case (0x710): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345168;
      cnt++;
      break;
    }
    case (0x714): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234516c;
      cnt++;
      break;
    }
    case (0x718): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345160;
      cnt++;
      break;
    }
    case (0x71c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345164;
      cnt++;
      break;
    }
    case (0x720): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345158;
      cnt++;
      break;
    }
    case (0x724): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234515c;
      cnt++;
      break;
    }
    case (0x728): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345150;
      cnt++;
      break;
    }
    case (0x72c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345154;
      cnt++;
      break;
    }
    case (0x730): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345148;
      cnt++;
      break;
    }
    case (0x734): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234514c;
      cnt++;
      break;
    }
    case (0x738): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345140;
      cnt++;
      break;
    }
    case (0x73c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345144;
      cnt++;
      break;
    }
    case (0x740): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345138;
      cnt++;
      break;
    }
    case (0x744): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234513c;
      cnt++;
      break;
    }
    case (0x748): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345130;
      cnt++;
      break;
    }
    case (0x74c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345134;
      cnt++;
      break;
    }
    case (0x750): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345128;
      cnt++;
      break;
    }
    case (0x754): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234512c;
      cnt++;
      break;
    }
    case (0x758): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345120;
      cnt++;
      break;
    }
    case (0x75c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345124;
      cnt++;
      break;
    }
    case (0x760): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345118;
      cnt++;
      break;
    }
    case (0x764): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234511c;
      cnt++;
      break;
    }
    case (0x768): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345110;
      cnt++;
      break;
    }
    case (0x76c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345114;
      cnt++;
      break;
    }
    case (0x770): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345108;
      cnt++;
      break;
    }
    case (0x774): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234510c;
      cnt++;
      break;
    }
    case (0x778): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345100;
      cnt++;
      break;
    }
    case (0x77c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345104;
      cnt++;
      break;
    }
    case (0x780): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451f8;
      cnt++;
      break;
    }
    case (0x784): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451fc;
      cnt++;
      break;
    }
    case (0x788): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451f0;
      cnt++;
      break;
    }
    case (0x78c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451f4;
      cnt++;
      break;
    }
    case (0x790): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451e8;
      cnt++;
      break;
    }
    case (0x794): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451ec;
      cnt++;
      break;
    }
    case (0x798): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451e0;
      cnt++;
      break;
    }
    case (0x79c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451e4;
      cnt++;
      break;
    }
    case (0x7a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451d8;
      cnt++;
      break;
    }
    case (0x7a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451dc;
      cnt++;
      break;
    }
    case (0x7a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451d0;
      cnt++;
      break;
    }
    case (0x7ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451d4;
      cnt++;
      break;
    }
    case (0x7b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451c8;
      cnt++;
      break;
    }
    case (0x7b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451cc;
      cnt++;
      break;
    }
    case (0x7b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451c0;
      cnt++;
      break;
    }
    case (0x7bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451c4;
      cnt++;
      break;
    }
    case (0x7c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451b8;
      cnt++;
      break;
    }
    case (0x7c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451bc;
      cnt++;
      break;
    }
    case (0x7c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451b0;
      cnt++;
      break;
    }
    case (0x7cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451b4;
      cnt++;
      break;
    }
    case (0x7d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451a8;
      cnt++;
      break;
    }
    case (0x7d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451ac;
      cnt++;
      break;
    }
    case (0x7d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451a0;
      cnt++;
      break;
    }
    case (0x7dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123451a4;
      cnt++;
      break;
    }
    case (0x7e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345198;
      cnt++;
      break;
    }
    case (0x7e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234519c;
      cnt++;
      break;
    }
    case (0x7e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345190;
      cnt++;
      break;
    }
    case (0x7ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345194;
      cnt++;
      break;
    }
    case (0x7f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345188;
      cnt++;
      break;
    }
    case (0x7f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234518c;
      cnt++;
      break;
    }
    case (0x7f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345180;
      cnt++;
      break;
    }
    case (0x7fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345184;
      cnt++;
      break;
    }
    case (0x800): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e78;
      cnt++;
      break;
    }
    case (0x804): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e7c;
      cnt++;
      break;
    }
    case (0x808): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e70;
      cnt++;
      break;
    }
    case (0x80c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e74;
      cnt++;
      break;
    }
    case (0x810): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e68;
      cnt++;
      break;
    }
    case (0x814): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e6c;
      cnt++;
      break;
    }
    case (0x818): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e60;
      cnt++;
      break;
    }
    case (0x81c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e64;
      cnt++;
      break;
    }
    case (0x820): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e58;
      cnt++;
      break;
    }
    case (0x824): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e5c;
      cnt++;
      break;
    }
    case (0x828): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e50;
      cnt++;
      break;
    }
    case (0x82c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e54;
      cnt++;
      break;
    }
    case (0x830): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e48;
      cnt++;
      break;
    }
    case (0x834): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e4c;
      cnt++;
      break;
    }
    case (0x838): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e40;
      cnt++;
      break;
    }
    case (0x83c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e44;
      cnt++;
      break;
    }
    case (0x840): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e38;
      cnt++;
      break;
    }
    case (0x844): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e3c;
      cnt++;
      break;
    }
    case (0x848): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e30;
      cnt++;
      break;
    }
    case (0x84c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e34;
      cnt++;
      break;
    }
    case (0x850): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e28;
      cnt++;
      break;
    }
    case (0x854): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e2c;
      cnt++;
      break;
    }
    case (0x858): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e20;
      cnt++;
      break;
    }
    case (0x85c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e24;
      cnt++;
      break;
    }
    case (0x860): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e18;
      cnt++;
      break;
    }
    case (0x864): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e1c;
      cnt++;
      break;
    }
    case (0x868): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e10;
      cnt++;
      break;
    }
    case (0x86c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e14;
      cnt++;
      break;
    }
    case (0x870): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e08;
      cnt++;
      break;
    }
    case (0x874): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e0c;
      cnt++;
      break;
    }
    case (0x878): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e00;
      cnt++;
      break;
    }
    case (0x87c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e04;
      cnt++;
      break;
    }
    case (0x880): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ef8;
      cnt++;
      break;
    }
    case (0x884): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345efc;
      cnt++;
      break;
    }
    case (0x888): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ef0;
      cnt++;
      break;
    }
    case (0x88c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ef4;
      cnt++;
      break;
    }
    case (0x890): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ee8;
      cnt++;
      break;
    }
    case (0x894): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345eec;
      cnt++;
      break;
    }
    case (0x898): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ee0;
      cnt++;
      break;
    }
    case (0x89c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ee4;
      cnt++;
      break;
    }
    case (0x8a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ed8;
      cnt++;
      break;
    }
    case (0x8a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345edc;
      cnt++;
      break;
    }
    case (0x8a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ed0;
      cnt++;
      break;
    }
    case (0x8ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ed4;
      cnt++;
      break;
    }
    case (0x8b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ec8;
      cnt++;
      break;
    }
    case (0x8b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ecc;
      cnt++;
      break;
    }
    case (0x8b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ec0;
      cnt++;
      break;
    }
    case (0x8bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ec4;
      cnt++;
      break;
    }
    case (0x8c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345eb8;
      cnt++;
      break;
    }
    case (0x8c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ebc;
      cnt++;
      break;
    }
    case (0x8c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345eb0;
      cnt++;
      break;
    }
    case (0x8cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345eb4;
      cnt++;
      break;
    }
    case (0x8d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ea8;
      cnt++;
      break;
    }
    case (0x8d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345eac;
      cnt++;
      break;
    }
    case (0x8d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ea0;
      cnt++;
      break;
    }
    case (0x8dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ea4;
      cnt++;
      break;
    }
    case (0x8e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e98;
      cnt++;
      break;
    }
    case (0x8e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e9c;
      cnt++;
      break;
    }
    case (0x8e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e90;
      cnt++;
      break;
    }
    case (0x8ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e94;
      cnt++;
      break;
    }
    case (0x8f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e88;
      cnt++;
      break;
    }
    case (0x8f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e8c;
      cnt++;
      break;
    }
    case (0x8f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e80;
      cnt++;
      break;
    }
    case (0x8fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345e84;
      cnt++;
      break;
    }
    case (0x900): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f78;
      cnt++;
      break;
    }
    case (0x904): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f7c;
      cnt++;
      break;
    }
    case (0x908): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f70;
      cnt++;
      break;
    }
    case (0x90c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f74;
      cnt++;
      break;
    }
    case (0x910): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f68;
      cnt++;
      break;
    }
    case (0x914): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f6c;
      cnt++;
      break;
    }
    case (0x918): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f60;
      cnt++;
      break;
    }
    case (0x91c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f64;
      cnt++;
      break;
    }
    case (0x920): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f58;
      cnt++;
      break;
    }
    case (0x924): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f5c;
      cnt++;
      break;
    }
    case (0x928): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f50;
      cnt++;
      break;
    }
    case (0x92c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f54;
      cnt++;
      break;
    }
    case (0x930): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f48;
      cnt++;
      break;
    }
    case (0x934): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f4c;
      cnt++;
      break;
    }
    case (0x938): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f40;
      cnt++;
      break;
    }
    case (0x93c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f44;
      cnt++;
      break;
    }
    case (0x940): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f38;
      cnt++;
      break;
    }
    case (0x944): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f3c;
      cnt++;
      break;
    }
    case (0x948): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f30;
      cnt++;
      break;
    }
    case (0x94c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f34;
      cnt++;
      break;
    }
    case (0x950): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f28;
      cnt++;
      break;
    }
    case (0x954): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f2c;
      cnt++;
      break;
    }
    case (0x958): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f20;
      cnt++;
      break;
    }
    case (0x95c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f24;
      cnt++;
      break;
    }
    case (0x960): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f18;
      cnt++;
      break;
    }
    case (0x964): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f1c;
      cnt++;
      break;
    }
    case (0x968): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f10;
      cnt++;
      break;
    }
    case (0x96c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f14;
      cnt++;
      break;
    }
    case (0x970): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f08;
      cnt++;
      break;
    }
    case (0x974): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f0c;
      cnt++;
      break;
    }
    case (0x978): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f00;
      cnt++;
      break;
    }
    case (0x97c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f04;
      cnt++;
      break;
    }
    case (0x980): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ff8;
      cnt++;
      break;
    }
    case (0x984): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ffc;
      cnt++;
      break;
    }
    case (0x988): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ff0;
      cnt++;
      break;
    }
    case (0x98c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ff4;
      cnt++;
      break;
    }
    case (0x990): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fe8;
      cnt++;
      break;
    }
    case (0x994): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fec;
      cnt++;
      break;
    }
    case (0x998): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fe0;
      cnt++;
      break;
    }
    case (0x99c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fe4;
      cnt++;
      break;
    }
    case (0x9a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fd8;
      cnt++;
      break;
    }
    case (0x9a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fdc;
      cnt++;
      break;
    }
    case (0x9a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fd0;
      cnt++;
      break;
    }
    case (0x9ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fd4;
      cnt++;
      break;
    }
    case (0x9b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fc8;
      cnt++;
      break;
    }
    case (0x9b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fcc;
      cnt++;
      break;
    }
    case (0x9b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fc0;
      cnt++;
      break;
    }
    case (0x9bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fc4;
      cnt++;
      break;
    }
    case (0x9c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fb8;
      cnt++;
      break;
    }
    case (0x9c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fbc;
      cnt++;
      break;
    }
    case (0x9c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fb0;
      cnt++;
      break;
    }
    case (0x9cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fb4;
      cnt++;
      break;
    }
    case (0x9d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fa8;
      cnt++;
      break;
    }
    case (0x9d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fac;
      cnt++;
      break;
    }
    case (0x9d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fa0;
      cnt++;
      break;
    }
    case (0x9dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345fa4;
      cnt++;
      break;
    }
    case (0x9e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f98;
      cnt++;
      break;
    }
    case (0x9e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f9c;
      cnt++;
      break;
    }
    case (0x9e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f90;
      cnt++;
      break;
    }
    case (0x9ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f94;
      cnt++;
      break;
    }
    case (0x9f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f88;
      cnt++;
      break;
    }
    case (0x9f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f8c;
      cnt++;
      break;
    }
    case (0x9f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f80;
      cnt++;
      break;
    }
    case (0x9fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345f84;
      cnt++;
      break;
    }
    case (0xa00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c78;
      cnt++;
      break;
    }
    case (0xa04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c7c;
      cnt++;
      break;
    }
    case (0xa08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c70;
      cnt++;
      break;
    }
    case (0xa0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c74;
      cnt++;
      break;
    }
    case (0xa10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c68;
      cnt++;
      break;
    }
    case (0xa14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c6c;
      cnt++;
      break;
    }
    case (0xa18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c60;
      cnt++;
      break;
    }
    case (0xa1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c64;
      cnt++;
      break;
    }
    case (0xa20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c58;
      cnt++;
      break;
    }
    case (0xa24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c5c;
      cnt++;
      break;
    }
    case (0xa28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c50;
      cnt++;
      break;
    }
    case (0xa2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c54;
      cnt++;
      break;
    }
    case (0xa30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c48;
      cnt++;
      break;
    }
    case (0xa34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c4c;
      cnt++;
      break;
    }
    case (0xa38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c40;
      cnt++;
      break;
    }
    case (0xa3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c44;
      cnt++;
      break;
    }
    case (0xa40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c38;
      cnt++;
      break;
    }
    case (0xa44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c3c;
      cnt++;
      break;
    }
    case (0xa48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c30;
      cnt++;
      break;
    }
    case (0xa4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c34;
      cnt++;
      break;
    }
    case (0xa50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c28;
      cnt++;
      break;
    }
    case (0xa54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c2c;
      cnt++;
      break;
    }
    case (0xa58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c20;
      cnt++;
      break;
    }
    case (0xa5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c24;
      cnt++;
      break;
    }
    case (0xa60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c18;
      cnt++;
      break;
    }
    case (0xa64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c1c;
      cnt++;
      break;
    }
    case (0xa68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c10;
      cnt++;
      break;
    }
    case (0xa6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c14;
      cnt++;
      break;
    }
    case (0xa70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c08;
      cnt++;
      break;
    }
    case (0xa74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c0c;
      cnt++;
      break;
    }
    case (0xa78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c00;
      cnt++;
      break;
    }
    case (0xa7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c04;
      cnt++;
      break;
    }
    case (0xa80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cf8;
      cnt++;
      break;
    }
    case (0xa84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cfc;
      cnt++;
      break;
    }
    case (0xa88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cf0;
      cnt++;
      break;
    }
    case (0xa8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cf4;
      cnt++;
      break;
    }
    case (0xa90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ce8;
      cnt++;
      break;
    }
    case (0xa94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cec;
      cnt++;
      break;
    }
    case (0xa98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ce0;
      cnt++;
      break;
    }
    case (0xa9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ce4;
      cnt++;
      break;
    }
    case (0xaa0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cd8;
      cnt++;
      break;
    }
    case (0xaa4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cdc;
      cnt++;
      break;
    }
    case (0xaa8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cd0;
      cnt++;
      break;
    }
    case (0xaac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cd4;
      cnt++;
      break;
    }
    case (0xab0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cc8;
      cnt++;
      break;
    }
    case (0xab4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ccc;
      cnt++;
      break;
    }
    case (0xab8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cc0;
      cnt++;
      break;
    }
    case (0xabc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cc4;
      cnt++;
      break;
    }
    case (0xac0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cb8;
      cnt++;
      break;
    }
    case (0xac4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cbc;
      cnt++;
      break;
    }
    case (0xac8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cb0;
      cnt++;
      break;
    }
    case (0xacc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cb4;
      cnt++;
      break;
    }
    case (0xad0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ca8;
      cnt++;
      break;
    }
    case (0xad4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345cac;
      cnt++;
      break;
    }
    case (0xad8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ca0;
      cnt++;
      break;
    }
    case (0xadc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ca4;
      cnt++;
      break;
    }
    case (0xae0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c98;
      cnt++;
      break;
    }
    case (0xae4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c9c;
      cnt++;
      break;
    }
    case (0xae8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c90;
      cnt++;
      break;
    }
    case (0xaec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c94;
      cnt++;
      break;
    }
    case (0xaf0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c88;
      cnt++;
      break;
    }
    case (0xaf4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c8c;
      cnt++;
      break;
    }
    case (0xaf8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c80;
      cnt++;
      break;
    }
    case (0xafc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345c84;
      cnt++;
      break;
    }
    case (0xb00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d78;
      cnt++;
      break;
    }
    case (0xb04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d7c;
      cnt++;
      break;
    }
    case (0xb08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d70;
      cnt++;
      break;
    }
    case (0xb0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d74;
      cnt++;
      break;
    }
    case (0xb10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d68;
      cnt++;
      break;
    }
    case (0xb14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d6c;
      cnt++;
      break;
    }
    case (0xb18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d60;
      cnt++;
      break;
    }
    case (0xb1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d64;
      cnt++;
      break;
    }
    case (0xb20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d58;
      cnt++;
      break;
    }
    case (0xb24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d5c;
      cnt++;
      break;
    }
    case (0xb28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d50;
      cnt++;
      break;
    }
    case (0xb2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d54;
      cnt++;
      break;
    }
    case (0xb30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d48;
      cnt++;
      break;
    }
    case (0xb34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d4c;
      cnt++;
      break;
    }
    case (0xb38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d40;
      cnt++;
      break;
    }
    case (0xb3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d44;
      cnt++;
      break;
    }
    case (0xb40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d38;
      cnt++;
      break;
    }
    case (0xb44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d3c;
      cnt++;
      break;
    }
    case (0xb48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d30;
      cnt++;
      break;
    }
    case (0xb4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d34;
      cnt++;
      break;
    }
    case (0xb50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d28;
      cnt++;
      break;
    }
    case (0xb54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d2c;
      cnt++;
      break;
    }
    case (0xb58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d20;
      cnt++;
      break;
    }
    case (0xb5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d24;
      cnt++;
      break;
    }
    case (0xb60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d18;
      cnt++;
      break;
    }
    case (0xb64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d1c;
      cnt++;
      break;
    }
    case (0xb68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d10;
      cnt++;
      break;
    }
    case (0xb6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d14;
      cnt++;
      break;
    }
    case (0xb70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d08;
      cnt++;
      break;
    }
    case (0xb74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d0c;
      cnt++;
      break;
    }
    case (0xb78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d00;
      cnt++;
      break;
    }
    case (0xb7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d04;
      cnt++;
      break;
    }
    case (0xb80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345df8;
      cnt++;
      break;
    }
    case (0xb84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dfc;
      cnt++;
      break;
    }
    case (0xb88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345df0;
      cnt++;
      break;
    }
    case (0xb8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345df4;
      cnt++;
      break;
    }
    case (0xb90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345de8;
      cnt++;
      break;
    }
    case (0xb94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dec;
      cnt++;
      break;
    }
    case (0xb98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345de0;
      cnt++;
      break;
    }
    case (0xb9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345de4;
      cnt++;
      break;
    }
    case (0xba0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dd8;
      cnt++;
      break;
    }
    case (0xba4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ddc;
      cnt++;
      break;
    }
    case (0xba8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dd0;
      cnt++;
      break;
    }
    case (0xbac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dd4;
      cnt++;
      break;
    }
    case (0xbb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dc8;
      cnt++;
      break;
    }
    case (0xbb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dcc;
      cnt++;
      break;
    }
    case (0xbb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dc0;
      cnt++;
      break;
    }
    case (0xbbc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dc4;
      cnt++;
      break;
    }
    case (0xbc0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345db8;
      cnt++;
      break;
    }
    case (0xbc4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dbc;
      cnt++;
      break;
    }
    case (0xbc8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345db0;
      cnt++;
      break;
    }
    case (0xbcc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345db4;
      cnt++;
      break;
    }
    case (0xbd0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345da8;
      cnt++;
      break;
    }
    case (0xbd4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345dac;
      cnt++;
      break;
    }
    case (0xbd8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345da0;
      cnt++;
      break;
    }
    case (0xbdc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345da4;
      cnt++;
      break;
    }
    case (0xbe0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d98;
      cnt++;
      break;
    }
    case (0xbe4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d9c;
      cnt++;
      break;
    }
    case (0xbe8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d90;
      cnt++;
      break;
    }
    case (0xbec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d94;
      cnt++;
      break;
    }
    case (0xbf0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d88;
      cnt++;
      break;
    }
    case (0xbf4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d8c;
      cnt++;
      break;
    }
    case (0xbf8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d80;
      cnt++;
      break;
    }
    case (0xbfc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345d84;
      cnt++;
      break;
    }
    case (0xc00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a78;
      cnt++;
      break;
    }
    case (0xc04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a7c;
      cnt++;
      break;
    }
    case (0xc08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a70;
      cnt++;
      break;
    }
    case (0xc0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a74;
      cnt++;
      break;
    }
    case (0xc10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a68;
      cnt++;
      break;
    }
    case (0xc14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a6c;
      cnt++;
      break;
    }
    case (0xc18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a60;
      cnt++;
      break;
    }
    case (0xc1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a64;
      cnt++;
      break;
    }
    case (0xc20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a58;
      cnt++;
      break;
    }
    case (0xc24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a5c;
      cnt++;
      break;
    }
    case (0xc28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a50;
      cnt++;
      break;
    }
    case (0xc2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a54;
      cnt++;
      break;
    }
    case (0xc30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a48;
      cnt++;
      break;
    }
    case (0xc34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a4c;
      cnt++;
      break;
    }
    case (0xc38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a40;
      cnt++;
      break;
    }
    case (0xc3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a44;
      cnt++;
      break;
    }
    case (0xc40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a38;
      cnt++;
      break;
    }
    case (0xc44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a3c;
      cnt++;
      break;
    }
    case (0xc48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a30;
      cnt++;
      break;
    }
    case (0xc4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a34;
      cnt++;
      break;
    }
    case (0xc50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a28;
      cnt++;
      break;
    }
    case (0xc54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a2c;
      cnt++;
      break;
    }
    case (0xc58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a20;
      cnt++;
      break;
    }
    case (0xc5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a24;
      cnt++;
      break;
    }
    case (0xc60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a18;
      cnt++;
      break;
    }
    case (0xc64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a1c;
      cnt++;
      break;
    }
    case (0xc68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a10;
      cnt++;
      break;
    }
    case (0xc6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a14;
      cnt++;
      break;
    }
    case (0xc70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a08;
      cnt++;
      break;
    }
    case (0xc74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a0c;
      cnt++;
      break;
    }
    case (0xc78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a00;
      cnt++;
      break;
    }
    case (0xc7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a04;
      cnt++;
      break;
    }
    case (0xc80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345af8;
      cnt++;
      break;
    }
    case (0xc84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345afc;
      cnt++;
      break;
    }
    case (0xc88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345af0;
      cnt++;
      break;
    }
    case (0xc8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345af4;
      cnt++;
      break;
    }
    case (0xc90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ae8;
      cnt++;
      break;
    }
    case (0xc94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345aec;
      cnt++;
      break;
    }
    case (0xc98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12cb5ae0;
      cnt++;
      break;
    }
    case (0x11b): {
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
