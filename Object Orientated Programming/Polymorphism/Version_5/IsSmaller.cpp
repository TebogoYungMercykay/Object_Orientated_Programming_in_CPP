#include "IsSmaller.h"
/*
*   This is a static variable of the IsSmaller class.
*   This variable will keep track of the number of current instantiated IsSmaller objects.
*   This variable should be initially initialized to a value of 0.
*/
    int IsSmaller::numAliveObjects = 0;
/*
*   This is the constructor for the IsSmaller class.
*   This function should increment the numAliveObjects variable.
*   This function should also initialize the inherited value member with the passed in member
*/
    IsSmaller::IsSmaller(int value): ValueDependantTester(value)
    {
        this->numAliveObjects++;
    }
/*
*   This is the destructor for the IsSmaller class.
*   This function should decrement the numAliveObjects variable.
*/
    IsSmaller::~IsSmaller()
    {
        this->numAliveObjects--;
    }

/*
*   This function should determine if the passed in value  is strictly smaller than the inherited value member.
*   If it is, then the function should return true else false.
*/
    bool IsSmaller::evaluate(int val)
    {
        return (val < this->value);
    }
/*
*   This function should return a new IsSmaller pointer initialized with the inherited variable member.
*/
    NumberTester* IsSmaller::clone()
    {
        return new IsSmaller(this->value);
    }
/*
*   This is a static function.
*   This function should return the static numAliveObjects member of IsSmaller class.
*/
    int IsSmaller::getNumAliveObjects()
    {
        return numAliveObjects;
    }