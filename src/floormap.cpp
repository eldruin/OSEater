/**
 * \file floormap.cpp \brief Methods for the movement considering the
 * walls.
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

#include <cassert>
#include <cstdlib>
#include <new>
#include "general.h"
#include "tile.h"
#include "floormap.h"

/// \f$ \infty \f$ value for the cost of going from one tile to
/// another, meaning there is no way to go through.
#define INFINITE 0xffffffff
#define Vertex unsigned int ///< Vertexes for Dijkstra.
#if 0
inline unsigned int abs (int a)
{
  return a >= 0 ? a : -a;
}
#endif

/// Sort from bigger to smaller
inline void inv_sort (unsigned int& a, unsigned int& b)
{
	if (a < b){
		unsigned int c = a;
		a = b;
		b = c;
	}
}

/** Cost from one coordinate to another.
 * \return 0 if the coordinates are the same.
 * \return 1 if the coordinates are adjacent and there is no wall.
 * \return INFINITE in other case.
 */
unsigned int FloorMap::cost (unsigned int a, unsigned int b) const
{
	inv_sort(a, b);
	if (a - b == 1)
		return (_matrix[1][b] ? 1 : INFINITE);
	else if (a - b == _tiles)
                return (_matrix[0][b] ? 1 : INFINITE);
        else if (a == b)
                return 0;
        else
                return INFINITE;
}

/// Add operator when dealing with infinites.
inline unsigned int sum (unsigned int a, unsigned int b)
{
  if (a == INFINITE || b == INFINITE)
    return INFINITE;
  return (a + b);
}

FloorMap::FloorMap (unsigned int tiles, char* walls)
{
  _tiles = tiles;
  _dimension = _tiles * _tiles;
  _matrix = new bool* [2];
  _matrix[0] = new bool [_dimension-2];
  assert(_matrix[0]);
  _matrix[1] = new bool [_dimension-1];
  assert(_matrix[1]);

  for (unsigned char i = 0; i < _dimension - 2; i++){
		_matrix[0][i] = true;
		_matrix[1][i] = true;
  }
  _matrix[1][_dimension-2] = true; // _dimension-1 => 0 to _tiles^2-2
  // inserts the walls
  for (unsigned char i = 0; walls[i] != '$'; i+=4){
    unsigned int x = walls[i] * _tiles + walls[i+1];
    unsigned int y = walls[i+2] * _tiles + walls[i+3];
   	inv_sort(x, y);
		if (x - y == 1)
			_matrix[1][y] = false;
		else if (x - y == _tiles)
    	_matrix[0][y] = false;
  }
}

#if 0
void FloorMap::clear (Tile from, Tile to)
{
  if (from.i*TILESIZE <= _dimension && from.j*TILESIZE <= _dimension &&
      to.i*TILESIZE <= _dimension && to.j*TILESIZE <= _dimension){
    _matrix [from.i * _tiles + from.j][to.i * _tiles + to.j] = true;
    _matrix [to.i * _tiles + to.j][from.i * _tiles + from.j] = true;
  }
}
#endif

bool FloorMap::way (Tile from, Tile to) const
{
  if (from.i < _tiles && from.j < _tiles &&
      to.i < _tiles && to.j < _tiles) { // Valid position
      unsigned int x = from.i * _tiles + from.j;
      unsigned int y = to.i * _tiles + to.j;
      inv_sort(x, y);
			if (x - y == 1)
				return _matrix[1][y];
			else if (x - y == _tiles)
  	  	return _matrix[0][y];
  	  else if (x == y)
  	  	return true;
  }
  return false;
}

Tile FloorMap::min_path (Tile from, Tile to) const
{
  Tile next;
  if (!(from == to)){
    if (0){
      // This is the Dijkstra algorithm but needs too much memory. 

      bool* marks = new bool [_dimension];
      assert(marks);
      Vertex origin = from.i*_tiles+from.j;
      Vertex destiny = to.i*_tiles+to.j;
      Vertex v, w;
      unsigned int min_cost, owv;

      unsigned int* min_cost_vector = new unsigned int [_dimension];
      assert(min_cost);
      unsigned int* path = new unsigned int [_dimension];
      assert(path);

      // Initialization.
      for (v = 0; v < _dimension; v++){
        marks[v] = false;
        min_cost_vector[v] = cost(origin, v);
        path[v] = origin;
      }
      marks[origin] = true;

      // Calculates the minimun cost vector
      for (unsigned int i = 0; i < _dimension-1; i++){
        min_cost = INFINITE;
        for (v = 0; v < _dimension; v++)
          if (!marks[v] && min_cost_vector[v] < min_cost){
            min_cost = min_cost_vector[v];
            w = v;
          }
        marks[w] = true;
        for (v = 0; v < _dimension; v++){
          owv = sum(min_cost_vector[w], cost(w,v));
          if (!marks[v] && min_cost_vector[v] > owv){
            min_cost_vector[v] = owv;
            path[v] = w;
          }
        }
      }

      // Recovers the path.
      next = from;
      for (v = destiny; path[v] != origin; v++){
        next = Tile(v/_tiles, v%_tiles);
      }
      delete marks, min_cost_vector, path;
    }
    else { // 33% of the times the movement is random
		   // Actually 100% of the times because the Dijkstra algorithm
		   // needs too much memory
    Tile t;
    bool moved = false;
    while (!moved){
      switch (rand()%4){
      case 0: // UP
        if (way(from, (t = Tile (from.i, from.j-1)))){
          next = t;
          moved = true;
        }
        break;
      case 1: // DOWN
        if (way(from, (t = Tile (from.i, from.j+1)))){
          next = t;
          moved = true;
        }
        break;
      case 2: // LEFT
        if (way(from, (t = Tile (from.i-1, from.j)))){
          next = t;
          moved = true;
        }
        break;
      case 3: // RIGHT
        if (way(from, (t = Tile (from.i+1, from.j)))){
          next = t;
          moved = true;
        }
        break;
      }
    }
    }
  }
  else
    next = from;

  return next;
}
