#include "LSBParser.h"

static int32_t parseLength(BYTE* buffer);

static void parseFileData(BYTE* fileData, BYTE* buffer, int length);

static void parseFileType(char* output, BYTE* buffer);

static char* getFileName(char* filename, char* fileType);

static void saveInFile(char* filename, BYTE* fileData, int length);

static int extractRawMessage(LSB_TYPE LSBType, BYTE* wavData, BYTE* output, int wavDataLength);

static void saveMessageToFile(char* fileName, BYTE* buffer);

//TODO: Add parameters to this.
void extractLSB(LSB_TYPE type, char* fileName, char* wavName) {
  BYTE* wavData;
  // As we don't know the number of bytes of wav yet (AKA: size of wavData), we pass a ** (or, equivalent, &wavData).
  wavHeader wavHeader = parseWavHeader(wavName, &wavData);

  BYTE* output = calloc(wavHeader.dataLength, sizeof(BYTE));
  //int fileSize = extractRawMessage(type, wavData, output, wavHeader.dataLength);
  extractRawMessage(type, wavData, output, wavHeader.dataLength);
  saveMessageToFile(fileName, output);

  free(wavData);
}

static int extractRawMessage(LSB_TYPE LSBType, BYTE* wavData, BYTE* output, int wavDataLength) {
  
  int length;
  
        switch (LSBType) {
          case LSB1:
            length = extractLSB1(output, wavData, wavDataLength);
            break;
          case LSB4:
            length = extractLSB4(output, wavData, wavDataLength);
            break;
          case LSBE:
            length = extractLSBE(output, wavData, wavDataLength);
        }
  
  return length;
}

// Private

static void saveMessageToFile(char* fileName, BYTE* buffer) {
  int32_t length = parseLength(buffer);
  BYTE * fileData = malloc(length * sizeof(BYTE));
  char fileType[20];
  
  parseFileData(fileData, buffer + sizeof(length), length);
  
  parseFileType(fileType, buffer + sizeof(length) + length);
  
  char* fileNameWithExtension = getFileName(fileName, fileType);
  
  saveInFile(fileNameWithExtension, fileData, length);
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

static char* getFileName(char* filename, char* fileType) {
  char *concatenated = malloc(strlen(filename) + strlen(fileType) +1);//+1 for the zero-terminator
  //in real code you would check for errors in malloc here
  strcpy(concatenated, filename);
  strcat(concatenated, fileType);
  
  return concatenated;
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
