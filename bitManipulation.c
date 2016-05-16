typedef unsigned char byte;

#define LSB1 0xfe
#define LSB4 0xf0

byte getBit(int position, byte value) {
  return (value >> (sizeof(value) * 8 - 1 - position)) & 0x01;
}

byte setBit(byte mask, byte value, byte replacement) {

  // Make sure that mask is the complement of replacement.
  if ((replacement & mask) != 0) {
    return -1;
  }

  return (value & mask) | replacement;
}