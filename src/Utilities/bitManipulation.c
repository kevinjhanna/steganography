#include <stdio.h>
#include "bitManipulation.h"

BYTE getBit(int position, BYTE byte) {
  return (byte >> (sizeof(byte) * 8 - 1 - position)) & 0x01;
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
