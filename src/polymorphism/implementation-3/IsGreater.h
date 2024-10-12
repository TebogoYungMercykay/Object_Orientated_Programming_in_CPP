#ifndef IsGreater_H
#define IsGreater_H
#include "ValueDependantTester.h"
#include <cstddef>

class IsGreater : public ValueDependantTester {
private:
  static int numAliveObjects;

protected:
public:
  IsGreater(int Value);
  ~IsGreater();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif