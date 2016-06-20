#pragma once

#include <stdlib.h>
#include "string.h"

#include "../Utilities/bitManipulation.h"
#include "../Utilities/bool.h"
#include "../Parser/wavParser.h"
#include "../Utilities/utilities.h"
#include "./LSB1.h"
#include "./LSB4.h"
#include "./LSBE.h"

typedef enum {LSB1, LSB4, LSBE} LSB_TYPE;

//TODO: receive parameters
void extractLSB(LSB_TYPE type, char* fileName, char* wavName);

//TODO: receive parameters
void embedLSB();

