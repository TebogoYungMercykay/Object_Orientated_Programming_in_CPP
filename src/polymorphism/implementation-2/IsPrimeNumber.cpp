#include "IsPrimeNumber.h"
int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() { this->numAliveObjects++; }
IsPrimeNumber::~IsPrimeNumber() { this->numAliveObjects--; }
bool IsPrimeNumber::evaluate(int val) {
  if (val == 0 || val == 1)
    return false;
  for (int i = 2; i <= (val / 2); ++i) {
    if (val % i == 0) {
      return false;
    }
  }
  return true;
}
NumberTester *IsPrimeNumber::clone() { return new IsPrimeNumber(); }
int IsPrimeNumber::getNumAliveObjects() { return numAliveObjects; }