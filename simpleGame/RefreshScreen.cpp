//
// Created by bmondal on 07/02/21.
//

#include "RefreshScreen.h"
#include <iostream>

RefreshScreen::RefreshScreen() {
}

RefreshScreen::~RefreshScreen() {}

void RefreshScreen::clearScreen() {
  system("clear");
}

void RefreshScreen::pauses(std::string sec) {
  std::string s = "sleep "+sec;	system(s.c_str());
}
