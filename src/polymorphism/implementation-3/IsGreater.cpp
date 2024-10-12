#include "IsGreater.h"

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value) {
  numAliveObjects++;
}

IsGreater::~IsGreater() { numAliveObjects--; }

bool IsGreater::evaluate(int val) {
  if (val > value) {
    return true;
  } else {
    return false;
  }
}

NumberTester *IsGreater::clone() {
  IsGreater *valptr = new IsGreater(value);
  return valptr;
}

int IsGreater::getNumAliveObjects() { return numAliveObjects; }