/**
 * \file objectlist.cpp \brief ObjectList class methods.
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
#include "tile.h"
#include "image.h"
#include "object.h"
#include "objectlist.h"

/// Abort function
void abort(void);

ObjectList::ObjectList(unsigned int dimension)
{
  extern unsigned int _objects_count;
  _objects = new Object** [dimension];
  assert(_objects);
  for (unsigned int i = 0; i < dimension; i++){
    _objects[i] = new Object* [dimension];
    assert(_objects[i]);
    for (unsigned int j = 0; j < dimension; j++)
      _objects[i][j] = 0;
  }

  _dimension = dimension;
  _objects_count = 0;
}

void ObjectList::add (Tile place, Object* object)
{
  extern unsigned int _objects_count;
  assert(object && place.i < _dimension && place.j < _dimension);
  _objects[place.i][place.j] = object;
  _objects_count++;
}

void ObjectList::remove (Tile place)
{
  extern unsigned int _objects_count;
  assert(place.i < _dimension && place.j < _dimension);
  if (_objects[place.i][place.j] != 0){
    _objects_count--;
    _objects[place.i][place.j]->~Object();
    _objects[place.i][place.j] = 0;
  }
}

Object* ObjectList::get (Tile place)
{
  assert(place.i < _dimension && place.j < _dimension);
  return _objects[place.i][place.j];
}

bool ObjectList::empty () const
{
  extern unsigned int _objects_count;
  return _objects_count == 0;
}

void ObjectList::Destructor ()
{
	for (unsigned int i = 0; i < _dimension; i++){
		for (unsigned int j = 0; j < _dimension; j++)
      if (_objects[i][j])
        delete _objects[i][j]; 
    delete _objects[i];
  }
  delete _objects;
}


void abort(void)
{
  while (1);
}
