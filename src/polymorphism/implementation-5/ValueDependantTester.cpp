#include "ValueDependantTester.h"
/*
 *   This is a static variable of the ValueDependantTester class.
 *   This variable will keep track of the number of current instantiated
 * ValueDependantTester objects. This variable should be initially initialized
 * to a value of 0.
 */
int ValueDependantTester::numAliveObjects = 0;
/*
 *   This is the constructor for the ValueDependantTester class.
 *   This function should initialize the value member with the passed in
 * parameter. This function should also increment the numAliveObjects variable.
 */
ValueDependantTester::ValueDependantTester(int val) : NumberTester() {
  this->value = val;
  this->numAliveObjects++;
}
/*
 *   This is the destructor for the ValueDependantTester class.
 *   This function should decrement the numAliveObjects variable.
 */
ValueDependantTester::~ValueDependantTester() { this->numAliveObjects--; }

/*
 *   This is a static function.
 *   This function should return the static numAliveObjects member of
 * ValueDependantTester class.
 */
int ValueDependantTester::getNumAliveObjects() { return numAliveObjects; }