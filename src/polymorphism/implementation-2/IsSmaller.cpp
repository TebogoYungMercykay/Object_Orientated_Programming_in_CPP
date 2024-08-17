#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int Value) : ValueDependantTester(Value) {
  this->numAliveObjects++;
}
IsSmaller::~IsSmaller() { this->numAliveObjects--; }
bool IsSmaller::evaluate(int val) { return (val < this->value); }
NumberTester *IsSmaller::clone() { return new IsSmaller(this->value); }
int IsSmaller::getNumAliveObjects() { return numAliveObjects; }