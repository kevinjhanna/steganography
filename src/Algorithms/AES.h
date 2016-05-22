#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/aes.h>
#include <openssl/bio.h>

int encrypt(const char* key, int AESType, const char* cin, const char* cout);