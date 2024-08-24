#include "CountArray.h"

CountArray::CountArray(int **array, int *sizes, int baseSize)
    : TwoDArray(array, sizes, baseSize) {}
int *CountArray::operator[](int index) {
  int temp = this->getSizes()[index];
  return new int(temp);
}