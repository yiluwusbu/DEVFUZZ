///
/// hardware model for anydev
/// this device will read VID,PID.. from environment
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_anydev : public HWModel {
public:
  HWModel_anydev() : HWModel("anydev", 0x0000, 0x0000), probe_len(0) {
    _vid = EnvKnob("SFP_VID").getUInt16Value();
    _pid = EnvKnob("SFP_PID").getUInt16Value();
    _subvid = EnvKnob("SFP_SUBVID").getUInt16Value();
    _subpid = EnvKnob("SFP_SUBPID").getUInt16Value();
    _devclass = EnvKnob("SFP_PCI_CLASS").getUInt32Value();
    ;
    _revision = EnvKnob("SFP_REVISION").getUInt16Value();

    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_anydev(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > -1)
      return 0;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual uint16_t getVid() { return _vid; }
  virtual uint16_t getPid() { return _pid; }
  virtual uint16_t getSubVid() { return _subvid; }
  virtual uint16_t getSubPid() { return _subpid; }
  virtual uint32_t getClass() { return _devclass; }
  virtual uint16_t getRev() { return _revision; }

private:
  int probe_len;
  uint16_t _vid;
  uint16_t _pid;
  uint16_t _subvid;
  uint16_t _subpid;
  uint32_t _devclass;
  uint16_t _revision;
};
