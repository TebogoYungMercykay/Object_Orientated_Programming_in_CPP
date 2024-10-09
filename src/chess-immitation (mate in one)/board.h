#ifndef BOARD_H
#include "piece.h"
#include <fstream>

class board {
public:
  board(std::string);
  ~board();
  board &operator--();
  bool checkIfPieceHasCheck(std::string, int, int, int, int);

private:
  int numWhitePieces;
  int numBlackPieces;
  piece **whitePieces;
  piece **blackPieces;
  std::string **chessboard;
  std::string move;
  char sideToMove;
  board &operator++();
};
#endif