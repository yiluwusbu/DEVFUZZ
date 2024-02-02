#ifndef PEX_PCI_DEF
#define PEX_PCI_DEF
// defined in libs2ecore/include/s2e/S2EExecutionStateMemory.h
// #define PORT_IO_ADDRESS_SPACE_SIZE 0x10000
// #define PORT_IO_ADDRESS_SPACE_LOW 0
// #define PORT_IO_ADDRESS_SPACE_HIGH 0xffff

// PCI port io address space 0xcf8 ~ (0xcf8 + 4 + 4)
#define PCI_CONFIG_ADDRESS_PORT 0xcf8
#define PCI_CONFIG_DATA_PORT 0xcfc
#define PCI_CONFIG_DATA_PORT_END (0xcfc + 0x03)

#define PCI_CONFIG_DATA_REG_0 (0x00)
#define PCI_CONFIG_DATA_REG_1 (0x01)
#define PCI_CONFIG_DATA_REG_2 (0x02)
#define PCI_CONFIG_DATA_REG_3 (0x03)
#define PCI_CONFIG_DATA_REG_BAR0 (0x04)
#define PCI_CONFIG_DATA_REG_BAR1 (0x05)
#define PCI_CONFIG_DATA_REG_BAR2 (0x06)
#define PCI_CONFIG_DATA_REG_BAR3 (0x07)
#define PCI_CONFIG_DATA_REG_BAR4 (0x08)
#define PCI_CONFIG_DATA_REG_BAR5 (0x09)
#define PCI_CONFIG_DATA_REG_A (0x0A)
#define PCI_CONFIG_DATA_REG_B (0x0B)
#define PCI_CONFIG_DATA_REG_C (0x0C)
#define PCI_CONFIG_DATA_REG_D (0x0D)
#define PCI_CONFIG_DATA_REG_E (0x0E)
#define PCI_CONFIG_DATA_REG_F (0x0F)
#define PCI_CONFIG_DATA_END 0x40

// decode value in PCI_CONFIG_ADDRESS_PORT register into
// bus device function register
#define BUS_ADDR(X) ((X >> 16) & 0xFF)
#define DEV_ADDR(X) ((X >> 11) & 0x1F)
#define FUN_ADDR(X) ((X >> 8) & 0x03)
// this is register offset in 32 bit granularity
#define REG_ADDR(X) ((X >> 2) & 0x3F)

// According to PCI® 3.0 base spec, I/O space must not consume more than 256 bytes per I/O Base Address register and the
// upper 16 bits of I/O Base Address registers are hardwired to zero for devices intended for 16 bit I/O system.  Since
// I/O space is usually used for controlling peripheral as single dword accesses, users do not typically need to
// allocate a large I/O memory map for this purpose.
// https://www.intel.com/content/www/us/en/programmable/support/support-resources/knowledge-base/solutions/rd08152011_738.html
// IO address space
// #define BAR_HMASK 0xffffff00
// MMIO memory address space
// #define BAR_HMASK 0xfff80000

// 0 means mmio bar
// 1 means pio bar
#define BAR_TYPE_MMIO 0
#define BAR_TYPE_PIO 1
// #define BAR_INIT_VALUE 0x0

#define PCI_ENABLE_BIT 0x80000000
#endif
