#include "LSB4.h"

static void extractLSB4ForByte(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  int i;
  for (i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(i, from));
    advanceIterators(bitIterator, byteIterator);
  }
}

int extractLSB4(BYTE* output, BYTE* carrier, int carrierLength) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i;
  for (i = 0; i < carrierLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
    if (isOdd(i)) {
      extractLSB4ForByte(&bitIterator, &byteIterator, carrier[i], output);
    }
  }
  
  // byte iterator is the length of the output.
  return byteIterator;
}


void embedLSB4(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i,j;
  for (i = 0; i < wavDataLength; i++) {
    if (byteIterator == length) {
      return;
    }
    
    if (isOdd(i)) {
      for (j = 4; j < 8; j++) {
        wavData[i] = replaceBit(j, wavData[i], getBit(bitIterator, rawMessage[byteIterator]));
        advanceIterators(&bitIterator, &byteIterator);
      }
    }
  }
}

