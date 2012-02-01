/**
 * \file ./zone2.h \brief This creates all the images and data for a
 * specific zone.
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
#ifndef __ZONE2_H__
#define __ZONE2_H__

/// \sa Zone::dimension
unsigned int zone2_dimension = 6;

/// \sa Zone::walls
char zone2_walls[] = {
  1,0, 1,1,
  2,0, 3,0,
  4,0, 4,1,
  5,0, 5,1,
  0,2, 1,2,
  0,3, 1,3,
  3,1, 3,2,
  4,2, 5,2,
  1,4, 1,5,
  2,4, 2,5,
  5,4, 5,5,
  // Pool:
  1,3, 2,3,
  3,3, 4,3,
  2,2, 2,3,
  3,2, 3,3,
  2,3, 2,4,
  3,3, 3,4,
  '$'
};

/// \sa Zone::object_list
char zone2_object_list [] = {
/// All the empty tiles have dots.
  APPLE, 0, 5,
    APPLE, 2, 0,
    '$'
};

/// \sa Zone::pool
char zone2_pool [] = {
  2, 3,
  3, 3
};

/// \sa Zone::bads
unsigned char zone2_bads = 1;

#include "images/zone2_img.h"

#endif

