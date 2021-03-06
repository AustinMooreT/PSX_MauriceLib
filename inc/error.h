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

#ifndef ERROR_H
#define ERROR_H

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

/**
   This file contains setup for an error handling system for this low level library.
   You can enable/disable error handling for specifici modules by #define the
   module name plus error. For example to enable errors for the fbuff module you will
   add this to your main program. #define FBUFF_ERROR.
 */

#ifdef CD_ERROR
#define CD_ERROR_TYPE unsigned int
#define CD_NO_ERROR 0
#define CD_READER_RUNNING 1
#define CD_READER_STOPPED 2
#define CD_FILE_READ_ERROR 4
#define CD_FILE_READ_MALLOC 8
#endif // CD_ERROR

#ifdef FBUFF_ERROR
#define FBUFF_ERROR_TYPE unsigned int
#define FBUFF_NO_ERROR 0
#define DISPLAY_BUFFER_INIT 1
#define FRAME_BUFFER_CLEAR 2
#endif // FBUFF_ERROR

#ifdef OTABLE_ERROR
#define OTABLE_ERROR_TYPE unsigned int
#define OTABLE_NO_ERROR 0
#define OTABLE_DOUBLE_INIT 1
#define OTABLE_INIT_HEADER_MALLOC 2
#define OTABLE_INIT_TABLE_MALLOC 4
#define OTABLE_TABLE_ID_GT_TABLE_COUNT 8 // GT is greater than.
#define OTABLE_TABLE_ID_LT_TABLE_COUNT 16 // LT is less than.
#define OTABLE_NOT_INIT 32
#define OTABLE_TABLE_DOUBLE_INIT 64
#define OTABLE_TABLE_INIT_MALLOC 128
#endif // OTABLE_ERROR

#ifdef TXT_ERROR
#define TXT_ERROR_TYPE unsigned int
#define TXT_NO_ERROR 0
#define TXT_FILE_MALLOC 1
#endif // TXT_ERROR

#endif  // ERROR_H
