/**
 * \file controls.cpp \brief Controls read function implementation.
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
 
#include <targets/LPC2378.h>
#include "controls.h"

unsigned int read_controls()
{
  unsigned long input = FIO0PIN;
  unsigned int buttons = BUTTON_NONE;

  if (!(input & (1<<29)))
    buttons |= BUTTON_1;
  if (!(input & (1<<18)))
    buttons |= BUTTON_2;

  input = FIO1PIN;
  if (!(input & (1<<27)))
    buttons |= BUTTON_LEFT;
  if (!(input & (1<<22)))
    buttons |= BUTTON_RIGHT;
  if (!(input & (1<<18)))
    buttons |= BUTTON_UP;
  if (!(input & (1<<19)))
    buttons |= BUTTON_DOWN;
  if (!(input & (1<<25)))
    buttons |= BUTTON_CENTRAL;

  return buttons;
}
