#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <openssl/crypto.h>
#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"

int main(int argc, const char **argv) {
	// if(parse(argc, argv)) {
	// 	return 1;
	// }

	// This will have the data
	BYTE* parsedBuffer = malloc(1);
	wavHeader wav = parseWavHeader("Wavs/fun.wav", parsedBuffer);

	for (int i = 0; i < 10; i++) {
		printByte(parsedBuffer[i]);
	}

	return 0;
}
