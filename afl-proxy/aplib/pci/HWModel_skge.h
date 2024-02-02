///
/// hardware model for skge
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_skge : public HWModel {
public:
  HWModel_skge()
      : HWModel("skge", 0x10b7, 0x1700, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_skge(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 7)
      return 0;
    switch (addr) {
    case (0x4): {
      *((uint16_t *)dest) = 0x0;
      break;
    }
    case (0x119): {
      *((uint8_t *)dest) = 0x0;
      break;
    }
    case (0x11b): {
      *((uint8_t *)dest) = 0xa;
      break;
    }
    case (0x11c): {
      *((uint8_t *)dest) = 0xfc;
      break;
    }
    case (0x11d): {
      *((uint8_t *)dest) = 0x0;
      break;
    }
    case (0x2400): {
      *((uint16_t *)dest) = 0x3030;
      break;
    }
    case (0x3400): {
      *((uint16_t *)dest) = 0x3030;
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

Stage2HWModel * new_stage2_model_skge() {
  unordered_map<int, HWInput> mmio_mdl =
  {
    {3848 ,         HWInput(3848, 1,
                    {0x2, 0x8, },
                    {},
                    {})
    },
    {3976 ,         HWInput(3976, 1,
                    {0x2, 0x8, },
                    {},
                    {})
    },
    {24 ,       HWInput(24, 4,
                  {0x2002, 0x10080, 0x80000, 0x200000, 0x800000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x80000000, },
                  {},
                  {0x0, 0x1, 0x2, 0x3, 0xffffffffffffffff, })
    },
    {8 ,      HWInput(8, 4,
                {0x80000000, },
                {},
                {})
    },
    {291 ,        HWInput(291, 1,
                  {},
                  {0x0, },
                  {})
    },
    {332 ,        HWInput(332, 4,
                  {},
                  {0x0, },
                  {})
    },
    {16 ,       HWInput(16, 4,
                  {0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x400, 0xc00, 0x1000, 0x2000, },
                  {},
                  {})
    },
    {328 ,        HWInput(328, 4,
                  {0x4, },
                  {},
                  {})
    },
  };

  vector<DMAInputModel> dma_mdl = {
    DMAInputModel(0x5000,32, {
    {0 , HWInput(0, 4,
            {0x80000000, 0x20000000,},
            {},
            {0x0, 0x1, 0x80, 0x81, 0xffffffffffffffff, })
    },
    {16 , HWInput(16, 4,
            {0x2, 0x8, 0x810, },
            {},
            {})
    },
    }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(32, 0x5000, 8);
  model->setDMAReg(0x420, 0x5000);
  return model;
}
