///
/// hardware model for pci200syn
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_pci200syn : public HWModel {
public:
  HWModel_pci200syn()
      : HWModel("pci200syn", 0x10b5, 0x9050, 0x10b5, 0x3196), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x80},
              {PCI_BAR_TYPE_MMIO, 0x400},
              {PCI_BAR_TYPE_MMIO, 0x400},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_pci200syn(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 1621)
      return 0;
    switch (addr) {
    case (0x50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x20000000;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 4)
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
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
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
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
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
        *((uint32_t *)dest) = 0x12345ae0;
      cnt++;
      break;
    }
    case (0xc9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ae4;
      cnt++;
      break;
    }
    case (0xca0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ad8;
      cnt++;
      break;
    }
    case (0xca4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345adc;
      cnt++;
      break;
    }
    case (0xca8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ad0;
      cnt++;
      break;
    }
    case (0xcac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ad4;
      cnt++;
      break;
    }
    case (0xcb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ac8;
      cnt++;
      break;
    }
    case (0xcb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345acc;
      cnt++;
      break;
    }
    case (0xcb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ac0;
      cnt++;
      break;
    }
    case (0xcbc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ac4;
      cnt++;
      break;
    }
    case (0xcc0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ab8;
      cnt++;
      break;
    }
    case (0xcc4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345abc;
      cnt++;
      break;
    }
    case (0xcc8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ab0;
      cnt++;
      break;
    }
    case (0xccc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ab4;
      cnt++;
      break;
    }
    case (0xcd0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345aa8;
      cnt++;
      break;
    }
    case (0xcd4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345aac;
      cnt++;
      break;
    }
    case (0xcd8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345aa0;
      cnt++;
      break;
    }
    case (0xcdc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345aa4;
      cnt++;
      break;
    }
    case (0xce0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a98;
      cnt++;
      break;
    }
    case (0xce4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a9c;
      cnt++;
      break;
    }
    case (0xce8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a90;
      cnt++;
      break;
    }
    case (0xcec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a94;
      cnt++;
      break;
    }
    case (0xcf0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a88;
      cnt++;
      break;
    }
    case (0xcf4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a8c;
      cnt++;
      break;
    }
    case (0xcf8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a80;
      cnt++;
      break;
    }
    case (0xcfc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345a84;
      cnt++;
      break;
    }
    case (0xd00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b78;
      cnt++;
      break;
    }
    case (0xd04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b7c;
      cnt++;
      break;
    }
    case (0xd08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b70;
      cnt++;
      break;
    }
    case (0xd0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b74;
      cnt++;
      break;
    }
    case (0xd10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b68;
      cnt++;
      break;
    }
    case (0xd14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b6c;
      cnt++;
      break;
    }
    case (0xd18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b60;
      cnt++;
      break;
    }
    case (0xd1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b64;
      cnt++;
      break;
    }
    case (0xd20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b58;
      cnt++;
      break;
    }
    case (0xd24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b5c;
      cnt++;
      break;
    }
    case (0xd28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b50;
      cnt++;
      break;
    }
    case (0xd2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b54;
      cnt++;
      break;
    }
    case (0xd30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b48;
      cnt++;
      break;
    }
    case (0xd34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b4c;
      cnt++;
      break;
    }
    case (0xd38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b40;
      cnt++;
      break;
    }
    case (0xd3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b44;
      cnt++;
      break;
    }
    case (0xd40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b38;
      cnt++;
      break;
    }
    case (0xd44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b3c;
      cnt++;
      break;
    }
    case (0xd48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b30;
      cnt++;
      break;
    }
    case (0xd4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b34;
      cnt++;
      break;
    }
    case (0xd50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b28;
      cnt++;
      break;
    }
    case (0xd54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b2c;
      cnt++;
      break;
    }
    case (0xd58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b20;
      cnt++;
      break;
    }
    case (0xd5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b24;
      cnt++;
      break;
    }
    case (0xd60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b18;
      cnt++;
      break;
    }
    case (0xd64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b1c;
      cnt++;
      break;
    }
    case (0xd68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b10;
      cnt++;
      break;
    }
    case (0xd6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b14;
      cnt++;
      break;
    }
    case (0xd70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b08;
      cnt++;
      break;
    }
    case (0xd74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b0c;
      cnt++;
      break;
    }
    case (0xd78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b00;
      cnt++;
      break;
    }
    case (0xd7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b04;
      cnt++;
      break;
    }
    case (0xd80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bf8;
      cnt++;
      break;
    }
    case (0xd84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bfc;
      cnt++;
      break;
    }
    case (0xd88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bf0;
      cnt++;
      break;
    }
    case (0xd8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bf4;
      cnt++;
      break;
    }
    case (0xd90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345be8;
      cnt++;
      break;
    }
    case (0xd94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bec;
      cnt++;
      break;
    }
    case (0xd98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345be0;
      cnt++;
      break;
    }
    case (0xd9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345be4;
      cnt++;
      break;
    }
    case (0xda0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bd8;
      cnt++;
      break;
    }
    case (0xda4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bdc;
      cnt++;
      break;
    }
    case (0xda8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bd0;
      cnt++;
      break;
    }
    case (0xdac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bd4;
      cnt++;
      break;
    }
    case (0xdb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bc8;
      cnt++;
      break;
    }
    case (0xdb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bcc;
      cnt++;
      break;
    }
    case (0xdb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bc0;
      cnt++;
      break;
    }
    case (0xdbc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bc4;
      cnt++;
      break;
    }
    case (0xdc0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bb8;
      cnt++;
      break;
    }
    case (0xdc4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bbc;
      cnt++;
      break;
    }
    case (0xdc8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bb0;
      cnt++;
      break;
    }
    case (0xdcc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bb4;
      cnt++;
      break;
    }
    case (0xdd0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ba8;
      cnt++;
      break;
    }
    case (0xdd4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345bac;
      cnt++;
      break;
    }
    case (0xdd8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ba0;
      cnt++;
      break;
    }
    case (0xddc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345ba4;
      cnt++;
      break;
    }
    case (0xde0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b98;
      cnt++;
      break;
    }
    case (0xde4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b9c;
      cnt++;
      break;
    }
    case (0xde8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b90;
      cnt++;
      break;
    }
    case (0xdec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b94;
      cnt++;
      break;
    }
    case (0xdf0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b88;
      cnt++;
      break;
    }
    case (0xdf4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b8c;
      cnt++;
      break;
    }
    case (0xdf8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b80;
      cnt++;
      break;
    }
    case (0xdfc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345b84;
      cnt++;
      break;
    }
    case (0xe00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345878;
      cnt++;
      break;
    }
    case (0xe04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234587c;
      cnt++;
      break;
    }
    case (0xe08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345870;
      cnt++;
      break;
    }
    case (0xe0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345874;
      cnt++;
      break;
    }
    case (0xe10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345868;
      cnt++;
      break;
    }
    case (0xe14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234586c;
      cnt++;
      break;
    }
    case (0xe18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345860;
      cnt++;
      break;
    }
    case (0xe1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345864;
      cnt++;
      break;
    }
    case (0xe20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345858;
      cnt++;
      break;
    }
    case (0xe24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234585c;
      cnt++;
      break;
    }
    case (0xe28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345850;
      cnt++;
      break;
    }
    case (0xe2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345854;
      cnt++;
      break;
    }
    case (0xe30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345848;
      cnt++;
      break;
    }
    case (0xe34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234584c;
      cnt++;
      break;
    }
    case (0xe38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345840;
      cnt++;
      break;
    }
    case (0xe3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345844;
      cnt++;
      break;
    }
    case (0xe40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345838;
      cnt++;
      break;
    }
    case (0xe44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234583c;
      cnt++;
      break;
    }
    case (0xe48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345830;
      cnt++;
      break;
    }
    case (0xe4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345834;
      cnt++;
      break;
    }
    case (0xe50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345828;
      cnt++;
      break;
    }
    case (0xe54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234582c;
      cnt++;
      break;
    }
    case (0xe58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345820;
      cnt++;
      break;
    }
    case (0xe5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345824;
      cnt++;
      break;
    }
    case (0xe60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345818;
      cnt++;
      break;
    }
    case (0xe64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234581c;
      cnt++;
      break;
    }
    case (0xe68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345810;
      cnt++;
      break;
    }
    case (0xe6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345814;
      cnt++;
      break;
    }
    case (0xe70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345808;
      cnt++;
      break;
    }
    case (0xe74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234580c;
      cnt++;
      break;
    }
    case (0xe78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345800;
      cnt++;
      break;
    }
    case (0xe7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345804;
      cnt++;
      break;
    }
    case (0xe80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458f8;
      cnt++;
      break;
    }
    case (0xe84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458fc;
      cnt++;
      break;
    }
    case (0xe88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458f0;
      cnt++;
      break;
    }
    case (0xe8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458f4;
      cnt++;
      break;
    }
    case (0xe90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458e8;
      cnt++;
      break;
    }
    case (0xe94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458ec;
      cnt++;
      break;
    }
    case (0xe98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458e0;
      cnt++;
      break;
    }
    case (0xe9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458e4;
      cnt++;
      break;
    }
    case (0xea0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458d8;
      cnt++;
      break;
    }
    case (0xea4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458dc;
      cnt++;
      break;
    }
    case (0xea8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458d0;
      cnt++;
      break;
    }
    case (0xeac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458d4;
      cnt++;
      break;
    }
    case (0xeb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458c8;
      cnt++;
      break;
    }
    case (0xeb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458cc;
      cnt++;
      break;
    }
    case (0xeb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458c0;
      cnt++;
      break;
    }
    case (0xebc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458c4;
      cnt++;
      break;
    }
    case (0xec0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458b8;
      cnt++;
      break;
    }
    case (0xec4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458bc;
      cnt++;
      break;
    }
    case (0xec8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458b0;
      cnt++;
      break;
    }
    case (0xecc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458b4;
      cnt++;
      break;
    }
    case (0xed0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458a8;
      cnt++;
      break;
    }
    case (0xed4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458ac;
      cnt++;
      break;
    }
    case (0xed8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458a0;
      cnt++;
      break;
    }
    case (0xedc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123458a4;
      cnt++;
      break;
    }
    case (0xee0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345898;
      cnt++;
      break;
    }
    case (0xee4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234589c;
      cnt++;
      break;
    }
    case (0xee8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345890;
      cnt++;
      break;
    }
    case (0xeec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345894;
      cnt++;
      break;
    }
    case (0xef0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345888;
      cnt++;
      break;
    }
    case (0xef4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234588c;
      cnt++;
      break;
    }
    case (0xef8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345880;
      cnt++;
      break;
    }
    case (0xefc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345884;
      cnt++;
      break;
    }
    case (0xf00): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345978;
      cnt++;
      break;
    }
    case (0xf04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234597c;
      cnt++;
      break;
    }
    case (0xf08): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345970;
      cnt++;
      break;
    }
    case (0xf0c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345974;
      cnt++;
      break;
    }
    case (0xf10): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345968;
      cnt++;
      break;
    }
    case (0xf14): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234596c;
      cnt++;
      break;
    }
    case (0xf18): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345960;
      cnt++;
      break;
    }
    case (0xf1c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345964;
      cnt++;
      break;
    }
    case (0xf20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345958;
      cnt++;
      break;
    }
    case (0xf24): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234595c;
      cnt++;
      break;
    }
    case (0xf28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345950;
      cnt++;
      break;
    }
    case (0xf2c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345954;
      cnt++;
      break;
    }
    case (0xf30): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345948;
      cnt++;
      break;
    }
    case (0xf34): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234594c;
      cnt++;
      break;
    }
    case (0xf38): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345940;
      cnt++;
      break;
    }
    case (0xf3c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345944;
      cnt++;
      break;
    }
    case (0xf40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345938;
      cnt++;
      break;
    }
    case (0xf44): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234593c;
      cnt++;
      break;
    }
    case (0xf48): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345930;
      cnt++;
      break;
    }
    case (0xf4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345934;
      cnt++;
      break;
    }
    case (0xf50): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345928;
      cnt++;
      break;
    }
    case (0xf54): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234592c;
      cnt++;
      break;
    }
    case (0xf58): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345920;
      cnt++;
      break;
    }
    case (0xf5c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345924;
      cnt++;
      break;
    }
    case (0xf60): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345918;
      cnt++;
      break;
    }
    case (0xf64): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234591c;
      cnt++;
      break;
    }
    case (0xf68): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345910;
      cnt++;
      break;
    }
    case (0xf6c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345914;
      cnt++;
      break;
    }
    case (0xf70): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345908;
      cnt++;
      break;
    }
    case (0xf74): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234590c;
      cnt++;
      break;
    }
    case (0xf78): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345900;
      cnt++;
      break;
    }
    case (0xf7c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345904;
      cnt++;
      break;
    }
    case (0xf80): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459f8;
      cnt++;
      break;
    }
    case (0xf84): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459fc;
      cnt++;
      break;
    }
    case (0xf88): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459f0;
      cnt++;
      break;
    }
    case (0xf8c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459f4;
      cnt++;
      break;
    }
    case (0xf90): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459e8;
      cnt++;
      break;
    }
    case (0xf94): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459ec;
      cnt++;
      break;
    }
    case (0xf98): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459e0;
      cnt++;
      break;
    }
    case (0xf9c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459e4;
      cnt++;
      break;
    }
    case (0xfa0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459d8;
      cnt++;
      break;
    }
    case (0xfa4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459dc;
      cnt++;
      break;
    }
    case (0xfa8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459d0;
      cnt++;
      break;
    }
    case (0xfac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459d4;
      cnt++;
      break;
    }
    case (0xfb0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459c8;
      cnt++;
      break;
    }
    case (0xfb4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459cc;
      cnt++;
      break;
    }
    case (0xfb8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459c0;
      cnt++;
      break;
    }
    case (0xfbc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459c4;
      cnt++;
      break;
    }
    case (0xfc0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459b8;
      cnt++;
      break;
    }
    case (0xfc4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459bc;
      cnt++;
      break;
    }
    case (0xfc8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459b0;
      cnt++;
      break;
    }
    case (0xfcc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459b4;
      cnt++;
      break;
    }
    case (0xfd0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459a8;
      cnt++;
      break;
    }
    case (0xfd4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459ac;
      cnt++;
      break;
    }
    case (0xfd8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459a0;
      cnt++;
      break;
    }
    case (0xfdc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123459a4;
      cnt++;
      break;
    }
    case (0xfe0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345998;
      cnt++;
      break;
    }
    case (0xfe4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234599c;
      cnt++;
      break;
    }
    case (0xfe8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345990;
      cnt++;
      break;
    }
    case (0xfec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345994;
      cnt++;
      break;
    }
    case (0xff0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345988;
      cnt++;
      break;
    }
    case (0xff4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234598c;
      cnt++;
      break;
    }
    case (0xff8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345980;
      cnt++;
      break;
    }
    case (0xffc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12345984;
      cnt++;
      break;
    }
    case (0x1000): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344678;
      cnt++;
      break;
    }
    case (0x1004): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234467c;
      cnt++;
      break;
    }
    case (0x1008): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344670;
      cnt++;
      break;
    }
    case (0x100c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344674;
      cnt++;
      break;
    }
    case (0x1010): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344668;
      cnt++;
      break;
    }
    case (0x1014): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234466c;
      cnt++;
      break;
    }
    case (0x1018): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344660;
      cnt++;
      break;
    }
    case (0x101c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344664;
      cnt++;
      break;
    }
    case (0x1020): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344658;
      cnt++;
      break;
    }
    case (0x1024): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234465c;
      cnt++;
      break;
    }
    case (0x1028): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344650;
      cnt++;
      break;
    }
    case (0x102c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344654;
      cnt++;
      break;
    }
    case (0x1030): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344648;
      cnt++;
      break;
    }
    case (0x1034): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234464c;
      cnt++;
      break;
    }
    case (0x1038): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344640;
      cnt++;
      break;
    }
    case (0x103c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344644;
      cnt++;
      break;
    }
    case (0x1040): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344638;
      cnt++;
      break;
    }
    case (0x1044): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234463c;
      cnt++;
      break;
    }
    case (0x1048): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344630;
      cnt++;
      break;
    }
    case (0x104c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344634;
      cnt++;
      break;
    }
    case (0x1050): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344628;
      cnt++;
      break;
    }
    case (0x1054): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234462c;
      cnt++;
      break;
    }
    case (0x1058): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344620;
      cnt++;
      break;
    }
    case (0x105c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344624;
      cnt++;
      break;
    }
    case (0x1060): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344618;
      cnt++;
      break;
    }
    case (0x1064): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234461c;
      cnt++;
      break;
    }
    case (0x1068): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344610;
      cnt++;
      break;
    }
    case (0x106c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344614;
      cnt++;
      break;
    }
    case (0x1070): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344608;
      cnt++;
      break;
    }
    case (0x1074): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234460c;
      cnt++;
      break;
    }
    case (0x1078): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344600;
      cnt++;
      break;
    }
    case (0x107c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344604;
      cnt++;
      break;
    }
    case (0x1080): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446f8;
      cnt++;
      break;
    }
    case (0x1084): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446fc;
      cnt++;
      break;
    }
    case (0x1088): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446f0;
      cnt++;
      break;
    }
    case (0x108c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446f4;
      cnt++;
      break;
    }
    case (0x1090): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446e8;
      cnt++;
      break;
    }
    case (0x1094): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446ec;
      cnt++;
      break;
    }
    case (0x1098): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446e0;
      cnt++;
      break;
    }
    case (0x109c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446e4;
      cnt++;
      break;
    }
    case (0x10a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446d8;
      cnt++;
      break;
    }
    case (0x10a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446dc;
      cnt++;
      break;
    }
    case (0x10a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446d0;
      cnt++;
      break;
    }
    case (0x10ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446d4;
      cnt++;
      break;
    }
    case (0x10b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446c8;
      cnt++;
      break;
    }
    case (0x10b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446cc;
      cnt++;
      break;
    }
    case (0x10b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446c0;
      cnt++;
      break;
    }
    case (0x10bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446c4;
      cnt++;
      break;
    }
    case (0x10c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446b8;
      cnt++;
      break;
    }
    case (0x10c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446bc;
      cnt++;
      break;
    }
    case (0x10c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446b0;
      cnt++;
      break;
    }
    case (0x10cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446b4;
      cnt++;
      break;
    }
    case (0x10d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446a8;
      cnt++;
      break;
    }
    case (0x10d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446ac;
      cnt++;
      break;
    }
    case (0x10d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446a0;
      cnt++;
      break;
    }
    case (0x10dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123446a4;
      cnt++;
      break;
    }
    case (0x10e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344698;
      cnt++;
      break;
    }
    case (0x10e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234469c;
      cnt++;
      break;
    }
    case (0x10e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344690;
      cnt++;
      break;
    }
    case (0x10ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344694;
      cnt++;
      break;
    }
    case (0x10f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344688;
      cnt++;
      break;
    }
    case (0x10f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234468c;
      cnt++;
      break;
    }
    case (0x10f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344680;
      cnt++;
      break;
    }
    case (0x10fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344684;
      cnt++;
      break;
    }
    case (0x1100): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344778;
      cnt++;
      break;
    }
    case (0x1104): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234477c;
      cnt++;
      break;
    }
    case (0x1108): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344770;
      cnt++;
      break;
    }
    case (0x110c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344774;
      cnt++;
      break;
    }
    case (0x1110): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344768;
      cnt++;
      break;
    }
    case (0x1114): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234476c;
      cnt++;
      break;
    }
    case (0x1118): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344760;
      cnt++;
      break;
    }
    case (0x111c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344764;
      cnt++;
      break;
    }
    case (0x1120): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344758;
      cnt++;
      break;
    }
    case (0x1124): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234475c;
      cnt++;
      break;
    }
    case (0x1128): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344750;
      cnt++;
      break;
    }
    case (0x112c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344754;
      cnt++;
      break;
    }
    case (0x1130): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344748;
      cnt++;
      break;
    }
    case (0x1134): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234474c;
      cnt++;
      break;
    }
    case (0x1138): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344740;
      cnt++;
      break;
    }
    case (0x113c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344744;
      cnt++;
      break;
    }
    case (0x1140): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344738;
      cnt++;
      break;
    }
    case (0x1144): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234473c;
      cnt++;
      break;
    }
    case (0x1148): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344730;
      cnt++;
      break;
    }
    case (0x114c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344734;
      cnt++;
      break;
    }
    case (0x1150): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344728;
      cnt++;
      break;
    }
    case (0x1154): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234472c;
      cnt++;
      break;
    }
    case (0x1158): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344720;
      cnt++;
      break;
    }
    case (0x115c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344724;
      cnt++;
      break;
    }
    case (0x1160): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344718;
      cnt++;
      break;
    }
    case (0x1164): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234471c;
      cnt++;
      break;
    }
    case (0x1168): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344710;
      cnt++;
      break;
    }
    case (0x116c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344714;
      cnt++;
      break;
    }
    case (0x1170): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344708;
      cnt++;
      break;
    }
    case (0x1174): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234470c;
      cnt++;
      break;
    }
    case (0x1178): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344700;
      cnt++;
      break;
    }
    case (0x117c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344704;
      cnt++;
      break;
    }
    case (0x1180): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447f8;
      cnt++;
      break;
    }
    case (0x1184): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447fc;
      cnt++;
      break;
    }
    case (0x1188): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447f0;
      cnt++;
      break;
    }
    case (0x118c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447f4;
      cnt++;
      break;
    }
    case (0x1190): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447e8;
      cnt++;
      break;
    }
    case (0x1194): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447ec;
      cnt++;
      break;
    }
    case (0x1198): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447e0;
      cnt++;
      break;
    }
    case (0x119c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447e4;
      cnt++;
      break;
    }
    case (0x11a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447d8;
      cnt++;
      break;
    }
    case (0x11a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447dc;
      cnt++;
      break;
    }
    case (0x11a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447d0;
      cnt++;
      break;
    }
    case (0x11ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447d4;
      cnt++;
      break;
    }
    case (0x11b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447c8;
      cnt++;
      break;
    }
    case (0x11b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447cc;
      cnt++;
      break;
    }
    case (0x11b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447c0;
      cnt++;
      break;
    }
    case (0x11bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447c4;
      cnt++;
      break;
    }
    case (0x11c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447b8;
      cnt++;
      break;
    }
    case (0x11c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447bc;
      cnt++;
      break;
    }
    case (0x11c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447b0;
      cnt++;
      break;
    }
    case (0x11cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447b4;
      cnt++;
      break;
    }
    case (0x11d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447a8;
      cnt++;
      break;
    }
    case (0x11d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447ac;
      cnt++;
      break;
    }
    case (0x11d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447a0;
      cnt++;
      break;
    }
    case (0x11dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123447a4;
      cnt++;
      break;
    }
    case (0x11e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344798;
      cnt++;
      break;
    }
    case (0x11e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234479c;
      cnt++;
      break;
    }
    case (0x11e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344790;
      cnt++;
      break;
    }
    case (0x11ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344794;
      cnt++;
      break;
    }
    case (0x11f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344788;
      cnt++;
      break;
    }
    case (0x11f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234478c;
      cnt++;
      break;
    }
    case (0x11f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344780;
      cnt++;
      break;
    }
    case (0x11fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344784;
      cnt++;
      break;
    }
    case (0x1200): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344478;
      cnt++;
      break;
    }
    case (0x1204): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234447c;
      cnt++;
      break;
    }
    case (0x1208): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344470;
      cnt++;
      break;
    }
    case (0x120c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344474;
      cnt++;
      break;
    }
    case (0x1210): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344468;
      cnt++;
      break;
    }
    case (0x1214): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234446c;
      cnt++;
      break;
    }
    case (0x1218): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344460;
      cnt++;
      break;
    }
    case (0x121c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344464;
      cnt++;
      break;
    }
    case (0x1220): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344458;
      cnt++;
      break;
    }
    case (0x1224): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234445c;
      cnt++;
      break;
    }
    case (0x1228): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344450;
      cnt++;
      break;
    }
    case (0x122c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344454;
      cnt++;
      break;
    }
    case (0x1230): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344448;
      cnt++;
      break;
    }
    case (0x1234): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234444c;
      cnt++;
      break;
    }
    case (0x1238): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344440;
      cnt++;
      break;
    }
    case (0x123c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344444;
      cnt++;
      break;
    }
    case (0x1240): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344438;
      cnt++;
      break;
    }
    case (0x1244): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234443c;
      cnt++;
      break;
    }
    case (0x1248): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344430;
      cnt++;
      break;
    }
    case (0x124c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344434;
      cnt++;
      break;
    }
    case (0x1250): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344428;
      cnt++;
      break;
    }
    case (0x1254): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234442c;
      cnt++;
      break;
    }
    case (0x1258): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344420;
      cnt++;
      break;
    }
    case (0x125c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344424;
      cnt++;
      break;
    }
    case (0x1260): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344418;
      cnt++;
      break;
    }
    case (0x1264): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234441c;
      cnt++;
      break;
    }
    case (0x1268): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344410;
      cnt++;
      break;
    }
    case (0x126c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344414;
      cnt++;
      break;
    }
    case (0x1270): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344408;
      cnt++;
      break;
    }
    case (0x1274): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234440c;
      cnt++;
      break;
    }
    case (0x1278): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344400;
      cnt++;
      break;
    }
    case (0x127c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344404;
      cnt++;
      break;
    }
    case (0x1280): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444f8;
      cnt++;
      break;
    }
    case (0x1284): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444fc;
      cnt++;
      break;
    }
    case (0x1288): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444f0;
      cnt++;
      break;
    }
    case (0x128c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444f4;
      cnt++;
      break;
    }
    case (0x1290): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444e8;
      cnt++;
      break;
    }
    case (0x1294): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444ec;
      cnt++;
      break;
    }
    case (0x1298): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444e0;
      cnt++;
      break;
    }
    case (0x129c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444e4;
      cnt++;
      break;
    }
    case (0x12a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444d8;
      cnt++;
      break;
    }
    case (0x12a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444dc;
      cnt++;
      break;
    }
    case (0x12a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444d0;
      cnt++;
      break;
    }
    case (0x12ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444d4;
      cnt++;
      break;
    }
    case (0x12b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444c8;
      cnt++;
      break;
    }
    case (0x12b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444cc;
      cnt++;
      break;
    }
    case (0x12b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444c0;
      cnt++;
      break;
    }
    case (0x12bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444c4;
      cnt++;
      break;
    }
    case (0x12c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444b8;
      cnt++;
      break;
    }
    case (0x12c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444bc;
      cnt++;
      break;
    }
    case (0x12c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444b0;
      cnt++;
      break;
    }
    case (0x12cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444b4;
      cnt++;
      break;
    }
    case (0x12d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444a8;
      cnt++;
      break;
    }
    case (0x12d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444ac;
      cnt++;
      break;
    }
    case (0x12d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444a0;
      cnt++;
      break;
    }
    case (0x12dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123444a4;
      cnt++;
      break;
    }
    case (0x12e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344498;
      cnt++;
      break;
    }
    case (0x12e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234449c;
      cnt++;
      break;
    }
    case (0x12e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344490;
      cnt++;
      break;
    }
    case (0x12ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344494;
      cnt++;
      break;
    }
    case (0x12f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344488;
      cnt++;
      break;
    }
    case (0x12f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234448c;
      cnt++;
      break;
    }
    case (0x12f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344480;
      cnt++;
      break;
    }
    case (0x12fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344484;
      cnt++;
      break;
    }
    case (0x1300): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344578;
      cnt++;
      break;
    }
    case (0x1304): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234457c;
      cnt++;
      break;
    }
    case (0x1308): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344570;
      cnt++;
      break;
    }
    case (0x130c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344574;
      cnt++;
      break;
    }
    case (0x1310): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344568;
      cnt++;
      break;
    }
    case (0x1314): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234456c;
      cnt++;
      break;
    }
    case (0x1318): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344560;
      cnt++;
      break;
    }
    case (0x131c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344564;
      cnt++;
      break;
    }
    case (0x1320): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344558;
      cnt++;
      break;
    }
    case (0x1324): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234455c;
      cnt++;
      break;
    }
    case (0x1328): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344550;
      cnt++;
      break;
    }
    case (0x132c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344554;
      cnt++;
      break;
    }
    case (0x1330): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344548;
      cnt++;
      break;
    }
    case (0x1334): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234454c;
      cnt++;
      break;
    }
    case (0x1338): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344540;
      cnt++;
      break;
    }
    case (0x133c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344544;
      cnt++;
      break;
    }
    case (0x1340): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344538;
      cnt++;
      break;
    }
    case (0x1344): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234453c;
      cnt++;
      break;
    }
    case (0x1348): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344530;
      cnt++;
      break;
    }
    case (0x134c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344534;
      cnt++;
      break;
    }
    case (0x1350): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344528;
      cnt++;
      break;
    }
    case (0x1354): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234452c;
      cnt++;
      break;
    }
    case (0x1358): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344520;
      cnt++;
      break;
    }
    case (0x135c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344524;
      cnt++;
      break;
    }
    case (0x1360): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344518;
      cnt++;
      break;
    }
    case (0x1364): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234451c;
      cnt++;
      break;
    }
    case (0x1368): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344510;
      cnt++;
      break;
    }
    case (0x136c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344514;
      cnt++;
      break;
    }
    case (0x1370): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344508;
      cnt++;
      break;
    }
    case (0x1374): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234450c;
      cnt++;
      break;
    }
    case (0x1378): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344500;
      cnt++;
      break;
    }
    case (0x137c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344504;
      cnt++;
      break;
    }
    case (0x1380): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445f8;
      cnt++;
      break;
    }
    case (0x1384): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445fc;
      cnt++;
      break;
    }
    case (0x1388): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445f0;
      cnt++;
      break;
    }
    case (0x138c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445f4;
      cnt++;
      break;
    }
    case (0x1390): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445e8;
      cnt++;
      break;
    }
    case (0x1394): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445ec;
      cnt++;
      break;
    }
    case (0x1398): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445e0;
      cnt++;
      break;
    }
    case (0x139c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445e4;
      cnt++;
      break;
    }
    case (0x13a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445d8;
      cnt++;
      break;
    }
    case (0x13a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445dc;
      cnt++;
      break;
    }
    case (0x13a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445d0;
      cnt++;
      break;
    }
    case (0x13ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445d4;
      cnt++;
      break;
    }
    case (0x13b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445c8;
      cnt++;
      break;
    }
    case (0x13b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445cc;
      cnt++;
      break;
    }
    case (0x13b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445c0;
      cnt++;
      break;
    }
    case (0x13bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445c4;
      cnt++;
      break;
    }
    case (0x13c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445b8;
      cnt++;
      break;
    }
    case (0x13c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445bc;
      cnt++;
      break;
    }
    case (0x13c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445b0;
      cnt++;
      break;
    }
    case (0x13cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445b4;
      cnt++;
      break;
    }
    case (0x13d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445a8;
      cnt++;
      break;
    }
    case (0x13d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445ac;
      cnt++;
      break;
    }
    case (0x13d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445a0;
      cnt++;
      break;
    }
    case (0x13dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123445a4;
      cnt++;
      break;
    }
    case (0x13e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344598;
      cnt++;
      break;
    }
    case (0x13e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234459c;
      cnt++;
      break;
    }
    case (0x13e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344590;
      cnt++;
      break;
    }
    case (0x13ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344594;
      cnt++;
      break;
    }
    case (0x13f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344588;
      cnt++;
      break;
    }
    case (0x13f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234458c;
      cnt++;
      break;
    }
    case (0x13f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344580;
      cnt++;
      break;
    }
    case (0x13fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344584;
      cnt++;
      break;
    }
    case (0x1400): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344278;
      cnt++;
      break;
    }
    case (0x1404): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234427c;
      cnt++;
      break;
    }
    case (0x1408): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344270;
      cnt++;
      break;
    }
    case (0x140c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344274;
      cnt++;
      break;
    }
    case (0x1410): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344268;
      cnt++;
      break;
    }
    case (0x1414): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234426c;
      cnt++;
      break;
    }
    case (0x1418): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344260;
      cnt++;
      break;
    }
    case (0x141c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344264;
      cnt++;
      break;
    }
    case (0x1420): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344258;
      cnt++;
      break;
    }
    case (0x1424): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234425c;
      cnt++;
      break;
    }
    case (0x1428): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344250;
      cnt++;
      break;
    }
    case (0x142c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344254;
      cnt++;
      break;
    }
    case (0x1430): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344248;
      cnt++;
      break;
    }
    case (0x1434): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234424c;
      cnt++;
      break;
    }
    case (0x1438): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344240;
      cnt++;
      break;
    }
    case (0x143c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344244;
      cnt++;
      break;
    }
    case (0x1440): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344238;
      cnt++;
      break;
    }
    case (0x1444): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234423c;
      cnt++;
      break;
    }
    case (0x1448): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344230;
      cnt++;
      break;
    }
    case (0x144c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344234;
      cnt++;
      break;
    }
    case (0x1450): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344228;
      cnt++;
      break;
    }
    case (0x1454): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234422c;
      cnt++;
      break;
    }
    case (0x1458): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344220;
      cnt++;
      break;
    }
    case (0x145c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344224;
      cnt++;
      break;
    }
    case (0x1460): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344218;
      cnt++;
      break;
    }
    case (0x1464): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234421c;
      cnt++;
      break;
    }
    case (0x1468): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344210;
      cnt++;
      break;
    }
    case (0x146c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344214;
      cnt++;
      break;
    }
    case (0x1470): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344208;
      cnt++;
      break;
    }
    case (0x1474): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234420c;
      cnt++;
      break;
    }
    case (0x1478): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344200;
      cnt++;
      break;
    }
    case (0x147c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344204;
      cnt++;
      break;
    }
    case (0x1480): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442f8;
      cnt++;
      break;
    }
    case (0x1484): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442fc;
      cnt++;
      break;
    }
    case (0x1488): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442f0;
      cnt++;
      break;
    }
    case (0x148c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442f4;
      cnt++;
      break;
    }
    case (0x1490): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442e8;
      cnt++;
      break;
    }
    case (0x1494): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442ec;
      cnt++;
      break;
    }
    case (0x1498): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442e0;
      cnt++;
      break;
    }
    case (0x149c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442e4;
      cnt++;
      break;
    }
    case (0x14a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442d8;
      cnt++;
      break;
    }
    case (0x14a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442dc;
      cnt++;
      break;
    }
    case (0x14a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442d0;
      cnt++;
      break;
    }
    case (0x14ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442d4;
      cnt++;
      break;
    }
    case (0x14b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442c8;
      cnt++;
      break;
    }
    case (0x14b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442cc;
      cnt++;
      break;
    }
    case (0x14b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442c0;
      cnt++;
      break;
    }
    case (0x14bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442c4;
      cnt++;
      break;
    }
    case (0x14c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442b8;
      cnt++;
      break;
    }
    case (0x14c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442bc;
      cnt++;
      break;
    }
    case (0x14c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442b0;
      cnt++;
      break;
    }
    case (0x14cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442b4;
      cnt++;
      break;
    }
    case (0x14d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442a8;
      cnt++;
      break;
    }
    case (0x14d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442ac;
      cnt++;
      break;
    }
    case (0x14d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442a0;
      cnt++;
      break;
    }
    case (0x14dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123442a4;
      cnt++;
      break;
    }
    case (0x14e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344298;
      cnt++;
      break;
    }
    case (0x14e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234429c;
      cnt++;
      break;
    }
    case (0x14e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344290;
      cnt++;
      break;
    }
    case (0x14ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344294;
      cnt++;
      break;
    }
    case (0x14f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344288;
      cnt++;
      break;
    }
    case (0x14f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234428c;
      cnt++;
      break;
    }
    case (0x14f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344280;
      cnt++;
      break;
    }
    case (0x14fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344284;
      cnt++;
      break;
    }
    case (0x1500): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344378;
      cnt++;
      break;
    }
    case (0x1504): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234437c;
      cnt++;
      break;
    }
    case (0x1508): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344370;
      cnt++;
      break;
    }
    case (0x150c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344374;
      cnt++;
      break;
    }
    case (0x1510): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344368;
      cnt++;
      break;
    }
    case (0x1514): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234436c;
      cnt++;
      break;
    }
    case (0x1518): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344360;
      cnt++;
      break;
    }
    case (0x151c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344364;
      cnt++;
      break;
    }
    case (0x1520): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344358;
      cnt++;
      break;
    }
    case (0x1524): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234435c;
      cnt++;
      break;
    }
    case (0x1528): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344350;
      cnt++;
      break;
    }
    case (0x152c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344354;
      cnt++;
      break;
    }
    case (0x1530): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344348;
      cnt++;
      break;
    }
    case (0x1534): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234434c;
      cnt++;
      break;
    }
    case (0x1538): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344340;
      cnt++;
      break;
    }
    case (0x153c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344344;
      cnt++;
      break;
    }
    case (0x1540): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344338;
      cnt++;
      break;
    }
    case (0x1544): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234433c;
      cnt++;
      break;
    }
    case (0x1548): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344330;
      cnt++;
      break;
    }
    case (0x154c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344334;
      cnt++;
      break;
    }
    case (0x1550): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344328;
      cnt++;
      break;
    }
    case (0x1554): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234432c;
      cnt++;
      break;
    }
    case (0x1558): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344320;
      cnt++;
      break;
    }
    case (0x155c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344324;
      cnt++;
      break;
    }
    case (0x1560): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344318;
      cnt++;
      break;
    }
    case (0x1564): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234431c;
      cnt++;
      break;
    }
    case (0x1568): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344310;
      cnt++;
      break;
    }
    case (0x156c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344314;
      cnt++;
      break;
    }
    case (0x1570): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344308;
      cnt++;
      break;
    }
    case (0x1574): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234430c;
      cnt++;
      break;
    }
    case (0x1578): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344300;
      cnt++;
      break;
    }
    case (0x157c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344304;
      cnt++;
      break;
    }
    case (0x1580): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443f8;
      cnt++;
      break;
    }
    case (0x1584): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443fc;
      cnt++;
      break;
    }
    case (0x1588): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443f0;
      cnt++;
      break;
    }
    case (0x158c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443f4;
      cnt++;
      break;
    }
    case (0x1590): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443e8;
      cnt++;
      break;
    }
    case (0x1594): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443ec;
      cnt++;
      break;
    }
    case (0x1598): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443e0;
      cnt++;
      break;
    }
    case (0x159c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443e4;
      cnt++;
      break;
    }
    case (0x15a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443d8;
      cnt++;
      break;
    }
    case (0x15a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443dc;
      cnt++;
      break;
    }
    case (0x15a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443d0;
      cnt++;
      break;
    }
    case (0x15ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443d4;
      cnt++;
      break;
    }
    case (0x15b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443c8;
      cnt++;
      break;
    }
    case (0x15b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443cc;
      cnt++;
      break;
    }
    case (0x15b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443c0;
      cnt++;
      break;
    }
    case (0x15bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443c4;
      cnt++;
      break;
    }
    case (0x15c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443b8;
      cnt++;
      break;
    }
    case (0x15c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443bc;
      cnt++;
      break;
    }
    case (0x15c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443b0;
      cnt++;
      break;
    }
    case (0x15cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443b4;
      cnt++;
      break;
    }
    case (0x15d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443a8;
      cnt++;
      break;
    }
    case (0x15d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443ac;
      cnt++;
      break;
    }
    case (0x15d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443a0;
      cnt++;
      break;
    }
    case (0x15dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123443a4;
      cnt++;
      break;
    }
    case (0x15e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344398;
      cnt++;
      break;
    }
    case (0x15e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234439c;
      cnt++;
      break;
    }
    case (0x15e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344390;
      cnt++;
      break;
    }
    case (0x15ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344394;
      cnt++;
      break;
    }
    case (0x15f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344388;
      cnt++;
      break;
    }
    case (0x15f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234438c;
      cnt++;
      break;
    }
    case (0x15f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344380;
      cnt++;
      break;
    }
    case (0x15fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344384;
      cnt++;
      break;
    }
    case (0x1600): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344078;
      cnt++;
      break;
    }
    case (0x1604): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234407c;
      cnt++;
      break;
    }
    case (0x1608): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344070;
      cnt++;
      break;
    }
    case (0x160c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344074;
      cnt++;
      break;
    }
    case (0x1610): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344068;
      cnt++;
      break;
    }
    case (0x1614): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234406c;
      cnt++;
      break;
    }
    case (0x1618): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344060;
      cnt++;
      break;
    }
    case (0x161c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344064;
      cnt++;
      break;
    }
    case (0x1620): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344058;
      cnt++;
      break;
    }
    case (0x1624): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234405c;
      cnt++;
      break;
    }
    case (0x1628): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344050;
      cnt++;
      break;
    }
    case (0x162c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344054;
      cnt++;
      break;
    }
    case (0x1630): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344048;
      cnt++;
      break;
    }
    case (0x1634): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234404c;
      cnt++;
      break;
    }
    case (0x1638): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344040;
      cnt++;
      break;
    }
    case (0x163c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344044;
      cnt++;
      break;
    }
    case (0x1640): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344038;
      cnt++;
      break;
    }
    case (0x1644): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234403c;
      cnt++;
      break;
    }
    case (0x1648): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344030;
      cnt++;
      break;
    }
    case (0x164c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344034;
      cnt++;
      break;
    }
    case (0x1650): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344028;
      cnt++;
      break;
    }
    case (0x1654): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234402c;
      cnt++;
      break;
    }
    case (0x1658): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344020;
      cnt++;
      break;
    }
    case (0x165c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344024;
      cnt++;
      break;
    }
    case (0x1660): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344018;
      cnt++;
      break;
    }
    case (0x1664): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234401c;
      cnt++;
      break;
    }
    case (0x1668): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344010;
      cnt++;
      break;
    }
    case (0x166c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344014;
      cnt++;
      break;
    }
    case (0x1670): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344008;
      cnt++;
      break;
    }
    case (0x1674): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234400c;
      cnt++;
      break;
    }
    case (0x1678): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344000;
      cnt++;
      break;
    }
    case (0x167c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344004;
      cnt++;
      break;
    }
    case (0x1680): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440f8;
      cnt++;
      break;
    }
    case (0x1684): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440fc;
      cnt++;
      break;
    }
    case (0x1688): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440f0;
      cnt++;
      break;
    }
    case (0x168c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440f4;
      cnt++;
      break;
    }
    case (0x1690): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440e8;
      cnt++;
      break;
    }
    case (0x1694): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440ec;
      cnt++;
      break;
    }
    case (0x1698): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440e0;
      cnt++;
      break;
    }
    case (0x169c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440e4;
      cnt++;
      break;
    }
    case (0x16a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440d8;
      cnt++;
      break;
    }
    case (0x16a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440dc;
      cnt++;
      break;
    }
    case (0x16a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440d0;
      cnt++;
      break;
    }
    case (0x16ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440d4;
      cnt++;
      break;
    }
    case (0x16b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440c8;
      cnt++;
      break;
    }
    case (0x16b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440cc;
      cnt++;
      break;
    }
    case (0x16b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440c0;
      cnt++;
      break;
    }
    case (0x16bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440c4;
      cnt++;
      break;
    }
    case (0x16c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440b8;
      cnt++;
      break;
    }
    case (0x16c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440bc;
      cnt++;
      break;
    }
    case (0x16c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440b0;
      cnt++;
      break;
    }
    case (0x16cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440b4;
      cnt++;
      break;
    }
    case (0x16d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440a8;
      cnt++;
      break;
    }
    case (0x16d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440ac;
      cnt++;
      break;
    }
    case (0x16d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440a0;
      cnt++;
      break;
    }
    case (0x16dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123440a4;
      cnt++;
      break;
    }
    case (0x16e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344098;
      cnt++;
      break;
    }
    case (0x16e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234409c;
      cnt++;
      break;
    }
    case (0x16e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344090;
      cnt++;
      break;
    }
    case (0x16ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344094;
      cnt++;
      break;
    }
    case (0x16f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344088;
      cnt++;
      break;
    }
    case (0x16f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234408c;
      cnt++;
      break;
    }
    case (0x16f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344080;
      cnt++;
      break;
    }
    case (0x16fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344084;
      cnt++;
      break;
    }
    case (0x1700): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344178;
      cnt++;
      break;
    }
    case (0x1704): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234417c;
      cnt++;
      break;
    }
    case (0x1708): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344170;
      cnt++;
      break;
    }
    case (0x170c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344174;
      cnt++;
      break;
    }
    case (0x1710): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344168;
      cnt++;
      break;
    }
    case (0x1714): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234416c;
      cnt++;
      break;
    }
    case (0x1718): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344160;
      cnt++;
      break;
    }
    case (0x171c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344164;
      cnt++;
      break;
    }
    case (0x1720): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344158;
      cnt++;
      break;
    }
    case (0x1724): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234415c;
      cnt++;
      break;
    }
    case (0x1728): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344150;
      cnt++;
      break;
    }
    case (0x172c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344154;
      cnt++;
      break;
    }
    case (0x1730): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344148;
      cnt++;
      break;
    }
    case (0x1734): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234414c;
      cnt++;
      break;
    }
    case (0x1738): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344140;
      cnt++;
      break;
    }
    case (0x173c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344144;
      cnt++;
      break;
    }
    case (0x1740): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344138;
      cnt++;
      break;
    }
    case (0x1744): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234413c;
      cnt++;
      break;
    }
    case (0x1748): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344130;
      cnt++;
      break;
    }
    case (0x174c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344134;
      cnt++;
      break;
    }
    case (0x1750): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344128;
      cnt++;
      break;
    }
    case (0x1754): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234412c;
      cnt++;
      break;
    }
    case (0x1758): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344120;
      cnt++;
      break;
    }
    case (0x175c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344124;
      cnt++;
      break;
    }
    case (0x1760): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344118;
      cnt++;
      break;
    }
    case (0x1764): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234411c;
      cnt++;
      break;
    }
    case (0x1768): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344110;
      cnt++;
      break;
    }
    case (0x176c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344114;
      cnt++;
      break;
    }
    case (0x1770): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344108;
      cnt++;
      break;
    }
    case (0x1774): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234410c;
      cnt++;
      break;
    }
    case (0x1778): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344100;
      cnt++;
      break;
    }
    case (0x177c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344104;
      cnt++;
      break;
    }
    case (0x1780): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441f8;
      cnt++;
      break;
    }
    case (0x1784): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441fc;
      cnt++;
      break;
    }
    case (0x1788): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441f0;
      cnt++;
      break;
    }
    case (0x178c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441f4;
      cnt++;
      break;
    }
    case (0x1790): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441e8;
      cnt++;
      break;
    }
    case (0x1794): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441ec;
      cnt++;
      break;
    }
    case (0x1798): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441e0;
      cnt++;
      break;
    }
    case (0x179c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441e4;
      cnt++;
      break;
    }
    case (0x17a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441d8;
      cnt++;
      break;
    }
    case (0x17a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441dc;
      cnt++;
      break;
    }
    case (0x17a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441d0;
      cnt++;
      break;
    }
    case (0x17ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441d4;
      cnt++;
      break;
    }
    case (0x17b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441c8;
      cnt++;
      break;
    }
    case (0x17b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441cc;
      cnt++;
      break;
    }
    case (0x17b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441c0;
      cnt++;
      break;
    }
    case (0x17bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441c4;
      cnt++;
      break;
    }
    case (0x17c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441b8;
      cnt++;
      break;
    }
    case (0x17c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441bc;
      cnt++;
      break;
    }
    case (0x17c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441b0;
      cnt++;
      break;
    }
    case (0x17cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441b4;
      cnt++;
      break;
    }
    case (0x17d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441a8;
      cnt++;
      break;
    }
    case (0x17d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441ac;
      cnt++;
      break;
    }
    case (0x17d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441a0;
      cnt++;
      break;
    }
    case (0x17dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x123441a4;
      cnt++;
      break;
    }
    case (0x17e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344198;
      cnt++;
      break;
    }
    case (0x17e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234419c;
      cnt++;
      break;
    }
    case (0x17e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344190;
      cnt++;
      break;
    }
    case (0x17ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344194;
      cnt++;
      break;
    }
    case (0x17f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344188;
      cnt++;
      break;
    }
    case (0x17f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1234418c;
      cnt++;
      break;
    }
    case (0x17f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344180;
      cnt++;
      break;
    }
    case (0x17fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344184;
      cnt++;
      break;
    }
    case (0x1800): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e78;
      cnt++;
      break;
    }
    case (0x1804): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e7c;
      cnt++;
      break;
    }
    case (0x1808): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e70;
      cnt++;
      break;
    }
    case (0x180c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e74;
      cnt++;
      break;
    }
    case (0x1810): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e68;
      cnt++;
      break;
    }
    case (0x1814): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e6c;
      cnt++;
      break;
    }
    case (0x1818): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e60;
      cnt++;
      break;
    }
    case (0x181c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e64;
      cnt++;
      break;
    }
    case (0x1820): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e58;
      cnt++;
      break;
    }
    case (0x1824): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e5c;
      cnt++;
      break;
    }
    case (0x1828): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e50;
      cnt++;
      break;
    }
    case (0x182c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e54;
      cnt++;
      break;
    }
    case (0x1830): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e48;
      cnt++;
      break;
    }
    case (0x1834): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e4c;
      cnt++;
      break;
    }
    case (0x1838): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e40;
      cnt++;
      break;
    }
    case (0x183c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e44;
      cnt++;
      break;
    }
    case (0x1840): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e38;
      cnt++;
      break;
    }
    case (0x1844): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e3c;
      cnt++;
      break;
    }
    case (0x1848): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e30;
      cnt++;
      break;
    }
    case (0x184c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e34;
      cnt++;
      break;
    }
    case (0x1850): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e28;
      cnt++;
      break;
    }
    case (0x1854): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e2c;
      cnt++;
      break;
    }
    case (0x1858): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e20;
      cnt++;
      break;
    }
    case (0x185c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e24;
      cnt++;
      break;
    }
    case (0x1860): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e18;
      cnt++;
      break;
    }
    case (0x1864): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e1c;
      cnt++;
      break;
    }
    case (0x1868): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e10;
      cnt++;
      break;
    }
    case (0x186c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e14;
      cnt++;
      break;
    }
    case (0x1870): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e08;
      cnt++;
      break;
    }
    case (0x1874): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e0c;
      cnt++;
      break;
    }
    case (0x1878): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e00;
      cnt++;
      break;
    }
    case (0x187c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e04;
      cnt++;
      break;
    }
    case (0x1880): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ef8;
      cnt++;
      break;
    }
    case (0x1884): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344efc;
      cnt++;
      break;
    }
    case (0x1888): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ef0;
      cnt++;
      break;
    }
    case (0x188c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ef4;
      cnt++;
      break;
    }
    case (0x1890): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ee8;
      cnt++;
      break;
    }
    case (0x1894): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344eec;
      cnt++;
      break;
    }
    case (0x1898): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ee0;
      cnt++;
      break;
    }
    case (0x189c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ee4;
      cnt++;
      break;
    }
    case (0x18a0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ed8;
      cnt++;
      break;
    }
    case (0x18a4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344edc;
      cnt++;
      break;
    }
    case (0x18a8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ed0;
      cnt++;
      break;
    }
    case (0x18ac): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ed4;
      cnt++;
      break;
    }
    case (0x18b0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ec8;
      cnt++;
      break;
    }
    case (0x18b4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ecc;
      cnt++;
      break;
    }
    case (0x18b8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ec0;
      cnt++;
      break;
    }
    case (0x18bc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ec4;
      cnt++;
      break;
    }
    case (0x18c0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344eb8;
      cnt++;
      break;
    }
    case (0x18c4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ebc;
      cnt++;
      break;
    }
    case (0x18c8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344eb0;
      cnt++;
      break;
    }
    case (0x18cc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344eb4;
      cnt++;
      break;
    }
    case (0x18d0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ea8;
      cnt++;
      break;
    }
    case (0x18d4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344eac;
      cnt++;
      break;
    }
    case (0x18d8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ea0;
      cnt++;
      break;
    }
    case (0x18dc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344ea4;
      cnt++;
      break;
    }
    case (0x18e0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e98;
      cnt++;
      break;
    }
    case (0x18e4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e9c;
      cnt++;
      break;
    }
    case (0x18e8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e90;
      cnt++;
      break;
    }
    case (0x18ec): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e94;
      cnt++;
      break;
    }
    case (0x18f0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e88;
      cnt++;
      break;
    }
    case (0x18f4): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e8c;
      cnt++;
      break;
    }
    case (0x18f8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e80;
      cnt++;
      break;
    }
    case (0x18fc): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344e84;
      cnt++;
      break;
    }
    case (0x1900): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f78;
      cnt++;
      break;
    }
    case (0x1904): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f7c;
      cnt++;
      break;
    }
    case (0x1908): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f70;
      cnt++;
      break;
    }
    case (0x190c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f74;
      cnt++;
      break;
    }
    case (0x1910): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f68;
      cnt++;
      break;
    }
    case (0x1914): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f6c;
      cnt++;
      break;
    }
    case (0x1918): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f60;
      cnt++;
      break;
    }
    case (0x191c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f64;
      cnt++;
      break;
    }
    case (0x1920): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f58;
      cnt++;
      break;
    }
    case (0x1924): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f5c;
      cnt++;
      break;
    }
    case (0x1928): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f50;
      cnt++;
      break;
    }
    case (0x192c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344f54;
      cnt++;
      break;
    }
    case (0x1930): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x12344fb7;
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
    case (0x19b): {
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
