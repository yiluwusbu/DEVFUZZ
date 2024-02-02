///
/// hardware model for mxser
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_mxser : public HWModel {
public:
  HWModel_mxser() : HWModel("mxser", 0x1393, 0x0001), probe_len(0) {
    setupBar({
        {PCI_BAR_TYPE_MMIO, 0},
        {PCI_BAR_TYPE_MMIO, 0},
        {PCI_BAR_TYPE_PIO, 0x100},
        {PCI_BAR_TYPE_PIO, 0x20},
    });
  }
  virtual ~HWModel_mxser(){};
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
