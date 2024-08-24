#ifndef SortArray_H
#define SortArray_H
#include "TwoDArray.h"

class SortArray : public TwoDArray {
public:
  SortArray(int **array, int *sizes, int baseSize);
  int *operator[](int index);
};
#endif