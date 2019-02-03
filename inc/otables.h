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

#ifndef OTABLE_H
#define OTABLE_H

// Sets up boolean data type just in case it's not setup.
#ifndef BOOL_T
#define BOOL_T
typedef unsigned char bool;
#define true 1
#define false 0
#endif  // BOOL_T

// Sets up nullptr value just in case it's not setup.
#ifndef nullptr
#define nullptr 0
#endif  // nullptr

#include <sys/types.h>
#include <stdlib.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <libgs.h>

typedef struct OrderingTables {
  unsigned char tableCount;
  GsOT* headers;
  GsOT_TAG** tables;
} OrderingTables;

/**
   \param ot ordering table to intialize to zero.
*/
void nullOrderingTables(OrderingTables* ot);

/**
   \param ot the ordering tables to initialize.
   \param tableCount the number of ordering tables to create.
   \return true on succesfull execution
*/
#ifdef OTABLE_ERROR
OTABLE_ERROR_TYPE initOrderingTables(OrderingTables* ot,
                                     unsigned char tableCount);
#endif // OTABLE_ERROR
#ifndef OTABLE_ERROR
void initOrderingTables(OrderingTables* ot,
                        unsigned char tableCount);
#endif // OTABLE_ERROR

/**
   \param ot the ordering tables to operate on.
   \param tableId the index of the table to initialize
          must be between 0 and tableCount.
   \param tableSize the size of the table to initialize
          must be between 1 and 15.
   \return true on succesfull execution.
 */
bool initTable(OrderingTables* ot,
               unsigned char tableId,
               unsigned char tableSize);

#endif  // OTABLE_H
