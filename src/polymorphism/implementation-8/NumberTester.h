#ifndef NumberTester_H
#define NumberTester_H
#include <cstddef>

class NumberTester {
private:
  static int numAliveObjects;

protected:
public:
  NumberTester();
  ~NumberTester();
  virtual bool evaluate(int val) = 0;
  virtual NumberTester *clone() = 0;
  static int getNumAliveObjects();
};
#endif