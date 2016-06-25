#include "LSBE.h"

void extractLSBE(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  
  int i;
  bool isLSBE = true;
  
  for (i = 0; i < 7; i++) {
  	if (getBit(i, from) == 0) {
  		isLSBE = false;
  		break;
  	}
  	//advanceIterators(bitIterator, byteIterator);
  }
  
  if(isLSBE){
    printByte(getBit(7, from));
  	output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(7, from));
  	advanceIterators(bitIterator, byteIterator);
  }
  
}

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length){
}