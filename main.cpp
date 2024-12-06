#include "src/GameOfLife.hpp"
#include "src/GridLib.hpp"
#include "src/display.h"
#include <chrono>
#include <cstddef>
#include <iostream>
#include <thread>

using namespace std;

using CellType = bool;
using MainGrid = Grid<50, 50, CellType>;
const size_t maxGenerations = 100000000;

/*MainGrid initDefaultGrid() {*/
/*    return MainGrid {*/
/*        0, 0, 0, 0, 0, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 0, 0, 0, 0, 0,*/
/*        0, 0, 0, 1, 1, 1, 0, 0, 0,*/
/*        0, 0, 0, 0, 1, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 1, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 1, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 0, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 0, 0, 0, 0, 0,*/
/*        0, 0, 0, 0, 0, 0, 0, 0, 0*/
/*    };*/
/*}*/

MainGrid initDefaultGrid() {
  MainGrid res = {};
  for (size_t i = 0; i < res.size(); i++) {
    for (size_t j = 0; j < res[0].size(); j++) {
      res[i][j] = (std::rand() > RAND_MAX / 2);
    }
  }
  return res;
}

// this is the rule that determines if a cell is alive or dead, can be overridden but parameters must be the same
CellType GOLRules(const CellType &cellState, size_t neighborCount) {
    return baseGOLRules(cellState, neighborCount);
}

bool isCellAlive(bool cell) {
    return baseIsCellAlive(cell);
}

int main() {
  MainGrid grid = initDefaultGrid();
  MainGrid newGen = grid;

  cout << "Ce programme ...\n" << endl;
  for (size_t i = 0; i < maxGenerations; i++) {
    generateNextGen(grid, newGen, GOLRules, isCellAlive);

    /*clearScreen();*/
    displayGenerationTitle(i);
    displayArray(grid, "X", ".");

    if (grid == newGen)
      break;

    this_thread::sleep_for(chrono::milliseconds(50));

    grid = newGen;
  }

  return EXIT_SUCCESS;
}
