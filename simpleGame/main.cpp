#include <iostream>
#include "RefreshScreen.h"

int main() {
  // print a loading *
  RefreshScreen refreshScreen;
  for (int i = 0; i<200; i++){
    refreshScreen.clearScreen();
    std::string star(i, '*');
    std::cout << "\e[0;" << 31 /*color code*/  << "m"<< star << "\e[0;0m" << std::endl;
    refreshScreen.pauses("0.01");
    refreshScreen.clearScreen();
  }

  return 0;
}

