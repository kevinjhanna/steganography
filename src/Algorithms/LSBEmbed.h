#pragma once

#include <stdio.h>

#include "../Parser/wavParser.h"
#include "../Utilities/bitManipulation.h"
#include "./LSBParser.h"

#include "./LSB1.h"

void embedLSB(LSB_TYPE type, char* fileName, char* wavName, char* waveFileName);