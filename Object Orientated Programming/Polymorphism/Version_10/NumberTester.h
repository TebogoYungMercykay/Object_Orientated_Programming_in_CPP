// The NumberTester class

// # directives....
#ifndef NumberTester_H // include guard
#define NumberTester_H
#include <cstddef>
// Do not add any more #includes
// NumberTester.h
class NumberTester
{
    private:
        static int numAliveObjects;
    protected:
    public:
        NumberTester();
        ~NumberTester();
        virtual bool evaluate(int val) = 0;
        virtual NumberTester* clone() = 0;
        static int getNumAliveObjects();
};
#endif /* NumberTester_H */