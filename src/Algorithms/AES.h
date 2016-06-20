#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/bio.h>

#define MAX_ENCR_LENGTH 1024*8
#define SUCCESS 0
#define FAILURE !SUCCESS

int encrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut);

int decrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut);

int saveEncryptedData(unsigned char *out, int len, unsigned char *where);

int loadEncryptedData(unsigned char *out, int len, unsigned char *where);

int saveDecryptedData(unsigned char *out, int len, unsigned char *where);

//int obtenerEntrada(unsigned char *in, unsigned char *inB64);

//void mostrarKey(unsigned char key[]);