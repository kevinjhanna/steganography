#include <stdio.h>
#include "bitManipulation.h"

BYTE getBit(int position, BYTE byte) {
  return (byte >> (sizeof(byte) * 8 - 1 - position)) & 0x01;
}

BYTE setBit(int position, BYTE byte, BYTE replacement) {
  if(replacement % 2 == 0) {
    BYTE invertMask = 0b00000001;
    BYTE aux = invertMask << (sizeof(BYTE) * 8 - 1 - position);
    return byte & ~aux;
  } else {
    BYTE aux = replacement << (sizeof(BYTE) * 8 - 1 - position);
    return (byte & ~aux) | aux;
  }
}

BYTE setBits(BYTE mask, BYTE byte, BYTE replacement) {
  return (replacement & mask) | (byte & ~mask);
}

void printByte(BYTE byte) {
  for (int i = 0; i < 8; i++) {
    printf("%d", getBit(i, byte));
  }
  printf("\n");
}

void printStream(BYTE* bytes, int numberOfBytes) {
  for (int j = 0; j < numberOfBytes; j++) {
    for (int i = 0; i < 8; i++) {
      printf("%d", getBit(i, bytes[j]));
    }
    printf("\n");
  }
}
