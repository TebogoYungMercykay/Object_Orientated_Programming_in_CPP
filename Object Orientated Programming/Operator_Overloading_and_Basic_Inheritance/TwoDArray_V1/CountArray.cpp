// The CountArray class

// # directives....
#include "CountArray.h"
// Do not add any more #includes
// CountArray.cpp
CountArray::CountArray(int** array, int* sizes, int baseSize) :TwoDArray(array,sizes,baseSize){

}
int* CountArray::operator[](int index){
    int *returnInt = new int(this->getSizes()[index]);
    return returnInt;
}