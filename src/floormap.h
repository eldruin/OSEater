/**
 * \file floormap.h \brief Graph implementing the ways available to
 * walk through.
 */
/* This file is part of OSEater.
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

#ifndef __FLOORMAP_H__
#define __FLOORMAP_H__

struct Tile;

/** \brief Graph implementing the ways available to walk through.
 *
 * It's a graph implemented as an adjacency matrix to determine
 * whether the character can walk to a tile.
*/
class FloorMap
{
 public:
  /** \brief Constructor.
   *
   * Creates the "matrix" from a wall vector (Zone::walls) that tells
   * the i,j and the k,l tile the wall is between. Both directions
   * are blocked.
   * \sa FloorMap::_matrix
   */
  FloorMap (unsigned int tiles, char* walls);
  //  void clear (Tile from, Tile to);

  /// \brief Checks if it's possible to walk between the given tiles.
  bool way (Tile from, Tile to) const;

  /// \brief Number of tiles the floormap has.
  /// \sa Zone::dimension.
  unsigned int tiles () const { return _tiles; }

  /** \brief Next tile for the minimum path between the given tiles.
   *
   * It's used for the bad characters to get close to the hero and to
   * return to the pool.
   * To make the game easier, the 33% of times the given tile is random.
   * \note Uses the Dijkstra algorithm.
   */
  Tile min_path (Tile from, Tile to) const;

  unsigned int cost (unsigned int a, unsigned int b) const;
  private:

  /** \brief Two adjacency vectors.
   *
   * The grid is a squared matrix of adjacency but if you pay attention,
   * if the tiles are not adjacent, it's always false, if the tiles are
   * the same, it's always true, so we can reduce it to 4 vectors,
   * but if you look again, these 4 vectors are equal by pairs, so if we
   * sort the coordinates, we can reduce it to just 2 vectors, with this
   * we change from a cost in space of \f$ tiles^4 \f$ to just
   * \f$ 2(tiles^2)-3 \f$ (-3 because of the matrix quadrature).
   */
  bool **_matrix;
  unsigned int _dimension; ///< _tiles * _tiles, just to be faster.
  /// Number of tiles the floormap has.
  /// \sa Zone::dimension
  unsigned int _tiles;
};

#endif
