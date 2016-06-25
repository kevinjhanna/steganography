#include "LSBE.h"

static void extractLSBEFromByte(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  
  int i;
  bool isLSBE = true;
  
  for (i = 0; i < 7; i++) {
    if (getBit(i, from) == 0) {
      isLSBE = false;
      break;
    }
  }
  
  if(isLSBE){
    output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(7, from));
    advanceIterators(bitIterator, byteIterator);
  }
  
}

int extractLSBE(BYTE* output, BYTE* carrier, int carrierLength) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i;
  for (i = 0; i < carrierLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
      extractLSBEFromByte(&bitIterator, &byteIterator, carrier[i], output);
  }
  
  // byte iterator is the length of the output.
  return byteIterator;
}

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length){
}