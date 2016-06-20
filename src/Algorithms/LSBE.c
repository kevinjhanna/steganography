#include "LSBE.h"

void extractLSBE(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  int i;
  int shouldLSBE = 1;
  
  for (i = 0; i < 7; i++) {
  	if (getBit(i, from) == 0) {
  		shouldLSBE = 0;
  		break;
  	}
  	//advanceIterators(bitIterator, byteIterator);
  }
  if(shouldLSBE){
  	printf("este es from %02x\n",(int)from);	
    printf("en particular agarro el %d\n",getBit(7, from));
  	output[*byteIterator] = replaceBit(*bitIterator, output[*byteIterator], getBit(7, from));
  	advanceIterators(bitIterator, byteIterator);
  } else {
  	printf("este no lsbe \n");
  }
  
}

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length){
}