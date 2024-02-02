///
/// hardware model for tsi721
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
/// tsi721 - rapidio PCIe bridge - tsi721_enable_msix: ERROR Failed to enable
/// MSI-X (err=-28//
///

#include "HWModel.h"

class HWModel_tsi721 : public HWModel {
public:
  HWModel_tsi721() : HWModel("tsi721", 0x111d, 0x80ab), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_tsi721(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 1000)
      return 0;
    switch (addr) {
    case (0x5c): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x68): {
      *((uint32_t *)dest) = *((uint32_t *)&device_ram[0x68]);
      break;
    }
    case (0x158): {
      *((uint32_t *)dest) = 0x2;
      break;
    }
    case (0x41300): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x58000): {
      *((uint32_t *)dest) = *((uint32_t *)&device_ram[0x58000]);
      break;
    }
    case (0x58004): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x58008): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x5800c): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x58014): {
      *((uint32_t *)dest) = 0x0;
      break;
    }
    case (0x5803c): {
      *((uint32_t *)dest) = 0x0;
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
    case (0x68): {
      *((uint32_t *)&device_ram[0x68]) = data;
      break;
    }
    case (0x58000): {
      *((uint32_t *)&device_ram[0x58000]) = data;
      break;
    }
    default:
      break;
    }
  };

private:
  int probe_len;
  uint8_t device_ram[1024000];
};
