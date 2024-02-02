///
/// hardware model for ds2490
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

#include "include/usb/desc.h"
#include "include/usb/usb.h"

#define USB_SFP_VID 0x4fa
#define USB_SFP_PID 0x2490

#define STRING_MANUFACTURER 1
#define STRING_PRODUCT 2
#define STRING_SERIALNUMBER 3
#define STRING_CONTROL 4

namespace ds2490 {
static USBDescStrings usb_sfp_stringtable = {
    usb_sfp_stringtable[STRING_MANUFACTURER] = "SFP",
    usb_sfp_stringtable[STRING_PRODUCT] = "USB SFP",
    usb_sfp_stringtable[STRING_SERIALNUMBER] = "sfpsfpsfpsfpsfpsfpsfp",
    usb_sfp_stringtable[STRING_CONTROL] = "sfpsfpsfp ctrl",
};
static USBDescIface desc_iface_sfp[] = {
    {.bInterfaceNumber = 3,
     .bAlternateSetting = 3,
     .bNumEndpoints = 3,
     .bInterfaceClass = USB_CLASS_VENDOR_SPEC,
     .bInterfaceSubClass = 1,
     .bInterfaceProtocol = 0,
     .iInterface = STRING_CONTROL,
     .ndesc = 4,
     .descs =
         (USBDescOther[]){
             {
                 /* Header Descriptor */
                 .data =
                     (uint8_t[]){
                         0x05,                /*  u8    bLength */
                         USB_DT_CS_INTERFACE, /*  u8    bDescriptorType */
                         0x10,                /*  u8    bDescriptorSubType */
                         0x10, 0x01,          /*  le16  bcdCDC */
                     },
             },
             {
                 /* Header Descriptor */
                 .data =
                     (uint8_t[]){
                         0x05,                /*  u8    bLength */
                         USB_DT_CS_INTERFACE, /*  u8    bDescriptorType */
                         0x10,                /*  u8    bDescriptorSubType */
                         0x10, 0x01,          /*  le16  bcdCDC */
                     },
             },
             {
                 /* Header Descriptor */
                 .data =
                     (uint8_t[]){
                         0x05,                /*  u8    bLength */
                         USB_DT_CS_INTERFACE, /*  u8    bDescriptorType */
                         0x10,                /*  u8    bDescriptorSubType */
                         0x10, 0x01,          /*  le16  bcdCDC */
                     },
             },
             {
                 /* Header Descriptor */
                 .data =
                     (uint8_t[]){
                         0x05,                /*  u8    bLength */
                         USB_DT_CS_INTERFACE, /*  u8    bDescriptorType */
                         0x10,                /*  u8    bDescriptorSubType */
                         0x10, 0x01,          /*  le16  bcdCDC */
                     },
             },
         },
     .eps = (USBDescEndpoint[]){
         {
             .bEndpointAddress = USB_DIR_OUT | 0x01,
             .bmAttributes = USB_ENDPOINT_XFER_INT,
             .wMaxPacketSize = 0x10,
             .bInterval = 1,
         },
         {
             .bEndpointAddress = USB_DIR_IN | 0x01,
             .bmAttributes = USB_ENDPOINT_XFER_INT,
             .wMaxPacketSize = 0x10,
             .bInterval = 1,
         },
         {
             .bEndpointAddress = USB_DIR_OUT | 0x02,
             .bmAttributes = USB_ENDPOINT_XFER_INT,
             .wMaxPacketSize = 0x10,
             .bInterval = 1,
         },
         {
             .bEndpointAddress = USB_DIR_IN | 0x02,
             .bmAttributes = USB_ENDPOINT_XFER_INT,
             .wMaxPacketSize = 0x10,
             .bInterval = 1,
         },
     }}};

static USBDescDevice desc_device_sfp = {
    .bcdUSB = 0x0200,
    .bDeviceClass = USB_CLASS_COMM,
    .bMaxPacketSize0 = 0x40,
    .bNumConfigurations = 1,
    .confs = (USBDescConfig[]){{
        .bNumInterfaces = 0, // dln2 require this to be 0
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
} // namespace ds2490
class HWModel_ds2490 : public HWModel {
public:
  HWModel_ds2490()
      : HWModel("ds2490", USB_SFP_VID, USB_SFP_PID), probe_len(0) {}
  virtual ~HWModel_ds2490(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > -1)
      return 0;
    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual void *getUSBDesc() { return ds2490::hw_model_usb_gen_desc(); }

private:
  int probe_len;
};
#undef USB_SFP_VID
#undef USB_SFP_PID
#undef STRING_MANUFACTURER
#undef STRING_PRODUCT
#undef STRING_SERIALNUMBER
#undef STRING_CONTROL
