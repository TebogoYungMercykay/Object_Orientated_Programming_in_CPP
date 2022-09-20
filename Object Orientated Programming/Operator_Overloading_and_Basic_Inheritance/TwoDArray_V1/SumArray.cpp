// The SumArray class

// # directives....
#include "SumArray.h"
// Do not add any more #includes
// SumArray.cpp
SumArray::SumArray(int** array, int* sizes, int baseSize) :TwoDArray(array,sizes,baseSize){

}
int* SumArray::operator[](int index){
    int tempInt = 0;
    for(int k_iterator = 0;k_iterator<(this->getSizes()[index]);k_iterator++){
        tempInt+=this->getArray()[index][k_iterator];
    }
    int *returnInt = new int(tempInt);
    return returnInt;
}