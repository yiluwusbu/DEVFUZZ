///
/// hardware model for ivtv
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ivtv : public HWModel {
public:
  HWModel_ivtv()
      : HWModel("ivtv", 0x4444, 0x0803, 0x1461, 0xa3cf), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_ivtv(){};
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

Stage2HWModel *new_stage2_model_ivtv() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {12 ,       HWInput(12, 4,
                {},
                {0x78123456, },
                {})
  },
  {2092 ,         HWInput(2092, 4,
                  {},
                  {0x0, },
                  {})
  },
  {8 ,      HWInput(8, 4,
              {},
              {0x56781234, },
              {})
  },
  {4 ,      HWInput(4, 4,
              {0x2, 0x3, 0x14, },
              {0x34567812, },
              {})
  },
  {10432 ,          HWInput(10432, 4,
                  {0x1, },
                  {},
                  {0x0, 0x1, 0x640000, 0x640001, 0xffffffffffffffff, })
  },
  {28684 ,          HWInput(28684, 4,
                  {0x1, },
                  {},
                  {})
  },
  {28680 ,          HWInput(28680, 4,
                  {0x1, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
