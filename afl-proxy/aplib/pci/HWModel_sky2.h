///
/// hardware model for sky2
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_sky2 : public HWModel {
public:
  HWModel_sky2() : HWModel("sky2", 0x1148, 0x9000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_sky2(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 9)
      return 0;
    switch (addr) {
    case (0x100):
      *((uint32_t *)dest) = 0x0;
      break;
    case (0x104):
      *((uint16_t *)dest) = 0x0;
      break;
    case (0x119):
      *((uint8_t *)dest) = 0x52;
      break;
    case (0x11a):
      *((uint8_t *)dest) = 0x0;
      break;
    case (0x11b):
      *((uint8_t *)dest) = 0xb3;
      break;
    case (0x11c):
      *((uint8_t *)dest) = 0x0;
      break;
    case (0x11e):
      *((uint8_t *)dest) = 0x0;
      break;
    case (0x1c06):
      *((uint16_t *)dest) = 0x0;
      break;
    case (0x280c):
      *((uint16_t *)dest) = 0x0;
      break;
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

Stage2HWModel * new_stage2_model_sky2() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {3976 ,         HWInput(3976, 1,
                  {0x2, 0x8, 0x10, 0x20, },
                  {},
                  {})
  },
  {8 ,      HWInput(8, 4,
              {},
              {0x0, },
              {})
  },
  {3768 ,         HWInput(3768, 1,
                  {},
                  {0x2, },
                  {})
  },
  {16 ,       HWInput(16, 4,
                {0x2000000, },
                {},
                {})
  },
  {3800 ,         HWInput(3800, 1,
                  {},
                  {0x2, },
                  {})
  },
  {4 ,      HWInput(4, 4,
              {0x10000, },
              {},
              {})
  },
  {3784 ,         HWInput(3784, 1,
                  {},
                  {0x2, },
                  {})
  },
  {28 ,       HWInput(28, 4,
                {0x2000000, },
                {0x0, },
                {0x0, 0x1, 0x2, 0x3, 0xffffffffffffffff, })
  },
  {286 ,        HWInput(286, 1,
                {0x3, },
                {},
                {})
  },
  {282 ,        HWInput(282, 1,
                {0x7, },
                {},
                {0x0, 0x1, 0x10, 0x11, 0xffffffffffffffff, })
  },
  {14464 ,          HWInput(14464, 2,
                  {0x10, },
                  {0xffff, },
                  {})
  },
  {3848 ,         HWInput(3848, 1,
                  {0x2, 0x8, 0x10, 0x20, },
                  {},
                  {})
  },
  {281 ,        HWInput(281, 1,
                {},
                {0x4c, 0x50, 0x53, },
                {})
  },
  {14468 ,          HWInput(14468, 2,
                  {},
                  {0x0, 0x141, 0xc91, },
                  {})
  },
  {285 ,        HWInput(285, 1,
                {0x80, },
                {},
                {})
  },
  {7524 ,         HWInput(7524, 2,
                  {0x3, },
                  {},
                  {})
  },
  {36 ,       HWInput(36, 4,
                {0x10, 0x20, 0x1000, 0x80000d0d, },
                {},
                {})
  },
  {284 ,        HWInput(284, 1,
                {},
                {0x0, },
                {0x0, 0x1, 0x4, 0x5, 0xffffffffffffffff, })
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(0x4000,8, {
  {7 , HWInput(7, 1,
          {0x60, 0x62, 0x64, 0x65, 0x66, 0x68, 0x80, },
          {},
          {})
  },
  {0 , HWInput(0, 4,
          {0x100, 0x187b, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(8, 8192, 0);
  model->setDMAReg(0xe88, 0x4000);
  model->setDMAReg(0x6d8, 0x400);
  model->setDMAReg(0x458, 0x2000);  
  return model;
}
