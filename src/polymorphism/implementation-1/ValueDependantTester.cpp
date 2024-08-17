#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val) {
  this->value = val;
  this->numAliveObjects += 1;
}
ValueDependantTester::~ValueDependantTester() { this->numAliveObjects -= 1; }
bool ValueDependantTester::evaluate(int val) { return false; }
NumberTester *ValueDependantTester::clone() { return NULL; }
int ValueDependantTester::getNumAliveObjects() { return numAliveObjects; }