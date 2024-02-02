///
/// hardware model for earth_pt1
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// 5.15 not working

#include "HWModel.h"

class HWModel_earth_pt1 : public HWModel {
public:
  HWModel_earth_pt1() : HWModel("earth_pt1", 0x10ee, 0x211a), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_earth_pt1(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
    switch (addr) {
    case (0): {
      uint32_t v = *(uint32_t *)&device_ram[0];
      if (v == 0x00000000)
        *(uint32_t *)dest = 0x00000004;
      if (v == 0x00000002) {
        static uint32_t v2 = 0xffffffff;
        *(uint32_t *)dest = v2;
        v2 = ~v2;
      }
      if (v == 0x00000008)
        *(uint32_t *)dest = 0xa0000000;
      if (v == 0x01000000)
        *(uint32_t *)dest = 0x00000001;
      if (v == 0x02000000)
        *(uint32_t *)dest = 0x00000002;
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
    switch (addr) {
    case (0x0): {
      *((uint32_t *)&device_ram[0x0]) = data;
      break;
    }
    default:
      break;
    }
  };

private:
  int probe_len;
  uint8_t device_ram[1024000];
};

Stage2HWModel * new_stage2_model_earth_pt1() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {0 ,      HWInput(0, 4,
              {0x1, 0x2, 0x80, 0x20000000, 0x80000000, },
              {},
              {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
