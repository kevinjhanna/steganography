#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"

int main(int argc, const char **argv) {
	// if(parse(argc, argv)) {
	// 	return 1;
	// }
	parseWav("Wavs/fun.wav");

	return 0;
}
