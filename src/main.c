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
  extractLSB(type, "Wavs/testEmbedExtract/extracted/test-LSB1-extraccion", "Wavs/testEmbedExtract/imageEmbeded/newWavLsb1.wav");
}

void testExtractLSBEncrypted(LSB_TYPE type, const struct evp_cipher_st * cipher, char * fileName, char * outName) {
  char * out = malloc(50 * sizeof(char));
  *out = '\0';
  strcat(out, "Wavs/testEncryptDecrypt/imageOut/");
  strcat(out, outName);

  char* stegoWaveFile = malloc(50 * sizeof(char));
  *stegoWaveFile = '\0';
  strcat(stegoWaveFile, "Wavs/testEncryptDecrypt/imageEmbeded/newWav");
  strcat(stegoWaveFile, fileName);
  extractEncryptedLSB(type, out, stegoWaveFile, "aifargotpirc", (EVP_CIPHER*)cipher);
}

void testEmbedLSBCrypted(LSB_TYPE type, const struct evp_cipher_st * cipher, char * fileName) {
  char* fileToHide = "Wavs/testEmbedExtract/images/genericImageToHide.jpg";
  char* carrier = "Wavs/testEmbedExtract/carrier.wav";
  char* stegoWaveFile = malloc(50 * sizeof(char));
  *stegoWaveFile = '\0';
  strcat(stegoWaveFile, "Wavs/testEncryptDecrypt/imageEmbeded/newWav");
  strcat(stegoWaveFile, fileName);
  embedCryptedLSB(type, fileToHide, (EVP_CIPHER*) carrier, stegoWaveFile, "aifargotpirc", cipher);
}

void testEmbedLSB1() {
  char* fileToHide = "Wavs/testEmbedExtract/images/genericImageToHide.jpg";
  char* carrier = "Wavs/testEmbedExtract/carrier.wav";
  char* stegoWaveFile = "Wavs/testEmbedExtract/imageEmbeded/newWavLsb1.wav";
  LSB_TYPE type = LSB1;
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void testExtractLSB4() {
  LSB_TYPE type = LSB4;
  extractLSB(type, "Wavs/testEmbedExtract/extracted/test-LSB4-extraccion", "Wavs/testEmbedExtract/imageEmbeded/newWavLsb4.wav");
}

void testEmbedLSB4() {
  char* fileToHide = "Wavs/testEmbedExtract/images/genericImageToHide.jpg";
  char* carrier = "Wavs/testEmbedExtract/carrier.wav";
  char* stegoWaveFile = "Wavs/testEmbedExtract/imageEmbeded/newWavLsb4.wav";
  LSB_TYPE type = LSB4;
  embedLSB(type, fileToHide, carrier, stegoWaveFile);
}

void testExtractLSBE() {
  LSB_TYPE type = LSBE;
  extractLSB(type, "Wavs/testEmbedExtract/extracted/test-LSBE-extraccion", "Wavs/testEmbedExtract/imageEmbeded/newWavLsbe.wav");
}

void testEmbedLSBE() {
  char* fileToHide = "Wavs/testEmbedExtract/images/genericImageToHide.jpg";
  char* carrier = "Wavs/testEmbedExtract/carrier.wav";
  char* stegoWaveFile = "Wavs/testEmbedExtract/imageEmbeded/newWavLsbe.wav";
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
  
  testEmbedLSBCrypted(LSB1, EVP_aes_192_cfb(), "aes192-cfb-lsb1.wav");
  testEmbedLSBCrypted(LSB4, EVP_aes_192_cfb(), "aes192-cfb-lsb4.wav");
  testEmbedLSBCrypted(LSBE, EVP_aes_192_cfb(), "aes192-cfb-lsbe.wav");
  
  testEmbedLSBCrypted(LSB1, EVP_des_ecb(), "des-ecb-lsb1.wav");
  testEmbedLSBCrypted(LSB4, EVP_des_ecb(), "des-ecb-lsb4.wav");
  testEmbedLSBCrypted(LSBE, EVP_des_ecb(), "des-ecb-lsbe.wav");

  testExtractLSBEncrypted(LSB1, EVP_aes_192_cfb(), "aes192-cfb-lsb1.wav", "image-aes192-cfb-lsb1");
  testExtractLSBEncrypted(LSB4, EVP_aes_192_cfb(), "aes192-cfb-lsb4.wav", "image-aes192-cfb-lsb4");
  testExtractLSBEncrypted(LSBE, EVP_aes_192_cfb(), "aes192-cfb-lsbe.wav", "image-aes192-cfb-lsbe");
  
  testExtractLSBEncrypted(LSB1, EVP_des_ecb(), "des-ecb-lsb1.wav", "image-des-ecb-lsb1");
  testExtractLSBEncrypted(LSB4, EVP_des_ecb(), "des-ecb-lsb4.wav", "image-des-ecb-lsb4");
  testExtractLSBEncrypted(LSBE, EVP_des_ecb(), "des-ecb-lsbe.wav", "image-des-ecb-lsbe");

  printf("Se acaban de correr los tests de LSB1 embed y extract\n");
  printf("Se acaban de correr los tests de LSB4 embed y extract\n");
  printf("Se acaban de correr los tests de LSBE embed y extract\n");
  printf("A partir wav ubicado en directorio testEmbedExtract se generaron portadores con imagen ubicados en imageEmbeded\n");
  printf("Luego a cada uno de estos portadores se les extrajo su respectiva imagen bajo el directorio extracted\n");
  printf("Es decir se testeo el embed y extract sobre cada uno\n\n");
  printf("Se corrieron tambien las mismas pruebas con cifrados aes 192 cfb y des + ecb para los 3 algoritmos\n");


}

static const char *const usage[] = {
    "stegowav [options] [[--] args]",
    "stegowav [options]",
    NULL,
};

/**
 * formato: stegowav -embed –in “kitty.bmp” –p “panamericano.wav” -out “papanamericano.wav” –steg LSBE
 * @param  in               Receives file to be input file
 * @param  out              Receives the file name of the output
 * @param  steg             Indicates the desired algorithm
 * @param  algorithm        Indicates the encryption algorithm
 */

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
        OPT_BOOLEAN('t',"test", &testing, "Corre pruebas de embeber y extraer"),
        OPT_GROUP("Opciones basicas"),
        OPT_BOOLEAN('e', "embed", &embed, "Indica que se va a ocultar la informacion. En caso de no poner este flag se asume que se extrae"),
        OPT_STRING('i', "in", &in, "Achivo de entrada."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave."),
        OPT_STRING('s', "steg", &steg, "Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)"),
        OPT_GROUP("Opcionales"),
        OPT_STRING('a', "algorithm", &algorithm, "Algoritmo de encriptacion. (aes128 | aes192 | aes256 | des)"),
        OPT_STRING('m', "blockcipher", &blockcipher, "Algoritmo de cifrado de bloques. (ecb | cfb | ofb | cbc)"),
        OPT_STRING('p', "password", &password, "Contraseña."),
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

    if (embed && (in == NULL || wavefile == NULL || out == NULL || steg == NULL)) {
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

    if ( password != NULL ) {
      if (algorithm == NULL){
        algorithm = "aes128";
      }
      if (blockcipher == NULL ) {
        blockcipher = "cbc";
      }
    }
    
    if (algorithm != NULL && password == NULL) {
      printf("Debe ingresar password\n");
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
  
  if (embed) {
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
      if (parseAlgorithm((const unsigned char *)algorithm, (const unsigned char *)blockcipher, &cipher) == 0){
        embedCryptedLSB(type, in, wavefile, out, password, cipher);
      } else {
        printf("Error while parsing algorithm\n");
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
    } else {
      type = LSB4;
    }

    if (algorithm != NULL) {
      EVP_CIPHER* cipher;
      if (parseAlgorithm((const unsigned char *)algorithm, (const unsigned char *)blockcipher, &cipher) == 0){
        extractEncryptedLSB(type, out, wavefile, password, cipher);
      } else {
        printf("Error while parsing algorithm\n");
      }
    } else {
      extractLSB(type, out, wavefile);
    }
  }

  return 0;
}
