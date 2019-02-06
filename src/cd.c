#include "../cd.h"

// isReaderActive
#ifdef CD_ERROR
bool isReaderActive;
#endif // CD_ERROR

// initCdReader
#ifdef CD_ERROR
CD_ERROR_TYPE initCdReader() {
  isReaderActive = false;
  return CD_NO_ERROR;
}
#endif // CD_ERROR
#ifndef CD_ERROR
void initCdReader() {}
#endif // CD_ERROR

#ifdef CD_ERROR
CD_ERROR_TYPE startCdReader() {
  if (isReaderActive) {
    return CD_READER_RUNNING;
  } else {
    isReaderActive = true;
    DsInit();
    return CD_NO_ERROR;
  }
}
#endif // CD_ERROR
#ifndef CD_ERROR
void startCdReader() {
  DsInit();
}
#endif // CD_ERROR

#ifdef CD_ERROR
CD_ERROR_TYPE stopCdReader() {
  if (!isReaderActive) {
    return CD_READER_STOPPED;
  } else {
    isReaderActive = false;
    DsClose();
    return CD_NO_ERROR;
  }
}
#endif // CD_ERROR
#ifndef CD_ERROR
void stopCdReader() {
  DsClose();
}

