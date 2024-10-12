// The ValueIndependantTester class

// # directives....
#ifndef ValueIndependantTester_H // include guard
#define ValueIndependantTester_H
#include "NumberTester.h"
#include <cstddef>
// Do not add any more #includes
// ValueIndependantTester.h
class ValueIndependantTester : public NumberTester {
private:
  static int numAliveObjects;

protected:
public:
  ValueIndependantTester();
  ~ValueIndependantTester();
  virtual bool evaluate(int val) = 0;
  virtual NumberTester *clone() = 0;
  static int getNumAliveObjects();
};
#endif /* ValueIndependantTester_H */