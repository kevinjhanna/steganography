#include <stdlib.h>

#include "../Utilities/bitManipulation.h"
#include "../Utilities/bool.h"
#include "string.h"

void hideLSB1(const unsigned char* carrier, const int sampleRate, const int carrierLength, const unsigned char* data, BYTE mask, char* output);
