///
/// hardware model for nozomi
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_nozomi : public HWModel {
public:
  HWModel_nozomi() : HWModel("nozomi", 0x1931, 0x000c), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 8192}});
  }
  virtual ~HWModel_nozomi(){};
  virtual void restart_device() final { probe_len = 0; };

  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    return 0;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
