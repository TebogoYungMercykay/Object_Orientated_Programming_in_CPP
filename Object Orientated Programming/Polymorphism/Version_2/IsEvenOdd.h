// The IsEvenOdd class

// # directives....
#ifndef IsEvenOdd_H // include guard
#define IsEvenOdd_H
#include <cstddef>
#include "ValueIndependantTester.h"
// Do not add any more #includes
// IsEvenOdd.h
class IsEvenOdd: public ValueIndependantTester
{
    private:
        static int numAliveObjects;
    protected:
    public:
        IsEvenOdd();
        ~IsEvenOdd();
        bool evaluate(int val);
        NumberTester* clone();
        int getNumAliveObjects();
};
#endif /* IsEvenOdd_H */