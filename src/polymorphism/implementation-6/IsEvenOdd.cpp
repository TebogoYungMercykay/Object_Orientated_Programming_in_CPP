#include "IsEvenOdd.h"
int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd() : ValueIndependantTester() {
  IsEvenOdd::numAliveObjects += 1;
}
IsEvenOdd::~IsEvenOdd() { IsEvenOdd::numAliveObjects -= 1; }
bool IsEvenOdd::evaluate(int val) {
  if (val % 2 == 0) {
    return true;
  } else {
    return false;
  }
}
NumberTester *IsEvenOdd::clone() {
  IsEvenOdd *evenodd;
  evenodd = new IsEvenOdd();
  return evenodd;
}
int IsEvenOdd::getNumAliveObjects() { return numAliveObjects; }