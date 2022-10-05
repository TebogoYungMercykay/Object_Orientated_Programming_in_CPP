#ifndef NumberTester_H
#define NumberTester_H
#include <cstddef>

class NumberTester
{
    private:
    /*
    *   This is a static variable of the NumberTester class.
    *   This variable will keep track of the number of current instantiated NumberTester objects.
    *   This variable should be initially initialized to a value of 0.
    */
        static int numAliveObjects;
    
    public:
    /*
    *   This is the constructor for the NumberTester class.
    *   This function should increment the numAliveObjects variable.
    */
        NumberTester();
    /*
    *   This is the destructor for the NumberTester class.
    *   This function should decrement the numAliveObjects variable.
    */
        ~NumberTester();
    /*
    *   This is a pure virtual function.
    */
        virtual bool evaluate(int val) = 0;
    /*
    *   This is a pure virtual function.
    */
        virtual NumberTester* clone() = 0;
    /*
    *   This is a static function.
    *   This function should return the static numAliveObjects member of NumberTester class.
    */
        static int getNumAliveObjects();
};
#endif