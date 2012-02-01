/**
 * \file character.h \brief Character class
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

#ifndef __CHARACTER_H__
#define __CHARACTER_H__

struct Tile;
class FloorMap;
class Image;
struct Zone;
#include "item.h"

/** \brief Class of all the characters.
 *
 * A character is the base for the \c BadCharacter and the \c
 * HeroCharacter classes.
 * A character is also an item.
 */
class Character: public Item
{
 public:
  /// \enum Type Type of the Character.
  enum Type {
    BAD, ///< Bad character. i.e. a Windows logo.
    HERO ///< Hero character. i.e. Tux.
  };

  /// Constructor
  Character(const Image& image, Tile position, Type type, unsigned int lifes = 0, unsigned int points = 0):
  Item(image), _position(position), _type(type) {}

  /** \brief Moves the character if it's possible.
   *
   * Checks in the FloorMap if it's possible to move from the actual
   * position to the parameter position.
   * \sa FloorMap::way()
   * \param to The destiny of the movement.
   * \param floormap The FloorMap of the actual Zone.
   * \return \c true if there was movement or \c false if there wasn't.
   */
  bool move (Tile to, const FloorMap& floormap);

  /// \return The Tile of the actual position.
  inline Tile& position () { return _position; }

  /// Draws the image of the character in _position.
  void draw () const;
 protected:
  Tile _position; ///< Actual position.
  Type _type;     ///< Type of the character.
};

#endif
