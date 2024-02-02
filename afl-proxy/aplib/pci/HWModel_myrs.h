///
/// hardware model for myrs
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2022 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_myrs : public HWModel {
public:
  HWModel_myrs() : HWModel("myrs", 0x1069, 0x50, 0, 0, 0x010000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x4000}});
  }
  virtual ~HWModel_myrs(){};
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
