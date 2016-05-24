#include <stdio.h>
#include "bitManipulation.h"

BYTE getBit(int position, BYTE byte) {
  return (byte >> (sizeof(byte) * 8 - 1 - position)) & 0x01;
}

BYTE setBit(int position, BYTE byte, BYTE replacement) {
  // BYTE aux = replacement >> (sizeof(BYTE) * 8 - 1 - position);
  BYTE aux = replacement << (sizeof(BYTE) * 8 - 1 - position);

  printf("aux:");
  printByte(aux);
  printf("\n");
  printf("~aux:");
  printByte(~aux);
  printf("\n");

  return (byte & ~aux) | aux;

  // return (byte & aux) & (byte & ~aux);
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
