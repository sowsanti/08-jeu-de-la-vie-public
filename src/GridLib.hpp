#ifndef _H_GRID_LIB
#define _H_GRID_LIB

#include <array>
#include <cstddef>

struct Coordinate {
  std::size_t x;
  std::size_t y;
};

template <std::size_t width = 9, std::size_t height = 9, typename CellType = bool>
using Grid = std::array<std::array<CellType, width>, height>;

template <int d = 1, std::size_t width = 9, std::size_t height = 9, typename CellType = bool>
Grid<d * 2 + 1, d * 2 + 1, CellType> cellNeighbors(const Grid<width, height, CellType> &grid, const Coordinate &coord) {
  Grid<d * 2 + 1, d * 2 + 1, CellType> neighbors;
  for (int dx = -d; dx <= d; ++dx) {
    for (int dy = -d; dy <= d; ++dy) {
      int neighborX = coord.x + dx;
      int neighborY = coord.y + dy;

      // Check if the neighbor is within grid bounds
      if (neighborX >= 0 && neighborX < width && neighborY >= 0 &&
          neighborY < width) {
        neighbors[dx + d][dy + d] = grid[neighborX][neighborY];
      } else {
        neighbors[dx + d][dy + d] = 0;
      }
    }
  }

  return neighbors;
}

#endif // _H_GRID_LIB
