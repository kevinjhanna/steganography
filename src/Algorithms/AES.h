#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <openssl/evp.h>
#include <openssl/bio.h>

#define MAX_ENCR_LENGTH 1024*8
#define SUCCESS 0
#define FAILURE !SUCCESS

<<<<<<< HEAD
int encrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut);

int decrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut);

int saveEncryptedData(unsigned char *out, int len,unsigned char *where);

int obtenerEntrada(unsigned char *in, unsigned char *inB64);

=======
int encrypt(const unsigned char* key, EVP_CIPHER* cipher, const unsigned char* in, unsigned char** out, int* len);

int saveEncryptedData(unsigned char *out, int len,unsigned char *where);

>>>>>>> cf1be73625eee1acc703fe98887e48788cebe3f2
void mostrarKey(unsigned char key[]);