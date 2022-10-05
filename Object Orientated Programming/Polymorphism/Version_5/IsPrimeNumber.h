#ifndef IsPrimeNumber_H
#define IsPrimeNumber_H
#include <cstddef>
#include "ValueIndependantTester.h"

class IsPrimeNumber: public ValueIndependantTester
{
    private:
    /*
    *   This is a static variable of the IsPrimeNumber class.
    *   This variable will keep track of the number of current instantiated IsPrimeNumber objects.
    *   This variable should be initially initialized to a value of 0.
    */
        static int numAliveObjects;

    public:
    /*
    *   This is the constructor for the IsPrimeNumber class.
    *   This function should increment the numAliveObjects variable.
    */
        IsPrimeNumber();
    /*
    *   This is the destructor for the IsPrimeNumber class.
    *   This function should decrement the numAliveObjects variable.
    */
        ~IsPrimeNumber();
    /*
    *   This function should test if the passed in value is a prime number or not.
    *   If it is a prime number the function should return true else false.
    */
        bool evaluate(int val);
    /*
    *   This function should return a new IsPrimeNumber pointer.
    */
        NumberTester* clone();
    /*
    *   This is a static function.
    *   This function should return the static numAliveObjects member of IsPrimeNumber class.
    */
        static int getNumAliveObjects();
};
#endif