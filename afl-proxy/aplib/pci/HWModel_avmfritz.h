///
/// hardware model for avmfritz
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// fcpci -- need IRQ

#include "HWModel.h"

class HWModel_avmfritz : public HWModel {
public:
  HWModel_avmfritz() : HWModel("avmfritz", 0x1244, 0x0a00), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024},
              {PCI_BAR_TYPE_PIO, 256},
              {PCI_BAR_TYPE_MMIO, 128 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_avmfritz(){};
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
