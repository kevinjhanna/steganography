typedef unsigned char byte;

#define LSB1 0xfe
#define LSB4 0xf0

byte getBit(int position, byte value);

byte setBit(byte mask, byte value, byte replacement);
