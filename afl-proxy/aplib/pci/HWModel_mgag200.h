///
/// hardware model for mgag200
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_mgag200 : public HWModel {
public:
  HWModel_mgag200() : HWModel("mgag200", 0x102b, 0x520), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_mgag200(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
#if 0
    switch (addr) {
    case (0x1fdf): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1fcc): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0xfe;
      cnt++;
      break;
    }
    case (0x0): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1fd5): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x3c0a): {
      static int cnt;
      if (cnt <= 235)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 236)
        *((uint8_t *)dest) = 0xfd;
      if (cnt >= 237)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    }
#endif
    switch (addr) {
    case (0x3c0a): {
      static uint8_t cnt;
      *((uint8_t *)dest) = cnt++;
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

Stage2HWModel * new_stage2_model_mgag200() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {8149 ,         HWInput(8149, 4,
                  {0xff, },
                  {},
                  {})
  },
  {7702 ,         HWInput(7702, 4,
                  {0x1, },
                  {},
                  {})
  },
  {15370 ,          HWInput(15370, 4,
                  {0x1, },
                  {},
                  {})
  },
  {7700 ,         HWInput(7700, 4,
                  {0x8, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
