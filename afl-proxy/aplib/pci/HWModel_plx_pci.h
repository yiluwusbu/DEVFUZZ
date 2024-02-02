///
/// hardware model for plx_pci
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_plx_pci : public HWModel {
public:
  HWModel_plx_pci()
      : HWModel("plx_pci", 0x10b5, 0x9056, 0x12fe, 0x000e), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_plx_pci(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 100)
      return 0;
    switch (addr) {
    case (0x0):
    case (0x100): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x21;
      else if (cnt < 4)
        *((uint8_t *)dest) = 0x1;
      cnt = (cnt + 1) % 4;
      break;
    }
    case (0x102):
    case (0x2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0c;
      else if (cnt == 1)
        *((uint8_t *)dest) = 0x3c;
      cnt = (cnt + 1) % 2;
      break;
    }
    case (0x103):
    case (0x03): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0xe0;
      else if (cnt == 1)
        *((uint8_t *)dest) = 0x00;
      cnt = (cnt + 1) % 2;
      break;
    }
    case (0x6c): {
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
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

private:
  int probe_len;
};
