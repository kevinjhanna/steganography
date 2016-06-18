#include "AES.h"

//TODO
/*
Now out is a filepath, it should be the data
*/
int encrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut) {
 	unsigned char *key = malloc(sizeof(unsigned char) * EVP_CIPHER_key_length(cipher));
	unsigned char *iv = malloc(sizeof(unsigned char) * EVP_CIPHER_iv_length(cipher));
	int outl, templ;

	*out = (unsigned char * ) malloc(MAX_ENCR_LENGTH * sizeof(unsigned char));
	
	//Key Generation. We don't need to use Salt
 	EVP_BytesToKey(cipher, EVP_md5(), NULL, pwd, strlen(pwd),1, key, iv); 
 	
	//Context initialization
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	//Encription parameters
	EVP_EncryptInit_ex(&ctx, cipher, NULL, key, iv);
	EVP_EncryptUpdate(&ctx, *out, &outl, in, lenIn);
	EVP_EncryptFinal(&ctx, *out + outl, &templ);

	*lenOut = outl + templ;
	//Cleaning context
	EVP_CIPHER_CTX_cleanup(&ctx);
	return EXIT_SUCCESS;
}

int decrypt(const unsigned char* pwd, EVP_CIPHER* cipher, const unsigned char* in, int lenIn, unsigned char** out, int* lenOut) {
 	unsigned char *key = malloc(sizeof(unsigned char) * EVP_CIPHER_key_length(cipher));
	unsigned char *iv = malloc(sizeof(unsigned char) * EVP_CIPHER_iv_length(cipher));
	int outl, templ;

	*out = (unsigned char * ) malloc(MAX_ENCR_LENGTH * sizeof(unsigned char));
	
	//Key Generation. We don't need to use Salt
 	EVP_BytesToKey(cipher, EVP_md5(), NULL, pwd, strlen(pwd),1, key, iv); 
 	
	// //Context initialization
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);

	// //Decrypr parameters
	EVP_DecryptInit_ex(&ctx, cipher, NULL, key, iv);
	EVP_DecryptUpdate(&ctx, *out, &outl, in, lenIn);
	EVP_DecryptFinal_ex(&ctx, *out + outl, &templ);
	
	*lenOut = outl + templ;
	// Cleaning context
	EVP_CIPHER_CTX_cleanup(&ctx);
	return EXIT_SUCCESS;
}

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

// int obtenerEntrada(unsigned char *in, unsigned char
//  *inB64) 
// { 
//     int inl, inl64; 
//     inl64 = strlen (inB64); 
//     inl = inl64 * 3 /4; 
//     fromBase64(in, inB64, inl64); 
//     inl = strlen(in); 
//     return inl; 
// } 

int loadEncryptedData(unsigned char *out, int len, unsigned char *where) {
    BIO *b64;
    BIO *bio;
    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_file());
    if(bio == NULL)
        return -1;

    if(!BIO_read_filename(bio, where))
        return -1;

    bio = BIO_push(b64, bio);
    BIO_read(bio, out, len);
    
    BIO_free_all(bio);
    return 0;
}
