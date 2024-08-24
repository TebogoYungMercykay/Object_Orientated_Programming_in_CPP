#ifndef SumArray_H
#define SumArray_H
#include "TwoDArray.h"

class SumArray : public TwoDArray {
public:
  SumArray(int **array, int *sizes, int baseSize);
  int *operator[](int index);
};
#endif