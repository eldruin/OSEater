/**
 * \file image.h Image \brief storing class
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

#ifndef __IMAGE_H__
#define __IMAGE_H__

/** \brief Stores the images.
 *
 * The \c Image class is used to store the images and provides
 * several methods.
 * It links to an array containing the raw data per pixel of the image.
 */
class Image
{
 public:
  /// Constructor
  Image (const char *const data, unsigned int width, unsigned int
         height): width(width), height(height), _data(data) {}

  /** \brief Extracts the color information of a pixel.
   *
   * \pre 0 <= x < width and 0 <= y < height.
   * \return 2 bytes value containing the color
   * in rgb format combined shifting the bits.
   */
  unsigned int pixel (unsigned int x, unsigned int y) const;

  /** Draws the image from some given coordinates full or just a
   *  given frame of it.
   * \pre 0 <= x < width and 0 <= y < height.
   */
  void draw (unsigned int x, unsigned int y, unsigned int frame_start_x = 0,
             unsigned int frame_start_y = 0, unsigned int frame_width = 0,
	     unsigned int frame_height = 0) const;

  unsigned int width,  ///< width of the image.
    height; ///< height of the image.
 private:
  /// Pointer to the image RAW data.
  const char *const _data;
};

#endif
