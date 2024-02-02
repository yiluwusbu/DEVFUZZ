///
/// hardware model for nosy
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2022 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_nosy : public HWModel {
public:
  HWModel_nosy() : HWModel("nosy", 0x104c, 0x8000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 0x1000}});
  }
  virtual ~HWModel_nosy(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 3)
      return 0;
    switch (addr) {
    case (0x40): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0x4c): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0x0;
      cnt++;
      break;
    }
    case (0xf04): {
      static int cnt;
      if (cnt == 0)
        *((uint32_t *)dest) = 0xbf;
      cnt++;
      break;
    }
    }
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual void write(uint64_t data, uint64_t addr, size_t size, int bar) {
    bars[bar]->write(data, addr, size);
    // assuming page aligned though not true
    if (addr == 0x104) {
      auto p = std::make_pair(data, 32 * 4 * 4);
      dmasgLock.lock();
      // dmasg.clear();
      dmasg.push_back(p);
      dmasgLock.unlock();
    }
  }
  virtual void feedRandomDMAData() {
    lockDMASG();
    for (auto p : dmasg) {
      uint64_t addr = p.first;
      uint64_t len = p.second;
      writeRandomDataToPhyMemGeneric(addr, len);
    }
    unlockDMASG();
  };

private:
  int probe_len;
};
