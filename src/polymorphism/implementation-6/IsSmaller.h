#ifndef ISSMALLER_H
#define ISSMALLER_H

#include "ValueDependantTester.h"
#include <cstddef>

using namespace std;

class IsSmaller : public ValueDependantTester {
private:
  static int numAliveObjects;

public:
  IsSmaller(int value);
  ~IsSmaller();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif