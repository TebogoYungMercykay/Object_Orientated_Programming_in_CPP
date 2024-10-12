#include "chessboard.h"
#include "chesspiece.h"

#include <iostream>

using namespace std;

static void task1() {
  Chessboard *board = new Chessboard(8, 8);

  board->addChesspiece(new Chesspiece("rook"), 0, 0);
  board->addChesspiece(new Chesspiece("knight"), 0, 1);

  board->addChesspiece(new Chesspiece(board->at(0, 0)), 0, 7);

  cout << board->at(0, 0).getName() << endl;
  cout << board->at(0, 1).getName() << endl;
  cout << board->at(0, 7).getName() << endl;

  cout << board->at(0, 0).getNumberOfPieces() << endl;
  Chessboard *board2 = new Chessboard(*board);
  cout << board->at(0, 1).getNumberOfPieces() << endl;

  board->removeChesspiece(0, 7);
  cout << board2->at(0, 7).getName() << endl;
  cout << board2->at(0, 1).getNumberOfPieces() << endl;
  cout << "**************** Here ****************" << endl;
}

static void task2() {

  Chessboard *board = new Chessboard(8, 8);

  board->addChesspiece(new Chesspiece("rook", true), 0, 0);
  board->addChesspiece(new Chesspiece("knight", true), 0, 1);
  board->addChesspiece(new Chesspiece("bishop", true), 0, 2);

  board->addChesspiece(new Chesspiece("rook", false), 7, 0);
  board->addChesspiece(new Chesspiece("knight", false), 7, 1);
  board->addChesspiece(new Chesspiece("bishop", false), 7, 2);

  board->displayBoard();

  cout << endl;

  Chessboard *board2 = new Chessboard(8, 8);
  *board2 = *board;

  board2->displayBoard();

  cout << endl;

  board2->addChesspiece(new Chesspiece("queen", true), 2, 6);
  board2->addChesspiece(new Chesspiece("knight", true), 3, 7);

  *board += *board2;

  board->displayBoard();
}

int main() {
  task1();
  task2();
  return 0;
}

/* Task 1 output

rook
knight
rook
3
6
rook
5

*/

/* Task 2 output
R K B * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
r k b * * * * *

R K B * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
* * * * * * * *
r k b * * * * *

R K B * * * * *
* * * * * * * *
* * * * * * Q *
* * * * * * * K
* * * * * * * *
* * * * * * * *
* * * * * * * *
r k b * * * * *

*/