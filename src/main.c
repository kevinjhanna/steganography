#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"
#include "Algorithms/LSBParser.h"

int main(int argc, const char **argv) {
	// if(parseInput(argc, argv)) {
	// 		printf("Correct parsing\n");
	// 		return 1;
	// }


  char fileNameLSB1[50] = "output-LSB1";
  char fileNameLSB4[50] = "output-LSB4";
  
  extractLSB(LSB1, fileNameLSB1, "Wavs/Examples/funT1.wav");
  extractLSB(LSB4, fileNameLSB4, "Wavs/Examples/funT4.wav");
  
	return 0;
}
