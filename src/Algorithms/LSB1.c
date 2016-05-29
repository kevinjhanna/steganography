#include "LSB1.h"
#include "../Utilities/bitManipulation.h"
#include "../Parser/wavParser.h"
#include "../Utilities/utilities.h"

static int32_t parseLength(BYTE* buffer);

static void parseFileData(BYTE* fileData, BYTE* buffer, int length);

static void parseFileType(char* output, char* buffer);

static void getFileName(char* filename, char* fileType);

static void saveInFile(char* filename, BYTE* fileData, int length);

static int extractRawMessage(BYTE* wavData, BYTE* output, int wavDataLength);

static void saveMessageToFile(char* fileName, BYTE* buffer);

//TODO: Add parameters to this.
void extractLSB() {
  BYTE* wavData;
  // As we don't know the number of bytes of wav yet (AKA: size of wavData), we pass a ** (or, equivalent, &wavData).
  wavHeader wavHeader = parseWavHeader("Wavs/funT1.wav", &wavData);

  BYTE* output = calloc(wavHeader.dataLength, sizeof(BYTE));
  int fileSize = extractRawMessage(wavData, output, wavHeader.dataLength);

  //TODO: This should be received by parameter
  char filename[50] = "./output";

  saveMessageToFile(filename, output);

  free(wavData);
}

static int extractRawMessage(BYTE* wavData, BYTE* output, int wavDataLength) {

  int byteIterator = 0;
  int bitIterator = 0;

  for (int i = 0; i < wavDataLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
    if (isOdd(i)) {
      // Here we are in a block in which we need the last bit.
      // The bitIterator is the variable that moves from 0 to 7, and it indicates the place in which we need to store the
      // next bit.
      output[byteIterator] = setBit(bitIterator, output[byteIterator], getBit(7, wavData[i]));
      // if the bitIterator reaches 7, it means that we need to write in a new byte.
      // So we reset bitIterator to 0 and increase the byteIterator;
      if (bitIterator == 7) {
        byteIterator++;
        bitIterator = 0;
      } else {
        bitIterator++;
      }
    }
  }
  return byteIterator;
}

// Private

static void saveMessageToFile(char* fileName, BYTE* buffer) {
  int32_t length = parseLength(buffer);
  BYTE * fileData = malloc(length * sizeof(BYTE));;
  char fileType[20];

  parseFileData(fileData, buffer + sizeof(length), length);

  parseFileType(fileType, buffer + sizeof(length) + length);

  getFileName(fileName, fileType);

  saveInFile(fileName, fileData, length);
}

static int32_t parseLength(BYTE* buffer) {
  int32_t length = 0;
  memcpy(&length, buffer, sizeof(length));

  // This is an issue with endianness.
  // It depends on the endianess of whom is executing this program.
  if (isLittleEndian()) {
    return ntohl(length);
  } else {
    return htonl(length);
  }
}

static void parseFileData(BYTE* fileData, BYTE* buffer, int length) {
    memcpy(fileData, buffer, length * sizeof(BYTE));
}

static void parseFileType(char* output, char* buffer) {
  //TODO: validate if it starts with '.' (correct format).
  sprintf(output, "%s", buffer);
}

static void getFileName(char* filename, char* fileType) {
    strcat(filename, fileType);
}

static void saveInFile(char* filename, BYTE* fileData, int length) {
  FILE *fp = fopen(filename, "w+");

  if (fp == NULL) {
    printf("Error opening file to write\n");
  }

  fwrite(fileData, sizeof(BYTE), length, fp);

  printf("Message successfully extracted to %s\n", filename);

  fclose(fp);
}
