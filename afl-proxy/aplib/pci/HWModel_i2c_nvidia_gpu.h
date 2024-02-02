///
/// hardware model for i2c_nvidia_gpu
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_i2c_nvidia_gpu : public HWModel {
public:
  HWModel_i2c_nvidia_gpu()
      : HWModel("i2c_nvidia_gpu", 0x10de, 0x0000, 0, 0, 0x0c80ff),
        probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 4 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 4 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 4 * 1024 * 1024}});
  }
  virtual ~HWModel_i2c_nvidia_gpu(){};
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
