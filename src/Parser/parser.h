#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "argparse.h"

// int parse(int argc, const char ** argv);

/**
 * Parser function to take hidden file from .wav file
 * formato pedido: stegowav –extract –p “papanamericano.wav” -out “kitty” –steg LSBE –a des –m cbc -pass “oculto”
 * Ejemplo: ./stegowav –-extract –p “papanamericano.wav” --out “kitty” –-steg LSBE –a des –m cbc --password “oculto”
 * @param  in               Receives file to be input file
 * @param  out              Receives the file name of the output
 * @param  steg             Indicates the desired algorithm
 * @param  algorithm        Indicates the encryption algorithm
 */
int parseInput(int argc, const char ** argv);
