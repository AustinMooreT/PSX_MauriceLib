#include "../cd.h"

bool isReaderActive;

#ifdef CD_ERROR
CD_ERROR_TYPE initCdReader() {
  isReaderActive = false;
  return CD_NO_ERROR
}
#endif // CD_ERROR
#ifndef CD_ERROR
void initCdReader() {
  isReaderActive = false;
}
#endif // CD_ERROR

