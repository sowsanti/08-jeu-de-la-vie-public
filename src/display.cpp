#include "display.h"
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void clearScreen() {
#ifdef _WIN32
  system("CLS");
#else
  system("clear");
#endif
}

void printCenteredContent(string_view text, int width) {
  int padding = (width - static_cast<int>(text.length())) / 2;
  cout << string(padding, ' ') << text << endl;
}

void displayGenerationTitle(size_t iterationNumber) {
  const static string title = "GENERATION NO ";

  cout << setfill('-') << setw(30) << "-" << endl;
  printCenteredContent(title + to_string(iterationNumber), 30);
  cout << setfill('-') << setw(30) << "-" << endl;
}
