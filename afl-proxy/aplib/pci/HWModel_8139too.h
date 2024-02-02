///
/// hardware model for 8139too
/// 2022 Yilun Wu<yiluwu@cs.stonybrook.edu>
/// 2021 Tong Zhang<ztong0001@gmail.com>
///

#include "HWModel.h"

class HWModel_8139too : public HWModel {
public:
  HWModel_8139too() : HWModel("8139too", 0x10ec, 0x8139), probe_len(0) {
    setupBar({{PCI_BAR_TYPE_PIO,  4 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024},
              {PCI_BAR_TYPE_MMIO, 64 * 1024 * 1024}});
  }
  virtual ~HWModel_8139too(){};
  virtual void restart_device() final { probe_len = 0; };
  virtual int read(uint8_t *dest, uint64_t addr, size_t size) final {
    if (probe_len > 312)
      return 0;
    switch (addr)
    {
      case( 0x40 ):{
      static int cnt;
      if (cnt== 0 ) *((uint32_t *)dest) = 4278255615 ;
      if (cnt== 1 ) *((uint32_t *)dest) = 0 ;
      cnt++;}
      case( 0x52 ):{
      static int cnt;
      if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
      cnt++;}
      case( 0x37 ):{
      static int cnt;
      if (cnt== 0 ) *((uint8_t *)dest) = 0 ;
      cnt++;}
      case( 0x50 ):{
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
      if (cnt== 10 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 11 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 12 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 13 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 14 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 15 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 16 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 17 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 18 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 19 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 20 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 21 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 22 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 23 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 24 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 25 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 26 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 27 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 28 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 29 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 30 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 31 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 32 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 33 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 34 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 35 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 36 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 37 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 38 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 39 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 40 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 41 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 42 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 43 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 44 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 45 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 46 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 47 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 48 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 49 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 50 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 51 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 52 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 53 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 54 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 55 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 56 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 57 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 58 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 59 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 60 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 61 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 62 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 63 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 64 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 65 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 66 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 67 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 68 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 69 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 70 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 71 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 72 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 73 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 74 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 75 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 76 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 77 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 78 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 79 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 80 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 81 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 82 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 83 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 84 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 85 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 86 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 87 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 88 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 89 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 90 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 91 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 92 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 93 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 94 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 95 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 96 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 97 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 98 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 99 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 100 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 101 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 102 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 103 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 104 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 105 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 106 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 107 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 108 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 109 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 110 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 111 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 112 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 113 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 114 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 115 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 116 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 117 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 118 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 119 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 120 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 121 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 122 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 123 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 124 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 125 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 126 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 127 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 128 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 129 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 130 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 131 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 132 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 133 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 134 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 135 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 136 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 137 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 138 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 139 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 140 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 141 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 142 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 143 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 144 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 145 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 146 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 147 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 148 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 149 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 150 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 151 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 152 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 153 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 154 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 155 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 156 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 157 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 158 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 159 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 160 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 161 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 162 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 163 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 164 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 165 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 166 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 167 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 168 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 169 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 170 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 171 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 172 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 173 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 174 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 175 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 176 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 177 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 178 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 179 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 180 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 181 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 182 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 183 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 184 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 185 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 186 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 187 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 188 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 189 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 190 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 191 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 192 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 193 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 194 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 195 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 196 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 197 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 198 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 199 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 200 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 201 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 202 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 203 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 204 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 205 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 206 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 207 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 208 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 209 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 210 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 211 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 212 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 213 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 214 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 215 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 216 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 217 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 218 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 219 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 220 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 221 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 222 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 223 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 224 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 225 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 226 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 227 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 228 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 229 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 230 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 231 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 232 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 233 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 234 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 235 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 236 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 237 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 238 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 239 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 240 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 241 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 242 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 243 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 244 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 245 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 246 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 247 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 248 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 249 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 250 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 251 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 252 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 253 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 254 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 255 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 256 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 257 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 258 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 259 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 260 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 261 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 262 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 263 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 264 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 265 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 266 ) *((uint8_t *)dest) = 1 ;
      if (cnt== 267 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 268 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 269 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 270 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 271 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 272 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 273 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 274 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 275 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 276 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 277 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 278 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 279 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 280 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 281 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 282 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 283 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 284 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 285 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 286 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 287 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 288 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 289 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 290 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 291 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 292 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 293 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 294 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 295 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 296 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 297 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 298 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 299 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 300 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 301 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 302 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 303 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 304 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 305 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 306 ) *((uint8_t *)dest) = 0 ;
      if (cnt== 307 ) *((uint8_t *)dest) = 0 ;
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

Stage2HWModel * new_stage2_model_8139too() {
  unordered_map<int, HWInput> mmio_mdl =
  {
  {216 ,        HWInput(216, 4,
                {0x10, 0x20, 0x40, },
                {},
                {})
  },
  {64 ,       HWInput(64, 4,
                {0x40000000, 0x60000000, 0x70000000, 0x70800000, 0x74000000, 0x74400000, 0x74c00000, 0x78000000, 0x78800000, 0x7c000000, },
                {0xffffffff, },
                {})
  },
  {116 ,        HWInput(116, 4,
                {0x400, 0x1000, 0x3000, 0x7000, },
                {},
                {})
  },
  {90 ,       HWInput(90, 4,
                {0x4, },
                {},
                {})
  },
  {55 ,       HWInput(55, 4,
                {0x1, 0x4, 0x8, 0xc, 0x10, },
                {},
                {})
  },
  {62 ,       HWInput(62, 4,
                {0x8, 0xc, 0x20, 0x40, 0x50, 0x51, 0xc022, 0xc07f, 0xffa6, 0xffff, },
                {},
                {})
  },
  };

  vector<DMAInputModel> dma_mdl = {
  };
  auto * model = new Stage2HWModel("XXX", mmio_mdl, dma_mdl);
  model->setDMAReg(0x20, 0x1c00);
  model->setDMAReg(0x24, 0x1c00);
  model->setDMAReg(0x28, 0x1c00);
  model->setDMAReg(0x30, 0x8810);
  return model;
}
