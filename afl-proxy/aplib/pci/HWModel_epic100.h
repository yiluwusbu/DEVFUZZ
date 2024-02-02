///
/// hardware model for epic100
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_epic100 : public HWModel {
public:
  HWModel_epic100()
      : HWModel("epic100", 0x10b8, 0x0005, 0x1092, 0x0ab4, 0x020000),
        probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_epic100(){};
  virtual void restart_device() final { probe_len = 0; restart_cnt++;};
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 87)
      return 0;
    switch (addr) {
    case (0x40): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x44): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x48): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x30): {
      static int cnt; CHECK_RESET;
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
      if (cnt == 12)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x34): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0xff;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 11)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 12)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 21)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 22)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 23)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 24)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 25)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 26)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 27)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 28)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 29)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 30)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 31)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x10): {
      static int cnt; CHECK_RESET;
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
      if (cnt == 12)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 13)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 14)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 15)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 16)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 17)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 18)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 19)
        *((uint32_t *)dest) = 0x0;
      if (cnt == 20)
        *((uint32_t *)dest) = 0x0;
      cnt++;
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
  virtual void write(uint64_t data, uint64_t addr, size_t size, int bar) {
    bars[bar]->write(data, addr, size);
    // assuming page aligned though not true
    if ((addr == 0xc4) || (addr == 0x84)) {
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

Stage2HWModel * new_stage2_model_epic100() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {0 ,      HWInput(0, 4,
              {},
              {0xffff, },
              {})
  },
  {52 ,       HWInput(52, 4,
                {0x4000, },
                {0x0, 0xffff, },
                {})
  },
  {116 ,        HWInput(116, 4,
                {0x10, },
                {},
                {})
  },
  {4 ,      HWInput(4, 4,
              {0x8, 0xc, 0x100, 0xcad, 0x7000, 0x7300, 0x10000, },
              {0xffffffff, },
              {})
  },
  {48 ,       HWInput(48, 4,
                {0x1, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(4096,16, {
  {0 , HWInput(0, 4,
          {0x1, 0x6, 0x8, 0x10, 0x40, 0x1050, 0x2000, 0x2006, 0x8000, },
          {},
          {0x5fb, 0x5fc, 0x5fd, 0xffffffff, 0x100000000, })
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(16, 4096, 4);
  model->setDMAReg(0xc4, 0x1000);
  model->setDMAReg(0x84, 0x1000);

  return model;
}
