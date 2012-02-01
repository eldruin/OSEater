/**
 * \file controls.h \brief Buttons and joystick read function.
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

/// Masks for the buttons that have been pressed.
enum Button {
  BUTTON_NONE = 0,     ///< None button has been pressed.
  BUTTON_1 = 1,        ///< Button 1 (left) has been pressed.
  BUTTON_2 = 2,        ///< Button 2 (right) has been pressed.
  BUTTON_LEFT = 4,     ///< Joystick moved to the left.
  BUTTON_RIGHT = 8,    ///< Joystick moved to the right.
  BUTTON_UP = 16,      ///< Joystick moved up.
  BUTTON_DOWN = 32,    ///< Joystick moved down.
  BUTTON_CENTRAL = 64  ///< Pressed the central button of the joystick.
};

/** \brief Read the buttons and joystick.
 *
 * \return An int where the buttons pressed can be
 * extracted aplying the masks in the \c Button enum.
 * \par Example:
 * \code
 * unsigned int c;
 * c = read_controls();
 * if (c & BUTTON_CENTRAL) // The central button has been pressed.
 * ...
 * \endcode
 */
unsigned int read_controls();
