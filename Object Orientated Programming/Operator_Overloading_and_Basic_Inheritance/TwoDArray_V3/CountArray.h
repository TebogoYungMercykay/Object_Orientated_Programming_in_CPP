#ifndef CountArray_Practical4
#define CountArray_Practical4
#include "TwoDArray.h"

class CountArray: public TwoDArray
{
    public:
        CountArray(int** array, int* sizes, int baseSize);
        int* operator[](int index);
};
#endif