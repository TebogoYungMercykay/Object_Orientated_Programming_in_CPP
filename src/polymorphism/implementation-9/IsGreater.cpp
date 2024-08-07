#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int Value) : ValueDependantTester(Value) {
  this->numAliveObjects++;
}
IsGreater::~IsGreater() { this->numAliveObjects--; }
bool IsGreater::evaluate(int val) {
  if (val > this->value) {
    return true;
  }
  return false;
}
NumberTester *IsGreater::clone() {
  IsGreater *ptr = new IsGreater(this->value);
  // ptr=&value;
  return ptr;
}
int IsGreater::getNumAliveObjects() { return numAliveObjects; }