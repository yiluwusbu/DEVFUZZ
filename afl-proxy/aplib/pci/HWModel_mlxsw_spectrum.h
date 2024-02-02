///
/// hardware model for mlxsw_spectrum
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// need MSI-X

#include "HWModel.h"

class HWModel_mlxsw_spectrum : public HWModel {
public:
  HWModel_mlxsw_spectrum()
      : HWModel("mlxsw_spectrum", 0x15b3, 0xcb84), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_mlxsw_spectrum(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 1000)
      return 0;
    switch (addr) {
    case (0xa1844): {
      *((uint32_t *)dest) = 0x5e000000;
      break;
    }
    case (0x71018): {
      *((uint32_t *)dest) = data_0x71018;
      data_0x71018 = 0;
      break;
    }
    default: {
      switch (size) {
      case (1):
        *((uint8_t *)dest) = rand();
        break;
      case (2):
        *((uint16_t *)dest) = rand();
        break;
      case (4):
        *((uint32_t *)dest) = rand();
        break;
      default:
        break;
      }
    }
    }

    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    switch (addr) {
    case (0x71018): {
      data_0x71018 = data;
      break;
    }
    default:
      break;
    }
  };

private:
  int probe_len;
  uint32_t data_0x71018;
};
