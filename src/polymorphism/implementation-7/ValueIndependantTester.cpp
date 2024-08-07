
#include "ValueIndependantTester.h"

int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester() {
  ValueIndependantTester::numAliveObjects++;
}

ValueIndependantTester::~ValueIndependantTester() {
  ValueIndependantTester::numAliveObjects--;
}

int ValueIndependantTester::getNumAliveObjects() {
  return ValueIndependantTester::numAliveObjects;
}