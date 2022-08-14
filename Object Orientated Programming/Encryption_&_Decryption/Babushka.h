#ifndef BABUSHKA_H
#define BABUSHKA_H

class Babushka{
    protected:
        const unsigned char* id;
        static const int ID_LENGTH = 10;
        static const unsigned char MIN_VALUE_INCLUSIVE = 32;
        static const unsigned char MAX_VALUE_INCLUSIVE = 126;
    public:
        Babushka( const unsigned char* id);
        virtual ~Babushka();
        const int getIdLength();
        const unsigned char*  getId();
        virtual void encrypt(unsigned char* data, int size)=0; 
        virtual void decrypt(unsigned char* data, int size)=0; 
};

#endif