#include "chesspiece.h"

// Instantiating the static Member Variable
int Chesspiece::numberOfPieces = 0;

Chesspiece::Chesspiece() {
  this->numberOfPieces++;
  this->name = "";
  this->type = true;
}

Chesspiece::Chesspiece(Chesspiece &obj) {
  this->type = obj.getType();
  this->name = obj.getName();
  this->numberOfPieces = obj.getNumberOfPieces();
  this->numberOfPieces++;
}

Chesspiece::Chesspiece(string in_name) {
  this->name = in_name;
  this->numberOfPieces += 1;
}

Chesspiece::~Chesspiece() { this->numberOfPieces -= 1; }

string Chesspiece::getName() const { return this->name; }

bool Chesspiece::getType() const { return this->type; }

int Chesspiece::getNumberOfPieces() const { return this->numberOfPieces; }

Chesspiece::Chesspiece(string in_name, bool in_type) {
  this->name = in_name;
  this->type = in_type;
  this->numberOfPieces += 1;
}
