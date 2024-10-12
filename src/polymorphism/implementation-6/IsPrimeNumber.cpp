#include "IsPrimeNumber.h"
int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() : ValueIndependantTester() {
  IsPrimeNumber::numAliveObjects += 1;
}
IsPrimeNumber::~IsPrimeNumber() { IsPrimeNumber::numAliveObjects -= 1; }
bool IsPrimeNumber::evaluate(int val) {
  if (val <= 1)
    return false;
  for (int i = 2; i < val; i++)
    if (val % i == 0)
      return false;
  return true;
}
NumberTester *IsPrimeNumber::clone() {
  IsPrimeNumber *prime;
  prime = new IsPrimeNumber();
  return prime;
}
int IsPrimeNumber::getNumAliveObjects() { return numAliveObjects; }