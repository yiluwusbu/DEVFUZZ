///
/// hardware model for ems_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ems_pci : public HWModel {
public:
  HWModel_ems_pci() : HWModel("ems_pci", 0x110a, 0x2104), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_ems_pci(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 7)
      return 0;
    switch (addr) {
    case (0): {
      *((uint8_t *)dest) = 0x55;
      break;
    }
    case (4): {
      *((uint8_t *)dest) = 0xAA;
      break;
    }
    case (8): {
      *((uint8_t *)dest) = 0x01;
      break;
    }
    case (0xc): {
      *((uint8_t *)dest) = 0xCB;
      break;
    }
    case (0x10): {
      *((uint8_t *)dest) = 0x11;
      break;
    }
    case (0x47c): {
      *((uint8_t *)dest) = 0x80;
      break;
    }
    case (0x67c): {
      *((uint8_t *)dest) = 0x80;
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
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
