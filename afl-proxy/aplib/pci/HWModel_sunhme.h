///
/// hardware model for sunhme
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_sunhme : public HWModel {
public:
  HWModel_sunhme() : HWModel("sunhme", 0x108e, 0x1001, 0,0,0x020000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_sunhme(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 151)
      return 0;
    switch (addr)
    {
      case( 0x0 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x7010 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 16843009 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x700c ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 19 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 20 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 21 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 22 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 23 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 24 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 25 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 26 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 27 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 28 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 29 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 30 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 31 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x6330 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x632c ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x6328 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x6248 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 19 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 20 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 21 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 22 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 23 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 24 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 25 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 26 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 27 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 28 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 29 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 30 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 31 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 32 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 33 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 34 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 35 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 36 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 37 ) *((uint32_t *)dest) = 0 ;
    cnt++;}
    case( 0x624c ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    cnt++;}


    }
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual void *getUSBDesc() { return nullptr; }

private:
  int probe_len;
};

Stage2HWModel * new_stage2_model_sunhme() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {5 ,      HWInput(5, 1,
              {},
              {0x6, },
              {})
  },
  {24 ,       HWInput(24, 4,
                {},
                {},
                {0x0, 0x1, 0x10000, 0x10001, 0xffffffffffffffff, })
  },
  {12 ,       HWInput(12, 4,
                {0x10000, },
                {},
                {})
  },
  {520 ,        HWInput(520, 4,
                {0x1, },
                {},
                {})
  },
  {0 ,      HWInput(0, 4,
              {},
              {0x0, 0x70011, },
              {})
  },
  {776 ,        HWInput(776, 4,
                {0x1, },
                {},
                {})
  },
  {256 ,        HWInput(256, 4,
                {0x20, 0x80, 0x200, 0x400, 0x10000, 0x20000, 0x40000, 0x100000, 0x200000, 0x340000, 0x400000, 0x800000, 0x2000000, 0x4000000, 0x8000000, 0x10000000, 0x20000000, 0x3c000000, 0xfc7efefc, 0xfcf40680, },
                {},
                {0x0, 0x1, 0x40000000, 0x40000001, 0xffffffffffffffff, })
  },
  {1 ,      HWInput(1, 1,
              {},
              {0x0, 0xaa, },
              {})
  },
  {2 ,      HWInput(2, 1,
              {},
              {0x9, },
              {})
  },
  {16 ,       HWInput(16, 4,
                {0x100, 0x200, },
                {},
                {})
  },
  {3 ,      HWInput(3, 1,
              {},
              {0x4e, },
              {})
  },
  {4 ,      HWInput(4, 1,
              {},
              {0x41, },
              {})
  },
  {524 ,        HWInput(524, 4,
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
