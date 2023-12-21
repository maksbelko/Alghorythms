#include "chess_board.h"

bool chess_board::canAttack() const {

  bool attacksOnRowsOrColumns = this->black().first == this->white().first ||
                                this->black().second == this->white().second;
  bool attacksOnDiagonales = abs(this->white().first - this->black().first) ==
                             abs(this->black().second - this->white().second);
  return attacksOnRowsOrColumns || attacksOnDiagonales;
}
