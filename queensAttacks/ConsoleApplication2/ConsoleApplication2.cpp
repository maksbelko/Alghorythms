// classical chess problem about 2 queens attacks each other or not
#include "chess_board.h"
#include <iostream>

int main() {
  const auto white = std::make_pair(4, 4);
  const auto black = std::make_pair(0, 0);
  chess_board board(white, black);
  std::cout << board.canAttack();
}

