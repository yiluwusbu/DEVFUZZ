///
/// hardware model for e1000
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_e1000 : public HWModel {
public:
  HWModel_e1000() : HWModel("e1000", 0x8086, 0x1000), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_e1000(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 774)
      return 0;
    switch (addr) {
    case( 0xa ):{
    static int cnt;
    if (cnt== 0 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 19 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 20 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 21 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 22 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 23 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 24 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 25 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 26 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 27 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 28 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 29 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 30 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 31 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 32 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 33 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 34 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 35 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 36 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 37 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 38 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 39 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 40 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 41 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 42 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 43 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 44 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 45 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 46 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 47 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 48 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 49 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 50 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 51 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 52 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 53 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 54 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 55 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 56 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 57 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 58 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 59 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 60 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 61 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 62 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 63 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 64 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 65 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 66 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 67 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 68 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 69 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 70 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 71 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 72 ) *((uint16_t *)dest) = 0 ;
    cnt++;}
    case( 0xc ):{
    static int cnt;
    if (cnt== 0 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint16_t *)dest) = 4 ;
    if (cnt== 11 ) *((uint16_t *)dest) = 4 ;
    if (cnt== 12 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint16_t *)dest) = 40960 ;
    if (cnt== 15 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint16_t *)dest) = 32768 ;
    if (cnt== 17 ) *((uint16_t *)dest) = 8192 ;
    if (cnt== 18 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 19 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 20 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 21 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 22 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 23 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 24 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 25 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 26 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 27 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 28 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 29 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 30 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 31 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 32 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 33 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 34 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 35 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 36 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 37 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 38 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 39 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 40 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 41 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 42 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 43 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 44 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 45 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 46 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 47 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 48 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 49 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 50 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 51 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 52 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 53 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 54 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 55 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 56 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 57 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 58 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 59 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 60 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 61 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 62 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 63 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 64 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 65 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 66 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 67 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 68 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 69 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 70 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 71 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 72 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 73 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 74 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 75 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 76 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 77 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 78 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 79 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 80 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 81 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x6 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x8 ):{
    static int cnt;
    if (cnt== 0 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 10 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 11 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 12 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 13 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 14 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 15 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 16 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 17 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 18 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 19 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 20 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 21 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 22 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 23 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 24 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 25 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 26 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 27 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 28 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 29 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 30 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 31 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 32 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 33 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 34 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 35 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 36 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 37 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 38 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 39 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 40 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 41 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 42 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 43 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 44 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 45 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 46 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 47 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 48 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 49 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 50 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 51 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 52 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 53 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 54 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 55 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 56 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 57 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 58 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 59 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 60 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 61 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 62 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 63 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 64 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 65 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 66 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 67 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 68 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 69 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 70 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 71 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 72 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 73 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 74 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 75 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 76 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 77 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 78 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 79 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 80 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 81 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 82 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 83 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 84 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 85 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 86 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 87 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 88 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 89 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 90 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 91 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 92 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 93 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 94 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 95 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 96 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 97 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 98 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 99 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 100 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 101 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 102 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 103 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 104 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 105 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 106 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 107 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 108 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 109 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 110 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 111 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 112 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 113 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 114 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 115 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 116 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 117 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 118 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 119 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 120 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 121 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 122 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 123 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 124 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 125 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 126 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 127 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 128 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 129 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 130 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 131 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 132 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 133 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 134 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 135 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 136 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 137 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 138 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 139 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 140 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 141 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 142 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 143 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 144 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 145 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 146 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 147 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 148 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 149 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 150 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 151 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 152 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 153 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 154 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 155 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 156 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 157 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 158 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 159 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 160 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 161 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 162 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 163 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 164 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 165 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 166 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 167 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 168 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 169 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 170 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 171 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 172 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 173 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 174 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 175 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 176 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 177 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 178 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 179 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 180 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 181 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 182 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 183 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 184 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 185 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 186 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 187 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 188 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 189 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 190 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 191 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 192 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 193 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 194 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 195 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 196 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 197 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 198 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 199 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 200 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 201 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 202 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 203 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 204 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 205 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 206 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 207 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 208 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 209 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 210 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 211 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 212 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 213 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 214 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 215 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 216 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 217 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 218 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 219 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 220 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 221 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 222 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 223 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 224 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 225 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 226 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 227 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 228 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 229 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 230 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 231 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 232 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 233 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 234 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 235 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 236 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 237 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 238 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 239 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 240 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 241 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 242 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 243 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 244 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 245 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 246 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 247 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 248 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 249 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 250 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 251 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 252 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 253 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 254 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 255 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 256 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 257 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 258 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 259 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 260 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 261 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 262 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 263 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 264 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 265 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 266 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 267 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 268 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 269 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 270 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 271 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 272 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 273 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 274 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 275 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 276 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 277 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 278 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 279 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 280 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 281 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 282 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 283 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 284 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 285 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 286 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 287 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 288 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 289 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 290 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 291 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 292 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 293 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 294 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 295 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 296 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 297 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 298 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 299 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 300 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 301 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 302 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 303 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 304 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 305 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 306 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 307 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 308 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 309 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 310 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 311 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 312 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 313 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 314 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 315 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 316 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 317 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 318 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 319 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 320 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 321 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 322 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 323 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 324 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 325 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 326 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 327 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 328 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 329 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 330 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 331 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 332 ) *((uint16_t *)dest) = 514 ;
    if (cnt== 333 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 334 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 335 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 336 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 337 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 338 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 339 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 340 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 341 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 342 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 343 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 344 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 345 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 346 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 347 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 348 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 349 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 350 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 351 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 352 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 353 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 354 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 355 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 356 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 357 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 358 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 359 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 360 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 361 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 362 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 363 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 364 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 365 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 366 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 367 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 368 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 369 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 370 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 371 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 372 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 373 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 374 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 375 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 376 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 377 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 378 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 379 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 380 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 381 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 382 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 383 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 384 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 385 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 386 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 387 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 388 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 389 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 390 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 391 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 392 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 393 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 394 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 395 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 396 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 397 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 398 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 399 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 400 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 401 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 402 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 403 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 404 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 405 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 406 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 407 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 408 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 409 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 410 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 411 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 412 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 413 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 414 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 415 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 416 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 417 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 418 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 419 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 420 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 421 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 422 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 423 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 424 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 425 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 426 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 427 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 428 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 429 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 430 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 431 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 432 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 433 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 434 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 435 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 436 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 437 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 438 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 439 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 440 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 441 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 442 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 443 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 444 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 445 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 446 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 447 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 448 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 449 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 450 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 451 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 452 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 453 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 454 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 455 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 456 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 457 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 458 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 459 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 460 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 461 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 462 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 463 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 464 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 465 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 466 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 467 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 468 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 469 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 470 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 471 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 472 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 473 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 474 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 475 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 476 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 477 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 478 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 479 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 480 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 481 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 482 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 483 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 484 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 485 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 486 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 487 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 488 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 489 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 490 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 491 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 492 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 493 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 494 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 495 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 496 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 497 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 498 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 499 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 500 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 501 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 502 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 503 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 504 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 505 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 506 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 507 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 508 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 509 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 510 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 511 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 512 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 513 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 514 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 515 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 516 ) *((uint16_t *)dest) = 0 ;
    if (cnt== 517 ) *((uint32_t *)dest) = 0 ;
    if (cnt== 518 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 519 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 520 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 521 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 522 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 523 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 524 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 525 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 526 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x0 ):{
    static int cnt;
    if (cnt== 0 ) *((uint32_t *)dest) = 1886417008 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 9 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x1 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x4 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x5 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x9 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x7 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x2 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0x3 ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    case( 0xd ):{
    static int cnt;
    if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 1 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 2 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 3 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 4 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 5 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 6 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 7 ) *((uint8_t *)dest) = 0 ;
    if (cnt== 8 ) *((uint8_t *)dest) = 0 ;
    cnt++;}
    }

    probe_len++;
    return size;
  };
  virtual void write(uint64_t data, uint64_t addr, size_t size) final{};

  virtual void *getUSBDesc() { return nullptr; }

private:
  int probe_len;
};

Stage2HWModel * new_stage2_model_e1000() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {32 ,       HWInput(32, 4,
                {0x10000000, 0x40000000, },
                {},
                {})
  },
  {192 ,        HWInput(192, 4,
                {0xc, },
                {0x0, },
                {})
  },
  {0 ,      HWInput(0, 4,
              {0x80000000, },
              {},
              {})
  },
  {376 ,        HWInput(376, 4,
                {0x80000000, },
                {},
                {})
  },
  {384 ,        HWInput(384, 4,
                {0x8000000, 0x40000000, },
                {},
                {})
  },
  {16 ,       HWInput(16, 4,
                {0x8, 0x80, 0x200, 0x400, 0x2000, },
                {},
                {})
  },
  {40 ,       HWInput(40, 4,
                {},
                {0x0, 0x5a5a5a5a, 0xa5a5a5a5, 0xffffffff, },
                {})
  },
  {22560 ,          HWInput(22560, 4,
                  {0x1, 0x120000, },
                  {},
                  {})
  },
  {44 ,       HWInput(44, 4,
                {},
                {0x0, 0x5a5a, 0xa5a5, 0xffff, },
                {})
  },
  {48 ,       HWInput(48, 4,
                {},
                {0x0, 0x5a5a, 0xa5a5, 0xffff, },
                {})
  },
  {4 ,      HWInput(4, 4,
              {0x80000000, },
              {},
              {})
  },
  {56 ,       HWInput(56, 4,
                {},
                {0x0, 0x5a5a, 0xa5a5, 0xffff, },
                {})
  },
  {8 ,      HWInput(8, 4,
              {0x1, 0x2, 0x4, 0x10, 0x20, 0x40, 0x80, 0x2000, 0x4000, 0x8000, 0xc000, },
              {},
              {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  DMAInputModel(0,16, {
  {8 , HWInput(8, 4,
          {},
          {0x41, 0x80, 0x100, 0x200, 0x400, 0x5f3, },
          {})
  },
  {13 , HWInput(13, 1,
          {0x20, 0x97, },
          {},
          {})
  },
  {12 , HWInput(12, 1,
          {0x1, },
          {},
          {})
  },
  }),
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setDMAReg(0x420, 0x1000);
  model->setDMAReg(0x110, 0x1000);
  return model;
}
