#ifndef TwoDArray_H
#define TwoDArray_H

#include <iostream>
#include <string>
class TwoDArray {
private:
  int baseSize;
  int *sizes;
  int **array;

protected:
  int getBaseSize();
  int *getSizes();
  int **getArray();

public:
  TwoDArray(int **array, int *sizes, int baseSize);
  ~TwoDArray();
  operator int();
  operator int *();
  operator int **();
  virtual int *operator[](int index) = 0;
  friend std::ostream &operator<<(std::ostream &os, TwoDArray &tda);
};
#endif