///
/// hardware model for w6692
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// NEED IRQ otherwise will get
/// w6692.1: IRQ(11) getting no IRQs during init 3

#include "HWModel.h"

class HWModel_w6692 : public HWModel {
public:
  HWModel_w6692() : HWModel("w6692", 0x0675, 0x1702), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 256}, {PCI_BAR_TYPE_PIO, 256}});
  }
  virtual ~HWModel_w6692(){};
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
