#include "../inc/txtfile.h"

#ifdef TXT_ERROR
TXT_ERROR_TYPE TXT_createTxtFile(void* fileData, TxtFile* fileStruct) {
  fileStruct = malloc3(sizeof(TxtFile));
  if (fileStruct == nullptr) {
    return TXT_FILE_MALLOC;
  }
  fileStruct->fileData = fileData;
  fileStruct->start = fileStruct->fileData;
  return TXT_NO_ERROR;
}
#endif // TXT_ERROR
#ifndef TXT_ERROR
void TXT_createTxtFile(void* fileData, TxtFile* fileStruct) {
  fileStruct = malloc3(sizeof(TxtFile));
  fileStruct->fileData = fileData;
  fileStruct->start = fileStruct->fileData;
}
#endif // TXT_ERROR
