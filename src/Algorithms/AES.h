#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/bio.h>

#include "../Utilities/bitManipulation.h"

#define MAX_ENCR_LENGTH 1024
#define SUCCESS 0
#define FAILURE !SUCCESS

int encrypt(const unsigned char* key, EVP_CIPHER* cipher, const unsigned char* in, unsigned char** out, int* len);

int saveEncryptedData(unsigned char *out, int len,unsigned char *where);

void mostrarKey(unsigned char key[]);