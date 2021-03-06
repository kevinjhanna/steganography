#include "crypto.h"

int encrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut) {
 	unsigned char *key = calloc(sizeof(unsigned char), EVP_CIPHER_key_length(cipher));
	unsigned char *iv = calloc(sizeof(unsigned char), EVP_CIPHER_iv_length(cipher));
	int outl, templ;
	
	*out = (unsigned char * ) calloc(MAX_ENCR_LENGTH, sizeof(unsigned char));
	
	//Key Generation. We don't need to use Salt
 	EVP_BytesToKey(cipher, EVP_md5(), NOSALT,(const unsigned char *) pwd, strlen((const char *)pwd),1, key, iv); 
 	
	//Context initialization
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	//Encription parameters
	EVP_EncryptInit_ex(&ctx, cipher, DEFAULTENGINE, key, iv);
	EVP_EncryptUpdate(&ctx, *out, &outl, in, lenIn);
	EVP_EncryptFinal(&ctx, *out + outl, &templ);
	

	*lenOut = outl + templ;
	//Cleaning context
	EVP_CIPHER_CTX_cleanup(&ctx);
	return EXIT_SUCCESS;
}

int decrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut) {
 	unsigned char *key = calloc(sizeof(unsigned char), EVP_CIPHER_key_length(cipher));
	unsigned char *iv = calloc(sizeof(unsigned char), EVP_CIPHER_iv_length(cipher));
	int outl, templ;

	printf("Password:%s\n",pwd);
	printf("lenIn:%d\n",lenIn);
	printf("lenOutInit:%d\n",*lenOut);

	*out = (unsigned char * ) calloc(MAX_ENCR_LENGTH, sizeof(unsigned char));

	// *out = (unsigned char * ) calloc(lenIn * sizeof(unsigned char) + 200 * sizeof(unsigned char));
	
	//Key Generation. We don't need to use Salt
 	EVP_BytesToKey(cipher, EVP_md5(), NOSALT, pwd, strlen((const char *)pwd),1, key, iv); 
 	
	// //Context initialization
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	// //Decrypr parameters
	if (EVP_DecryptInit_ex(&ctx, cipher, DEFAULTENGINE, key, iv) == 0) {
		printf("ERROR EVP_DecryptInit_ex\n");
	}
	if (EVP_DecryptUpdate(&ctx, *out, &outl, in, lenIn) == 0) {
		printf("ERROR EVP_DecryptUpdate\n");
	}
	printf("Init encrypt length:%d\n",outl);
	if (EVP_DecryptFinal_ex(&ctx, *out + outl, &templ) == 0) {
		printf("ERROR EVP_DecryptFinal_ex\n");
	}
	printf("Padding encrypt length:%d\n",templ);
	
	*lenOut = outl + templ;

	// Cleaning context
	EVP_CIPHER_CTX_cleanup(&ctx);
	return EXIT_SUCCESS;
}