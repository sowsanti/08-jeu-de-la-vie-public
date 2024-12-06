#ifndef PRG1_B_08_JEUX_DE_LA_VIE_KIALA_BINGA_SUGRANES_DISPLAY_H
#define PRG1_B_08_JEUX_DE_LA_VIE_KIALA_BINGA_SUGRANES_DISPLAY_H

#include "GridLib.hpp"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string_view>

void printCenteredContent(std::string_view text, int width);
void displayGenerationTitle(std::size_t iterationNumber);

template <std::size_t width = 9, std::size_t height = 9, typename CellType = bool>
void displayArray(Grid<width, height, CellType> &grid, 
        std::string_view alive = "X", std::string_view dead = ".") {
  std::cout << std::setfill(' ') << std::setw(3) << " ";
  for (std::size_t column = 0; column < width; ++column) {
    std::cout << std::setfill(' ') << std::setw(3) << column;
  }
  std::cout << std::endl;

  for (std::size_t line = 0; line < height; ++line) {
    std::cout << std::setw(3) << line;
    for (std::size_t column = 0; column < width; ++column) {
      std::cout << std::setfill(' ') << std::setw(3)
                << (grid[line][column] ? alive : dead);
    }
    std::cout << std::endl;
  }
}

void clearScreen();

#endif // PRG1_B_08_JEUX_DE_LA_VIE_KIALA_BINGA_SUGRANES_DISPLAY_H
