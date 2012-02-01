/**
 * \file herocharacter.h \brief Hero character class
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

#ifndef __HERO_CHARACTER_H__
#define __HERO_CHARACTER_H__

#include "character.h"

/** \brief The hero character.
 *
 * The \c HeroCharacter class is the hero character.
 * It has several aditional methods and attributes.
 */
class HeroCharacter: public Character
{
 public:
  /// Constructor
 HeroCharacter(const Image& image, Tile position, unsigned int lifes = 0,
               unsigned int points = 0):
  Character (image, position, Character::HERO, lifes, points) {}

  /// \brief Number of lifes of the hero.
  /// \return A reference to it.
  inline unsigned int& lifes () { return _lifes; }

  /// \brief Points that the hero has.
  /// \return A reference to it.
  inline unsigned int& points () { return _points; }
 private:
  unsigned int _lifes, ///< Number of lifes the character has.
    _points; ///< Number of points the character has.
};

#endif
