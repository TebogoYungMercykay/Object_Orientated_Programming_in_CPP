#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int Value) : ValueDependantTester(Value) {
  this->numAliveObjects += 1;
}
IsDivisible::~IsDivisible() { this->numAliveObjects -= 1; }
bool IsDivisible::evaluate(int val) {
  int result = (val % this->value);
  bool Temp = result == 0;
  return Temp;
}
NumberTester *IsDivisible::clone() {
  IsDivisible *Temp = new IsDivisible(this->value);
  return Temp;
}
int IsDivisible::getNumAliveObjects() { return numAliveObjects; }