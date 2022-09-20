#include "TwoDArray.h"

TwoDArray::TwoDArray(int** array, int* sizes, int baseSize)
{
    this->baseSize = baseSize;
    this->sizes = new int[this->getBaseSize()]; int index=0;
    for(;index<this->getBaseSize();index+=1)
    {
        this->sizes[index] = sizes[index];
    }
    this->array = new int*[this->getBaseSize()];
    int size=this->getBaseSize(), counter = 0, size2;
    index=0;
    for(;index<size;index+=1)
    {
        counter = 0;
        this->array[index] = new int[this->getSizes()[index]];
        for(size2 = this->getSizes()[index];counter<size2;counter+=1)
        {
            this->array[index][counter] = array[index][counter];
        }
    }
}
TwoDArray::~TwoDArray()
{
    int i = 0, size = this->getBaseSize();
    for(;i<size;i+=1)
    {
        delete this->array[i];
        this->array[i] = 0;
    }
    delete this->array;
    delete this->sizes;
    this->array = 0;
    this->sizes = 0;
}
std::ostream& operator<<(std::ostream& os, TwoDArray& tda)
{
    int size = tda.getBaseSize(), sizes = 0, i=0, j=0, sizetemp;
    for(;i<size;i+=1)
    {
        j = 0;
        sizes = tda.getSizes()[i];
        for(sizetemp=(sizes-1);j<sizes;j+=1)
        {
            os<<tda.array[i][j];
            if(j<sizetemp)
            {
                os<<" ";
            }
        }
        os<<std::endl;
    }
    return os;
}
int TwoDArray::getBaseSize()
{
    return this->baseSize;
}
TwoDArray::operator int()
{
    int temp = this->getBaseSize();
    return temp;
}
int* TwoDArray::getSizes()
{
    int* ptr = new int[this->getBaseSize()], index=0;
    for(;index<this->getBaseSize();index+=1)
    {
        ptr[index] = this->sizes[index];
    }
    return ptr;
}
TwoDArray::operator int*()
{
    int* temp = this->getSizes();
    return temp;
}
int** TwoDArray::getArray()
{
    int size=this->getBaseSize(), **ptr = new int*[size], index=0, counter = 0, size2;
    for(;index<size;index+=1)
    {
        counter = 0;
        ptr[index] = new int[this->getSizes()[index]];
        for(size2 = this->getSizes()[index];counter<size2;counter+=1)
        {
            ptr[index][counter] = this->array[index][counter];
        }
    }
    return ptr;
}
TwoDArray::operator int**()
{
    int** temp = this->getArray();
    return temp;
}