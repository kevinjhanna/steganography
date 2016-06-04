//
//  LSB4.h
//  steganography
//
//  Created by Francisco Depascuali on 6/4/16.
//  Copyright © 2016 DepaStudios. All rights reserved.
//

#pragma once

#include <stdio.h>
#include "../Utilities/bitManipulation.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output);