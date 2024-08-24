#ifndef SumArray_Practical4
#define SumArray_Practical4
#include "TwoDArray.h"

class SumArray : public TwoDArray {
public:
  SumArray(int **array, int *sizes, int baseSize);
  int *operator[](int index);
};
#endif