///
/// hardware model for ipmi_si
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_ipmi_si : public HWModel {
public:
  HWModel_ipmi_si()
      : HWModel("ipmi_si", 0x103c, 0x121a, 0, 0, 0xc0700), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_ipmi_si(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 22)
      return 0;
    switch (addr) {
    case (0x1): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0xc0;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x3e;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x3f;
      if (cnt == 5)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint8_t *)dest) = 0x3f;
      if (cnt == 7)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint8_t *)dest) = 0x3f;
      if (cnt == 9)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint8_t *)dest) = 0x3f;
      cnt++;
      break;
    }
    case (0x2): {
      static int cnt;
      if (cnt == 0)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 1)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 2)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 3)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 4)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 5)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 6)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 7)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 8)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 9)
        *((uint8_t *)dest) = 0x0;
      if (cnt == 10)
        *((uint8_t *)dest) = 0x0;
      cnt++;
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
