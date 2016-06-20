#include "LSBE.h"

void extractLSBE(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  printf("heyhey\n");
  for (int i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(i, from));
    advanceIterators(bitIterator, byteIterator);
  }
}

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length){
}