/**
 * \file object.h \brief Object class
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

#ifndef __OBJECT_H__
#define __OBJECT_H__

class Image;
#include "item.h"

/** \brief Class of all the objects in the screen which are also
 *   items.
 *
 * An object is an item which the hero can eat. There are two types
 * depending on the effect of the object.
 * When the \c HeroCharacter eats it, receives its properties.
 */
class Object: public Item
{
 public:
  /** \enum Type Types of objects.
   *
   *  An special objects changes the game mode.
   */
  enum Type {
    REGULAR,  ///< A regular object.
    SPECIAL ///< A special object changes the game mode.
  };

  /// Constructor
  Object (const Image& image, unsigned int points, bool extra_life = false, Type type = REGULAR):
  Item(image), _points(points), _extra_life(extra_life), _type(type) {}

  /// \return Whether the object provides an extra life or not.
  inline bool extra_life () { return _extra_life; }

  /// \return The points that the objects provides.
  inline unsigned int points () { return _points; }

  /// \return Type of the object.
  inline Type type () { return _type; }
 private:
  /// Points the object provides.
  unsigned int _points;
  /// Whether the object provides an extra life when eaten.
  bool _extra_life;
  /// Type of object.
  Type _type;
};

#endif
