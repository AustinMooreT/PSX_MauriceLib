#include "../inc/fbuff.h"
#include "../inc/otables.h"

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <libgs.h>
#include <stdlib.h>

unsigned long __ramsize =   0x00200000;          // force 2 megabytes of RAM
unsigned long __stacksize = 0x00004000;          // force 16 kilobytes of stack

// Sets up boolean data type just in case it's not setup.
#ifndef BOOL_T
typedef unsigned char bool;
#define true 1
#define false 0
#endif // BOOL_T

// Sets up nullptr value just in case it's not seetup.
#ifndef nullptr
#define nullptr 0
#endif // nullptr

// TODO @maurice : work on a memory management system.

int main() {
  OrderingTables ot;
  ResetCallback();  // Sets all callback fps to 0.
  nullOrderingTables(&ot);
  InitHeap3((void*)0x800F8000, 0x00100000);

#ifdef FBUFF_ERROR
  initGraphics(true);
#endif // FBUFF_ERORR
#ifndef FBUFF_ERROR
  initGraphics(true);
#endif

#ifdef OTABLE_ERROR
  initOrderingTables(&ot, 2);
#endif // OTABLE_ERROR
#ifndef OTABLE_ERROR
  initOrderingTables(&ot, 2);
#endif // OTABLE_ERROR

#ifdef OTABLE_ERROR
  initTable(&ot, 0, 1);
  initTable(&ot, 1, 1);
#endif // OTABLE_ERROR
#ifndef OTABLE_ERROR
  initTable(&ot, 0, 1);
  initTable(&ot, 1, 1);
#endif // OTABLE_ERROR

  FntLoad(960, 256);
  SetDumpFnt(FntOpen(10, 10, 320, 240, 0, 512));
  while (1) {
    FntPrint("Bean\n");
    FntFlush(-1);
    DrawSync(0);
    VSync(0);
    GsSwapDispBuff();
  }
  return 0;
}
