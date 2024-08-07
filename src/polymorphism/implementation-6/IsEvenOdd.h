#ifndef ISEVENODD_H
#define ISEVENODD_H

#include "ValueIndependantTester.h"
#include <cstddef>

class IsEvenOdd : public ValueIndependantTester {
private:
  static int numAliveObjects;

public:
  IsEvenOdd();
  ~IsEvenOdd();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif