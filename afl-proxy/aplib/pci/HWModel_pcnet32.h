///
/// hardware model for pcnet32
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_pcnet32 : public HWModel {
public:
  HWModel_pcnet32()
      : HWModel("pcnet32", 0x1022, 0x2000, 0, 0, 0x0200), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_pcnet32(){};
  virtual void restart_device() final { probe_len = 0; restart_cnt++; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 40)
      return 0;
    switch (addr) {
    case (0x14): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x10): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x4;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x3;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x243;
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
        *((uint16_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x12): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x58;
      cnt++;
      break;
    }
    case (0x0): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x2): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x5): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x16): {
      static int cnt;
      CHECK_RESET;
      if (cnt == 0)
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

Stage2HWModel *new_stage2_model_pcnet32() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {16 ,       HWInput(16, 4,
                {0x1, 0x3, 0x4, 0x100, 0xdf00, 0xdf00, 0xdf00 },
                {0xffff},
                {})
  },
  {22 ,       HWInput(22, 2,
                {0x20, 0x40, 0x80, 0x800, 0x4000, },
                {0xc0, 0xffff, },
                {})
  },
  {28 ,       HWInput(28, 4,
                {0x20, 0x40, 0x80, 0x800, 0x4000, },
                {0xc0, 0xffff, },
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(0x100, 16, {
  {0 , HWInput(0, 4,
          {},
          {0x0, },
          {})
  },
  {8 , HWInput(8, 4,
          {0x4000000, 0x8000000, 0x10000000, 0x40000000, },
          {},
          {0x0, 0x1, 0x40, 0x41, 0x60b, 0x60c, 0x60d, 0xffffffff, 0x100000000, 0xffffffffffffffff, })
  },
  {6 , HWInput(6, 2,
          {0x100, 0x400, 0x800, 0x1000, 0x1800, 0x2000, 0x4000, 0x8000, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  // model->setSecondaryDMAInfo(16, 0x200, 0);
  model->setSecondaryDMAInfo(28, 0x1c, 24, 0x100);
  model->setSecondaryDMAInfo(28, 0x1c, 20, 0x100);
  model->setDMATopHalfReg(0x10, 0x1c);
  model->setDMABottomHalfReg(0x10, 0x1c);
  return model;
}
