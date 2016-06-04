#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"

void testSetBits() {

//	BYTE byte = 0b11101010;
//	printf("Test 1\n");
//	printf("El byte original: ");
//	printByte(byte);
//	printf("\n");
////
//	BYTE replacement = 0b11110111;
//  
//  printByte(setBits(4, 8, byte, replacement));
//	int position =3;
//	BYTE newbyte = setBit(position, byte, 0b00000001);
//	printf("El bit Numero %d de izquierda a derecha modificado con el valor de \n", position);
//	printByte(replacement);
//	printf("Da como resultado el bit modificado\n");
//	printByte(newbyte);
//
//	printf("-----------------\n");
//	printf("Test 2\n");
//	printf("El byte original: ");
//	printByte(byte);
//	printf("\n");
//
//	BYTE replacement2 = 0b00000000;
//	int position2 = 0;
//	BYTE newbyte2 = setBit(position2, byte, replacement2);
//	printf("El bit Numero %d de izquierda a derecha modificado con el valor de \n", position2);
//	printByte(replacement2);
//	printf("Da como resultado el bit modificado\n");
//	printByte(newbyte2);

}


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

//  testSetBits();
	extractLSB();
	return 0;
}
