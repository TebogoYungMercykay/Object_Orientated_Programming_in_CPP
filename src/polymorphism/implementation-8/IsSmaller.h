#ifndef IsSmaller_H
#define IsSmaller_H
#include "ValueDependantTester.h"
#include <cstddef>

class IsSmaller : public ValueDependantTester {
private:
  static int numAliveObjects;

protected:
public:
  IsSmaller(int Value);
  ~IsSmaller();
  bool evaluate(int val);
  NumberTester *clone();
  static int getNumAliveObjects();
};
#endif