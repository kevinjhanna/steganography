#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Parser/parser.h"
#include "Parser/wavParser.h"
#include "Utilities/bitManipulation.h"
#include "Algorithms/LSBParser.h"

void testExtractLSB1() {
  LSB_TYPE type = LSB1;
  extractLSB(type, "Wavs/extracted/test-LSB1-extraccion", "Wavs/toEmbed/imageEmbeded/newWavLsb1.wav");
}

void testEmbedLSB1() {
  char* fileToHide = "Wavs/toEmbed/images/genericImageToHide.jpg";
  char* carrier = "Wavs/toEmbed/carrier.wav";
  char* stegoWaveFile = "Wavs/toEmbed/imageEmbeded/newWavLsb1.wav";
  LSB_TYPE type = LSB1;
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void testExtractLSB4() {
  LSB_TYPE type = LSB4;
  extractLSB(type, "Wavs/extracted/test-LSB4-extraccion", "Wavs/toEmbed/imageEmbeded/newWavLsb4.wav");
}

void testEmbedLSB4() {
  char* fileToHide = "Wavs/toEmbed/images/genericImageToHide.jpg";
  char* carrier = "Wavs/toEmbed/carrier.wav";
  char* stegoWaveFile = "Wavs/toEmbed/imageEmbeded/newWavLsb4.wav";
  LSB_TYPE type = LSB4;
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void testExtractLSBE() {
  LSB_TYPE type = LSBE;
  extractLSB(type, "Wavs/extracted/test-LSBE-extraccion", "Wavs/toEmbed/imageEmbeded/newWavLsbe.wav");
}

void testEmbedLSBE() {
  char* fileToHide = "Wavs/toEmbed/images/genericImageToHide.jpg";
  char* carrier = "Wavs/toEmbed/carrier.wav";
  char* stegoWaveFile = "Wavs/toEmbed/imageEmbeded/newWavLsbe.wav";
  LSB_TYPE type = LSBE;
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void runTests() {
  
  testEmbedLSB1();
  testExtractLSB1();
  
  testEmbedLSB4();
  testExtractLSB4();

  testEmbedLSBE();
  testExtractLSBE();
  printf("Se acaban de correr los tests de LSB1 embed y extract\n");
  printf("Se acaban de correr los tests de LSB4 embed y extract\n");
  printf("Se acaban de correr los tests de LSBE embed y extract\n");
  printf("A partir wav ubicado en directorio toEmbed se generaron portadores con imagen ubicados en imageEmbeded\n");
  printf("Luego a cada uno de estos portadores se les extrajo su respectiva imagen bajo el directorio extracted\n");
}

int main(int argc, const char **argv) {
  int result;
  if((result = parse(argc, argv))) {
     printf("Correct parsing\n");
     if(result == RUN_TESTS) {
      runTests();
      return 0;
     }
  } else {
    return -1;
  }

  
  printf("%s", argparse.description);
  printf("%s", argparse.epilog);
  printf("%s\n", argparse.argc);
  printf("%s\n", argparse.argv);
  //printf("%s\n", (argparse.options[1]).short_name);
  printf("%s\n", argparse.usages);


  // enum argparse_option_type type;
  //   const char short_name;
  //   const char *long_name;
  //   void *value;
  //   const char *help;
  //   argparse_callback *callback;
  //   intptr_t data;
  //   int flags;
  char fileNameLSB1[50] = "output-LSB1";
  // if (embed) {
  //   char* fileToHide = othide
  //   char* carrier = wavfile
  //   char* stegoWaveFile = out
  //   LSB_TYPE type = LSBE;
  //   embedLSB(type, fileToHide, carrier, stegoWaveFile);
  // } else {
  //   LSB_TYPE type = LSBE;
  //   extractLSB(type, fileNameLSB4, "Wavs/Examples/funT4.wav");

  // }

  return 0;
}
