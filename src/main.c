#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "Parser/parser.h"
#include "Parser/cryptoParser.h"
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
  printf("Es decir se testeo el embed y extract sobre cada uno\n\n");
}

static const char *const usage[] = {
    "criptografy [options] [[--] args]",
    "criptografy [options]",
    NULL,
};

int main(int argc, const char **argv) {
   int embed = 0;
    const char *in = NULL;
    const char *out = NULL;
    const char *wavefile = NULL;
    const char *steg = NULL;
    const char *algorithm = NULL;
    const char *blockcipher = NULL;
    const char *password = NULL;
    const char *testing = NULL;


    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Opciones basicas"),
        OPT_STRING('i', "in", &in, "Achivo de entrada."),
        OPT_BOOLEAN('e', "embed", &embed, "Indica que se va a ocultar la informacion."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave."),
        OPT_STRING('s', "steg", &steg, "Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)"),
        OPT_GROUP("Opcionales"),
        OPT_STRING('a', "algorithm", &algorithm, "Algoritmo de encriptacion. (AES-128 | AES-192 | AES-256 | DES)"),
        OPT_STRING('m', "blockcipher", &blockcipher, "Algoritmo de cifrado de bloques. (ECB | CFB | OFB | CBC)"),
        OPT_STRING('p', "password", &password, "Contraseña."),
        OPT_BOOLEAN('t',"test", &testing, "Corre un par de pruebas"),
        OPT_END(),
    };

 
    
    argparse_init(&argparse, options, usage, 0);
    argparse_describe(&argparse, "\nEsteganografía de archivos wav.\n", "\nITBA 2016\n");
    argc = argparse_parse(&argparse, argc, argv);

    int invalidArguments = 0;

    if (testing != NULL) {
        printf("Se correran una serie de pruebas\n");
        runTests();
        return 0;
    }

    if (embed != NULL && (in == NULL || wavefile == NULL || out == NULL || steg == NULL)) {
        printf("Faltan argumentos para poder realizar el embeded\n");
        return -1;
    }

    if (out == NULL) {
      printf("Se requiere argumento out.\n");
      invalidArguments = 1;
    }

    if (wavefile == NULL) {
      printf("Se requiere argumento wavefile.\n");
      invalidArguments = 1;
    }

    if (steg == NULL){
      printf("Se requiere argumento steg.\n");
      invalidArguments = 1;
    } else if(strcmp(steg,"LSB1") && strcmp(steg,"LSB4") && strcmp(steg,"LSBE")) {
      printf("Argumento steg invalido. Por favor seleccione una de las siguientes opciones: LSB1, LSB4, LSBE\n");
      invalidArguments = 1;
    }

    if (algorithm != NULL && (blockcipher == NULL || password == NULL) || (blockcipher != NULL && (algorithm == NULL || password == NULL)) || (password != NULL && (blockcipher == NULL || algorithm == NULL))) {
      printf("Debe ingresar algoritmo, cifrado de bloque y password, o ninguno\n");
      invalidArguments = 1;
    }

    if(invalidArguments){
      return -1;
    }

    if (argc != 0) {
      // Here we can use argc
        printf("argc: %d\n", argc);
        int i;
        for (i = 0; i < argc; i++) {
          // Here we can use argsv
            printf("argv[%d]: %s\n", i, *(argv + i));
        }
    }



  printf("out %s\n", out);
  printf("in %s\n", in);
  printf("steg %s\n", steg);
  printf("wavefile %s\n", wavefile);
  

  if (embed != NULL) {
    printf("\nEmbeding file, this may take some seconds, please wait...\n");
    LSB_TYPE type;

    if (strcmp(steg, "LSBE") == 0) {
      type = LSBE;
    } else if ( strcmp(steg, "LSB1") == 0) {
      type = LSB1;
    } else if ( strcmp(steg, "LSB4") == 0 ) {
      type = LSB4;
    }

    if (algorithm != NULL) {
      EVP_CIPHER* cipher;
      if (parseAlgorithm(algorithm, blockcipher, &cipher)){
        //should call embed with crypted
      } 
    } else {
      embedLSB(type, in, wavefile, out);  
    }

  } else {
    printf("\nMaking extraction, this may take some seconds, please wait...\n");
    LSB_TYPE type;

    if (strcmp(steg, "LSBE") == 0) {
      type = LSBE;
    } else if ( strcmp(steg, "LSB1") == 0) {
      type = LSB1;
    } else if ( strcmp(steg, "LSB4") == 0 ) {
      type = LSB4;
    }
    extractLSB(type, out, wavefile);
  }

  return 0;
}
