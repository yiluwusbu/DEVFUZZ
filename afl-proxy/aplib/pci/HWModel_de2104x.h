///
/// hardware model for de2104x
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_de2104x : public HWModel {
public:
  HWModel_de2104x()
      : HWModel("de2104x", 0x1011, 0x0002, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0}, {PCI_BAR_TYPE_MMIO, 0x100}});
  }
  virtual ~HWModel_de2104x(){};
  virtual void restart_device() final { probe_len = 0; restart_cnt++; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 16)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xff00ffff;
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
      cnt++;
      break;
    }
    case (0x28): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x48): {
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
    }

    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};

Stage2HWModel * new_stage2_model_de2104x() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {0 ,      HWInput(0, 4,
              {},
              {0xffffffff, },
              {})
  },
  {96 ,       HWInput(96, 4,
                {0x2, 0x4, 0x200, },
                {},
                {})
  },
  {72 ,       HWInput(72, 4,
                {0x80000000, },
                {},
                {})
  },
  {48 ,       HWInput(48, 4,
                {0x2002, },
                {},
                {})
  },
  {40 ,       HWInput(40, 4,
                {0x5, 0x10, 0x80, 0xc0, 0x1000, 0x1010, 0x2000, 0x7e0000, },
                {0xffff, },
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(3072,16, {
  {0 , HWInput(0, 4,
          {0x2, 0x100, 0x200, 0x300, 0xc04, 0x8000, 0x40000000, 0x80000000, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(16, 3072, 8);
  model->setDMAReg(0x18, 0xc00);
  model->setDMAReg(0x20, 0xc00);  
  return model;
}
