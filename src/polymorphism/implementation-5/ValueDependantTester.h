#ifndef ValueDependantTester_H
#define ValueDependantTester_H
#include "NumberTester.h"
#include <cstddef>

class ValueDependantTester : public NumberTester {
private:
  /*
   *   This is a static variable of the ValueDependantTester class.
   *   This variable will keep track of the number of current instantiated
   * ValueDependantTester objects. This variable should be initially
   * initialized to a value of 0.
   */
  static int numAliveObjects;

protected:
  /*
   *   This is the value that will be used by objects of this class.
   */
  int value;

public:
  /*
   *   This is the constructor for the ValueDependantTester class.
   *   This function should initialize the value member with the passed in
   * parameter. This function should also increment the numAliveObjects
   * variable.
   */
  ValueDependantTester(int val);
  /*
   *   This is the destructor for the ValueDependantTester class.
   *   This function should decrement the numAliveObjects variable.
   */
  ~ValueDependantTester();
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
   * ValueDependantTester class.
   */
  static int getNumAliveObjects();
};
#endif
