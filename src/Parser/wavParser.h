// http://yannesposito.com/Scratch/en/blog/2010-10-14-Fun-with-wav/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for memcmp
#include <stdint.h> // for int16_t and int32_t

typedef struct wavfile
{
    char    id[4];          // should always contain "RIFF"
    int32_t totallength;    // total file length minus 8
    char    wavefmt[8];     // should be "WAVEfmt "
    int32_t format;         // 16 for PCM format
    int16_t pcm;            // 1 for PCM format
    int16_t channels;       // channels
    int32_t frequency;      // sampling frequency
    int32_t bytes_per_second;
    int16_t bytes_by_capture;
    int16_t bits_per_sample;
    char    data[4];        // should always contain "data"
    int32_t bytes_in_data;
} wavfile;

wavfile parseWav(char* filename);
