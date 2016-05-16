#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "argparse.h"

#include "argparse.h"

static const char *const usage[] = {
    "test_argparse [options] [[--] args]",
    "test_argparse [options]",
    NULL,
};

#define PERM_READ  (1<<0)
#define PERM_WRITE (1<<1)
#define PERM_EXEC  (1<<2)

int
main(int argc, const char **argv)
{
    int embed = 0;
    const char *in = NULL;
    const char *out = NULL;
    const char *wavefile = NULL;
    const char *steg = NULL;
    const char *algorithm = NULL;
    const char *blockcipher = NULL;
    const char *password = NULL;
    
    int num = 0;
    int perms = 0;

    struct argparse_option options[] = {
        OPT_HELP(),
        OPT_GROUP("Opciones basicas"),
        OPT_BOOLEAN('e', "embed", &embed, "Indica que se va a ocultar la informacion."),
        OPT_STRING('i', "in", &in, "Achivo de entrada."),
        OPT_STRING('o', "out", &out, "Archivo de salida."),
        OPT_STRING('w', "wavefile", &wavefile, "Archivo wave."),
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
    if (in != NULL)
        printf("in: %s\n", in);
    else {
    	printf("in argument required\n");
    	invalidArguments = 1;
    }
    if (out != NULL)
        printf("out: %s\n", out);
    else {
    	printf("out argument required\n");
    	invalidArguments = 1;
    }
    if (wavefile != NULL)
        printf("wavefile: %s\n", wavefile);
    else {
    	printf("wavefile argument required\n");
    	invalidArguments = 1;
    }
    if (steg != NULL){
        printf("steg: %s\n", steg);
        if(strcmp(steg,"LSB1") && strcmp(steg,"LSB2") && strcmp(steg,"LSBE")) {
        	printf("invalid argument steg. Please choose one of this values: LSB1, LSB4, LSBE\n");
        	invalidArguments = 1;
        }
    }
    else {
    	printf("steg argument required\n");
    	invalidArguments = 1;
    }
    if(invalidArguments)
    	return 1;


    if (argc != 0) {
        printf("argc: %d\n", argc);
        int i;
        for (i = 0; i < argc; i++) {
            printf("argv[%d]: %s\n", i, *(argv + i));
        }
    }
    if (perms) {
        printf("perms: %d\n", perms);
    }
    return 0;
}