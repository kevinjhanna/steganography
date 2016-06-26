#include "parser.h"

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
    const char *in = NULL;
    const char *out = NULL;
    const char *wavefile = NULL;
    const char *steg = NULL;
    const char *algorithm = NULL;
    const char *blockcipher = NULL;
    const char *password = NULL;
    const char *testing = NULL;

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Opciones basicas"),
        OPT_BOOLEAN('e', "embed", &embed, "Indica que se va a ocultar la informacion."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave."),
        OPT_STRING('s', "steg", &steg, "Algoritmo de esteganografiado. (LSB1 | LSB4 | LSBE)"),
        OPT_GROUP("Opcionales"),
        OPT_STRING('i', "in", &in, "Achivo de entrada."),
        OPT_STRING('a', "algorithm", &algorithm, "Algoritmo de encriptacion. (AES-128 | AES-192 | AES-256 | DES)"),
        OPT_STRING('m', "blockcipher", &blockcipher, "Algoritmo de cifrado de bloques. (ECB | CFB | OFB | CBC)"),
        OPT_STRING('p', "password", &password, "Contraseña."),
        OPT_BOOLEAN('t',"test", &testing, "Corre un par de pruebas"),
        OPT_END(),
    };

    
    argparse_init(&argparse, options, usage, 0);
    argparse_describe(&argparse, "\nEsteganografía de archivos wav.\n", "\nITBA 2016\n");
    argc = argparse_parse(&argparse, argc, argv);

    int invalidArguments = 0;

    if (testing != NULL) {
        printf("Se correran una serie de pruebas\n");
        return RUN_TESTS;
    }

    if (embed != NULL && (in == NULL || wavefile == NULL || out == NULL || steg == NULL)) {
        printf("Faltan argumentos para poder realizar el embeded\n");
        return -1;
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

    return 1;
}

