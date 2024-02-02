///
/// hardware model for saa7134
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_saa7134 : public HWModel {
public:
  HWModel_saa7134()
      : HWModel("saa7134", 0x1131, 0x7134, 0x1131, 0x2001), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_saa7134(){};
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

Stage2HWModel * new_stage2_model_saa7134() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {286 ,        HWInput(286, 1,
                {0x3, 0x40, },
                {},
                {})
  },
  {325 ,        HWInput(325, 1,
                {0x3, 0x5, },
                {},
                {})
  },
  {322 ,        HWInput(322, 1,
                {0x1, 0x2, },
                {},
                {})
  },
  {323 ,        HWInput(323, 1,
                {0x1, },
                {},
                {})
  },
  {1408 ,         HWInput(1408, 1,
                  {0x1, 0x8, },
                  {},
                  {})
  },
  {287 ,        HWInput(287, 1,
                {0x1, 0xe, 0x40, },
                {},
                {})
  },
  {716 ,        HWInput(716, 4,
                {0x4, 0x8, 0x20, 0x180, 0x4000, 0x8000, },
                {0x0, },
                {})
  },
  {384 ,        HWInput(384, 1,
                {},
                {},
                {0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0xff, 0x100, })
  },
  {436 ,        HWInput(436, 4,
                {0x40, 0x100, 0x40000, 0x400000, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
