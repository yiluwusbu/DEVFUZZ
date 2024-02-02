///
/// hardware model for mISDNinfineon
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// qs1000.1: IRQ(11) got no requests during init 1

#include "HWModel.h"

class HWModel_mISDNinfineon : public HWModel {
public:
  HWModel_mISDNinfineon()
      : HWModel("mISDNinfineon", 0x1048, 0x1000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 128},
              {PCI_BAR_TYPE_PIO, 128},
              {PCI_BAR_TYPE_PIO, 128},
              {PCI_BAR_TYPE_PIO, 128},
              {PCI_BAR_TYPE_PIO, 128},
              {PCI_BAR_TYPE_PIO, 128}});
  }
  virtual ~HWModel_mISDNinfineon(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 761)
      return 0;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
