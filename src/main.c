#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"
#include "algorithms/LSB1.h"

int main(int argc, const char **argv) {
	// if(parseInput(argc, argv)) {
	// 		printf("Correct parsing\n");
	// 		return 1;
	// }

	// // This will have the data
	// BYTE* parsedBuffer = malloc(1);
	// wavHeader wav = parseWavHeader("Wavs/fun.wav", parsedBuffer);
	//
	// for (int i = 0; i < 10; i++) {
	// 	printByte(parsedBuffer[i]);
	// }

	BYTE byte = 0b11101010;
	BYTE newByte = setBit(0, byte, 0b00000000);
	printf("byte: ");
	printByte(byte);
	printf("\n");
	printf("newByte: ");
	printByte(newByte);
	printf("\n");

	// extractLSB();
	return 0;
}
