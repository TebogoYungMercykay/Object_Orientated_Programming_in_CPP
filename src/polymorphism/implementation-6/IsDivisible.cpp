#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int value) : ValueDependantTester(value) {
  IsDivisible::numAliveObjects++;
  //    ValueDependantTester::value = value;
}
IsDivisible::~IsDivisible() { numAliveObjects--; }
bool IsDivisible::evaluate(int val) {

  if (val % IsDivisible::value == 0) {
    return true;
  }
  return false;
}
NumberTester *IsDivisible::clone() {
  IsDivisible *divisible;
  divisible = new IsDivisible(this->value);
  return divisible;
}
int IsDivisible::getNumAliveObjects() { return numAliveObjects; }