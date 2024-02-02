///
/// hardware model for cirrus
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_cirrus : public HWModel {
public:
  HWModel_cirrus()
      : HWModel("cirrus", 0x1013, 0x00b8, 0x1af4, 0x1100), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_cirrus(){};
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

Stage2HWModel *new_stage2_model_cirrus() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {975 ,        HWInput(975, 1,
                {0x3, 0x8, },
                {},
                {})
  },
  {965 ,        HWInput(965, 1,
                {0x8, 0x10, 0x18, },
                {},
                {})
  },
  {981 ,        HWInput(981, 1,
                {0x80, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
