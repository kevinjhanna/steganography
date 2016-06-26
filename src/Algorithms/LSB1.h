#pragma once

#include <stdio.h>

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

int extractLSB1(BYTE* wavData, BYTE* output, int wavDataLength);

void embedLSB1(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);