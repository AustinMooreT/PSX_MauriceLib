/*
  Copyright Austin Moore 2018
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef TXTFILE_H
#define TXTFILE_H

// Sets up boolean data type just in case it's not setup.
#ifndef BOOL_T
#define BOOL_T
typedef unsigned char bool;
#define true 1
#define false 0
#endif // BOOL_T

// Sets up nullptr value just in case it's not seetup.
#ifndef nullptr
#define nullptr 0
#endif // nullptr

#include "error.h"
#include <stdlib.h>

typedef struct TxtFile {
  char* fileData;
  char* start;
} TxtFile;

#ifdef TXT_ERROR
TXT_ERROR_TYPE TXT_createTxtFile(void* fileData, TxtFile* fileStruct);
#endif // TXT_ERROR
#ifndef TXT_ERROR
void TXT_createTxtFile(void* fileData, TxtFile* fileStruct);
#endif // TXT_ERROR

// TODO @ maurice : There's lots of useful functions you could add.

#endif // TXTFILE_H
