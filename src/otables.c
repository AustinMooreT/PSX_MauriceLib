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

bool initOrderingTables(OrderingTables* ot,
                        unsigned char tableCount) {
  if (ot->headers != nullptr ||
      ot->tables != nullptr) {  // Verify someone hasn't already called init.
    return false;
  }
  ot->headers = (GsOT*)malloc3(sizeof(GsOT) * tableCount);
  if (ot->headers == nullptr) {  // Verify malloc was succesfull.
    return false;
  }
  ot->tables = (GsOT_TAG**)malloc3(sizeof(GsOT_TAG*) * tableCount);
  if (ot->tables == nullptr) {
    free3(ot->headers);
    return false;
  }
  ot->tableCount = tableCount;
  return true;
}

bool initTable(OrderingTables* ot,
               unsigned char tableId,
               unsigned char tableSize) {
  if (tableId > ot->tableCount) {
    return false;
  }
  if (tableSize < 1 || tableSize > 14) {
    return false;
  }
  if (ot->headers == nullptr ||
     ot->tables == nullptr) {
    return false;
  }
  if (ot->tables[tableId] != nullptr) {
    return false;
  }
  // NOTE the actual table size is 2^tableSize. (1<<tableSize) for fast exponent
  ot->tables[tableId] = (GsOT_TAG*)malloc3(sizeof(GsOT_TAG) * (1 << tableSize));
  if (ot->tables[tableId] == nullptr) {
    return false;
  }
  ot->headers[tableId].length = tableSize;
  ot->headers[tableId].org = ot->tables[tableId];
  //TODO @maurice : figure out the first two params
  GsClearOt(0, 0, ot->headers + tableId);
  return true;
}
