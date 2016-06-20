#pragma once

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

void extractLSBE(int* bitIterator, int* byteIterator, BYTE from, BYTE* output);

void embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);