#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include <stdexcept>
#include <utility>

class chess_board {
  const int board_size = 7;
  using position = std::pair<int, int>;

public:
  chess_board() : whitePos_({0, 0}), blackPos_({7, 7}) {}
  explicit chess_board(position white, position black)
      : whitePos_(white), blackPos_(black) {
    if (whitePos_ == blackPos_) {
      throw std::domain_error("Queens positions must be distinct!");
    }
    if (whitePos_.first > 7 || whitePos_.first < 0 || whitePos_.second > 7 ||
        whitePos_.second < 0 || blackPos_.first > 7 || blackPos_.first < 0 ||
        blackPos_.second > 7 || blackPos_.second < 0) {
      throw std::domain_error("Wrong placed queens");
    }
  }
  const position &white() const { return whitePos_; }
  const position &black() const { return blackPos_; }
  bool canAttack() const;

private:
  position whitePos_;
  position blackPos_;
};

#endif // !"chess_board.h"
