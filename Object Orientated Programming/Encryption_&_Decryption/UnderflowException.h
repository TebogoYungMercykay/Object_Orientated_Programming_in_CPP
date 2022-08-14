#ifndef UNDERFLOWEXCEPTION_H
#define UNDERFLOWEXCEPTION_H
#include "BabushkaException.h"

class UnderflowException: public BabushkaException{
    public:
        virtual void printMessage(); 
};
#endif