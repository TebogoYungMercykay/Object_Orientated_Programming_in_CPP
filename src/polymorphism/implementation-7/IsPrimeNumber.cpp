
#include "IsPrimeNumber.h"

int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() { IsPrimeNumber::numAliveObjects++; }

IsPrimeNumber::~IsPrimeNumber() { IsPrimeNumber::numAliveObjects--; }

bool IsPrimeNumber::evaluate(int val) {
  int count = 0;
  for (int i = 1; i <= val; i++) {
    if (val % i == 0) {
      count++;
    }
  }

  if (count == 2) {
    return true;
  }
  return false;
}

int IsPrimeNumber::getNumAliveObjects() {
  return IsPrimeNumber::numAliveObjects;
}

NumberTester *IsPrimeNumber::clone() {
  NumberTester *ipn = new IsPrimeNumber();
  return ipn;
}