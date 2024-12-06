#include "GameOfLife.hpp"

bool baseIsCellAlive(bool cell) { return cell; }

bool baseGOLRules(const bool &cellState, std::size_t aliveNeighborCount) {
  if (aliveNeighborCount == 2) {
    return cellState;
  } else if (aliveNeighborCount == 3) {
    return true;
  } else {
    return false;
  }
}
