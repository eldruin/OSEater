/**
 * \file tile.h \brief Tile class. They are coordinates.
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

#ifndef __TILE_H__
#define __TILE_H__

/// Coordinates struct.
struct Tile {
  /// Constructor.
  Tile () {}
  /// Constructor.
  Tile (unsigned int i, unsigned int j): i(i), j(j) {}
  /// Copy constructor.
  Tile (const Tile& t)
  {
    i = t.i;
    j = t.j;
  }

  /// Comparison operator.
  bool operator== ( Tile t ) const
  {
    return ( i == t.i && j == t.j );
  }

  /// Assign operator.
  Tile& operator= ( Tile t )
  {
    i = t.i;
    j = t.j;

    return *this;
  }

  unsigned int i,  ///< Row of the zone.
    j;             ///< Column of the zone.
};

#endif
