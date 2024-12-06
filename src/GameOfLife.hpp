#ifndef _H_GAME_OF_LIFE
#define _H_GAME_OF_LIFE

#include "GridLib.hpp"
#include <cstddef>

enum class BaseRules {
  ShouldLive = 2,
  ShouldBeBorn = 3,
};

bool baseGOLRules(const bool &cellState, size_t aliveNeighborCount);
bool baseIsCellAlive(bool cell);

template <int d = 1, typename CellType = bool, typename FnAlive>
std::size_t aliveNeighbors(const Grid<d * 2 + 1, d * 2 + 1, CellType> &neighbors, FnAlive isCellAlive) {
  size_t aliveCount = 0;
  for (size_t i = 0; i < (d * 2 + 1); i++) {
    for (size_t j = 0; j < (d * 2 + 1); j++) {
      // Skip the cell itself
      if (i == d && j == d) continue;
      if (isCellAlive(neighbors[i][j])) aliveCount++;
    }
  }

  return aliveCount;
}

template <int d = 1, std::size_t width = 9, std::size_t height = 9, typename CellType = bool, typename FnRules, typename FnAlive>
void applyRuleForCell(const Grid<width, height, CellType> &current,
                      Grid<width, height, CellType> &next, 
                      std::size_t i, std::size_t j, 
                      FnRules GOLRules = baseGOLRules, FnAlive isCellAlive = baseIsCellAlive) {
  std::size_t aliveNeighborCount = aliveNeighbors(cellNeighbors(current, {i, j}), isCellAlive);
  next[i][j] = GOLRules(current[i][j], aliveNeighborCount);
}

template <int d = 1, std::size_t width = 9, std::size_t height = 9, typename CellType = bool, typename FnRules, typename FnAlive>
void generateNextGen(const Grid<width, height, CellType> &current, Grid<width, height, CellType> &next,
                     FnRules fnRules = baseGOLRules, FnAlive fnAlive = baseIsCellAlive) {
  for (std::size_t i = 0; i < height; ++i) {
    for (std::size_t j = 0; j < width; ++j) {
      applyRuleForCell<d, width, height, CellType, FnRules, FnAlive>(current, next, i, j, fnRules, fnAlive);
    }
  }
}

#endif // _H_GAME_OF_LIFE
