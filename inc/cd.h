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

#ifndef CD_H
#define CD_H

#include <stdlib.h>
#include <libcd.h>
#include <libds.h>

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

#define CD_READER_STATUS_TYPE short
#define COMPLETE 0
#define READING 1
#define ERROR 2

// CD_readerStatus
#ifdef CD_ERROR
CD_ERROR_TYPE CD_readerStatus(CD_READER_STATUS_TYPE* status);
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_readerStatus(CD_READER_STATUS_TYPE* status);
#endif // CD_ERROR

// CD_initReader
#ifdef CD_ERROR
CD_ERROR_TYPE CD_initReader();
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_initReader();
#endif // CD_ERROR

// CD_stopReader
#ifdef CD_ERROR
CD_ERROR_TYPE CD_stopReader();
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_stopReader();
#endif // CD_ERROR

#ifdef CD_ERROR
CD_ERROR_TYPE CD_readFile(void* fileData, char* fileName);
#endif // CD_ERROR
#ifndef CD_ERROR
void CD_readFile(void* fileData, char* fileName);
#endif // CD_ERROR

#endif // CD_H
