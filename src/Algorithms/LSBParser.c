#include "LSBParser.h"

static int32_t parseLength(BYTE* buffer);

static void parseFileData(BYTE* fileData, BYTE* buffer, int length);

static void parseFileType(char* output, BYTE* buffer);

static void getFileName(char* filename, char* fileType);

static void saveInFile(char* filename, BYTE* fileData, int length);

static int extractRawMessage(LSB_TYPE LSBType, BYTE* wavData, BYTE* output, int wavDataLength);

static void saveMessageToFile(char* fileName, BYTE* buffer);

//TODO: Add parameters to this.
void extractLSB(LSB_TYPE type, char* fileName, char* wavName) {
  BYTE* wavData;
  // As we don't know the number of bytes of wav yet (AKA: size of wavData), we pass a ** (or, equivalent, &wavData).
  wavHeader wavHeader = parseWavHeader(wavName, &wavData);

  BYTE* output = calloc(wavHeader.dataLength, sizeof(BYTE));
  int fileSize = extractRawMessage(type, wavData, output, wavHeader.dataLength);

  saveMessageToFile(fileName, output);

  free(wavData);
}

static int extractRawMessage(LSB_TYPE LSBType, BYTE* wavData, BYTE* output, int wavDataLength) {
  
  int byteIterator = 0;
  int bitIterator = 0;
  int i;
  for (i = 0; i < wavDataLength; i++) {
    // TODO: Change this. It is assuming the size of the block is 16 bits. It actually depends on the bit rate.
    // Remember that i refers to bytes.
    if (isOdd(i)) {
      
      switch (LSBType) {
        case LSB1:
          extractLSB1(&bitIterator, &byteIterator, wavData[i], output);
          break;
        case LSB4:
          extractLSB4(&bitIterator, &byteIterator, wavData[i], output);
          break;
        case LSBE:
          extractLSBE(&bitIterator, &byteIterator, wavData[i], output);
      }
    }
  }
  
  return byteIterator;
}

// Private

static void saveMessageToFile(char* fileName, BYTE* buffer) {
  int32_t length = parseLength(buffer);
  BYTE * fileData = malloc(length * sizeof(BYTE));
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
  return ntohl(length);
}

static void parseFileData(BYTE* fileData, BYTE* buffer, int length) {
  memcpy(fileData, buffer, length * sizeof(BYTE));
}

static void parseFileType(char* output, BYTE* buffer) {
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
