///
/// hardware model for alcor_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_alcor_pci : public HWModel {
public:
  HWModel_alcor_pci() : HWModel("alcor_pci", 0x1aea, 0x6601), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x100}});
  }
  virtual ~HWModel_alcor_pci(){};
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
