///
/// hardware model for vmxnet3
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_vmxnet3 : public HWModel {
public:
  HWModel_vmxnet3() : HWModel("vmxnet3", 0x15ad, 0x07b0), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_vmxnet3(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 6)
      return 0;
    switch (addr) {
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x2020202;
      cnt++;
      break;
    }
    case (0x8): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x1010101;
      cnt++;
      break;
    }
    case (0x20): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x28): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30): {
      static int cnt;
      if (cnt == 0)
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

Stage2HWModel * new_stage2_model_vmxnet3() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {8 ,      HWInput(8, 4,
              {0x1, },
              {},
              {})
  },
  {56 ,       HWInput(56, 4,
                {},
                {0x0, },
                {})
  },
  {32 ,       HWInput(32, 4,
                {0x1, 0x2, 0x3, },
                {0x0, },
                {0x0, 0x1, 0xffffffff, 0x100000000, 0xffffffffffffffff, })
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(16,16, {
  {0 , HWInput(0, 4,
          {},
          {0x0, 0x1, 0x2, 0x3, },
          {})
  },
  }),
  DMAInputModel(16,176, {
  {6 , HWInput(6, 2,
          {0x1, 0x3, },
          {0x0, 0x1, },
          {0x0, 0x1, 0x3, 0x4, 0xffffffffffffffff, })
  },
  }),
  DMAInputModel(16,256, {
  {80 , HWInput(80, 1,
          {},
          {0x0, },
          {})
  },
  }),
  DMAInputModel(16,800, {
  {696 , HWInput(696, 4,
          {0x3, 0x4, },
          {0x0, },
          {})
  },
  }),
  DMAInputModel(16,256, {
  {80 , HWInput(80, 1,
          {},
          {0x0, },
          {})
  },
  }),
  DMAInputModel(16,16, {
  {0 , HWInput(0, 8,
          {},
          {0x0, },
          {})
  },
  {8 , HWInput(8, 8,
          {0x4000, 0x100000000000, 0xffff00000000, 0x4000000000000, 0x6000000000000, 0x10000000000000, 0x20000000000000, 0x40000000000000, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(16, 16, 0, 4096);
  model->setDMAReg(0x10, 0x320);
  model->setDMABottomHalfReg(0x28, 0x10000);
  model->setDMABottomHalfReg(0x28, 0x5000);
  return model;
}
