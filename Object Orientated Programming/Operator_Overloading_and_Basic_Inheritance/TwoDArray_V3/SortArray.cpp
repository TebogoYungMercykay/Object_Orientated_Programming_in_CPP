#include "SortArray.h"
SortArray::SortArray(int** array, int* sizes, int baseSize): TwoDArray(array,sizes,baseSize)
{}
int* operatorSort(int input[], int size);
int* SortArray::operator[](int index)
{
    return operatorSort(this->getArray()[index], getSizes()[index]);;
}
int* operatorSort(int input[], int size)
{
	int tmp1=0, tmp=0, i=0;
	for(i = 1;i<size;i++)
	{
		tmp = input[i];
		for(tmp1 = i;tmp<input[tmp1-1] && tmp1>0;tmp1-=1)
		{
			input[tmp1]=input[tmp1-1];
		}
		input[tmp1] = tmp;
	}
	return input;
}