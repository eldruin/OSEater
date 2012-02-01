/**
 * \file badcharacter.cpp \brief BadCharacter class methods.
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
 
#include <cstdlib>
#include "general.h"
#include "tile.h"
#include "image.h"
#include "zone.h"
#include "badcharacter.h"

void BadCharacter::draw (const Zone& zone, unsigned char number) const
{
  if (!(_position == Tile(zone.dimension, zone.dimension)))
    Character::draw();
  else
    zone.draw_pool(number);
}

void BadCharacter::die (const Zone& zone)
{
  // Move them to pool
  _position = Tile(zone.dimension, zone.dimension);
  _dead_time = rand() % MAX_DEAD;
  _deads++;
}
