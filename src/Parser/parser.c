#include "parser.h"
#include "../Algorithms/AES.h"

static const char *const usage[] = {
    "criptografy [options] [[--] args]",
    "criptografy [options]",
    NULL,
};

/**
 * formato: stegowav -embed –in “kitty.bmp” –p “panamericano.wav” -out “papanamericano.wav” –steg LSBE
 * @param  in               Receives file to be input file
 * @param  out              Receives the file name of the output
 * @param  steg             Indicates the desired algorithm
 * @param  algorithm        Indicates the encryption algorithm
 */

int parse(int argc, const char ** argv) {
	int embed = 0;
    int len = 0;
    int inLen = 0;
    unsigned char *outData;
    unsigned char* inCrypted;
    const unsigned char *in = NULL;
    const unsigned char *out = NULL;
    const unsigned char *wavefile = NULL;
    const unsigned char *steg = NULL;
    const unsigned char *algorithm = NULL;
    const unsigned char *blockcipher = NULL;
    const unsigned char *password = NULL;
    EVP_CIPHER* cipher;

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Opciones basicas"),
        OPT_BOOLEAN('e', "embed", &embed, "Indica que se va a ocultar la informacion."),
        OPT_STRING('i', "in", &in, "Achivo de entrada."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave."),
        OPT_STRING('s', "steg", &steg, "Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)"),
        OPT_GROUP("Opcionales"),
        OPT_STRING('a', "algorithm", &algorithm, "Algoritmo de encriptacion. (aes-128 | aes-192 | aes-256 | des)"),
        OPT_STRING('m', "blockcipher", &blockcipher, "Algoritmo de cifrado de bloques. (ecb | cfb | ofb | cbc)"),
        OPT_STRING('p', "password", &password, "Contraseña."),
        OPT_END(),
    };

    struct argparse argparse;
    argparse_init(&argparse, options, usage, 0);
    argparse_describe(&argparse, "\nEsteganografía de archivos wav.", "\nEste es un programa muy bueno; :).");
    argc = argparse_parse(&argparse, argc, argv);

    int invalidArguments = 0;

    if (in == NULL) {
    	printf("Se requiere argumento in.\n");
    	invalidArguments = 1;
    }

    if (out == NULL) {
    	printf("Se requiere argumento out.\n");
    	invalidArguments = 1;
    }

    // if (wavefile == NULL) {
    // 	printf("Se requiere argumento wavefile.\n");
    // 	invalidArguments = 1;
    // }

    // if (steg == NULL){
    // 	printf("Se requiere argumento steg.\n");
    // 	invalidArguments = 1;
    // } else if(strcmp(steg,"LSB1") && strcmp(steg,"LSB2") && strcmp(steg,"LSBE")) {
    // 	printf("Argumento steg invalido. Por favor seleccione una de las siguientes opciones: LSB1, LSB4, LSBE\n");
    // 	invalidArguments = 1;
    // }
    if (password != NULL) {
        if (algorithm == NULL) {
            algorithm = "aes128";
        }
        if (blockcipher == NULL) {
            blockcipher = "cbc";
        }
    }

    if(invalidArguments){
    	return -1;
    }
    if(parseAlgorithm(algorithm, blockcipher, &cipher) == -1) {
        printf("Algoritmo inválido.\n");
        return -1;
    }
    //encrypt(password, cipher, in, &outData, &len);

    //base64Decode(const char *b64message, const size_t length, unsigned char **buffer);
    //inLen = obtenerEntrada(inCrypted, in);
    decrypt(password, cipher, inCrypted, inLen, &out, &len);
    // printf("outData:%p\n",(outData));
    printf("len:%s\n",out);
    //saveEncryptedData(outData, len, out);

    if (argc != 0) {
    	// Here we can use argc
        // printf("argc: %d\n", argc);
        int i;
        for (i = 0; i < argc; i++) {
        	// Here we can use argsv
            // printf("argv[%d]: %s\n", i, *(argv + i));
        }
    }

    return 0;
}


/**
 * Parser function to take hidden file from .wav file
 * formato: stegowav –extract –p “papanamericano.wav” -out “kitty” –steg LSBE –a des –m cbc -pass “oculto”
 * @param  in               Receives file to be input file
 * @param  out              Receives the file name of the output
 * @param  steg             Indicates the desired algorithm
 * @param  algorithm        Indicates the encryption algorithm
 */

int parseInput(int argc, const char ** argv) {
    const char *extract = NULL;
    const char *out = NULL;
    const char *wavefile = NULL;
    const char *steg = NULL;
    const char *algorithm = NULL;
    const char *blockcipher = NULL;
    const char *password = NULL;

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Opciones basicas"),
        OPT_BOOLEAN('e', "extract", &extract, "Indica que se va a extraer la informacion."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave portador."),
        OPT_STRING('s', "steg", &steg, "Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)"),
        OPT_GROUP("Opcionales"),
        OPT_STRING('a', "algorithm", &algorithm, "Algoritmo de encriptacion. (AES-128 | AES-192 | AES-256 | DES)"),
        OPT_STRING('m', "blockcipher", &blockcipher, "Algoritmo de cifrado de bloques. (ECB | CFB | OFB | CBC)"),
        OPT_STRING('p', "password", &password, "Contraseña."),
        OPT_END(),
    };

    struct argparse argparse;
    argparse_init(&argparse, options, usage, 0);
    argparse_describe(&argparse, "\nEsteganografía de archivos wav.", "\nEste es un programa muy bueno; :).");
    argc = argparse_parse(&argparse, argc, argv);

    int invalidArguments = 0;


    if (extract == NULL) {
        printf("Se requiere argumento extract.\n");
        invalidArguments = 1;
    }

    if (out == NULL) {
        printf("Se requiere argumento out.\n");
        invalidArguments = 1;
    }

    if (wavefile == NULL) {
        printf("Se requiere argumento wavefile.\n");
        invalidArguments = 1;
    }

    if (steg == NULL){
        printf("Se requiere argumento steg.\n");
        invalidArguments = 1;
    } else if(strcmp(steg,"LSB1") && strcmp(steg,"LSB2") && strcmp(steg,"LSBE")) {
        printf("Argumento steg invalido. Por favor seleccione una de las siguientes opciones: LSB1, LSB4, LSBE\n");
        invalidArguments = 1;
    }

    if(invalidArguments){
        return -1;
    }

    if (argc != 0) {
        // Here we can use argc
        // printf("argc: %d\n", argc);
        int i;
        for (i = 0; i < argc; i++) {
            // Here we can use argsv
            // printf("argv[%d]: %s\n", i, *(argv + i));
        }
    }

    return 0;
}

// int parseAlgorithm(const unsigned char* algorithm, const unsigned char* blockcipher, EVP_CIPHER** cipher) {
//     OpenSSL_add_all_ciphers();
//     unsigned char* algStr = malloc(12 * sizeof(BYTE));
//     strcpy(algStr, algorithm);
//     strcat(algStr,"-");
//     strcat(algStr,blockcipher);
//     printf("Alg:%s",algStr);
//     *cipher = EVP_get_cipherbyname(algStr);
//     return 0;
// }

int parseAlgorithm(const unsigned char* algorithm, const unsigned char* blockcipher, EVP_CIPHER** cipher) {
    if (strstr(algorithm, "des") != NULL) {
        if (strstr(blockcipher, "ecb") != NULL) {
            *cipher = EVP_des_ecb();
            printf("Selected Cipher EVP_des_ecb");
            return 0;
        }
        if (strstr(blockcipher, "cfb") != NULL) {
            *cipher = EVP_des_cfb();
            printf("Selected Cipher EVP_des_cfb");
            return 0;
        }
        if (strstr(blockcipher, "ofb") != NULL) {
            *cipher = EVP_des_ofb();
            printf("Selected Cipher EVP_des_ofb");
            return 0;
        }
        if (strstr(blockcipher, "cbc") != NULL) {
            *cipher = EVP_des_cbc();
            printf("Selected Cipher EVP_des_cbc");
            return 0;
        }
    }
    if (strstr(algorithm, "aes") != NULL) {
        if (strstr(algorithm, "128") != NULL) {
            if (strstr(blockcipher, "ecb") != NULL) {
                *cipher = EVP_aes_128_ecb();
                printf("Selected Cipher EVP_aes_128_ecb");
                return 0;
            }
            if (strstr(blockcipher, "cfb") != NULL) {
                *cipher = EVP_aes_128_cfb();
                printf("Selected Cipher EVP_aes_128_cfb");
                return 0;
            }
            if (strstr(blockcipher, "ofb") != NULL) {
                *cipher = EVP_aes_128_ofb();
                printf("Selected Cipher EVP_aes_128_ofb");
                return 0;
            }
            if (strstr(blockcipher, "cbc") != NULL) {
                *cipher = EVP_aes_128_cbc();
                printf("Selected Cipher EVP_aes_128_cbc");
                return 0;
            }
        }
        if (strstr(algorithm, "192") != NULL) {
            if (strstr(blockcipher, "ecb") != NULL) {
                *cipher = EVP_aes_192_ecb();
                printf("Selected Cipher EVP_aes_192_ecb");
                return 0;
            }
            if (strstr(blockcipher, "cfb") != NULL) {
                *cipher = EVP_aes_192_cfb();
                printf("Selected Cipher EVP_aes_192_cfb");
                return 0;
            }
            if (strstr(blockcipher, "ofb") != NULL) {
                *cipher = EVP_aes_192_ofb();
                printf("Selected Cipher EVP_aes_192_ofb");
                return 0;
            }
            if (strstr(blockcipher, "cbc") != NULL) {
                *cipher = EVP_aes_192_cbc();
                printf("Selected Cipher EVP_aes_192_cbc");
                return 0;
            }
        }
        if (strstr(algorithm, "256") != NULL) {
            if (strstr(blockcipher, "ecb") != NULL) {
                *cipher = EVP_aes_256_ecb();
                printf("Selected Cipher EVP_aes_256_ecb");
                return 0;
            }
            if (strstr(blockcipher, "cfb") != NULL) {
                *cipher = EVP_aes_256_cfb();
                printf("Selected Cipher EVP_aes_256_cfb");
                return 0;
            }
            if (strstr(blockcipher, "ofb") != NULL) {
                *cipher = EVP_aes_256_ofb();
                printf("Selected Cipher EVP_aes_256_ofb");
                return 0;
            }
            if (strstr(blockcipher, "cbc") != NULL) {
                *cipher = EVP_aes_256_cbc();
                printf("Selected Cipher EVP_aes_256_cbc");
                return 0;
            }
        }
    }
    return -1;
}