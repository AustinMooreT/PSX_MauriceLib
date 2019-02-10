#include "../inc/cd.h"

#ifdef CD_ERROR
bool isDsActive;
#endif // CD_ERROR

// CD_readerStatus
#ifdef CD_ERROR
CD_ERROR_TYPE CD_readerStatus(CD_READER_STATUS_TYPE* status) {
  unsigned char temp; // TODO @ maurice : figure out what gets stored in here.
  int results;
  results = DsReadSync(&temp);
  if (results < 0) {
    *status = ERROR;
    return CD_FILE_READ_ERROR;
  } else if (results > 0) {
    *status = READING;
    return CD_NO_ERROR;
  } else {
    *status = COMPLETE;
    return CD_NO_ERROR;
  }
}
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_readerStatus(CD_READER_STATUS_TYPE* status) {
  unsigned char temp; // TODO @ maurice : figure out what gets stored in here.
  int results = DsReadSync(&temp);
  if (results < 0) {
    *status = ERROR;
  } else if (results > 0) {
    *status = READING;
  } else {
    *status = COMPLETE;
  }
}
#endif // CD_ERROR

// CD_initReader
#ifdef CD_ERROR
CD_ERROR_TYPE CD_initReader() {
  if (isDsActive) {
    return CD_READER_RUNNING;
  }
  DsInit();
  return CD_NO_ERROR;
}
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_initReader() {
  DsInit();
}
#endif // CD_ERROR

// CD_stopReader
#ifdef CD_ERROR
CD_ERROR_TYPE CD_stopReader() {
  int status;
  if (!isDsActive) {
    return CD_READER_STOPPED;
  }
  CD_readerStatus(status&);
  if (status == READING) {
    return CD_READER_RUNNING;
  }
  isReaderActive = false;
  DsClose();
  return CD_NO_ERROR;
}
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_stopReader() {
  DsClose();
}
#endif // CD_ERROR

#ifdef CD_ERROR
CD_ERROR_TYPE CD_readFile(void* fileData, char* fileName) {
  DslFILE fileInfo;
  int sizeSectors;
  int status;
  CD_readerStatus(status&);
  if (status == READING) {
    return CD_READER_RUNNING;
  }
  if (DsSearchFile(&fileInfo, fileName) <= 0) {
    return CD_FILE_READ_ERROR;
  }
  // TODO @ maurice : get rid of magic numbers
  sizeSectors = (fileInfo.size + 2047) / 2048;
  fileData = malloc3(sizeSectors * 2048);
  if (fileData == nullptr) {
    return  CD_FILE_READ_MALLOC;
  }
  return CD_NO_ERROR;
}
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_readFile(void* fileData, char* fileName) {
  DslFILE fileInfo;
  int sizeSectors;
  DsSearchFile(&fileInfo, fileName);
  // TODO @ maurice : get rid of magic numbers
  sizeSectors = (fileInfo.size + 2047) / 2048;
  fileData = malloc3(sizeSectors * 2048);
}
#endif // CD_ERROR
