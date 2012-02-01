/**
 * \file collision.cpp \brief Collision processing functions.
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

#include "general.h"
#include "tile.h"
#include "image.h"
#include "character.h"
#include "badcharacter.h"
#include "herocharacter.h"
#include "object.h"
#include "objectlist.h"
#include "collision.h"
#include <olimex-lpc2378-stk/sound.h>
#include "sounds/point.ogg.h"
#include "sounds/life.ogg.h"
#include "sounds/die.ogg.h"

bool collision (HeroCharacter& c, ObjectList ol, bool& hero_win)
{
  extern GameMode Game_mode;
  extern unsigned int Game_mode_counter;
  Object* obj;
  hero_win = false;
  if ( (obj = ol.get(c.position())) ){
    if (obj->extra_life()){
      c.lifes()++;
      reproducir_sonido (life_ogg, life_ogg_size);
    }
    else
      reproducir_sonido (point_ogg, point_ogg_size);
    c.points() += obj->points();
    if (obj->type() == Object::SPECIAL){
      Game_mode = MODE_EAT;
      Game_mode_counter = MODE_COUNTER;
    }
    ol.remove(c.position());

    return true;
  }
  else if (ol.empty())
    hero_win = true;

  return false;
}

bool collision (HeroCharacter& a, BadCharacter& b,
		const Zone& zone, bool& bads_win)
{
  extern GameMode Game_mode;
  bads_win = false;
  if (a.position() == b.position()){
    if (Game_mode == MODE_DIE)
      bads_win = true;
    else if (Game_mode == MODE_EAT){
      b.die(zone);
      a.points() += 20;
    }
    reproducir_sonido (die_ogg, die_ogg_size);
    return true;
  }
  return false;
}
