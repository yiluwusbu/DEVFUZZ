///
/// this file is mostly from QEMU hw/usb/desc.h
///
#ifndef QEMU_HW_USB_DESC_H
#define QEMU_HW_USB_DESC_H

#include <wchar.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

typedef struct USBBus USBBus;
typedef struct USBBusOps USBBusOps;
typedef struct USBPort USBPort;
typedef struct USBDevice USBDevice;
typedef struct USBPacket USBPacket;
typedef struct USBCombinedPacket USBCombinedPacket;
typedef struct USBEndpoint USBEndpoint;

typedef struct USBDesc USBDesc;
typedef struct USBDescID USBDescID;
typedef struct USBDescDevice USBDescDevice;
typedef struct USBDescConfig USBDescConfig;
typedef struct USBDescIfaceAssoc USBDescIfaceAssoc;
typedef struct USBDescIface USBDescIface;
typedef struct USBDescEndpoint USBDescEndpoint;
typedef struct USBDescOther USBDescOther;
typedef struct USBDescString USBDescString;
typedef struct USBDescMSOS USBDescMSOS;

struct USBDescID {
  uint16_t idVendor;
  uint16_t idProduct;
  uint16_t bcdDevice;
  uint8_t iManufacturer;
  uint8_t iProduct;
  uint8_t iSerialNumber;
};

struct USBDescDevice {
  uint16_t bcdUSB;
  uint8_t bDeviceClass;
  uint8_t bDeviceSubClass;
  uint8_t bDeviceProtocol;
  uint8_t bMaxPacketSize0;
  uint8_t bNumConfigurations;

  const USBDescConfig *confs;
};

struct USBDescConfig {
  uint8_t bNumInterfaces;
  uint8_t bConfigurationValue;
  uint8_t iConfiguration;
  uint8_t bmAttributes;
  uint8_t bMaxPower;

  /* grouped interfaces */
  uint8_t nif_groups;
  const USBDescIfaceAssoc *if_groups;

  /* "normal" interfaces */
  uint8_t nif;
  const USBDescIface *ifs;
};

/* conceptually an Interface Association Descriptor, and releated interfaces */
struct USBDescIfaceAssoc {
  uint8_t bFirstInterface;
  uint8_t bInterfaceCount;
  uint8_t bFunctionClass;
  uint8_t bFunctionSubClass;
  uint8_t bFunctionProtocol;
  uint8_t iFunction;

  uint8_t nif;
  const USBDescIface *ifs;
};

struct USBDescIface {
  uint8_t bInterfaceNumber;
  uint8_t bAlternateSetting;
  uint8_t bNumEndpoints;
  uint8_t bInterfaceClass;
  uint8_t bInterfaceSubClass;
  uint8_t bInterfaceProtocol;
  uint8_t iInterface;

  uint8_t ndesc;
  USBDescOther *descs;
  USBDescEndpoint *eps;
};

struct USBDescEndpoint {
  uint8_t bEndpointAddress;
  uint8_t bmAttributes;
  uint16_t wMaxPacketSize;
  uint8_t bInterval;
  uint8_t bRefresh;
  uint8_t bSynchAddress;

  uint8_t is_audio; /* has bRefresh + bSynchAddress */
  uint8_t *extra;

  /* superspeed endpoint companion */
  uint8_t bMaxBurst;
  uint8_t bmAttributes_super;
  uint16_t wBytesPerInterval;
};

struct USBDescOther {
  uint8_t length;
  const uint8_t *data;
};

struct USBDescMSOS {
  const char *CompatibleID;
  const wchar_t *Label;
  bool SelectiveSuspendEnabled;
};

typedef const char *USBDescStrings[256];

struct USBDesc {
  USBDescID id;
  const USBDescDevice *full;
  const USBDescDevice *high;
  const USBDescDevice *super;
  const char *const *str;
  const USBDescMSOS *msos;
};

#endif /* QEMU_HW_USB_DESC_H */
