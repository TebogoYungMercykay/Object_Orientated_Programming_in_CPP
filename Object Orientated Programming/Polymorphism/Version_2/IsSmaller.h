// The IsSmaller class

// # directives....
#ifndef IsSmaller_H // include guard
#define IsSmaller_H
#include <cstddef>
#include "ValueDependantTester.h"
// Do not add any more #includes
// IsSmaller.h
class IsSmaller: public ValueDependantTester
{
    private:
        static int numAliveObjects;
    protected:
    public:
        IsSmaller(int Value);
        ~IsSmaller();
        bool evaluate(int val);
        NumberTester* clone();
        int getNumAliveObjects();
};
#endif /* IsSmaller_H */