// The ValueDependantTester class

// # directives....
#ifndef ValueDependantTester_H // include guard
#define ValueDependantTester_H
#include <cstddef>
#include "NumberTester.h"
// Do not add any more #includes
// ValueDependantTester.h
class ValueDependantTester: public NumberTester
{
    private:
        static int numAliveObjects;
    protected:
        int value;
    public:
        ValueDependantTester(int val);
        ~ValueDependantTester();
        virtual bool evaluate(int val) = 0;
        virtual NumberTester* clone() = 0;
        static int getNumAliveObjects();
};
#endif /* ValueDependantTester_H */