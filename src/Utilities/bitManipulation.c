#include <stdio.h>
#include "bitManipulation.h"

BYTE getBit(int position, BYTE byte) {
  return (byte >> (sizeof(byte) * 8 - 1 - position)) & 0x01;
}

BYTE replaceBit(int position, BYTE byte, BYTE replacement) {
  BYTE invertMask = 0b00000001;
  if(replacement % 2 == 0) {
    BYTE aux = invertMask << (sizeof(BYTE) * 8 - 1 - position);
    return byte & ~aux;
  } else {
    BYTE aux = replacement << (sizeof(BYTE) * 8 - 1 - position);
    return (byte & ~aux) | aux;
  }
}

BYTE replaceLastBit(int position, BYTE byte, BYTE replacement) {
  return replaceBit(position, byte, getBit(7, replacement));
}

BYTE replaceBits(int from, int to, BYTE byte, BYTE replacement) {
  BYTE result = byte;
  
  for (int i = from; i <= to; i++ ) {
    result = replaceBit(i, result, getBit(i, replacement));
  }
  
  return result;
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

int32_t toCarrier(int number) {
  return ntohl(number);
}

int32_t fromCarrier(int number) {
  return ntohl(number);
}


// It is meant to used AFTER setting a value.
void advanceIterators(int* bitIterator, int* byteIterator) {
  if (*bitIterator == 7) {
    (*byteIterator)++;
    *bitIterator = 0;
  } else {
    (*bitIterator)++;
  }
}
