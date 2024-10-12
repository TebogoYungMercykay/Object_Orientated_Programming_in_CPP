#include "IsPrimeNumber.h"
/*
 *   This is a static variable of the IsPrimeNumber class.
 *   This variable will keep track of the number of current instantiated
 * IsPrimeNumber objects. This variable should be initially initialized to a
 * value of 0.
 */
int IsPrimeNumber::numAliveObjects = 0;

/*
 *   This is the constructor for the IsPrimeNumber class.
 *   This function should increment the numAliveObjects variable.
 */
IsPrimeNumber::IsPrimeNumber() : ValueIndependantTester() {
  this->numAliveObjects++;
}
/*
 *   This is the destructor for the IsPrimeNumber class.
 *   This function should decrement the numAliveObjects variable.
 */
IsPrimeNumber::~IsPrimeNumber() { this->numAliveObjects--; }
/*
 *   This function should test if the passed in value is a prime number or not.
 *   If it is a prime number the function should return true else false.
 */
bool IsPrimeNumber::evaluate(int val) {
  if (val <= 1) {
    return false;
  } else {
    for (int i = 2; i < val; i++)
      if (val % i == 0)
        return false;
    return true;
  }
}
/*
 *   This function should return a new IsPrimeNumber pointer.
 */
NumberTester *IsPrimeNumber::clone() { return new IsPrimeNumber(); }
/*
 *   This is a static function.
 *   This function should return the static numAliveObjects member of
 * IsPrimeNumber class.
 */
int IsPrimeNumber::getNumAliveObjects() { return numAliveObjects; }