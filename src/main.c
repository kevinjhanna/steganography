#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"
#include "Algorithms/LSBParser.h"

void textExtractLSB1() {
  LSB_TYPE type = LSB1;
  char fileName[20] = "test-LSB1";
  extractLSB(type, fileName, "newWav.wav");
}

void testEmbedLSB1() {
  
  char* fileToHide = "output-LSB1.jpg";
  char* carrier = "Wavs/Examples/funT1.wav";
  char* stegoWaveFile = "newWav.wav";
  LSB_TYPE type = LSB1;

  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void textExtractLSB4() {
  LSB_TYPE type = LSB4;
  char fileName[50] = "test-LSB4";
  extractLSB(type, fileName, "newWav-LSB4.wav");
}

void testEmbedLSB4() {
  
  char* fileToHide = "output-LSB4.jpg";
  char* carrier = "Wavs/Examples/funT4.wav";
  char* stegoWaveFile = "newWav-LSB4.wav";
  LSB_TYPE type = LSB4;
  
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void textExtractLSBE() {
  LSB_TYPE type = LSBE;
  char fileName[20] = "test-LSBE";
  extractLSB(type, fileName, "newWav-LSBE.wav");
}


int main(int argc, const char **argv) {
	// if(parseInput(argc, argv)) {
	// 		printf("Correct parsing\n");
	// 		return 1;
	// }


//  char fileNameLSB1[50] = "output-LSB1";
//  char fileNameLSB4[50] = "output-LSB4";
//  extractLSB(LSB1, fileNameLSB1, "Wavs/Examples/funT1.wav");
//  extractLSB(LSB4, fileNameLSB4, "Wavs/Examples/funT4.wav");
//
  testEmbedLSB1();
  textExtractLSB1();
  
  testEmbedLSB4();
  textExtractLSB4();

  textExtractLSBE();
  
	return 0;
}
