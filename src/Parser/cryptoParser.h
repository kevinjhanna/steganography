#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>

#define SUCCESS 0
#define FAILURE !SUCCESS

int parseAlgorithm(const unsigned char* algorithm, const unsigned char* blockcipher, EVP_CIPHER** cipher);