// The SumArray class

// # directives....
#ifndef SumArray_H // include guard
#define SumArray_H
#include "TwoDArray.h"

// Do not add any more #includes
// SumArray.h
class SumArray : public TwoDArray {
public:
  SumArray(int **array, int *sizes, int baseSize);
  int *operator[](int index);
};
#endif /* SumArray_H */