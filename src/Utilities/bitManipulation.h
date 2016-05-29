typedef unsigned char BYTE;

#define LSB1 0x01 // 0000 0000 0000 0001
#define LSB4 0x0f // 0000 0000 0000 1111

#define BIT_ONE 0b00000001
#define BIT_ZERO 0b00000000


BYTE getBit(int position, BYTE value);

BYTE setBit(int position, BYTE byte, BYTE replacement);

BYTE setBits(BYTE mask, BYTE byte, BYTE replacement);

void printByte(BYTE byte);

void printStream(BYTE* bytes, int numberOfBytes);
