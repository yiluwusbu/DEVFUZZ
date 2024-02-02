///
/// hardware model for ksz884x
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ksz884x : public HWModel {
public:
  HWModel_ksz884x() : HWModel("ksz884x", 0x16c6, 0x8841), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x1000}});
  }
  virtual ~HWModel_ksz884x(){};
  virtual void restart_device() final { probe_len = 0; restart_cnt++; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 106)
      return 0;
    switch (addr) {
    case (0x400): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x8800;
      cnt++;
      break;
    }
    case (0x200): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x201): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x202): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x203): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x204): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x205): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint8_t *)dest) = 0xff;
      cnt++;
      break;
    }
    case (0x406): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
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
      cnt++;
      break;
    }
    case (0x402): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x404): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x500): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
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
      cnt++;
      break;
    }
    case (0x520): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
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
      cnt++;
      break;
    }
    case (0x540): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x502): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x522): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x542): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint16_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x28): {
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
      cnt++;
      break;
    }
    case (0x4a0): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
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
      cnt++;
      break;
    }
    case (0x4a8): {
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
      cnt++;
      break;
    }
    case (0x504): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x524): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x544): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x512): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x532): {
      static int cnt; CHECK_RESET;
      if (cnt == 0)
        *((uint16_t *)dest) = 0x0;
      cnt++;
      break;
    }
    }
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};


Stage2HWModel * new_stage2_model_ksz884x() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {0 ,      HWInput(0, 4,
              {0x1, },
              {},
              {})
  },
  {1026 ,         HWInput(1026, 2,
                  {0x3000, },
                  {},
                  {})
  },
  {44 ,       HWInput(44, 4,
                {0x2000000, 0x4000000, 0x8000000, 0x20000000, 0x50000000, 0x80000000, },
                {0x0, },
                {})
  },
  {1024 ,         HWInput(1024, 2,
                  {0xc, 0x8800, 0x8810, },
                  {},
                  {})
  },
  {1192 ,         HWInput(1192, 4,
                  {0x80000, 0x40000000, },
                  {},
                  {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(0x810,16, {
  {0 , HWInput(0, 4,
          {0x2000000, 0x60000000, 0x80000000, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setSecondaryDMAInfo(16, 0x810, 8, 4096);
  model->setDMAReg(0x14, 0x810);
  return model;
}
