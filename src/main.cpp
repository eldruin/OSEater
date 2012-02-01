/**
 * \file main.cpp \brief Main function file where all happens.
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
#include <cassert>
#include <cstdlib>
#include <olimex-lpc2378-stk/init.h>
#include <olimex-lpc2378-stk/lcd.h>
#include <olimex-lpc2378-stk/sound.h>
#include "general.h"
#include "tile.h"
#include "image.h"
#include "floormap.h"
#include "object.h"
#include "objectlist.h"
#include "character.h"
#include "badcharacter.h"
#include "herocharacter.h"
#include "zone.h"
#include "collision.h"
#include "controls.h"
#include "menu.h"
#include "scoreboard.h"

// Objects available
#define DOT 1    ///< Type of object.
#define APPLE 2  ///< Type of object.

#include "zone2.h"
#include "images/tux.h"
#include "images/win.h"
#include "images/dot.h"
#include "images/apple.h"

using namespace std;

/// Initialization of the microcontroller.
void Inicializar_LPC2378(void);

GameMode Game_mode; ///< Mode of the game
unsigned int Game_mode_counter = 0; ///< Down counter for the Game_mode.


unsigned char BadCharacter::_deads = 0; ///< Static members need initialization.
unsigned int _objects_count; ///< Attribute of ObjectList. Moved for bugfixing.

/// Main function of the game. Manages it all.
int main (void)
{
  Inicializar_LPC2378();
  inicializar_reproduccion_sonido();
  LCD_inicializar();
  LCD_borrar();

  Zone zone2;

  zone2.dimension = zone2_dimension;
  zone2.walls = zone2_walls;
  zone2.object_list = zone2_object_list;
  zone2.pool = zone2_pool;
  zone2.bads = zone2_bads;
  zone2.image = new Image (zone2_image_data, zone2_width, zone2_height);

  Zone zone = zone2;

  FloorMap fm (zone.dimension, zone.walls);

  Image tux (tux_image_data, tux_width, tux_height);
  Image win (win_image_data, win_width, win_height);
  Image dot (dot_image_data, dot_width, dot_height);
  Image apple (apple_image_data, apple_width, apple_height);

  while(1){
    Game_mode = MODE_DIE;
    BadCharacter::deads() = zone.bads;
    HeroCharacter hero (tux, Tile(zone.dimension-1, zone.dimension-1), 1);

    hero.position() = Tile(zone.dimension-1, zone.dimension-1);
    hero.points() = 0;
    hero.lifes() = 0;

    BadCharacter* bads[zone.bads];
    for (int i = 0; i < zone.bads; i++){
      bads[i] = new BadCharacter (win, Tile(zone.dimension,
                                            zone.dimension),
                                  rand()%MAX_DEAD);
      assert(bads[i]);
    }
    ObjectList obj_list(zone.dimension);

    // Fill the zone with dots
    for (unsigned char i = 0; i < zone.dimension; i++){
      for (unsigned char j = 0; j < zone.dimension; j++){
        // If outside the bad characters pool.
        if ((i < zone.pool[0] || i > zone.pool[2]) ||
            (j < zone.pool[1] || j > zone.pool[3]))
          obj_list.add(Tile(i,j), new Object(dot, 5));
      }
    }

    // Add the zone own objects
    for (unsigned int i = 0; zone.object_list[i] != '$'; i++){
      switch(zone.object_list[i++]){
      case APPLE: Tile place (zone.object_list[i],
                              zone.object_list[i+1]);
        i++;
        obj_list.remove(place);
        obj_list.add(place, new Object(apple, 15, true, Object::SPECIAL));
      }
    }

    obj_list.remove(Tile(zone.dimension-1, zone.dimension-1));

    Character::Type winner;
    // Menu
    menu();
    LCD_rectangulo(0, 0, 132, 132, 1, BLACK);
    zone.image->draw(BOARD_OFFSET_Y, BOARD_OFFSET_X);
    scoreboard_update (hero);
    // Draw all the objects
    Object* obj;
    for(unsigned int j = 0; j < zone.dimension; j++)
      for(unsigned int i = 0; i < zone.dimension; i++)
        if ((obj = obj_list.get(Tile(i,j))))
          obj->draw(j*TILESIZE+ 2 + BOARD_OFFSET_Y, i*TILESIZE + 2 + BOARD_OFFSET_X);


    // Draw the hero.
    hero.draw();

    // Draw the bad character image in the pool
    bads[0]->Item::draw(zone.pool[2]*TILESIZE+2+ BOARD_OFFSET_Y, zone.pool[3]*TILESIZE+2 + BOARD_OFFSET_X);
    while (1){ // Gaming loop
      // Read controls
      unsigned int buttons = read_controls();
      Tile position = hero.position();
      // Move the hero
      if (buttons & BUTTON_LEFT){
        if (hero.move(Tile (hero.position().i-1, hero.position().j), fm))
          zone.image->draw(position.j*TILESIZE+2+BOARD_OFFSET_Y, position.i*TILESIZE+2+BOARD_OFFSET_X,
                           position.j*TILESIZE+2, position.i*TILESIZE+2,
                           hero.image_width(), hero.image_height());
      }
      if (buttons & BUTTON_RIGHT){
        if (hero.move(Tile (hero.position().i+1, hero.position().j), fm))
          zone.image->draw(position.j*TILESIZE+2+BOARD_OFFSET_Y, position.i*TILESIZE+2+BOARD_OFFSET_X,
                           position.j*TILESIZE+2, position.i*TILESIZE+2,
                           hero.image_width(), hero.image_height());
      }
      if (buttons & BUTTON_UP){
        if (hero.move(Tile (hero.position().i, hero.position().j-1), fm))
          zone.image->draw(position.j*TILESIZE+2+BOARD_OFFSET_Y, position.i*TILESIZE+2+BOARD_OFFSET_X,
                           position.j*TILESIZE+2, position.i*TILESIZE+2,
                           hero.image_width(), hero.image_height());
      }
      if (buttons & BUTTON_DOWN){
        if (hero.move(Tile (hero.position().i, hero.position().j+1), fm))
          zone.image->draw(position.j*TILESIZE+2+BOARD_OFFSET_Y, position.i*TILESIZE+2+BOARD_OFFSET_X,
                           position.j*TILESIZE+2, position.i*TILESIZE+2,
                           hero.image_width(), hero.image_height());
      }

      // For each bad character:
      // Calculate next tile for the shortest path from the actual
      // position to the hero's position and move the bad character.
      for (int i = 0; i < zone.bads; i++){
        Tile previous, next;
        if (bads[i]->alive()){
          // If it's alive
          previous = bads[i]->position();
          if (Game_mode == MODE_DIE)
            // Chase the hero
            next = fm.min_path(bads[i]->position(), hero.position());
          else
            // Go back to pool
            next = fm.min_path(bads[i]->position(),
                               Tile(zone.pool[0], zone.pool[1]-1));

          if (bads[i]->move(next, fm)){
            // If there was movement redraw the background and object
            zone.image->draw(previous.j*TILESIZE+2 + BOARD_OFFSET_Y, previous.i*TILESIZE+2 + BOARD_OFFSET_X,
                             previous.j*TILESIZE+2, previous.i*TILESIZE+2,
                             bads[i]->image_width(), bads[i]->image_height());
            Object* obj;
            if ((obj = obj_list.get(previous)))
              obj->draw(previous.j*TILESIZE+2 + BOARD_OFFSET_Y, previous.i*TILESIZE+2+BOARD_OFFSET_X);
          }
          else if (Game_mode == MODE_EAT && bads[i]->position() ==
                   Tile(zone.pool[0], zone.pool[1]-1)){
            // If it's already in the entrance of the pool
            bads[i]->die(zone);
            // Redraw the background and object
            zone.image->draw(previous.j*TILESIZE+2 + BOARD_OFFSET_Y, previous.i*TILESIZE+2 + BOARD_OFFSET_X,
                             previous.j*TILESIZE+2, previous.i*TILESIZE+2,
                             bads[i]->image_width(), bads[i]->image_height());
            Object* obj;
            if ((obj = obj_list.get(previous)))
              obj->draw(previous.j*TILESIZE+2 + BOARD_OFFSET_Y, previous.i*TILESIZE+2 + BOARD_OFFSET_X);
          }
        }
        else{
          bads[i]->dec_dead_time();
          if (bads[i]->alive()){
            bads[i]->position() = Tile(zone.pool[0], zone.pool[1]-1);
            zone.draw_pool(BadCharacter::deads());
          }
        }
      }

      // Process collisions
      bool hero_win, bads_win;
      collision (hero, obj_list, hero_win);
      for (int i = 0; i < zone.bads; i++)
        collision (hero, *(bads[i]), zone, bads_win);

      // Draw it all.
      scoreboard_update (hero);
      hero.draw();
      for (int i = 0; i < zone.bads; i++)
        bads[i]->draw(zone, BadCharacter::deads());
      if (bads_win){
        if (!hero.lifes()){
          winner = Character::BAD;
          break; // Game over.
        }
        else
          hero.lifes()--;
      }
      if (hero_win){
        winner = Character::HERO;
        break; // Freedom wins!
      }
      // Delay
      // Update the Game mode
      if (Game_mode_counter){
        if(--Game_mode_counter){
          LCD_imprimir_caracter('E', 2, 5, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('A', 10, 6, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('T', 18, 6, FONT_MEDIANO, RED, BLACK);
        
          LCD_imprimir_caracter('T', 34, 6, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('H', 42, 6, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('E', 50, 5, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('M', 58, 5, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('!', 66, 7, FONT_MEDIANO, RED, BLACK);

          LCD_imprimir_caracter('E', 2, 120, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('A', 10, 121, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('T', 18, 121, FONT_MEDIANO, RED, BLACK);
          
          LCD_imprimir_caracter('T', 34, 120, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('H', 42, 121, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('E', 50, 120, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('M', 58, 121, FONT_MEDIANO, RED, BLACK);
          LCD_imprimir_caracter('!', 66, 123, FONT_MEDIANO, RED, BLACK);
        }
        else{
          Game_mode = MODE_DIE;
          LCD_rectangulo(2, 5, 74, 13, 1, BLACK);
          LCD_rectangulo(2, 120, 74, 128, 1, BLACK);
        }
      }

      retardo(300000);
    }
    // Show results
    if (winner == Character::BAD)
      menu_game_over();
    if (winner == Character::HERO)
      menu_freedom_wins();

    obj_list.Destructor();
    for (int i = 0; i < zone.bads; i++)
      delete bads[i];
  }
}



