#pragma once

#include <stdio.h>

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

int extractLSB4(BYTE* output, BYTE* carrier, int carrierLength);

void embedLSB4(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);