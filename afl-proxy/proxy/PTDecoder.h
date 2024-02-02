///
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
///
#ifndef _PT_DECODER_H_
#define _PT_DECODER_H_

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <cstdint>
#include <string.h>

#define LEFT(x) ((end - p) >= (x))
#define BIT(x) (1u << (x))

#include "aflclient.h"

extern AFLClient *aflClient;

class PTDecoder {
public:
  PTDecoder(){};
  ~PTDecoder(){};
  void decode(uint8_t *map, size_t len) {
    uint8_t *end = &map[len];
    uint8_t *p;
    size_t skipped = 0;
    size_t overflow = 0;
    uint64_t last_ip = 0;

    for (p = map; p < end;) {
      uint8_t *prev = p;
      /* look for PSB */
      p = (uint8_t *)memmem(p, end - p, psb, 16);
      if (!p) {
        p = end;
        break;
      }
      skipped += p - prev;
      while (p < end) {
        // printf("%lx\t", p - map);

        if (*p == 2 && LEFT(2)) {
          if (p[1] == 0xa3 && LEFT(8)) { /* long TNT */
            // printf("tnt64 ");
            // print_multi_tnt(p + 2, 6);
            // printf("\n");
            p += 8;
            continue;
          }
          if (p[1] == 0x43 && LEFT(8)) { /* PIP */
            p += 2;
            auto val = (get_val(&p, 6) >> 1) << 5;
            // printf("pip\t%lx\n", val);
            continue;
          }
          if (p[1] == 3 && LEFT(4) && p[3] == 0) { /* CBR */
            // printf("cbr\t%u\n", p[2]);
            p += 4;
            continue;
          }
          if (p[1] == 0b10000011) {
            // printf("tracestop\n");
            p += 2;
            continue;
          }
          if (p[1] == 0b11110011 && LEFT(8)) { /* OVF */
            // printf("ovf\n");
            p += 8;
            overflow++;
            continue;
          }
          if (p[1] == 0x82 && LEFT(16) && !memcmp(p, psb, 16)) { /* PSB */
            // printf("psb\n");
            p += 16;
            continue;
          }
          if (p[1] == 0b100011) { /* PSBEND */
            // printf("psbend\n");
            p += 2;
            continue;
          }
          /* MNT */
          if (p[1] == 0b11000011 && LEFT(11) && p[2] == 0b10001000) {
            // printf("mnt\t%lx\n",
            //       p[3] | ((uint64_t)p[4] << 8) | ((uint64_t)p[5] << 16) |
            //           ((uint64_t)p[6] << 24) | ((uint64_t)p[7] << 32) |
            //           ((uint64_t)p[8] << 40) | ((uint64_t)p[9] << 48) |
            //           ((uint64_t)p[10] << 56));
            p += 10;
            continue;
          }
          /* TMA */
          if (p[1] == 0b01110011 && LEFT(7)) {
            // printf("tma\tctc=%u fc=%u\n", p[2] | (p[3] << 8),
            //        p[5] | ((p[6] & 1) << 8));
            p += 7;
            continue;
          }
          /* VMCS */
          if (p[1] == 0b11001000 && LEFT(7)) {
            // printf("vmcs\t%lx\n",
            //       ((uint64_t)p[2] << 12) | ((uint64_t)p[3] << 20) |
            //           ((uint64_t)p[4] << 28) | ((uint64_t)p[5] << 36) |
            //           ((uint64_t)p[6] << 44));
            p += 7;
            continue;
          }
        }

        if ((*p & BIT(0)) == 0) {
          if (*p == 0) { /* PAD */
            // printf("pad\n");
            p++;
            continue;
          }
          // printf("tnt8 ");
          // print_tnt_stop(*p >> 1);
          // printf("\n");
          p++;
          continue;
        }

        const char *name = nullptr;
        switch (*p & 0x1f) {
        case 0xd:
          name = "tip";
          break;
        case 0x11:
          name = "tip.pge";
          break;
        case 0x1:
          name = "tip.pgd";
          break;
        case 0x1d:
          name = "fup";
          break;
        }
        if (name) {
          int ipl = *p >> 5;
          p++;
          auto ip = get_ip_val(&p, end, ipl, &last_ip);
          // LOG_TO_FILE("afl.log", "ip@" << std::hex << ip);
          // printf("%s\t%d: 0x%lx\n", name, ipl, ip);
          aflClient->AFLMaybeLog(ip);
          continue;
        }
        if (*p == 0x99 && LEFT(2)) { /* MODE */
          if ((p[1] >> 5) == 1) {
            // printf("mode.tsx");
            // if (p[1] & BIT(0))
            //  printf(" intx");
            // if (p[1] & BIT(1))
            //  printf(" txabort");
            // printf("\n");
            p += 2;
            continue;
          } else if ((p[1] >> 5) == 0) {
            // printf("mode.exec");
            // printf(" lma=%d", (p[1] & BIT(0)));
            // printf(" cs.d=%d", !!(p[1] & BIT(1)));
            // printf("\n");
            p += 2;
            continue;
          }
        }

        if (*p == 0x19 && LEFT(8)) { /* TSC */
          p++;
          auto val = get_val(&p, 7);
          // printf("tsc\t%lu\n", val);
          continue;
        }
        if (*p == 0b01011001 && LEFT(2)) { /* MTC */
          // printf("mtc\t%u\n", p[1]);
          p += 2;
          continue;
        }
        if ((*p & 3) == 3) { /* CYC */
          uint64_t cyc = *p >> 2;
          unsigned shift = 4;
          if ((*p & 4) && LEFT(1)) {
            do {
              p++;
              cyc |= (*p >> 1) << shift;
              shift += 7;
            } while ((*p & 1) && LEFT(1));
          }
          // printf("cyc\t%lu\n", cyc);
          p++;
          continue;
        }
        // print_unknown(p, end, map);
        break;
      }
    }
#if 0
    if (p < end || skipped)
      printf("%lu bytes undecoded\n", (end - p) + skipped);
    if (overflow)
      printf("%lu overflows\n", overflow);
#endif
    fflush(stdout);
  }

private:
  const uint8_t psb[16] = {0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82,
                           0x02, 0x82, 0x02, 0x82, 0x02, 0x82, 0x02, 0x82};
  /* Caller must have checked length */
  uint64_t get_ip_val(unsigned char **pp, unsigned char *end, int len,
                      uint64_t *last_ip) {
    unsigned char *p = *pp;
    uint64_t v = *last_ip;
    unsigned shift = 0;

    if (len == 0) {
      *last_ip = 0;
      return 0; /* out of context */
    }
    if (len < 4) {
      if (!LEFT(len)) {
        *last_ip = 0;
        return 0; /* XXX error */
      }
      for (int i = 0; i < len; i++, shift += 16, p += 2) {
        uint64_t b = *(uint16_t *)p;
        v = (v & ~(0xffffULL << shift)) | (b << shift);
      }
      v = ((int64_t)(v << (64 - 48))) >> (64 - 48); /* sign extension */
    } else {
      return 0; /* XXX error */
    }
    *pp = p;
    *last_ip = v;
    return v;
  }

  /* Caller must have checked length */
  uint64_t get_val(unsigned char **pp, int len) {
    unsigned char *p = *pp;
    uint64_t v = 0;
    unsigned shift = 0;

    for (int i = 0; i < len; i++, shift += 8)
      v |= ((uint64_t)(*p++)) << shift;
    *pp = p;
    return v;
  }

  void print_unknown(unsigned char *p, unsigned char *end, unsigned char *map) {
    printf("unknown packet: ");
    unsigned len = end - p;
    int i;
    if (len > 16)
      len = 16;
    for (i = 0; i < len; i++)
      printf("%02x ", p[i]);
    printf("\n");
  }

  void print_tnt_byte(unsigned char v, int max) {
    int i;
    for (i = max - 1; i >= 0; i--)
      printf((v & BIT(i)) ? "T" : "N");
  }

  void print_tnt_stop(unsigned char v) {
    int j;
    for (j = 7; j >= 0; j--) {
      if (v & BIT(j))
        break;
    }
    print_tnt_byte(v, j);
  }

  void print_multi_tnt(unsigned char *p, int len) {
    int i;
    for (i = len - 1; i >= 0 && p[i] == 0; i--) {
    };
    if (i >= 0) {
      print_tnt_stop(p[i]);
      i--;
    } else {
      printf("??? no stop bit");
      return;
    }
    for (; i >= 0; i--)
      print_tnt_byte(p[i], 8);
  }
};
#undef LEFT

#endif //_PT_DECODER_H_
