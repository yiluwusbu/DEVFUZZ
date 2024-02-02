///
/// hardware model for atl1
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// need MSI

#include "HWModel.h"

class HWModel_atl1 : public HWModel {
public:
  HWModel_atl1()
      : HWModel("atl1", 0x1969, 0x1048, 0, 0, 0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_atl1(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 28)
      return 0;
    switch (addr) {
    case (0x1402): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1400): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x140c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1410): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x200): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x58): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x9393;
      cnt++;
      break;
    }
    case (0x208): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xa5a5a5a5;
      cnt++;
      break;
    }
    case (0x1488): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x148c): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x101;
      cnt++;
      break;
    }
    case (0x1414): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x1008): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4): {
      static int cnt;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)dest) = 0;
        break;
      case (2):
        *((uint16_t *)dest) = 0;
        break;
      case (4):
        *((uint32_t *)dest) = 0;
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
  virtual void write(uint64_t data, uint64_t addr, size_t size, int bar) {
    bars[bar]->write(data, addr, size);
    // assuming page aligned though not true
    if (addr == 0x154c) {
      auto p = std::make_pair(data, 32 * 4 * 4);
      dmasgLock.lock();
      // dmasg.clear();
      dmasg.push_back(p);
      dmasgLock.unlock();
    }
  }

private:
  int probe_len;
};


Stage2HWModel * new_stage2_model_atl1() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {112 ,        HWInput(112, 4,
                {0x5a, },
                {},
                {})
  },
  {5632 ,         HWInput(5632, 4,
                  {0x10000000, },
                  {},
                  {})
  },
  {5136 ,         HWInput(5136, 4,
                  {},
                  {0x0, },
                  {})
  },
  {88 ,       HWInput(88, 4,
                {0x6c00, },
                {},
                {})
  },
  {108 ,        HWInput(108, 4,
                {0x80000000, },
                {},
                {})
  },
  {520 ,        HWInput(520, 4,
                {0x5a, },
                {},
                {})
  },
  {512 ,        HWInput(512, 4,
                {0x800, 0x2000, },
                {},
                {})
  },
  {5140 ,         HWInput(5140, 4,
                  {0x4, 0x800, 0x4000, 0x8000, 0xc000, 0x8800000, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  return model;
}
