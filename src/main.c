#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Parser/parser.h"
#include "Utilities/bitManipulation.h"

int main(int argc, const char **argv) {

	int i;
	byte b = 0b10010101;

	printf("hola\n");
	for (i = 0; i < 8; i++) {
		printf("bit %d = %d\n", i, getBit(i, b));
	}

	// if(parse(argc, argv)) {
	// 	return 1;
	// }
	// printf("(hola)\n");
    //Here we should call the respective functions
    return 0;
}
