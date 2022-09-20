// The CountArray class

// # directives....
#ifndef CountArray_H // include guard
#define CountArray_H
#include "TwoDArray.h"

// Do not add any more #includes
// CountArray.h
class CountArray: public TwoDArray
{
    public:
        CountArray(int** array, int* sizes, int baseSize);
        int* operator[](int index);
};
#endif /* CountArray_H */