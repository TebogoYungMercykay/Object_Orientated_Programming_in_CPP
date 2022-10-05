// The IsPrimeNumber class

// # directives....
#ifndef IsPrimeNumber_H // include guard
#define IsPrimeNumber_H
#include <cstddef>
#include "ValueIndependantTester.h"
// Do not add any more #includes
// IsPrimeNumber.h
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
        int getNumAliveObjects();
};
#endif /* IsPrimeNumber_H */