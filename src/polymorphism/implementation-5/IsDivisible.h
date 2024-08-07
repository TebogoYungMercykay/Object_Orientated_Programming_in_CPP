#ifndef IsDivisible_H
#define IsDivisible_H
#include "ValueDependantTester.h"
#include <cstddef>

class IsDivisible : public ValueDependantTester {
private:
  /*
   *   This is a static variable of the IsDivisible class.
   *   This variable will keep track of the number of current instantiated
   * IsDivisible objects. This variable should be initially initialized to a
   * value of 0.
   */
  static int numAliveObjects;

public:
  /*
   *   This is the constructor for the IsDivisible class.
   *   This function should increment the numAliveObjects variable.
   *   This function should also initialize the inherited value member with
   * the passed in member
   */
  IsDivisible(int value);
  /*
   *   This is the destructor for the IsDivisible class.
   *   This function should decrement the numAliveObjects variable.
   */
  ~IsDivisible();

  /*
   *   This function should determine if the passed in value is divisible with
   * the inherited value member. If it is, then the function should return
   * true else false.
   */
  bool evaluate(int val);
  /*
   *   This function should return a new IsDivisible pointer initialized with
   * the inherited variable member.
   */
  NumberTester *clone();
  /*
   *   This is a static function.
   *   This function should return the static numAliveObjects member of
   * IsDivisible class.
   */
  static int getNumAliveObjects();
};
#endif