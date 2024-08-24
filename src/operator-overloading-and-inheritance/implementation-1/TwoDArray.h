// The base 2D array class

// # directives....
#ifndef TwoDArray_H // include guard
#define TwoDArray_H

// Do not add any more #includes
#include <iostream>
#include <string>
// Define class below
// TwoDArray.h
class TwoDArray {
private:
  int **array;
  int *sizes;
  int baseSize;

protected:
  int **getArray();
  int *getSizes();
  int getBaseSize();

public:
  operator int **();
  operator int *();
  operator int();
  TwoDArray(int **array, int *sizes, int baseSize);
  ~TwoDArray();
  virtual int *operator[](int index) = 0;
  friend std::ostream &operator<<(std::ostream &os, TwoDArray &tda);
};
#endif /* TwoDArray_H */