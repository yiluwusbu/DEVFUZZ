///
/// 2020-2021 Tong Zhang<ztong0001@gmail.com>
///
#ifndef _PERF_AUX_BUFFER_H_
#define _PERF_AUX_BUFFER_H_

#include "logutil.h"
#include <cstdint>

class PerfAuxBuffer {
public:
  PerfAuxBuffer(uint8_t *ring, size_t auxRingSize, size_t auxOffset,
                size_t auxSize)
      : buffer(nullptr), _size(auxSize) {
    buffer = (uint8_t *)malloc(_size);
    size_t realOffset = auxOffset % auxRingSize;
    if (realOffset + _size < auxRingSize) {
      memcpy(buffer, &ring[realOffset], _size);
      return;
    }
    size_t size1 = auxRingSize - realOffset;
    size_t size2 = _size - size1;
    memcpy(buffer, &ring[realOffset], size1);
    memcpy(&buffer[size1], ring, size2);
  };
  ~PerfAuxBuffer() {
    if (buffer)
      free(buffer);
  };
  uint8_t *data() { return buffer; };
  size_t size() { return _size; };

private:
  uint8_t *buffer;
  size_t _size;
};

#endif //_PERF_AUX_BUFFER_H_
