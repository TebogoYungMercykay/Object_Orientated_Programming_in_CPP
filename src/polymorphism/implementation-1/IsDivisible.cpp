#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int Value) : ValueDependantTester(Value) {
  IsDivisible::numAliveObjects += 1;
}
IsDivisible::~IsDivisible() { IsDivisible::numAliveObjects -= 1; }
bool IsDivisible::evaluate(int val) { return (val % IsDivisible::value) == 0; }
NumberTester *IsDivisible::clone() {
  return new IsDivisible(IsDivisible::value);
}
int IsDivisible::getNumAliveObjects() { return numAliveObjects; }