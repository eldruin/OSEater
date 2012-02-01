/**
 * \file badcharacter.h \brief BadCharacter class
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

#ifndef __BAD_CHARACTER_H__
#define __BAD_CHARACTER_H__

struct Zone;
#include "character.h"

/** \brief Bad characters class.
 *
 * The \c BadCharacter class is a character which is bad.
 * It has several aditional methods and attributes.
 */
class BadCharacter: public Character
{
 public:
  /// Constructor
 BadCharacter(const Image& image, Tile position, unsigned char dead_time):
  Character (image, position, Character::BAD), _dead_time(dead_time) {}

  /** \brief Draws the character or the number in the pool.
   * If the character is alive it draws the image in the actual
   * position.
   * \sa Character::draw()
   *
   * If it's dead it updates the number of deads in the pool.
   * \sa Zone::draw_pool()
   * \param zone The zone where the character will be drawn. It's
   * needed to check if the position is valid.
   * \param number Number of character that are in the pool (must be
   * counted externally).
   */
  void draw (const Zone& zone, unsigned char number) const;

  /** \brief Kills the character.
   *
   * Moves the character to the pool directly, sets a random dead
   * time and updates the deads counter.
   * \param zone The zone is needed to move the character out of the
   * zone.
   */
  void die (const Zone& zone);

  /// \brief Decrements the dead time of a character.
  inline void dec_dead_time ()
  {
    if (_dead_time && !(--_dead_time))
      _deads--;
  }

  /// \return Whether the character is alive or not.
  inline bool alive () const { return _dead_time == 0; }

  /// \brief Number of dead characters.
  /// \return A reference to the number.
  static inline unsigned char& deads() { return _deads; }
 private:
  /// Dead time the character will be. If it's 0 means the character
  /// is alive.
  unsigned char _dead_time;
  /// Number of characters that are dead.
  static unsigned char _deads;
};

#endif
