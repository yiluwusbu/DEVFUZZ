///
/// hardware model for pegasus_notetaker
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"
#include "include/usb/desc.h"
#include "include/usb/usb.h"

#define USB_SFP_VID 0x0e20
#define USB_SFP_PID 0x0101

#define STRING_MANUFACTURER 1
#define STRING_PRODUCT 2
#define STRING_SERIALNUMBER 3
#define STRING_CONTROL 4

namespace pegasus_notetaker {
static USBDescStrings usb_sfp_stringtable = {
    usb_sfp_stringtable[STRING_MANUFACTURER] = "SFP",
    usb_sfp_stringtable[STRING_PRODUCT] = "USB SFP",
    usb_sfp_stringtable[STRING_SERIALNUMBER] = "sfpsfpsfpsfpsfpsfpsfp",
    usb_sfp_stringtable[STRING_CONTROL] = "sfpsfpsfp ctrl",
};

static USBDescIface desc_iface_sfp[] = {
    {.bInterfaceNumber = 0,
     .bNumEndpoints = 2,
     .bInterfaceClass = USB_CLASS_AUDIO,
     .bInterfaceSubClass = 0,
     .bInterfaceProtocol = 0,
     .iInterface = STRING_CONTROL,
     .eps = (USBDescEndpoint[]){
         {
             .bEndpointAddress = USB_DIR_IN | 0x01,
             .bmAttributes = USB_ENDPOINT_XFER_BULK,
             .wMaxPacketSize = 0x40,
             .bInterval = 1,
         },
         {
             .bEndpointAddress = USB_DIR_OUT | 0x02,
             .bmAttributes = USB_ENDPOINT_XFER_BULK,
             .wMaxPacketSize = 0x40,
             .bInterval = 1,
         },
     }}};

static USBDescDevice desc_device_sfp = {
    .bcdUSB = 0x0200,
    .bDeviceClass = USB_CLASS_AUDIO,
    .bMaxPacketSize0 = 0x40,
    .bNumConfigurations = 1,
    .confs = (USBDescConfig[]){{
        .bNumInterfaces = 1,
        .bConfigurationValue = 1,
        .iConfiguration = 7,
        .bmAttributes = USB_CFG_ATT_ONE | USB_CFG_ATT_SELFPOWER,
        .bMaxPower = 0x32,
        // TODO: need to randomize this part
        .nif = ARRAY_SIZE(desc_iface_sfp),
        .ifs = desc_iface_sfp,
    }},
};

static USBDesc desc = {
    .id =
        {
            .idVendor = USB_SFP_VID,
            .idProduct = USB_SFP_PID,
            .bcdDevice = 0,
            .iManufacturer = STRING_MANUFACTURER,
            .iProduct = STRING_PRODUCT,
            .iSerialNumber = STRING_SERIALNUMBER,
        },
    // full speed usb device
    .full = &desc_device_sfp,
    .str = usb_sfp_stringtable,
};

static void *hw_model_usb_gen_desc() { return &desc; }
} // namespace pegasus_notetaker
class HWModel_pegasus_notetaker : public HWModel {
public:
  HWModel_pegasus_notetaker()
      : HWModel("pegasus_notetaker", USB_SFP_VID, USB_SFP_PID), probe_len(0) {}
  virtual ~HWModel_pegasus_notetaker(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    uint8_t *ptr = &(device_ram[addr]);
    switch (size) {
    case (1):
      *((uint8_t *)dest) = *(uint8_t *)(ptr);
      break;
    case (2):
      *((uint16_t *)dest) = *(uint16_t *)(ptr);
      break;
    case (4):
      *((uint32_t *)dest) = *(uint32_t *)(ptr);
      break;
    case (8):
      *((uint64_t *)ptr) = *(uint64_t *)(ptr);
      break;
    default:
      assert(0);
    }
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final {
    uint8_t *ptr = &device_ram[addr];
    switch (size) {
    case (1):
      *ptr = (uint8_t)((data)&0xff);
      break;
    case (2):
      *((uint16_t *)ptr) = (uint16_t)((data)&0xffff);
      break;
    case (4):
      *((uint32_t *)ptr) = (uint32_t)((data)&0xffffffff);
      break;
    case (8):
      *((uint64_t *)ptr) = (uint64_t)(data);
      break;
    default:
      assert(0);
    }
  };

  virtual void *getUSBDesc() {
    return pegasus_notetaker::hw_model_usb_gen_desc();
  }

private:
  int probe_len;
  uint8_t device_ram[1024000];
};
#undef USB_SFP_VID
#undef USB_SFP_PID
#undef STRING_MANUFACTURER
#undef STRING_PRODUCT
#undef STRING_SERIALNUMBER
#undef STRING_CONTROL
