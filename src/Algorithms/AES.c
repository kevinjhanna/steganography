#include "AES.h"

//TODO
/*
Now out is a filepath, it should be the data
*/
int encrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, unsigned char** out, int* len) {
 	unsigned char *key = malloc(sizeof(unsigned char) * EVP_CIPHER_key_length(cipher));
	unsigned char *iv = malloc(sizeof(unsigned char) * EVP_CIPHER_iv_length(cipher));
	int outl, templ;

	*out = (unsigned char * ) malloc(MAX_ENCR_LENGTH * sizeof(BYTE));
	
	//Key Generation. We don't need to use Salt
 	EVP_BytesToKey(cipher, EVP_md5(), NULL, pwd, strlen(pwd),1, key, iv); 
 	
	//Context initialization
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	//Encription parameters
	EVP_EncryptInit_ex(&ctx, cipher, NULL, key, iv);
	EVP_EncryptUpdate(&ctx, out, &outl, in, strlen(in));
	EVP_EncryptFinal(&ctx, *out + outl, &templ);
	
	//Cleaning context
	EVP_CIPHER_CTX_cleanup(&ctx);
	*len = outl + templ;
	return EXIT_SUCCESS;
}

// // int decrypt() {
// //     //TODO
// //     return 0;
// // }

// // int toUnsignedChar(const char* in, unsigned char* out) {
// //     out = malloc(strlen(in) * sizeof(unsigned char));
// //     strncpy(out, in, strlen(in));
// //     return 0;
// // }

// // void EncryptECB(unsigned char *in, int inl, unsigned char *out, AES_KEY *ks)
// // {
// //     unsigned char inB[AES_BLOCK_SIZE]; 
// //     unsigned char outB[AES_BLOCK_SIZE];
// //     int numB;
// //     int i;
// //     numB = inl / AES_BLOCK_SIZE;
// //     for (i = 0; i < numB; i++) {
// //         memcpy(inB, in + i * AES_BLOCK_SIZE, AES_BLOCK_SIZE);
// //         AES_ecb_encrypt(inB, outB, ks, AES_ENCRYPT);
// //         memcpy(out + i * AES_BLOCK_SIZE, outB, AES_BLOCK_SIZE);
// //     }
// //     return;
// // }

// // void padding(unsigned char *in, int *inl, size_t blocksize, unsigned char* inPad) {
// //     int pad;
// //     int i;
// //     pad = blocksize - (*inl) % blocksize;
// //     inPad = malloc(*inl + pad);
// //     memcpy(inPad, in, *inl);
// //     for (i = (*inl); i < (*inl + pad); i++)
// //         inPad[i] = pad;
// //     *inl +=pad;
// //     return;
// // } 

int saveEncryptedData(unsigned char *out, int len, unsigned char *where) {
    BIO *b64;
    BIO *bio;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_file());
    if(bio == NULL)
        return -1;

    if(!BIO_write_filename(bio, where))
        return -1;

    bio = BIO_push(b64, bio);
    BIO_write(bio, out, len);
    BIO_flush(bio);
    BIO_free_all(bio);
    return 0;
}