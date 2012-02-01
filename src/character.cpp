/**
 * \file character.cpp \brief Character class methods.
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

#include "general.h"
#include "tile.h"
#include "floormap.h"
#include "image.h"
#include "item.h"
#include "character.h"

/// \return The absolute value of the given parameter.
inline unsigned int abs (int a)
{
  return a >= 0 ? a : -a;
}

bool Character::move (Tile to, const FloorMap& floormap)
{
  if (abs(_position.i - to.i) + abs(_position.j - to.j) == 1) // up, down, left and right only.
    if (floormap.way(_position, to)){
      _position = to;
      return true;
    }
  return false;
}

void Character::draw () const
{
  Item::draw(_position.j*TILESIZE + 2 + BOARD_OFFSET_Y,
             _position.i*TILESIZE + 2 + BOARD_OFFSET_X);
}

