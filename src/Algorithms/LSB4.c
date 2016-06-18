#include "LSB4.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  for (int i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(i, from));
    advanceIterators(bitIterator, byteIterator);
  }
}

void embedLSB4(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length) {
  int byteIterator = 0;
  int bitIterator = 0;
  
  for (int i = 0; i < wavDataLength; i++) {
    if (byteIterator == length) {
      return;
    }
    
    if (isOdd(i)) {
      for (int j = 4; j < 8; j++) {
        wavData[i] = replaceBit(j, wavData[i], getBit(bitIterator, rawMessage[byteIterator]));
        advanceIterators(&bitIterator, &byteIterator);
      }
    }
  }
}

