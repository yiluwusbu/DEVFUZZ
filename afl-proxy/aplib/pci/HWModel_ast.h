///
/// hardware model for ast
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ast : public HWModel {
public:
  HWModel_ast() : HWModel("ast", 0x1a03, 0x2000, 0, 0, 0x30000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_ast(){};
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

Stage2HWModel * new_stage2_model_ast() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {65792 ,          HWInput(65792, 4,
                  {},
                  {0xa8, },
                  {})
  },
  {90 ,       HWInput(90, 4,
                {0x8, },
                {},
                {})
  },
  {85 ,       HWInput(85, 4,
                {0x1, 0x80, },
                {0x4, 0x8, 0xc, },
                {})
  },
  {65564 ,          HWInput(65564, 4,
                  {0x800, 0x8000000, },
                  {},
                  {})
  },
  {66304 ,          HWInput(66304, 4,
                  {0xa0000, },
                  {},
                  {})
  },
  {73728 ,          HWInput(73728, 4,
                  {},
                  {0x1, },
                  {})
  },
  {65824 ,          HWInput(65824, 4,
                  {},
                  {0x5061, },
                  {0x0, 0x1, 0x3, 0x4, 0xffffffffffffffff, })
  },
  {73852 ,          HWInput(73852, 4,
                  {0x100, 0x200, 0x300, },
                  {},
                  {})
  },
  {61440 ,          HWInput(61440, 4,
                  {0x10, },
                  {},
                  {})
  },
  {61444 ,          HWInput(61444, 4,
                  {0x1e600000, 0x1e6e0000, 0x1e720000, 0x1e780000, 0x80100000, 0x88100000, 0x90100000, 0xa0100000, },
                  {},
                  {0x0, 0x1, 0x2, 0xffffffff, 0x100000000, })
  },
  {65648 ,          HWInput(65648, 4,
                  {0x1, 0x40, 0x1000, 0x2000, 0x3000, },
                  {},
                  {})
  },
  {65536 ,          HWInput(65536, 4,
                  {},
                  {0x1, 0x292a2b2c, 0x35363738, 0x41424344, },
                  {})
  },
  {73840 ,          HWInput(73840, 4,
                  {0x800000, 0x1000000, 0x2000000, 0x8000000, },
                  {},
                  {})
  },
  {61456 ,          HWInput(61456, 4,
                  {0x2, },
                  {},
                  {})
  },
  {65632 ,          HWInput(65632, 4,
                  {0x1, },
                  {},
                  {})
  },
  {61460 ,          HWInput(61460, 4,
                  {0xff0000, },
                  {},
                  {})
  },
  {65636 ,          HWInput(65636, 4,
                  {},
                  {},
                  {0x5f, 0x60, 0x61, 0xffffffff, 0x100000000, })
  },
  {65540 ,          HWInput(65540, 4,
                  {0x1, 0x2, 0x3, 0x40, 0x80000, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
