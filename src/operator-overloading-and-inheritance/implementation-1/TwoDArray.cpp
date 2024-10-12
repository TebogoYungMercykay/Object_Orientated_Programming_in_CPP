// The TwoDArray class

// # directives....
#include "TwoDArray.h"
// Do not add any more #includes
// TwoDArray.cpp
int **TwoDArray::getArray() {
  int **arrayTemp = new int *[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    arrayTemp[k_iterator] = new int[this->sizes[k_iterator]];
    for (int t_iterator = 0; t_iterator < this->sizes[k_iterator];
         t_iterator++) {
      arrayTemp[k_iterator][t_iterator] = this->array[k_iterator][t_iterator];
    }
  }
  return arrayTemp;
}
int *TwoDArray::getSizes() {
  int *sizesTemp = new int[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    sizesTemp[k_iterator] = this->sizes[k_iterator];
  }
  return sizesTemp;
}
int TwoDArray::getBaseSize() { return this->baseSize; }
TwoDArray::TwoDArray(int **array, int *sizes, int baseSize) {
  this->baseSize = baseSize;
  this->sizes = new int[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    this->sizes[k_iterator] = sizes[k_iterator];
  }
  this->array = new int *[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    this->array[k_iterator] = new int[this->sizes[k_iterator]];
    for (int t_iterator = 0; t_iterator < this->sizes[k_iterator];
         t_iterator++) {
      this->array[k_iterator][t_iterator] = array[k_iterator][t_iterator];
    }
  }
}
TwoDArray::~TwoDArray() {
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    delete this->array[k_iterator];
    this->array[k_iterator] = NULL;
  }
  delete this->array;
  this->array = NULL;
  delete this->sizes;
  this->sizes = NULL;
}
TwoDArray::operator int **() {
  int **arrayTemp = new int *[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    arrayTemp[k_iterator] = new int[this->sizes[k_iterator]];
    for (int t_iterator = 0; t_iterator < this->sizes[k_iterator];
         t_iterator++) {
      arrayTemp[k_iterator][t_iterator] = this->array[k_iterator][t_iterator];
    }
  }
  return arrayTemp;
}
TwoDArray::operator int *() {
  int *sizesTemp = new int[this->baseSize];
  for (int k_iterator = 0; k_iterator < this->baseSize; k_iterator++) {
    sizesTemp[k_iterator] = this->sizes[k_iterator];
  }
  return sizesTemp;
}
TwoDArray::operator int() { return this->baseSize; }
std::ostream &operator<<(std::ostream &os, TwoDArray &tda) {
  for (int k_iterator = 0; k_iterator < tda.baseSize; k_iterator++) {
    for (int t_iterator = 0, n_iterator = tda.sizes[k_iterator];
         t_iterator < n_iterator; t_iterator++) {
      if (t_iterator < (n_iterator - 1)) {
        os << tda.array[k_iterator][t_iterator];
        os << " ";
      } else {
        os << tda.array[k_iterator][t_iterator];
        os << "\n";
      }
    }
  }
  return os;
}
// This function is pure virtual within the twoDArray Class.
int *TwoDArray::operator[](int index) { return NULL; }