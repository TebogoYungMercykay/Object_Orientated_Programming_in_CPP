#ifndef IsDivisible_H
#define IsDivisible_H
#include "ValueDependantTester.h"
#include <cstddef>

class IsDivisible : public ValueDependantTester {
private:
  static int numAliveObjects;

protected:
public:
  IsDivisible(int Value);
  ~IsDivisible();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif