#ifndef VALUEINDEPENDANTTESTER_H
#define VALUEINDEPENDANTTESTER_H

#include "NumberTester.h"
#include <cstddef>

class ValueIndependantTester : public NumberTester {
private:
  static int numAliveObjects;

public:
  ValueIndependantTester();
  ~ValueIndependantTester();
  virtual bool evaluate(int val) = 0;
  virtual NumberTester *clone() = 0;
  static int getNumAliveObjects();
};
#endif