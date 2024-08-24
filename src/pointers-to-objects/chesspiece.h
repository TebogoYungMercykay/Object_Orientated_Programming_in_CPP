#ifndef CHESSPIECE_H
#define CHESSPIECE_H

#include <iostream>

using namespace std;

class Chesspiece {

private:
  string name;
  bool type;
  static int numberOfPieces;

public:
  Chesspiece();

  Chesspiece(Chesspiece &obj);

  Chesspiece(string in_name);

  ~Chesspiece();

  string getName() const;

  bool getType() const;

  int getNumberOfPieces() const;

  Chesspiece(string in_name, bool in_type);
};

#endif // CHESSPIECE_H
