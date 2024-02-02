///
/// hardware model for pcwd_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_pcwd_pci : public HWModel {
public:
  HWModel_pcwd_pci() : HWModel("pcwd_pci", 0x11e3, 0x5030), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 0x100}});
  }
  virtual ~HWModel_pcwd_pci(){};
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
