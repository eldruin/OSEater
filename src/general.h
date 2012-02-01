/**
 *\file general.h \brief General definitions and variables
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

#ifndef __GENERAL_H__
#define __GENERAL_H__

/// Game Mode
enum GameMode {
  MODE_EAT, ///< In this mode the bads can be eaten.
  MODE_DIE  ///< In this mode the bads kill the hero.
};

#define MODE_COUNTER 100 ///< Time that the EAT mode last.
#define TILESIZE 16      ///< Size of pixels each tile has.
#define MAX_DEAD 100      ///< Maximum time a bad character can be dead.
// Image adapting
#define BOARD_OFFSET_X 17 ///< X axis offset applied to the game board image.
#define BOARD_OFFSET_Y 3  ///< Y axis offset applied to the game board image.

#endif
