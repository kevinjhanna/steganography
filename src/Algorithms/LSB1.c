#include "LSB1.h"

void extractLSB1(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  output[*byteIterator] = replaceLastBit(*bitIterator, output[*byteIterator], from);
  advanceIterators(bitIterator, byteIterator);
}
 