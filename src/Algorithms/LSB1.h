#pragma once

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

void extractLSB1(int* bitIterator, int* byteIterator, BYTE from, BYTE* output);

void embedLSB1(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);