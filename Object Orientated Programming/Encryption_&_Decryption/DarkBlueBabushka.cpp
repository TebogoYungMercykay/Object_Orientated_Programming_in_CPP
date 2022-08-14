#include "DarkBlueBabushka.h"
#include "UnderflowException.h"
#include "OverflowException.h"

DarkBlueBabushka::DarkBlueBabushka(const unsigned char* id, unsigned int amount) : BlueBabushka(id, amount){
    this->amount = amount;
}
void DarkBlueBabushka::encrypt(unsigned char* data, int size)
{   UnderflowException underflowException;
    OverflowException overflowException;
    int i = 0;
    while( i < size)
    {if(data[i] - this->amount > MAX_VALUE_INCLUSIVE)throw overflowException;
        else if(data[i] - this->amount < MIN_VALUE_INCLUSIVE) throw underflowException;
        data[i] -= this->amount;
        i++;
    }
}
void DarkBlueBabushka::decrypt(unsigned char* data, int size){
    UnderflowException underflowException;
    OverflowException overflowException;
    int i = 0;
    while( i < size)
    {if(data[i] + this->amount > MAX_VALUE_INCLUSIVE)throw overflowException;
        else if(data[i] + this->amount < MIN_VALUE_INCLUSIVE) throw underflowException;
        data[i] += this->amount;
        i++;
    }
}