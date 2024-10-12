// The SortArray class

// # directives....
#include "SortArray.h"
// Do not add any more #includes
// SortArray.cpp
SortArray::SortArray(int **array, int *sizes, int baseSize)
    : TwoDArray(array, sizes, baseSize) {}
int *SortArray::operator[](int index) {
  int *arrayTemp = new int[this->getSizes()[index]];
  for (int k_iterator = 0; k_iterator < (this->getSizes()[index]);
       k_iterator++) {
    arrayTemp[k_iterator] = this->getArray()[index][k_iterator];
  }
  // Sorting - ASCENDING ORDER
  int bubble;
  for (int i_iterator = 0; i_iterator < this->getSizes()[index] - 1;
       i_iterator++) {
    bubble = 0;
    double temporary;
    for (int k_iterator = 0;
         k_iterator < (this->getSizes()[index] - i_iterator) - 1;
         k_iterator++) {
      if (arrayTemp[k_iterator] > arrayTemp[k_iterator + 1]) {
        temporary = arrayTemp[k_iterator];
        arrayTemp[k_iterator] = arrayTemp[k_iterator + 1];
        arrayTemp[k_iterator + 1] = temporary;
        bubble += 1;
      }
    }
    while (bubble == 0) {
      break;
    }
  }
  return arrayTemp;
}