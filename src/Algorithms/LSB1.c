#include "LSB1.h"

int extractLSB1(BYTE* output, BYTE* carrier, int carrierLength) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i;
  for (i = 0; i < carrierLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
    if (isOdd(i)) {
      output[byteIterator] = replaceLastBit(bitIterator, output[byteIterator], carrier[i]);
      advanceIterators(&bitIterator, &byteIterator);
    }
  }
  
  // byte iterator is the length of the output.
  return byteIterator;
}

void embedLSB1(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i;
  for (i = 0; i < wavDataLength; i++) {
    if (byteIterator == length) {
      return;
    }
    
    if (isOdd(i)) {
      wavData[i] = replaceBit(7, wavData[i], getBit(bitIterator, rawMessage[byteIterator]));
      advanceIterators(&bitIterator, &byteIterator);
    }
  }
}