/**
 * \file zone.h \brief Zone properties.
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
#ifndef __ZONE_H__
#define __ZONE_H__

class Image;

/// \brief Struct of all the zones.
struct Zone
{
  unsigned int dimension; ///< Number of tiles per axis (must be the same).

  /** \brief Walls of the zone.
   *
   * It's an array containing the tiles i and j coordinates of origin
   * and destination meaning there is a wall from the origin tile to
   * the destiny.
   * The finish is marked with a $ symbol.
   */
  char* walls;
  /** \brief List of objects.
   *
   * It's an array containing the type of object and its tiles i and
   * j coordinates.
   */
  char* object_list;
  /** \brief Bads pool.
   *
   * It's an array with the i and j coordinates of origin and finish
   * of the bads pool meaning the pool is a square from the origin to
   * the finish tile.
   */
  char* pool;

  /// Number of bad characters in the pool.
  char bads;

  /// Background image.
  Image* image;

  /// \brief It draws the number of characters there are in the pool.
  void draw_pool (unsigned char number) const;
};

#endif
