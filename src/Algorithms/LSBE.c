#include "LSBE.h"

void extractLSBE(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  int i;
  int shouldLSBE = 1;
  
  for (i = 0; i < 7; i++) {
  	if (getBit(i, from) == 0) {
  		shouldLSBE = 0;
  	}
  }
  if(shouldLSBE){
  	printf("este es from %02x\n",(int)from);	
  	// output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(i, from));
   //  advanceIterators(bitIterator, byteIterator);	
  }
}

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length){
}