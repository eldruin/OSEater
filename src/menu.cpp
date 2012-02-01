/**
 * \file menu.cpp \brief Menu functions.
 *
 * The main menu will be:
 *
 *  /// OSEater \\\
 *     Main Menu
 *        Play
 *       Credits
 *        Help
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
 
#include "lcd.h"
#include "menu.h"
#include "controls.h"

/// Menu showing the settings available, currently none.
static void show_settings();
/// Function that shows the credits of the game.
static void show_credits();
/// Little help for those who need it.
static void show_help();
/// Puts the screen off.
static void off();

void menu ()
{
  unsigned char selected = 1;
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_imprimir_cadena("/// OSEater \\\\\\", 4, 4, FONT_GRANDE, WHITE,
  BLACK);
  LCD_imprimir_cadena("Main Menu", 24, 28, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("Play", 48, 48, FONT_GRANDE, RED, BLACK);
  LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("Help", 88, 48, FONT_GRANDE, WHITE, BLACK);
  while (1){
    unsigned int buttons = read_controls();
    if (buttons & BUTTON_CENTRAL){
      switch(selected){
      case 1:
        return;
      case 2:
        show_credits();
        selected = 1;
        LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
        LCD_imprimir_cadena("/// OSEater \\\\\\", 4, 4, FONT_GRANDE, WHITE,
                            BLACK);
        LCD_imprimir_cadena("Main Menu", 24, 28, FONT_GRANDE, WHITE, BLACK);
        LCD_imprimir_cadena("Play", 48, 48, FONT_GRANDE, RED, BLACK);
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, WHITE, BLACK);
        LCD_imprimir_cadena("Help", 88, 48, FONT_GRANDE, WHITE, BLACK);
        break;
      case 3:
        show_help();
        selected = 1;
        LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
        LCD_imprimir_cadena("/// OSEater \\\\\\", 4, 4, FONT_GRANDE, WHITE,
                            BLACK);
        LCD_imprimir_cadena("Main Menu", 24, 28, FONT_GRANDE, WHITE, BLACK);
        LCD_imprimir_cadena("Play", 48, 48, FONT_GRANDE, RED, BLACK);
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, WHITE, BLACK);
        LCD_imprimir_cadena("Help", 88, 48, FONT_GRANDE, WHITE, BLACK);
        break;
      }
    }
    if (buttons & BUTTON_DOWN){
      switch(selected){
      case 1:
        LCD_imprimir_cadena("Play", 48, 48, FONT_GRANDE, WHITE,
                            BLACK);
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, RED,
                            BLACK);
        break;
      case 2:
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, WHITE,
                            BLACK);
        LCD_imprimir_cadena("Help", 88, 48, FONT_GRANDE, RED,
                            BLACK);
        break;
      default:
        selected--;
      }
      selected++;
    }
    else if (buttons & BUTTON_UP){
      switch(selected){
      case 2:
        LCD_imprimir_cadena("Play", 48, 48, FONT_GRANDE, RED,
                            BLACK);
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, WHITE,
                            BLACK);
        break;
      case 3:
        LCD_imprimir_cadena("Credits", 68, 36, FONT_GRANDE, RED,
                            BLACK);
        LCD_imprimir_cadena("Help", 88, 48, FONT_GRANDE, WHITE,
                            BLACK);
        break;
      default:
        selected++;
      }
      selected--;
    }
    retardo(300000);
  }
}


void menu_freedom_wins ()
{unsigned char selected = 1;
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_imprimir_cadena("/// OSEater \\\\\\", 4, 4, FONT_GRANDE, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Freedom Wins!", 24, 14, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("Play again", 48, 26, FONT_MEDIANO, RED, BLACK);
  LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, RED, BLACK);
  LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, WHITE, BLACK);
  while (1){
    unsigned int buttons = read_controls();
    if (buttons & BUTTON_CENTRAL){
      switch(selected){
      case 1:
        return;
      case 2:
        off();
        break;
      }
    }
    if (buttons & BUTTON_DOWN){
      if (selected == 1){
        LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, WHITE, BLACK);
        LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, RED, BLACK);
        selected++;
      }
    }
    else if (buttons & BUTTON_UP){
      if (selected == 2){
        LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, RED, BLACK);
        LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, WHITE, BLACK);
        selected--;
      }
    }
  }
}

void menu_game_over()
{
  unsigned char selected = 1;
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_imprimir_cadena("/// OSEater \\\\\\", 4, 4, FONT_GRANDE, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Game over", 24, 30, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("Play again", 48, 26, FONT_MEDIANO, RED, BLACK);
  LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, RED, BLACK);
  LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, WHITE, BLACK);
  while (1){
    unsigned int buttons = read_controls();
    if (buttons & BUTTON_CENTRAL){
      switch(selected){
      case 1:
        return;
      case 2:
        off();
        break;
      }
    }
    if (buttons & BUTTON_DOWN){
      if (selected == 1){
        LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, WHITE, BLACK);
        LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, RED, BLACK);
        selected++;
      }
    }
    else if (buttons & BUTTON_UP){
      if (selected == 2){
        LCD_imprimir_cadena("Yes", 68, 57, FONT_PEQUENO, RED, BLACK);
        LCD_imprimir_cadena("No", 88, 60, FONT_PEQUENO, WHITE, BLACK);
        selected--;
      }
    }
  }
}


void show_credits()
{
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_imprimir_cadena("/// OSEater \\\\", 4, 4, FONT_GRANDE, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Credits", 24, 36, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("A game by", 44, 8, FONT_MEDIANO, WHITE, BLACK);
  LCD_imprimir_cadena("Diego Barrios", 56, 8, FONT_MEDIANO, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Romero.", 68, 8, FONT_MEDIANO, WHITE, BLACK);
  LCD_imprimir_cadena("Developed for", 80, 8, FONT_PEQUENO, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Microprocessors", 90, 8, FONT_PEQUENO, WHITE,
                      BLACK);
  LCD_imprimir_cadena("& Micro-", 100, 8, FONT_PEQUENO, WHITE, BLACK);
  LCD_imprimir_cadena("controllers", 110, 8, FONT_PEQUENO, WHITE,
                      BLACK);
  LCD_imprimir_cadena("subject.", 120, 8, FONT_PEQUENO, WHITE, BLACK);
  while(!read_controls());
}

void show_help()
{
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_imprimir_cadena("/// OSEater \\\\", 4, 4, FONT_GRANDE, WHITE,
                      BLACK);
  LCD_imprimir_cadena("Help", 24, 48, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("Just move the", 44, 8, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("joystick", 64, 8, FONT_GRANDE, WHITE, BLACK);
  LCD_imprimir_cadena("to move around", 84, 8, FONT_GRANDE, WHITE,
                      BLACK);
  while(!read_controls());
}

void off()
{
  LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
  LCD_apagar_backlight();
  while(1);
}
