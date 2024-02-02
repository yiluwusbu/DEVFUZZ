///
/// hardware model for isst_if_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_isst_if_pci : public HWModel {
public:
  HWModel_isst_if_pci() : HWModel("isst_if_pci", 0x8086, 0x3259), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO, 1024},
              {PCI_BAR_TYPE_PIO, 1024},
              {PCI_BAR_TYPE_PIO, 1024},
              {PCI_BAR_TYPE_PIO, 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_isst_if_pci(){};
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
