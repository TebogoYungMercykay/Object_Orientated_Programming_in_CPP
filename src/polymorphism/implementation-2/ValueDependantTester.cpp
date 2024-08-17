#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val) {
  this->value = val;
  this->numAliveObjects++;
}
ValueDependantTester::~ValueDependantTester() { this->numAliveObjects--; }
bool ValueDependantTester::evaluate(int val) {
  // This is a pure virtual function.
  return true;
}
NumberTester *ValueDependantTester::clone() {
  // This is a pure virtual function.
  return NULL;
}
int ValueDependantTester::getNumAliveObjects() { return numAliveObjects; }