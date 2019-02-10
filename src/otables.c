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

#include "../inc/otables.h"

void nullOrderingTables(OrderingTables* ot) {
  ot->tableCount = 0;
  ot->headers = nullptr;
  ot->tables = nullptr;
}

// initOrderingTables
#ifdef OTABLE_ERROR
OTABLE_ERROR_TYPE initOrderingTables(OrderingTables* ot,
                                     unsigned char tableCount) {
  if (ot->headers != nullptr ||
      ot->tables != nullptr) {  // Verify someone hasn't already called init.
    return OTABLE_DOUBLE_INIT;
  }
  ot->headers = (GsOT*)malloc3(sizeof(GsOT) * tableCount);
  if (ot->headers == nullptr) {  // Verify malloc was succesfull.
    return OTABLE_INIT_HEADER_MALLOC;
  }
  ot->tables = (GsOT_TAG**)malloc3(sizeof(GsOT_TAG*) * tableCount);
  if (ot->tables == nullptr) { // Verify malloc was succesfull.
    free3(ot->headers);
    return OTABLE_INIT_TABLE_MALLOC;
  }
  ot->tableCount = tableCount;
  return OTABLE_NO_ERROR;
}
#endif // OTABLE_ERROR
#ifndef OTABLE_ERROR
void initOrderingTables(OrderingTables* ot,
                        unsigned char tableCount) {
  ot->headers = (GsOT*)malloc3(sizeof(GsOT) * tableCount);
  ot->tables = (GsOT_TAG**)malloc3(sizeof(GsOT_TAG*) * tableCount);
  ot->tableCount = tableCount;
}
#endif // OTABLE_ERROR

#ifdef OTABLE_ERROR
OTABLE_ERROR_TYPE initTable(OrderingTables* ot,
                            unsigned char tableId,
                            unsigned char tableSize) {
  if (tableId > ot->tableCount) { // Bounds checking
    return OTABLE_TABLE_ID_GT_TABLE_COUNT;
  }
  if (tableSize < 1 || tableSize > 14) { // Bounds checking
    return OTABLE_TABLE_ID_LT_TABLE_COUNT;
  }
  if (ot->headers == nullptr ||
      ot->tables == nullptr) { // Make sure ot is initialized.
    return OTABLE_NOT_INIT;
  }
  if (ot->tables[tableId] != nullptr) { // Verify table isn't inited.
    return OTABLE_TABLE_DOUBLE_INIT;
  }
  // NOTE the actual table size is 2^tableSize. (1<<tableSize) for fast exponent
  ot->tables[tableId] = (GsOT_TAG*)malloc3(sizeof(GsOT_TAG) * (1 << tableSize));
  if (ot->tables[tableId] == nullptr) {
    return OTABLE_TABLE_INIT_MALLOC;
  }
  ot->headers[tableId].length = tableSize;
  ot->headers[tableId].org = ot->tables[tableId];
  //TODO @maurice : figure out the first two params
  GsClearOt(0, 0, ot->headers + tableId);
  return OTABLE_NO_ERROR;
}
#endif // OTABLE_ERROR
#ifndef OTABLE_ERROR
void initTable(OrderingTables* ot,
               unsigned char tableId,
               unsigned char tableSize) {
  // NOTE the actual table size is 2^tableSize. (1<<tableSize) for fast exponent
  ot->tables[tableId] = (GsOT_TAG*)malloc3(sizeof(GsOT_TAG) * (1 << tableSize));
  ot->headers[tableId].length = tableSize;
  ot->headers[tableId].org = ot->tables[tableId];
  //TODO @maurice : figure out the first two params
  GsClearOt(0, 0, ot->headers + tableId);
}
#endif // OTABLE_ERROR

