///
/// hardware model for farsync
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_farsync : public HWModel {
public:
  HWModel_farsync() : HWModel("farsync", 0x1619, 0x0400), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_farsync(){};
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

Stage2HWModel *new_stage2_model_farsync() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {19344 ,          HWInput(19344, 4,
                  {},
                  {0x12345678, },
                  {})
  },
  {18752 ,          HWInput(18752, 1,
                  {},
                  {0x0, 0x1, 0xff, },
                  {})
  },
  {18964 ,          HWInput(18964, 4,
                  {},
                  {0x0, },
                  {})
  },
  {19301 ,          HWInput(19301, 1,
                  {},
                  {0x0, },
                  {})
  },
  {18754 ,          HWInput(18754, 2,
                  {},
                  {0x18, },
                  {})
  },
  {18753 ,          HWInput(18753, 1,
                  {},
                  {0x1, },
                  {})
  },
  {19234 ,          HWInput(19234, 1,
                  {},
                  {0x0, },
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
