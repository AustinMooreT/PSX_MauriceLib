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

#ifndef FBUFF_H
#define FBUFF_H

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

#include <sys/types.h>
#include <libgte.h>
#include <libgpu.h>
#include <libetc.h>
#include <libgs.h>

// There are 16 bits per pixel.
#define PIXEL_WIDTH 16

// Pixel width and height of the frame buffer.
#define FRAMEBUFFER_WIDTH 1024
#define FRAMEBUFFER_HEIGHT 512

typedef struct FrameBuffer {
  DISPENV dispEnv;
  DRAWENV drawEnv;
} FrameBuffer;

/**
   \param fb framebuffer to setup display buffer in.
   \param db if true then the framebuffer is double buffered.
   \return true if succesfull.
   Sets up the display buffers for a given framebuffer.
*/
bool initDispBuffer(FrameBuffer* fb, bool db);

/**
   \param fb framebuffer to buffer swap on.
   \return true if successfull.
   If fb is double buffered swaps the display buffer with the drawing buffer.
*/
bool swapBuffer(FrameBuffer* fb);

/**
   \param fb framebuffer to check.
   \return if interlacing is enabled.
   Checks wether or not interlacing is enabled.
*/
bool isInterlaced(FrameBuffer* fb);

/**
   \param fb framebuffer to clear.
   \return if the framebuffer was succesfully cleared.
   Sets all of vram to 0.
*/
bool clearFrameBuffer(FrameBuffer* fb);

/**
   \return true if successfull.
   Sets up all internal data structures and globals for the graphics
   environment.
*/
bool initGraphics(bool db);

#endif // FBUFF_H
