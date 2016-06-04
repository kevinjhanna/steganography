#include "LSB4.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  for (int i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(i, from));
    advanceIterators(bitIterator, byteIterator);
  }
}

