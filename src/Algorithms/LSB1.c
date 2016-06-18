#include "LSB1.h"

void extractLSB1(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  output[*byteIterator] = replaceLastBit(*bitIterator, output[*byteIterator], from);
  advanceIterators(bitIterator, byteIterator);
}

void embedLSB1(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length) {
  int byteIterator = 0;
  int bitIterator = 0;
  
  for (int i = 0; i < wavDataLength; i++) {
    if (byteIterator == length) {
      return;
    }
    
    if (isOdd(i)) {
      wavData[i] = replaceBit(7, wavData[i], getBit(bitIterator, rawMessage[byteIterator]));
      advanceIterators(&bitIterator, &byteIterator);
    }
  }
}