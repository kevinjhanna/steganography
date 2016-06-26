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


void embedLSBEFromByte(int* bitIterator, int* byteIterator, BYTE* actualWavData, BYTE * secretMessage){
  int i;
  bool shouldEmbed = true;
  
  for (i = 0; i < 7; i++) {
    if (getBit(i, *actualWavData) == 0) {
      //printf("should not %02x\n",actualWavData );
      shouldEmbed = false;
      break;
    }
  }
  
  if(shouldEmbed){
    printf("antes wavdata %02x\n",*actualWavData );
    printf("el bit %02x\n", getBit(*bitIterator, secretMessage[*byteIterator]));
    *actualWavData = replaceLastBit(7, *actualWavData, getBit(*bitIterator, secretMessage[*byteIterator]));
     
     printf("despues wavdata %02x\n",*actualWavData );
     printf("byteIterator %d\n",*byteIterator);
     printf("bitIterator %d\n",*bitIterator);
    advanceIterators(bitIterator, byteIterator);
  }
}

int embedLSBE(BYTE* secretMessage, BYTE* wavData, int wavDataLength, int secretMessageLength) {
  int byteIterator = 0;
  int bitIterator = 0;
  int i;

  for (int i = 0; i < secretMessageLength; ++i)
  {
    printf("%02x",secretMessage[i]);
  }


  for (i = 0; i < wavDataLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
    //1865 secretMessageLength

      if (byteIterator == secretMessageLength)
          return byteIterator;
      embedLSBEFromByte(&bitIterator, &byteIterator, wavData + i, secretMessage);
  }
  
  // byte iterator is the length of the output.
  if (byteIterator != secretMessageLength)
    return -1; 

  return byteIterator;
}
