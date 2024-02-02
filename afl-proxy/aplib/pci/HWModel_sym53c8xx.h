///
/// hardware model for sym53c8xx
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2022 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_sym53c8xx : public HWModel {
public:
  HWModel_sym53c8xx()
      : HWModel("sym53c8xx", 0x1000, 0x1, 0, 0, 0x010000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x4000},
              {PCI_BAR_TYPE_MMIO, 0x4000},
              {PCI_BAR_TYPE_MMIO, 0x4000},
              {PCI_BAR_TYPE_MMIO, 0x4000}});
  }
  virtual ~HWModel_sym53c8xx(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > -1)
      return 0;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
