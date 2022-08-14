#ifndef GOLDBABUSHKA_H
#define GOLDBABUSHKA_H
#include "Babushka.h"

class GoldBabushka: public Babushka{
    protected:
        unsigned char xorValue;
    public:
        GoldBabushka( const unsigned char* id, unsigned char xorValue);
        virtual void encrypt(unsigned char* data, int size); 
        virtual void decrypt(unsigned char* data, int size);
};

#endif