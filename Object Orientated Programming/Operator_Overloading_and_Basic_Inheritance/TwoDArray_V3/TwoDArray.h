#ifndef TwoDArray_Practical4
#define TwoDArray_Practical4

#include <iostream>
#include <string>
class TwoDArray
{
    protected:
        int getBaseSize();
        int* getSizes();
        int** getArray();
    private:
        int baseSize;
        int* sizes;
        int** array;
    public:
        TwoDArray(int** array, int* sizes, int baseSize);
        ~TwoDArray();
        operator int();
        operator int*();
        operator int**();
        virtual int* operator[](int index)=0;
        friend std::ostream& operator<<(std::ostream& os, TwoDArray& tda);
};
#endif