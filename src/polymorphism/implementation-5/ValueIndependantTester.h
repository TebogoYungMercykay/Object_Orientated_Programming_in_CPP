#ifndef ValueIndependantTester_H
#define ValueIndependantTester_H
#include "NumberTester.h"
#include <cstddef>

class ValueIndependantTester : public NumberTester {
private:
  /*
   *   This is a static variable of the ValueIndependantTester class.
   *   This variable will keep track of the number of current instantiated
   * ValueIndependantTester objects. This variable should be initially
   * initialized to a value of 0.
   */
  static int numAliveObjects;

public:
  /*
   *   This is the constructor for the ValueIndependantTester class.
   *   This function should also increment the numAliveObjects variable.
   */
  ValueIndependantTester();
  /*
   *   This is the destructor for the ValueIndependantTester class.
   *   This function should decrement the numAliveObjects variable.
   */
  ~ValueIndependantTester();
  /*
   *   This is a pure virtual function.
   */
  virtual bool evaluate(int val) = 0;
  /*
   *   This is a pure virtual function.
   */
  virtual NumberTester *clone() = 0;
  /*
   *   This is a static function.
   *   This function should return the static numAliveObjects member of
   * ValueIndependantTester class.
   */
  static int getNumAliveObjects();
};
#endif
