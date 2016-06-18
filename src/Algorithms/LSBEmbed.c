#include "LSBEmbed.h"

static int loadMessageFromFile(BYTE** rawMessage, char* fileName);

static char* getFileType(char *fileName);

static void embedMessage(LSB_TYPE type, BYTE* rawMessage, BYTE* wavData, int wavDataLength, int length);

static void saveInFile(char* filename, BYTE* fileData, wavHeader wavHeader);

void embedLSB(LSB_TYPE type, char* fileName, char* wavName, char* waveFileName) {
  BYTE* wavData;
  // As we don't know the number of bytes of wav yet (AKA: size of wavData), we pass a ** (or, equivalent, &wavData).
  wavHeader wavHeader = parseWavHeader(wavName, &wavData);
  
  BYTE* message;
  
  int length = loadMessageFromFile(&message, fileName);
  
  //TODO: Validate that length is valid for message to fit the carrier
  switch (type) {
    case LSB1:
      embedLSB1(message, wavData, wavHeader.dataLength, length);
      break;
    case LSB4:
      embedLSB4(message, wavData, wavHeader.dataLength, length);
      break;
  }
  
  saveInFile(waveFileName, wavData, wavHeader);
  free(wavData);
}

static int loadMessageFromFile(BYTE** rawMessage, char* fileName) {
  FILE *fp = fopen(fileName, "r");
  
  if (fp == NULL) {
    printf("Error opening file to read\n");
  }
  
  char* fileType = getFileType(fileName);
  int fileTypeLength = (int)strlen(fileType) + 1;
  
  struct stat st;
  stat(fileName, &st);
  
  int fileSize = getFileSize(fileName);
  
  BYTE* buffer = malloc(sizeof(fileSize) + sizeof(BYTE) * fileSize + fileTypeLength);
  
  int aux = toCarrier(fileSize);
  memcpy(buffer, &aux, sizeof(fileSize));
  
  //TODO: This could fail.
  int read = fread(buffer + sizeof(fileSize), sizeof(BYTE), fileSize, fp);
  
  strcpy(buffer + sizeof(fileSize) + sizeof(BYTE) * fileSize, fileType);
  
  *rawMessage = buffer;
  fclose(fp);
  return sizeof(fileSize) + fileSize + fileTypeLength;
}

char* getFileType(char *filename) {
  char *dot = strrchr(filename, '.');
  if(!dot || dot == filename) {
    return "";
  }
  return dot;
}

static void saveInFile(char* filename, BYTE* fileData, wavHeader wavHeader) {
  FILE *fp = fopen(filename, "w+");
  
  if (fp == NULL) {
    printf("Error opening file to write\n");
  }
  
  fwrite(&wavHeader, sizeof(wavHeader), 1, fp);
  fwrite(fileData, wavHeader.dataLength, 1, fp);
  
  printf("Message successfully extracted to %s\n", filename);
  
  fclose(fp);
}
