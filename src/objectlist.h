/**
 * \file objectlist.h \brief Matrix where are stored the objects in
 * the zone.
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

#ifndef __OBJECTLIST_H__
#define __OBJECTLIST_H__

struct Tile;
class Object;

/// List of objects that are in a zone.
class ObjectList
{
 public:
  /// Constructor.
  ObjectList (unsigned int dimension);

  /// Adds the given object in the given tile of the map.
  /// If the tile already has an object it has no effect.
  void add (Tile place, Object* object);

  /// Removes and deletes the object in the given tile.
  void remove (Tile place);

  /** \brief Searches and return the object in the given tile.
   * \return The object that is in the given tile.
   * \return NULL if there is no object in that tile.
   */
  Object* get (Tile place);

  /// \return Whether the list is empty or not.
  bool empty () const;
  
  /// Destructor.
  void Destructor ();
 private:
  /// Matrix full of the objects in the zone.
  Object*** _objects;
  // Number of objects contained.
  //unsigned int _objects_count;
  /// Dimension of the matrix.
  unsigned int _dimension;
};

#endif
