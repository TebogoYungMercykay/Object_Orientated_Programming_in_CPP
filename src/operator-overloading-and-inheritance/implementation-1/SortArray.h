// The SortArray class

// # directives....
#ifndef SortArray_H // include guard
#define SortArray_H
#include "TwoDArray.h"

// Do not add any more #includes
// SortArray.h
class SortArray : public TwoDArray {
public:
  SortArray(int **array, int *sizes, int baseSize);
  int *operator[](int index);
};
#endif /* SortArray_H */