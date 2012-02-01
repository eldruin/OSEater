/**
 * \file item.h \brief Base class for all the things in the screen.
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

#ifndef __ITEM_H__
#define __ITEM_H__

class Image;

/// The \c Item class is the base for all the things in the screen.
class Item {
 public:
  /// Constructor
  Item(const Image& image): _image(image) {}
  /// \sa Image::draw()
  void draw ( unsigned int x, unsigned int y ) const;
  /// \return Image::width
  inline unsigned int image_width() const { return _image.width; }
  /// \return Image::height
  inline unsigned int image_height() const { return _image.height; }

  virtual ~Item () {}
 protected:
  /// Image of the item.
  const Image& _image;
};

#endif
