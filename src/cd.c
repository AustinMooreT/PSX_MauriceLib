#include "../cd.h"

bool CD_ReaderStatus() {
  
}

#ifdef CD_ERROR

bool isDsActive;

CD_ERROR_TYPE CD_initReader() {
  if (isDsActive) {
    return CD_READER_RUNNING;
  }
  DsInit();
  return CD_NO_ERROR;
}

CD_ERROR_TYPE CD_stopReader() {
  if (!isReaderActive) {
    return CD_READER_STOPPED;
  }
  isReaderActive = false;
  DsClose();
  return CD_NO_ERROR;
}

CD_ERROR_TYPE CD_readFile(void* fileData, char* fileName) {
  DslFILE fileInfo;
  int sizeSectors = 0;
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

void stopCdReader() {
  DsClose();
}


#endif // CD_ERROR
