#include "TwoDArray.h"

TwoDArray::TwoDArray(int** array, int* sizes, int baseSize){
    this->baseSize = baseSize;
    const int size = this->getBaseSize();
    this->sizes = new int[size];
    for(int i = 0;i<size;i++){
        this->sizes[i] = sizes[i];
    }
    this->array = new int*[size];
    for(int i = 0;i<size;i++){
        const int size = this->getSizes()[i];
        this->array[i] = new int[size];
        for(int j = 0;j<size;j++){
            this->array[i][j] = array[i][j];
        }
    }
}
TwoDArray::~TwoDArray(){
    const int size = this->getBaseSize();
    for(int i = 0;i<size;i++){
        delete this->array[i];
    }
    for(int i = 0;i<size;i++){
        this->array[i] = NULL;
    }
    delete this->array;
    delete this->sizes;
    this->array = NULL;
    this->sizes = NULL;
}
TwoDArray::operator int(){
    return this->getBaseSize();
}
TwoDArray::operator int*(){
    return this->getSizes();
}
TwoDArray::operator int**(){
    return this->getArray();
}
std::ostream& operator<<(std::ostream& os, TwoDArray& tda){
    const int size = tda.getBaseSize();
    for(int i = 0;i<size;i++){
        const int sizes = tda.getSizes()[i];
        for(int j = 0;j<sizes;j++){
            os<<tda.array[i][j];
            if(j>=(tda.getSizes()[i]-1)){
                os<<std::endl;
            }
            else{
                os<<" ";
            }
        }
    }
    return os;
}
int TwoDArray::getBaseSize(){
    return this->baseSize;
}
int* TwoDArray::getSizes(){
    const int size = this->getBaseSize();
    int* temp1 = new int[size];
    for(int i = 0;i<size;i++){
        temp1[i] = this->sizes[i];
    }
    return temp1;
}
int** TwoDArray::getArray(){
    int **temp = new int*[this->getBaseSize()];
    for(int i = 0, size = this->getBaseSize();i<size;i++){
        const int temp2 = this->getSizes()[i];
        temp[i] = new int[temp2];
        for(int j = 0;j<temp2;j++){
            temp[i][j] = this->array[i][j];
        }
    }
    return temp;
}
int* TwoDArray::operator[](int index){
    return 0;
}