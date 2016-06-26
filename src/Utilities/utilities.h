#pragma once

#include <stdint.h> // for int16_t and int32_t

#include "bool.h"
#include <sys/stat.h>

#define RUN_TESTS 7


bool isEven(int number);

bool isOdd(int number);

bool isBigEndian();

bool isLittleEndian();
