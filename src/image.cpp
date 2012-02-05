/**
 * \file image.cpp \brief Image class methods.
 */
/* Copyright 2008, 2009 Diego Barrios Romero.
 *
 * This file is part of OSEater.
 *
 * OSEater is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * OSEater is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with OSEater.  If not, see <http://www.gnu.org/licenses/>.
 */
 
#include <cassert>
#include <cctype> // For isspace()
#include <olimex-lpc2378-stk/lcd.h>
#include "image.h"

/// Assert fail function.
void __assert(const char *error, const char *file, int line);
/// Abort function.
void abort(void);

unsigned int Image::pixel (unsigned int x, unsigned int y) const
{
  if (x < width && y < height){
    x *= 3;
    y *= 3;
    return RGB_COLOR((_data[y*width+x])>>4,
      (_data[y*width+x+1])>>4, (_data[y*width+x+2])>>4);
  }
  return 0;
}

#if 0
void Image::clear (Tile position)
{
  draw(position.j*TILESIZE, position.i*TILESIZE);
}
#endif

void Image::draw (unsigned int x, unsigned int y, unsigned int frame_start_x,
                  unsigned int frame_start_y, unsigned int frame_width,
		  unsigned int frame_height) const
{
  if (!frame_width && !frame_height)
    for (unsigned int j = 0; j < height; j++)
      for(unsigned int i = 0; i < width; i++)
      	LCD_pixel(x+i, y+j, pixel(frame_start_y+j, frame_start_x+i));
  else
    for (unsigned int j = 0; j < frame_height; j++)
      for(unsigned int i = 0; i < frame_width; i++)
      	LCD_pixel(x+i, y+j, pixel(frame_start_y+j, frame_start_x+i));
}
#if 0
// Convert a character which is a hex digit to an integer
static int hex(char v)
{
  if (v >= 'A' && v <= 'F')
    return (v - 'A' + 10);
  if (v >= 'a' && v <= 'f')
    return (v - 'a' + 10);
  return (v - '0');
}
#endif

void __assert(const char *error, const char *file, int line)
{
  while (1);
}

