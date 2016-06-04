// http://yannesposito.com/Scratch/en/blog/2010-10-14-Fun-with-wav/

#include "../Utilities/utilities.h"
#include "wavParser.h"

wavHeader parseWavHeader(char* filename, BYTE** parsedBuffer) {
    FILE *wav = fopen(filename,"rb");
    struct wavHeader header;

    if ( wav == NULL ) {
        fprintf(stderr,"Can't open input file %s\n", filename);
        exit(1);
    }


    if ( fread(&header, sizeof(header),1,wav) < 1 ) {
        fprintf(stderr,"Can't read input file header %s\n", filename);
        exit(1);
    }

    // if wav file isn't the same endianness than the current environment
    // we quit
    if ( isBigEndian() ) {
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
    fprintf(stderr,"Format: %d bits", header.format);
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
    fprintf(stderr, "\n" );
    fprintf(stderr, "Header length: %lu\n", sizeof(header));
    fprintf(stderr, "Channel: %d\n", header.pcm);
    fprintf(stderr, "Total file length: %d Bytes\n", header.totallength);
    fprintf(stderr, "Frequency: %d\n", header.frequency);
    fprintf(stderr, "Bytes per sec: %d\n", header.bytes_per_second);
    fprintf(stderr, "Bytes by capture: %d\n", header.bytes_by_capture);
    fprintf(stderr, "Bits per sample: %d\n", header.bytes_by_capture);
    fprintf(stderr, "Data length: %d Bytes", header.dataLength);
    fprintf(stderr, "\n" );
    fprintf(stderr, "\n" );

    if ( memcmp( header.data, "data", 4) != 0 ) {
        fprintf(stderr,"ERROR: Prrroblem?\n");
        exit(1);
    }

    BYTE* buffer = calloc(header.dataLength, sizeof(BYTE));

    if (buffer == NULL) {
      printf("error at alloc\n");
      exit(1);
    }
    // This could fail, but meh.
    int read = fread(buffer, sizeof(BYTE), header.dataLength, wav);

    *parsedBuffer = buffer;
    return header;
}
