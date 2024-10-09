#ifndef solver_H
#define solver_H
#include "board.h"

class solver {
private:
  int numGames;
  board **boards;

public:
  solver(std::string);
  ~solver();
};
#endif