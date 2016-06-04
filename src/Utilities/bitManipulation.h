typedef unsigned char BYTE;

#pragma once

#define BIT_ONE 0b00000001
#define BIT_ZERO 0b00000000


BYTE getBit(int position, BYTE value);

BYTE replaceBit(int position, BYTE byte, BYTE replacement);

BYTE replaceLastBit(int position, BYTE byte, BYTE replacement);

BYTE replaceBits(int from, int to, BYTE byte, BYTE replacement);

void printByte(BYTE byte);

void printStream(BYTE* bytes, int numberOfBytes);

void advanceIterators(int* bitIterator, int* byteIterator);
