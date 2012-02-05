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
 
#include <olimex-lpc2378-stk/lcd.h>
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
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_print_string("/// OSEater \\\\\\", 4, 4, BIG_FONT, WHITE,
  BLACK);
  LCD_print_string("Main Menu", 24, 28, BIG_FONT, WHITE, BLACK);
  LCD_print_string("Play", 48, 48, BIG_FONT, RED, BLACK);
  LCD_print_string("Credits", 68, 36, BIG_FONT, WHITE, BLACK);
  LCD_print_string("Help", 88, 48, BIG_FONT, WHITE, BLACK);
  while (1){
    unsigned int buttons = read_controls();
    if (buttons & BUTTON_CENTRAL){
      switch(selected){
      case 1:
        return;
      case 2:
        show_credits();
        selected = 1;
        LCD_rectangle(0, 0, 132, 132, 1, BLACK);
        LCD_print_string("/// OSEater \\\\\\", 4, 4, BIG_FONT, WHITE,
                            BLACK);
        LCD_print_string("Main Menu", 24, 28, BIG_FONT, WHITE, BLACK);
        LCD_print_string("Play", 48, 48, BIG_FONT, RED, BLACK);
        LCD_print_string("Credits", 68, 36, BIG_FONT, WHITE, BLACK);
        LCD_print_string("Help", 88, 48, BIG_FONT, WHITE, BLACK);
        break;
      case 3:
        show_help();
        selected = 1;
        LCD_rectangle(0, 0, 132, 132, 1, BLACK);
        LCD_print_string("/// OSEater \\\\\\", 4, 4, BIG_FONT, WHITE,
                            BLACK);
        LCD_print_string("Main Menu", 24, 28, BIG_FONT, WHITE, BLACK);
        LCD_print_string("Play", 48, 48, BIG_FONT, RED, BLACK);
        LCD_print_string("Credits", 68, 36, BIG_FONT, WHITE, BLACK);
        LCD_print_string("Help", 88, 48, BIG_FONT, WHITE, BLACK);
        break;
      }
    }
    if (buttons & BUTTON_DOWN){
      switch(selected){
      case 1:
        LCD_print_string("Play", 48, 48, BIG_FONT, WHITE,
                            BLACK);
        LCD_print_string("Credits", 68, 36, BIG_FONT, RED,
                            BLACK);
        break;
      case 2:
        LCD_print_string("Credits", 68, 36, BIG_FONT, WHITE,
                            BLACK);
        LCD_print_string("Help", 88, 48, BIG_FONT, RED,
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
        LCD_print_string("Play", 48, 48, BIG_FONT, RED,
                            BLACK);
        LCD_print_string("Credits", 68, 36, BIG_FONT, WHITE,
                            BLACK);
        break;
      case 3:
        LCD_print_string("Credits", 68, 36, BIG_FONT, RED,
                            BLACK);
        LCD_print_string("Help", 88, 48, BIG_FONT, WHITE,
                            BLACK);
        break;
      default:
        selected++;
      }
      selected--;
    }
    delay(300000);
  }
}


void menu_freedom_wins ()
{unsigned char selected = 1;
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_print_string("/// OSEater \\\\\\", 4, 4, BIG_FONT, WHITE,
                      BLACK);
  LCD_print_string("Freedom Wins!", 24, 14, BIG_FONT, WHITE, BLACK);
  LCD_print_string("Play again", 48, 26, MEDIUM_FONT, RED, BLACK);
  LCD_print_string("Yes", 68, 57, SMALL_FONT, RED, BLACK);
  LCD_print_string("No", 88, 60, SMALL_FONT, WHITE, BLACK);
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
        LCD_print_string("Yes", 68, 57, SMALL_FONT, WHITE, BLACK);
        LCD_print_string("No", 88, 60, SMALL_FONT, RED, BLACK);
        selected++;
      }
    }
    else if (buttons & BUTTON_UP){
      if (selected == 2){
        LCD_print_string("Yes", 68, 57, SMALL_FONT, RED, BLACK);
        LCD_print_string("No", 88, 60, SMALL_FONT, WHITE, BLACK);
        selected--;
      }
    }
  }
}

void menu_game_over()
{
  unsigned char selected = 1;
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_print_string("/// OSEater \\\\\\", 4, 4, BIG_FONT, WHITE,
                      BLACK);
  LCD_print_string("Game over", 24, 30, BIG_FONT, WHITE, BLACK);
  LCD_print_string("Play again", 48, 26, MEDIUM_FONT, RED, BLACK);
  LCD_print_string("Yes", 68, 57, SMALL_FONT, RED, BLACK);
  LCD_print_string("No", 88, 60, SMALL_FONT, WHITE, BLACK);
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
        LCD_print_string("Yes", 68, 57, SMALL_FONT, WHITE, BLACK);
        LCD_print_string("No", 88, 60, SMALL_FONT, RED, BLACK);
        selected++;
      }
    }
    else if (buttons & BUTTON_UP){
      if (selected == 2){
        LCD_print_string("Yes", 68, 57, SMALL_FONT, RED, BLACK);
        LCD_print_string("No", 88, 60, SMALL_FONT, WHITE, BLACK);
        selected--;
      }
    }
  }
}


void show_credits()
{
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_print_string("/// OSEater \\\\", 4, 4, BIG_FONT, WHITE,
                      BLACK);
  LCD_print_string("Credits", 24, 36, BIG_FONT, WHITE, BLACK);
  LCD_print_string("A game by", 44, 8, MEDIUM_FONT, WHITE, BLACK);
  LCD_print_string("Diego Barrios", 56, 8, MEDIUM_FONT, WHITE,
                      BLACK);
  LCD_print_string("Romero.", 68, 8, MEDIUM_FONT, WHITE, BLACK);
  LCD_print_string("Developed for", 80, 8, SMALL_FONT, WHITE,
                      BLACK);
  LCD_print_string("Microprocessors", 90, 8, SMALL_FONT, WHITE,
                      BLACK);
  LCD_print_string("& Micro-", 100, 8, SMALL_FONT, WHITE, BLACK);
  LCD_print_string("controllers", 110, 8, SMALL_FONT, WHITE,
                      BLACK);
  LCD_print_string("subject.", 120, 8, SMALL_FONT, WHITE, BLACK);
  while(!read_controls());
}

void show_help()
{
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_print_string("/// OSEater \\\\", 4, 4, BIG_FONT, WHITE,
                      BLACK);
  LCD_print_string("Help", 24, 48, BIG_FONT, WHITE, BLACK);
  LCD_print_string("Just move the", 44, 8, BIG_FONT, WHITE, BLACK);
  LCD_print_string("joystick", 64, 8, BIG_FONT, WHITE, BLACK);
  LCD_print_string("to move around", 84, 8, BIG_FONT, WHITE,
                      BLACK);
  while(!read_controls());
}

void off()
{
  LCD_rectangle(0, 0, 132, 132, 1, BLACK);
  LCD_turn_off_backlight();
  while(1);
}
