#ifndef TesterInterface_H
#define TesterInterface_H
#include "NumberTester.h"
#include <cstddef>

class TesterInterface {
private:
  int maxNumTesters;
  int currNumTesters;
  NumberTester **testers;

protected:
public:
  TesterInterface(int maxNumTests);
  TesterInterface(TesterInterface *other);
  TesterInterface(TesterInterface &other);
  ~TesterInterface();
  int addTester(NumberTester *tester);
  bool removeTester(int pos);
  bool evaluate(int num);
  int *failedTests(int num);
  int numberOfFailedTests(int num);
  NumberTester *operator[](int pos);
  int getCurrNumTesters() const;
  int getMaxNumTesters() const;
};
#endif