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


	if(parse(argc, argv)) {
		return 1;
	}
	
	// This will have the data
	// BYTE* parsedBuffer = malloc(1);
	// wavHeader wav = parseWavHeader("Wavs/fun.wav", parsedBuffer);

	// for (int i = 0; i < 10; i++) {
	// 	printByte(parsedBuffer[i]);
	// }


	//Uncomment this.
  	//char fileNameLSB1[50] = "output-LSB1";
  	//char fileNameLSB4[50] = "output-LSB4";
  
	//extractLSB(LSB1, fileNameLSB1, "Wavs/funT1.wav");
  	//extractLSB(LSB4, fileNameLSB4, "Wavs/funT4.wav");
  
	return 0;
}
