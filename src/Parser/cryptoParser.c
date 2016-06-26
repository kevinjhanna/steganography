#include "cryptoParser.h"

int parseAlgorithm(const unsigned char* algorithm, const unsigned char* blockcipher, EVP_CIPHER** cipher) {
    if (strstr((const char *)algorithm, "des") != NULL) {
        if (strstr((const char *)blockcipher, "ecb") != NULL) {
            *cipher = (EVP_CIPHER*)EVP_des_ecb();
            printf("Selected Cipher EVP_des_ecb\n");
            return SUCCESS;
        }
        if (strstr((const char *)blockcipher, "cfb") != NULL) {
            *cipher = (EVP_CIPHER*)EVP_des_cfb();
            printf("Selected Cipher EVP_des_cfb\n");
            return SUCCESS;
        }
        if (strstr((const char *)blockcipher, "ofb") != NULL) {
            *cipher = (EVP_CIPHER*)EVP_des_ofb();
            printf("Selected Cipher EVP_des_ofb\n");
            return SUCCESS;
        }
        if (strstr((const char *)blockcipher, "cbc") != NULL) {
            *cipher = (EVP_CIPHER*)EVP_des_cbc();
            printf("Selected Cipher EVP_des_cbc\n");
            return SUCCESS;
        }
    }
    if (strstr((const char *)algorithm, "aes") != NULL) {
        if (strstr((const char *)algorithm, "128") != NULL) {
            if (strstr((const char *)blockcipher, "ecb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_128_ecb();
                printf("Selected Cipher EVP_aes_128_ecb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cfb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_128_cfb();
                printf("Selected Cipher EVP_aes_128_cfb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "ofb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_128_ofb();
                printf("Selected Cipher EVP_aes_128_ofb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cbc") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_128_cbc();
                printf("Selected Cipher EVP_aes_128_cbc\n");
                return SUCCESS;
            }
        }
        if (strstr((const char *)algorithm, "192") != NULL) {
            if (strstr((const char *)blockcipher, "ecb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_192_ecb();
                printf("Selected Cipher EVP_aes_192_ecb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cfb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_192_cfb();
                printf("Selected Cipher EVP_aes_192_cfb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "ofb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_192_ofb();
                printf("Selected Cipher EVP_aes_192_ofb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cbc") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_192_cbc();
                printf("Selected Cipher EVP_aes_192_cbc\n");
                return SUCCESS;
            }
        }
        if (strstr((const char *)algorithm, "256") != NULL) {
            if (strstr((const char *)blockcipher, "ecb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_256_ecb();
                printf("Selected Cipher EVP_aes_256_ecb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cfb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_256_cfb();
                printf("Selected Cipher EVP_aes_256_cfb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "ofb") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_256_ofb();
                printf("Selected Cipher EVP_aes_256_ofb\n");
                return SUCCESS;
            }
            if (strstr((const char *)blockcipher, "cbc") != NULL) {
                *cipher = (EVP_CIPHER*)EVP_aes_256_cbc();
                printf("Selected Cipher EVP_aes_256_cbc\n");
                return SUCCESS;
            }
        }
    }
    return FAILURE;
}