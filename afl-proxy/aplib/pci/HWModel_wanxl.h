///
/// hardware model for wanxl
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_wanxl : public HWModel {
public:
  HWModel_wanxl() : HWModel("wanxl", 0x1176, 0x0301), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_wanxl(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 10)
      return 0;
    switch (addr) {
    case (0x40): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x44): {
      *((uint32_t *)dest) = 0x0;
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

Stage2HWModel * new_stage2_model_wanxl() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {64 ,       HWInput(64, 4,
                {0x80, 0xc0, },
                {0x0, },
                {})
  },
  {68 ,       HWInput(68, 4,
                {},
                {0x0, },
                {})
  },
  {84 ,       HWInput(84, 4,
                {},
                {0x0, },
                {})
  },
  {100 ,        HWInput(100, 4,
                {0x10, },
                {0x0, },
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
