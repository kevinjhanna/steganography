#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "parser.h"

int main(int argc, const char **argv) {
	if(parse(argc, argv)) {
		return 1;
	}
    //Here we should call the respective functions
    return 0;
}