#ifndef SortArray_Practical4
#define SortArray_Practical4
#include "TwoDArray.h"

class SortArray: public TwoDArray
{
    public:
        SortArray(int** array, int* sizes, int baseSize);
        int* operator[](int index);
};
#endif