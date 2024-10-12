#include "IsPrimeNumber.h"
int IsPrimeNumber::numAliveObjects = 0;

IsPrimeNumber::IsPrimeNumber() { this->numAliveObjects += 1; }
IsPrimeNumber::~IsPrimeNumber() { this->numAliveObjects -= 1; }
bool IsPrimeNumber::evaluate(int val) {
  bool Temp = true;
  if (val == 0 || val == 1)
    Temp = false;
  for (int i = 2; i <= (val / 2); ++i) {
    bool Temp2 = (val % i == 0);
    if (Temp2)
      Temp = false;
  }
  return Temp;
}
NumberTester *IsPrimeNumber::clone() {
  IsPrimeNumber *Temp = new IsPrimeNumber();
  return Temp;
}
int IsPrimeNumber::getNumAliveObjects() { return numAliveObjects; }