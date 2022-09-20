#include "SumArray.h"
SumArray::SumArray(int** array, int* sizes, int baseSize): TwoDArray(array,sizes,baseSize)
{}
int operatorSum(int input[], int size);
int* SumArray::operator[](int index)
{
    return new int(operatorSum(this->getArray()[index], this->getSizes()[index]));
}
int operatorSum(int input[], int size)
{
    int temp = 0;
	for(int k_iterator = 0, sizearr = size;k_iterator<size;k_iterator+=1){
        temp+=input[k_iterator];
    }
    return temp;
}