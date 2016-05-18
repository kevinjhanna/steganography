typedef unsigned char BYTE;

#define LSB1 0x01 // 0000 0000 0000 0001
#define LSB4 0x0f // 0000 0000 0000 1111

BYTE getBit(int position, BYTE value);

BYTE setBits(BYTE mask, BYTE byte, BYTE replacement);

void printByte(BYTE byte);
