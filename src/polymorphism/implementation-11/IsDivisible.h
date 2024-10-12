// The IsDivisible class

// # directives....
#ifndef IsDivisible_H // include guard
#define IsDivisible_H
#include "ValueDependantTester.h"
#include <cstddef>
// Do not add any more #includes
// IsDivisible.h
class IsDivisible : public ValueDependantTester {
private:
  static int numAliveObjects;

protected:
public:
  IsDivisible(int Value);
  ~IsDivisible();
  bool evaluate(int val);
  NumberTester *clone();
  int getNumAliveObjects();
};
#endif /* IsDivisible_H */