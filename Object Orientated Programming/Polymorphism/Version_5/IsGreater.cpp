#include "IsGreater.h"
/*
*   This is a static variable of the IsGreater class.
*   This variable will keep track of the number of current instantiated IsGreater objects.
*   This variable should be initially initialized to a value of 0.
*/
    int IsGreater::numAliveObjects = 0;
/*
*   This is the constructor for the IsGreater class.
*   This function should increment the numAliveObjects variable.
*   This function should also initialize the inherited value member with the passed in member
*/
    IsGreater::IsGreater(int value): ValueDependantTester(value)
    {
        this->numAliveObjects++;
    }
/*
*   This is the destructor for the IsGreater class.
*   This function should decrement the numAliveObjects variable.
*/
    IsGreater::~IsGreater()
    {
        this->numAliveObjects--;
    }

/*
*   This function should determine if the passed in value  is strictly greater than the inherited value member.
*   If it is, then the function should return true else false.
*/
    bool IsGreater::evaluate(int val)
    {
        return (val > this->value);
    }
/*
*   This function should return a new IsGreater pointer initialized with the inherited variable member.
*/
    NumberTester* IsGreater::clone()
    {
        return new IsGreater(this->value);
    }
/*
*   This is a static function.
*   This function should return the static numAliveObjects member of IsGreater class.
*/
    int IsGreater::getNumAliveObjects()
    {
        return numAliveObjects;
    }