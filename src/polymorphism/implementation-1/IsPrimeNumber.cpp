#include "IsPrimeNumber.h"
int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() { IsPrimeNumber::numAliveObjects += 1; }
IsPrimeNumber::~IsPrimeNumber() { IsPrimeNumber::numAliveObjects -= 1; }
bool IsPrimeNumber::evaluate(int val) {
  int flag = 0;
  for (int i = 2; i < (val / 2) + 1; i++) {
    if (val % i == 0) {
      flag = 1;
      break;
    }
  }
  return (flag == 0);
}
NumberTester *IsPrimeNumber::clone() { return new IsPrimeNumber(); }
int IsPrimeNumber::getNumAliveObjects() { return numAliveObjects; }