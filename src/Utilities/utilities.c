
#include "utilities.h"

bool isEven(int number) {
  return number % 2 == 0;
}

bool isOdd(int number) {
  return !isEven(number);
}

bool isBigEndian() {
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01000000};
    return bint.c[0]==1;
}

bool isLittleEndian() {
  return !isBigEndian();
}

int getFileSize(char* fileName) {
  struct stat st;
  stat(fileName, &st);
  
  return (int)st.st_size;
}