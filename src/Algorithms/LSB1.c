#include "LSB1.h"
#include "../Utilities/bitManipulation.h"
#include "../Parser/wavParser.h"

bool isLastBitFromBlock(int position, int sampleRate) {
  return ((position + 1) % sampleRate) == 0;
}

// TODO: continue this
void hideLSB1(const unsigned char* carrier, const int sampleRate, const int carrierLength, const unsigned char* data, BYTE mask, char* output) {
  output = malloc(carrierLength);
  int i,k = 0;
  BYTE* byteToCopy = malloc(sizeof(BYTE));
  // I assume sampleRate = 8 or 16
  // int increment = sampleRate / 8
  for (i = 0; i < carrierLength; i++) {
    if (isLastBitFromBlock(i, sampleRate)) {
      *byteToCopy = setBits(mask, *(carrier + i * sizeof(BYTE)), *(data + k++));
    } else {
      byteToCopy = carrier + i * sizeof(BYTE);
    }
    memcpy(output + i * sizeof(BYTE), byteToCopy, sizeof(BYTE));
  }
}

void extractLSB() {
// void extractLSB(const unsigned char* carrier, const int sampleRate, const int carrierLength, unsigned char* output) {
  BYTE* parsedBuffer = malloc(1);
  wavHeader wav = parseWavHeader("Wavs/funT1.wav", parsedBuffer);
  printf("---------------------------------------\n");
  
  int i = 0;
  int k = 0;

  BYTE* output = malloc(wav.dataLength * sizeof(BYTE));

  for (i = 0; i < 20; i++) {
    if (i % 2 == 1) {
      printf("original byte: ");
      printByte(parsedBuffer[i]);
      printf("\n");
      BYTE currentByte = getBit(7, parsedBuffer[i]);
      printf("current byte: ");
      printByte(currentByte);
      printf("\n");
      
      BYTE toReplace = setBits(LSB1, parsedBuffer[i], currentByte);
      // printf("to replace: ");
      // printByte(toReplace);
      // printf("\n");
      // memcpy(output + k, &toReplace, sizeof(BYTE));
      // k++;
    }
  }

  // for(int i = 1; i < 20; i++) {
  //   printf("original message: ");
  //   printByte(parsedBuffer[i]);
  //   printf("\n");
  // }
  //
  // for(int i = 1; i < 3; i++) {
  //   printf("extracted: ");
  //   printByte(output[i]);
  //   printf("\n");
  // }

  // for (int i = 0; i < 10; i++) {
  // 	printByte(parsedBuffer[i]);
  // }


}
