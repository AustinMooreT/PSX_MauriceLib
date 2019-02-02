#include "../inc/fbuff.h"

FrameBuffer FRAMEBUFFER;

bool initDisplayBuffer(FrameBuffer* fb, bool db) {
  unsigned short screenW;
  unsigned short screenH;
  if (*((char*)0xbfc7ff52)=='E') {
    // PAL MODE
    screenW = 320;
    screenH = 256;
    SetVideoMode(1);
  } else {
    // NTSC MODE
    screenW = 320;
    screenH = 240;
    SetVideoMode(0);
  }
  // Set the graphics mode resolutions
  GsInitGraph(screenW, screenH, GsNONINTER|GsOFSGPU, 1, 0);
  // Set the top left coordinates of the two buffers in video memory
  if (db) {
    GsDefDispBuff(0, 0, 0, screenH);
  } else {
    GsDefDispBuff(0, 0, 0, 0);
  }
  GetDispEnv(&(fb->dispEnv));
  GetDrawEnv(&(fb->drawEnv));
  return true;
}

// swapBuffer
#ifdef FBUFF_ERROR
FBUFF_ERROR_TYPE swapBuffer(FrameBuffer* fb) {
  ResetGraph(1);
  GsSwapDispBuff();
  //TODO @maurice : This may be redundant.
  GetDispEnv(&(fb->dispEnv));
  GetDrawEnv(&(fb->drawEnv));
  return FBUFF_NO_ERROR;
}
#endif // FBUFF_ERROR
#ifndef FBUFF_ERROR
void swapBuffer(FrameBuffer* fb) {
  ResetGraph(1);
  GsSwapDispBuff();
  //TODO @maurice : This may be redundant.
  GetDispEnv(&(fb->dispEnv));
  GetDrawEnv(&(fb->drawEnv));
}
#endif // FBUFF_ERROR

bool isInterlaced(Frame3Buffer* fb) {
  return fb->dispEnv.isinter;
}

// clearFrameBuffer
#ifdef FBUFF_ERROR
FBUFF_ERROR_TYPE clearFrameBuffer(FrameBuffer* fb) {
  RECT fbram; // Rectangular primitive covering all of the framebuffer.
  setRECT(&fbram, 0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  // ClearImage2 works for interlaced buffers, while
  // ClearImage works works for non interlaced buffers.
  if (isInterlaced(fb)) {
    ClearImage2(&fbram, 0, 0, 0);
  } else {
    ClearImage(&fbram, 0, 0, 0);
  }
  DrawSync(0); // Block execution till the framebuffer is clear.
  return FBUFF_NO_ERROR;
}
#endif // FBUFF_ERROR
#ifndef FBUFF_ERROR
void clearFrameBuffer(FrameBuffer* fb) {
  RECT fbram; // Rectangular primitive covering all of the framebuffer.
  setRECT(&fbram, 0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT);
  // ClearImage2 works for interlaced buffers, while
  // ClearImage works works for non interlaced buffers.
  if (isInterlaced(fb)) {
    ClearImage2(&fbram, 0, 0, 0);
  } else {
    ClearImage(&fbram, 0, 0, 0);
  }
  DrawSync(0); // Block execution till the framebuffer is clear.
}
#endif // FBUFF_ERROR

// initGraphics
#ifdef FBUFF_ERROR
FBUFF_ERROR_TYPE initGraphics(bool db) {
  SetDispMask(1); //TODO @maurice : figure display masking details out.
  ResetGraph(0);
  return initDisplayBuffer(&FRAMEBUFFER, db) || clearFrameBuffer(&FRAMEBUFFER)
  //TODO @maurice : Finish implementing this.
}
#endif // FBUFF_ERROR
#ifndef FBUFF_ERROR
void initGraphics(bool db) {
  SetDispMask(1); //TODO @maurice : figure display masking details out.
  ResetGraph(0);
  //TODO @maurice : Finish implementing this.
}
#endif // FBUFF_ERROR
