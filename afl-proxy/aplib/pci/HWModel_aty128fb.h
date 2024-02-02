///
/// hardware model for aty128fb
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_aty128fb : public HWModel {
public:
  HWModel_aty128fb() : HWModel("aty128fb", 0x1002, 0x4c45), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_aty128fb(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    addr = addr % 1024000;
    if (probe_len > 10000)
      return 0;
    switch (addr) {
    case (0x10): {
      *((uint32_t *)dest) = *(uint32_t *)&device_ram[addr];
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
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    addr = addr % 1024000;
    switch (addr) {
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)&device_ram[addr]) = data;
        break;
      case (2):
        *((uint16_t *)&device_ram[addr]) = data;
        break;
      case (4):
        *((uint32_t *)&device_ram[addr]) = data;
        break;
      default:
        break;
      }
      break;
    }
    }
  };

private:
  int probe_len;
  uint8_t device_ram[1024000];
};

Stage2HWModel * new_stage2_model_aty128fb() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {1 ,      HWInput(1, 1,
              {},
              {0xaa, },
              {})
  },
  {16 ,       HWInput(16, 4,
                {},
                {0x55555555, },
                {})
  },
  {5952 ,         HWInput(5952, 4,
                  {0x80000000, },
                  {},
                  {0x3e, 0x3f, 0x40, 0xffffffff, 0x100000000, })
  },
  {12 ,       HWInput(12, 4,
                {0x8000, },
                {},
                {})
  },
  {320 ,        HWInput(320, 4,
                {0x3, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
