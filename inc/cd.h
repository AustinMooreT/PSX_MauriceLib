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

/**
   Initializes the CD reader subsystem should only be ran once.
*/
#ifdef CD_ERROR
CD_ERROR_TYPE initCdReader();
#ifndef CD_ERROR
void initCdReader();
#endif // CD_ERROR

/**
   Starts the CD reader to read some data.
   You should stop the reader after you are finished
*/
#ifdef CD_ERROR
CD_ERROR_TYPE startCdReader();
#endif // CD_ERROR
#ifndef CD_ERROR
void startCdReader();
#endif // CD_ERROR

#endif // CD_H
