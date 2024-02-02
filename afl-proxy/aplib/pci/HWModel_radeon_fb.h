///
/// hardware model for radeon_fb
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// need VGA BIOS

#include "HWModel.h"

class HWModel_radeon_fb : public HWModel {
public:
  HWModel_radeon_fb()
      : HWModel("radeon_fb", 0x1002, 0x4147, 0, 0, 0x30000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_radeon_fb(){};
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


Stage2HWModel *new_stage2_model_radeon_fb() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {1 ,      HWInput(1, 1,
              {},
              {0xaa, },
              {})
  },
  {248 ,        HWInput(248, 4,
                {0x1f000000, },
                {},
                {})
  },
  {348 ,        HWInput(348, 4,
                {0x1f000000, },
                {},
                {})
  },
  {12 ,       HWInput(12, 4,
                {0x1, 0x2, 0x3, 0x4, 0x6, 0x7, 0x8000, 0x200000, },
                {},
                {})
  },
  {3648 ,         HWInput(3648, 4,
                  {0x40, 0x7e, 0x80000000, },
                  {},
                  {0x0, 0x1, 0x6, 0x7, 0x9, 0xa, 0xb, 0x14, 0x15, 0x1f, 0x20, 0xffffffffffffffff, })
  },
  {320 ,        HWInput(320, 4,
                {0x1, 0x2, 0x3, 0x4, 0x8, },
                {},
                {})
  },
  {648 ,        HWInput(648, 4,
                {0x3, 0x4, },
                {},
                {})
  },
  {336 ,        HWInput(336, 4,
                {0x3, },
                {},
                {})
  },
  {224 ,        HWInput(224, 4,
                {0xe0000, 0xf0000, },
                {},
                {0x0, 0x1, 0x20001, 0x20002, 0xffffffffffffffff, })
  },
  {5908 ,         HWInput(5908, 4,
                  {0x80000000, },
                  {},
                  {})
  },
  {32 ,       HWInput(32, 4,
                {0x4, },
                {},
                {})
  },
  {720 ,        HWInput(720, 4,
                {0x1, 0x80001, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
