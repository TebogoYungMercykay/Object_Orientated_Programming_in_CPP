#ifndef ISPRIMENUMBER_H
#define ISPRIMENUMBER_H

#include "ValueIndependantTester.h"
#include <cstddef>

class IsPrimeNumber : public ValueIndependantTester {
private:
  static int numAliveObjects;

public:
  IsPrimeNumber();
  ~IsPrimeNumber();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif