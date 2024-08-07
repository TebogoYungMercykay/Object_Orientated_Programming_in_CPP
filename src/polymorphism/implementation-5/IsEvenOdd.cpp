#include "IsEvenOdd.h"
/*
 *   This is a static variable of the IsEvenOdd class.
 *   This variable will keep track of the number of current instantiated
 * IsEvenOdd objects. This variable should be initially initialized to a value
 * of 0.
 */
int IsEvenOdd::numAliveObjects = 0;

/*
 *   This is the constructor for the IsEvenOdd class.
 *   This function should increment the numAliveObjects variable.
 */
IsEvenOdd::IsEvenOdd() : ValueIndependantTester() { this->numAliveObjects++; }
/*
 *   This is the destructor for the IsEvenOdd class.
 *   This function should decrement the numAliveObjects variable.
 */
IsEvenOdd::~IsEvenOdd() { this->numAliveObjects--; }
/*
 *   This function should test if the passed in value is even or odd.
 *   If it is even the function should return true else false.
 */
bool IsEvenOdd::evaluate(int val) { return (val % 2 == 0); }
/*
 *   This function should return a new IsEvenOdd pointer.
 */
NumberTester *IsEvenOdd::clone() { return new IsEvenOdd(); }
/*
 *   This is a static function.
 *   This function should return the static numAliveObjects member of IsEvenOdd
 * class.
 */
int IsEvenOdd::getNumAliveObjects() { return numAliveObjects; }