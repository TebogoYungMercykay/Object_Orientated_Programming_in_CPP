#include "IsEvenOdd.h"
int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd() { this->numAliveObjects += 1; }
IsEvenOdd::~IsEvenOdd() { this->numAliveObjects -= 1; }
bool IsEvenOdd::evaluate(int val) {
  bool Temp = (val % 2 == 0);
  return Temp;
}
NumberTester *IsEvenOdd::clone() {
  IsEvenOdd *Temp = new IsEvenOdd();
  return Temp;
}
int IsEvenOdd::getNumAliveObjects() { return numAliveObjects; }