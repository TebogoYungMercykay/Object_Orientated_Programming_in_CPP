// The IsGreater class

// # directives....
#ifndef IsGreater_H // include guard
#define IsGreater_H
#include <cstddef>
#include "ValueDependantTester.h"
// Do not add any more #includes
// IsGreater.h
class IsGreater: public ValueDependantTester
{
    private:
        static int numAliveObjects;
    protected:
    public:
        IsGreater(int Value);
        ~IsGreater();
        bool evaluate(int val);
        NumberTester* clone();
        int getNumAliveObjects();
};
#endif /* IsGreater_H */