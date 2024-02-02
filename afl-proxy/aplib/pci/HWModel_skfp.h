///
/// hardware model for skfp
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// - fddi0

#include "HWModel.h"

class HWModel_skfp : public HWModel {
public:
  HWModel_skfp() : HWModel("skfp", 0x1148, 0x4000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_skfp(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > -1)
      return 0;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};

Stage2HWModel *new_stage2_model_skfp() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {960 ,        HWInput(960, 4,
                {0x7800, 0xf800, },
                {},
                {})
  },
  {328 ,        HWInput(328, 4,
                {0x8, },
                {},
                {})
  },
  {392 ,        HWInput(392, 4,
                {0x20, 0x30, },
                {},
                {})
  },
  {12 ,       HWInput(12, 4,
                {},
                {0x0, },
                {})
  },
  {8 ,      HWInput(8, 4,
              {0x1, 0x10, 0x22, 0x1000, 0x2000, 0x8000, 0x10000, 0x20000, 0x40000, 0x80000, 0x100000, 0x200000, 0x400000, 0x7f9011, 0x7fb033, },
              {},
              {})
  },
  {1600 ,         HWInput(1600, 4,
                  {0x7800, 0xf800, },
                  {},
                  {})
  },
  {1028 ,         HWInput(1028, 4,
                  {0x700, 0x7000, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
