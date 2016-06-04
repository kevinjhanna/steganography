#include "LSB4.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  
  for (int i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(i, output[*byteIterator], from);
    advanceIterators(bitIterator, byteIterator);
  }
  
}

