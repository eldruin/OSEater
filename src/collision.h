/**
 * \file collision.h \brief Collision process functions
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

#ifndef __COLLISION_H__
#define __COLLISION_H__
/** \brief Processes the collisions between the hero character and the
 *  list of objects.
 *
 * It searches in the ObjectList with the HeroCharacter position and
 * if there is an object in its position the object is extracted and
 * the character status is updated.
 * Also plays a sound when you eat an object.
 * \param c Character that collides.
 * \param ol \c ObjectList where the fuction searches.
 * \param hero_win If the object list is empty, the hero_win variable
 * is returned true and false if it's not.
 * \return Whether there was a collision with an object or not.
 */
bool collision (HeroCharacter& c, ObjectList ol, bool& hero_win);

/** \brief Processes the collisions between the hero character and a
 *  bad character.
 *
 * It compares the characters positions and depending on the
 * Game_mode it updates the characters status.
 * Also plays a sound when a character dies.
 * \param a Hero character that collides.
 * \param b Bad character that collides.
 * \param zone Zone where the collision occurs. Needed if the bad
 * character dies.
 * \param bads_win If there is a collision and the Game_mode is
 * GameMode::DIE, it is returned true. Otherwise it is false.
 * \return Whether there was a collision or not.
 */
bool collision (HeroCharacter& a, BadCharacter& b,
		const Zone& zone, bool& bads_win);

#endif
