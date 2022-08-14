#ifndef GREENBABUSHKA_H
#define GREENBABUSHKA_H
#include "Babushka.h"

class GreenBabushka: public Babushka{
    protected:
        unsigned int displacement;
    public:
        GreenBabushka( const unsigned char* id, unsigned int displacement);
        virtual void encrypt(unsigned char* data, int size); 
        virtual void decrypt(unsigned char* data, int size); 
};

#endif