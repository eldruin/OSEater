/**
 * \file zone.cpp \brief Zone class methods.
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
 
#include <olimex-lpc2378-stk/lcd.h>
#include "general.h"
#include "zone.h"

void Zone::draw_pool(unsigned char number) const
{
  LCD_print_character(number + '0', (pool[0]+1) * TILESIZE + TILESIZE/2,
			pool[1] * TILESIZE + TILESIZE/2-3, MEDIUM_FONT, RED, 0x444);
}
