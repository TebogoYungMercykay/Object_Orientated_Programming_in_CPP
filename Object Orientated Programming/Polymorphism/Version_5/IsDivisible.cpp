#include "IsDivisible.h"
/*
*   This is a static variable of the IsDivisible class.
*   This variable will keep track of the number of current instantiated IsDivisible objects.
*   This variable should be initially initialized to a value of 0.
*/
    int IsDivisible::numAliveObjects = 0;
/*
*   This is the constructor for the IsDivisible class.
*   This function should increment the numAliveObjects variable.
*   This function should also initialize the inherited value member with the passed in member
*/
    IsDivisible::IsDivisible(int value): ValueDependantTester(value)
    {
        this->numAliveObjects++;
    }
/*
*   This is the destructor for the IsDivisible class.
*   This function should decrement the numAliveObjects variable.
*/
    IsDivisible::~IsDivisible()
    {
        this->numAliveObjects--;
    }

/*
*   This function should determine if the passed in value is divisible with the inherited value member.
*   If it is, then the function should return true else false.
*/
    bool IsDivisible::evaluate(int val)
    {
        return (val % this->value == 0);
    }
/*
*   This function should return a new IsDivisible pointer initialized with the inherited variable member.
*/
    NumberTester* IsDivisible::clone()
    {
        return new IsDivisible(this->value);
    }
/*
*   This is a static function.
*   This function should return the static numAliveObjects member of IsDivisible class.
*/
    int IsDivisible::getNumAliveObjects()
    {
        return numAliveObjects;
    }