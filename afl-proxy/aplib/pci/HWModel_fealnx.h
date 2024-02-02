///
/// hardware model for fealnx
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_fealnx : public HWModel {
public:
  HWModel_fealnx() : HWModel("fealnx", 0x1516, 0x0800), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_fealnx(){};
  virtual void restart_device() final { probe_len = 0; restart_cnt++; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 159)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x5): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x40): {
      static int cnt; CHECK_RESET;
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
        *((uint32_t *)dest) = 0x2020202;
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
        *((uint32_t *)dest) = 0xfc;
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
        *((uint32_t *)dest) = 0x2020202;
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
    if ((addr == 0x2c) || (addr == 0x30)) {
      auto p = std::make_pair(data, 4096);
      dmasgLock.lock();
      // dmasg.clear();
      dmasg.push_back(p);
      dmasgLock.unlock();
    }
  }

private:
  int probe_len;
};

Stage2HWModel * new_stage2_model_fealnx() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {80 ,       HWInput(80, 4,
                {},
                {0xd0000302, },
                {})
  },
  {52 ,       HWInput(52, 4,
                {0x4, 0x24, 0x40, 0x400, },
                {},
                {})
  },
  {76 ,       HWInput(76, 4,
                {0x40000, },
                {},
                {})
  },
  {24 ,       HWInput(24, 4,
                {0x8000, 0x80000, 0x4008000, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(240,40, {
  {0 , HWInput(0, 4,
          {0x4, 0x8, 0x60, 0x80, 0x100, 0x400, 0x800, 0xc00, 0x1000, 0x2000, 0x3d00, 0x80000000, },
          {},
          {})
  },
  {4 , HWInput(4, 4,
          {0x20000000, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(40, 240, 8);
  model->setDMAReg(0x30, 0x1e0);
  model->setDMAReg(0x2c, 0xf0);
  return model;
}
