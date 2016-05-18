#include "LSB1.h"

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
