#include "SumArray.h"

SumArray::SumArray(int **array, int *sizes, int baseSize)
    : TwoDArray(array, sizes, baseSize) {}
int *SumArray::operator[](int index) {
  int *temp = this->getArray()[index];
  int result = 0, num_rows = (this->getSizes()[index]);
  for (int i = 0; i < num_rows; i++) {
    result += temp[i];
  }
  delete temp;
  temp = NULL;
  return new int(result);
}