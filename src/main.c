#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <openssl/evp.h>

#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"
#include "Algorithms/LSBParser.h"

void textExtractLSB1() {
  LSB_TYPE type = LSB1;
  extractLSB(type, "test-LSB1", "Examples/funT1.wav");
}

void testEmbedLSB1() {
  
  char* fileToHide = "output-LSB1.jpg";
  char* carrier = "Wavs/Examples/funT1.wav";
  char* stegoWaveFile = "newWav.wav";
  LSB_TYPE type = LSB1;

  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void testDecryptLSB1() {
  LSB_TYPE type = LSB1;
  //extractEncryptedLSB(type, "videito", "Wavs/StegoFiles/whateveroasis11a.wav", "aplausos", EVP_aes_128_cfb());
  extractEncryptedLSB(type, "michelin", "Examples/funT1E.wav", "oculto", EVP_aes_192_cbc());
}

void textExtractLSB4() {
  LSB_TYPE type = LSB4;
  extractLSB(type, "test-LSB4", "Wavs/StegoFiles/bendita11a.wav");
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
  extractLSB(type, "test-LSBE", "Wavs/StegoFiles/whateveroasis11b.wav");
}

void testDecrypt() {
  LSB_TYPE type = LSB1;
  char* fileName = "test-decrypt";
  extractLSB(type, fileName, "Wavs/GrupoIvo/labioscompartidos12.wav");
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
  // testEmbedLSB1();
  //textExtractLSB1();
  testDecryptLSB1();
  //textExtractLSB1();
  
  // testEmbedLSB4();
  // textExtractLSB4();
  //testDecryptLSB1();
  
	return 0;
}
