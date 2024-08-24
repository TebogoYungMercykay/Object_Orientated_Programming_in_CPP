#include "SortArray.h"

SortArray::SortArray(int **array, int *sizes, int baseSize)
    : TwoDArray(array, sizes, baseSize) {}
int *SortArray::operator[](int index) {
  int *temp = this->getArray()[index];
  int size = getSizes()[index];
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (temp[i] > temp[j]) {
        std::swap(temp[i], temp[j]);
      }
    }
  }
  return temp;
}