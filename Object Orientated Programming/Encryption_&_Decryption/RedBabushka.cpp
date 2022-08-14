#include "RedBabushka.h"
#include "RotateException.h"

RedBabushka::RedBabushka(const unsigned char* id, unsigned int rotationAmount) : Babushka(id){
    this->rotationAmount = rotationAmount;
}
void RedBabushka::encrypt(unsigned char* data, int size){
    RotateException rotateException;
    if(this->rotationAmount >= size) throw rotateException;
    else{
        unsigned char* last;
        last  = new unsigned char[this->rotationAmount];
        int x = 0;
        for(int i = size - this->rotationAmount; i < size; i++)
        {last[x] = data[i];
            x++;}
        for(int i = size; i >= this->rotationAmount; i--)data[i] = data[i - this->rotationAmount];
        for(int i = 0; i < this->rotationAmount; i++)data[i] = last[i];
    }
}
void RedBabushka::decrypt(unsigned char* data, int size)
{   RotateException rotateException;
    if(this->rotationAmount >= size)throw rotateException;
    else{
        unsigned char* first;
        first = new unsigned char[this->rotationAmount];
        for(int i = 0; i < this->rotationAmount; i++)first[i] = data[i];
        for(int i = 0; i < size - this->rotationAmount; i++)data[i] = data[i + this->rotationAmount];
        int x =0;
        for(int i = size - this->rotationAmount; i < size; i++){
            data[i] = first[x];
            x++;
        }
    }
}