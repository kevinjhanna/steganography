#pragma once

#include "../Utilities/bitManipulation.h"
#include "../Utilities/utilities.h"

int extractLSBE(BYTE* output, BYTE* carrier, int carrierLength);

int embedLSBE(BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);