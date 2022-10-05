#ifndef IsGreater_H
#define IsGreater_H
#include <cstddef>
#include "ValueDependantTester.h"

class IsGreater: public ValueDependantTester
{
    private:
    /*
    *   This is a static variable of the IsGreater class.
    *   This variable will keep track of the number of current instantiated IsGreater objects.
    *   This variable should be initially initialized to a value of 0.
    */
        static int numAliveObjects;
    public:
    /*
    *   This is the constructor for the IsGreater class.
    *   This function should increment the numAliveObjects variable.
    *   This function should also initialize the inherited value member with the passed in member
    */
        IsGreater(int value);
    /*
    *   This is the destructor for the IsGreater class.
    *   This function should decrement the numAliveObjects variable.
    */
        ~IsGreater();
    
    /*
    *   This function should determine if the passed in value  is strictly greater than the inherited value member.
    *   If it is, then the function should return true else false.
    */
        bool evaluate(int val);
    /*
    *   This function should return a new IsGreater pointer initialized with the inherited variable member.
    */
        NumberTester* clone();
    /*
    *   This is a static function.
    *   This function should return the static numAliveObjects member of IsGreater class.
    */
        static int getNumAliveObjects();
};
#endif