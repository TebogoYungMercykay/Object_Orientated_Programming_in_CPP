#include "ValueIndependantTester.h"
/*
*   This is a static variable of the ValueIndependantTester class.
*   This variable will keep track of the number of current instantiated ValueIndependantTester objects.
*   This variable should be initially initialized to a value of 0.
*/
    int ValueIndependantTester::numAliveObjects = 0;
/*
*   This is the constructor for the ValueIndependantTester class.
*   This function should also increment the numAliveObjects variable.
*/
    ValueIndependantTester::ValueIndependantTester(): NumberTester()
    {
        this->numAliveObjects++;
    }
/*
*   This is the destructor for the ValueIndependantTester class.
*   This function should decrement the numAliveObjects variable.
*/
    ValueIndependantTester::~ValueIndependantTester()
    {
        this->numAliveObjects--;
    }

/*
*   This is a static function.
*   This function should return the static numAliveObjects member of ValueIndependantTester class.
*/
    int ValueIndependantTester::getNumAliveObjects()
    {
        return numAliveObjects;
    }