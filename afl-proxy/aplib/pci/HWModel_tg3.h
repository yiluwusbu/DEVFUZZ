///
/// hardware model for tg3
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_tg3 : public HWModel {
public:
  HWModel_tg3() : HWModel("tg3", 0x106b, 0x1645, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_tg3(){};
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

Stage2HWModel * new_stage2_model_tg3() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {33536 ,          HWInput(33536, 4,
                  {},
                  {0x0, },
                  {})
  },
  {16400 ,          HWInput(16400, 4,
                  {0x2, },
                  {},
                  {})
  },
  {8 ,      HWInput(8, 4,
              {0x11110, 0x22220, },
              {},
              {})
  },
  {236 ,        HWInput(236, 4,
                {0x1, },
                {},
                {})
  },
  {16384 ,          HWInput(16384, 4,
                  {},
                  {0x41504521, },
                  {})
  },
  {17152 ,          HWInput(17152, 4,
                  {0x80000000, },
                  {},
                  {})
  },
  {16396 ,          HWInput(16396, 4,
                  {0x100, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
