// http://yannesposito.com/Scratch/en/blog/2010-10-14-Fun-with-wav/

#include "wavParser.h"

int is_big_endian(void) {
    union {
        uint32_t i;
        char c[4];
    } bint = {0x01000000};
    return bint.c[0]==1;
}

wavfile parseWav(char* filename) {
    FILE *wav = fopen(filename,"rb");
    struct wavfile header;

    if ( wav == NULL ) {
        fprintf(stderr,"Can't open input file %s\n", filename);
        exit(1);
    }

    // read header
    if ( fread(&header, sizeof(header),1,wav) < 1 ) {
        fprintf(stderr,"Can't read input file header %s\n", filename);
        exit(1);
    }

    // if wav file isn't the same endianness than the current environment
    // we quit
    if ( is_big_endian() ) {
        if (   memcmp( header.id,"RIFX", 4) != 0 ) {
            fprintf(stderr,"ERROR: %s is not a big endian wav file\n", filename);
            exit(1);
        }
    } else {
        if (   memcmp( header.id,"RIFF", 4) != 0 ) {
            fprintf(stderr,"ERROR: %s is not a little endian wav file\n", filename);
            exit(1);
        }
    }

    if (   memcmp( header.wavefmt, "WAVEfmt ", 8) != 0
        || memcmp( header.data, "data", 4) != 0
            ) {
        fprintf(stderr,"ERROR: Not wav format\n");
        exit(1);
    }
    if (header.format != 16) {
        fprintf(stderr,"\nERROR: not 16 bit wav format.");
        exit(1);
    }
    fprintf(stderr,"format: %d bits", header.format);
    if (header.format == 16) {
        fprintf(stderr,", PCM");
    } else {
        fprintf(stderr,", not PCM (%d)", header.format);
    }
    if (header.pcm == 1) {
        fprintf(stderr, " uncompressed" );
    } else {
        fprintf(stderr, " compressed" );
    }

    fprintf(stderr,", channel %d", header.pcm);
    fprintf(stderr,", freq %d", header.frequency );
    fprintf(stderr,", %d bytes per sec", header.bytes_per_second );
    fprintf(stderr,", %d bytes by capture", header.bytes_by_capture );
    fprintf(stderr,", %d bits per sample", header.bytes_by_capture );
    fprintf(stderr,"\n" );

    if ( memcmp( header.data, "data", 4) != 0 ) {
        fprintf(stderr,"ERROR: Prrroblem?\n");
        exit(1);
    }
    fprintf(stderr,"wav format\n");

    // read data
    long long sum=0;
    int16_t value;
    int i=0;
    fprintf(stderr,"---\n", value);
    while( fread(&value,sizeof(value),1,wav) ) {
        if (value<0) { value=-value; }
        sum += value;
    }
    printf("%lld\n",sum);
    return header;
}
