#ifndef IsPrimeNumber_H
#define IsPrimeNumber_H
#include <cstddef>
#include "ValueIndependantTester.h"

class IsPrimeNumber: public ValueIndependantTester
{
    private:
        static int numAliveObjects;
    protected:
    public:
        IsPrimeNumber();
        ~IsPrimeNumber();
        bool evaluate(int val);
        NumberTester* clone();
        static int getNumAliveObjects();
};
#endif