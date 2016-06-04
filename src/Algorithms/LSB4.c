//
//  LSB4.c
//  steganography
//
//  Created by Francisco Depascuali on 6/4/16.
//  Copyright © 2016 DepaStudios. All rights reserved.
//

#include "LSB4.h"

void extractLSB4(int* bitIterator, int* byteIterator, BYTE from, BYTE* output) {
  
  for (int i = 4; i < 8; i++) {
    output[*byteIterator] = replaceBit(i, output[*byteIterator], from);
    advanceIterators(bitIterator, byteIterator);
  }
  
}

