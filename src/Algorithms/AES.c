#include "AES.h"

int encrypt(const char* key, int AESType, const char* cin, const char* fout) {

    AES_KEY ks;
    unsigned char* in;
    unsigned char* out;
    unsigned char* cout;
    unsigned char* inPad;
    unsigned char* uKey;
    int inl, outl;

    if (strlen(key)*8 != AESType) {
        printf("Key length does not match with AES-%d", AESType);
        return -1;
    }

    toUnsignedChar(key,uKey);
    AES_set_encrypt_key(uKey, AESType, &ks); 

    toUnsignedChar(cin, in);
    /* Padding */
    inl = strlen(in);
    padding(in, &inl, AES_BLOCK_SIZE, inPad); 

    /* Modo ecb encripta de a BLOQUES*/
    out = malloc (inl);
    outl = inl;
    EncryptECB(inPad, inl, out, &ks);

    toUnsignedChar(fout, cout);
    saveEncryptedData(out, outl, cout);
    
    free(in);
    free(out);
    return 0; 

}

int decrypt() {
    //TODO
    return 0;
}

int toUnsignedChar(const char* in, unsigned char* out) {
    out = malloc(strlen(in) * sizeof(unsigned char));
    strncpy(out, in, strlen(in));
    return 0;
}

void EncryptECB(unsigned char *in, int inl, unsigned char *out, AES_KEY *ks)
{
    unsigned char inB[AES_BLOCK_SIZE]; 
    unsigned char outB[AES_BLOCK_SIZE];
    int numB;
    int i;
    numB = inl / AES_BLOCK_SIZE;
    for (i = 0; i < numB; i++) {
        memcpy(inB, in + i * AES_BLOCK_SIZE, AES_BLOCK_SIZE);
        AES_ecb_encrypt(inB, outB, ks, AES_ENCRYPT);
        memcpy(out + i * AES_BLOCK_SIZE, outB, AES_BLOCK_SIZE);
    }
    return;
}

void padding(unsigned char *in, int *inl, size_t blocksize, unsigned char* inPad) {
    int pad;
    int i;
    pad = blocksize - (*inl) % blocksize;
    inPad = malloc(*inl + pad);
    memcpy(inPad, in, *inl);
    for (i = (*inl); i < (*inl + pad); i++)
        inPad[i] = pad;
    *inl +=pad;
    return;
} 

int saveEncryptedData(unsigned char *out, int len,unsigned char *where) {
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