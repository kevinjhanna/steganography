#include "LSB1.h"

void extractLSB1(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  output[*byteIterator] = setBit(*bitIterator, output[*byteIterator], getBit(7, from));
  // if the bitIterator reaches 7, it means that we need to write in a new byte.
  // So we reset bitIterator to 0 and increase the byteIterator;
  if (*bitIterator == 7) {
    (*byteIterator)++;
    *bitIterator = 0;
  } else {
    (*bitIterator)++;
  }
}
