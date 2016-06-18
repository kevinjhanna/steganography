#pragma once

#include <stdio.h>

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output);

void embedLSB4(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);