#ifndef IsEvenOdd_H
#define IsEvenOdd_H
#include <cstddef>
#include "ValueIndependantTester.h"

class IsEvenOdd: public ValueIndependantTester
{
    private:
    /*
    *   This is a static variable of the IsEvenOdd class.
    *   This variable will keep track of the number of current instantiated IsEvenOdd objects.
    *   This variable should be initially initialized to a value of 0.
    */
        static int numAliveObjects;

    public:
    /*
    *   This is the constructor for the IsEvenOdd class.
    *   This function should increment the numAliveObjects variable.
    */
        IsEvenOdd();
    /*
    *   This is the destructor for the IsEvenOdd class.
    *   This function should decrement the numAliveObjects variable.
    */
        ~IsEvenOdd();
    /*
    *   This function should test if the passed in value is even or odd.
    *   If it is even the function should return true else false.
    */
        bool evaluate(int val);
    /*
    *   This function should return a new IsEvenOdd pointer.
    */
        NumberTester* clone();
    /*
    *   This is a static function.
    *   This function should return the static numAliveObjects member of IsEvenOdd class.
    */
        static int getNumAliveObjects();
};
#endif