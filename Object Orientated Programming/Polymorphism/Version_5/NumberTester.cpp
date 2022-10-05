#include "NumberTester.h"
/*
*   This is a static variable of the NumberTester class.
*   This variable will keep track of the number of current instantiated NumberTester objects.
*   This variable should be initially initialized to a value of 0.
*/
    int NumberTester::numAliveObjects = 0;
/*
*   This is the constructor for the NumberTester class.
*   This function should increment the numAliveObjects variable.
*/
    NumberTester::NumberTester()
    {
        this->numAliveObjects++;
    }
/*
*   This is the destructor for the NumberTester class.
*   This function should decrement the numAliveObjects variable.
*/
    NumberTester::~NumberTester()
    {
        this->numAliveObjects--;
    }
/*
*   This is a static function.
*   This function should return the static numAliveObjects member of NumberTester class.
*/
    int NumberTester::getNumAliveObjects()
    {
        return numAliveObjects;
    }