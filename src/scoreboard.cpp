/**
 * \file scoreboard.cpp \brief Scoreboard showing the points and the
 * lifes.
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
#include "lcd.h"
#include "tile.h"
#include "image.h"
#include "herocharacter.h"
#include "scoreboard.h"

void scoreboard_update (HeroCharacter& c)
{
  LCD_imprimir_cadena("Score:", 106, 15, FONT_PEQUENO, WHITE, BLACK);
  LCD_imprimir_caracter(c.points()/100 + '0', 116, 24, FONT_PEQUENO,
                        WHITE, BLACK);
  LCD_imprimir_caracter(c.points()%100/10 + '0', 116, 30, FONT_PEQUENO,
                        WHITE, BLACK);
  LCD_imprimir_caracter(c.points()%10 + '0', 116, 36, FONT_PEQUENO,
                        WHITE, BLACK);
  LCD_imprimir_cadena("Lifes:", 106, 81, FONT_PEQUENO, WHITE, BLACK);
  LCD_imprimir_caracter(c.lifes() + '0', 116, 96, FONT_PEQUENO, WHITE, BLACK);
}

