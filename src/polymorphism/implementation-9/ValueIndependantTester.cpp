#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester() { this->numAliveObjects++; }
ValueIndependantTester::~ValueIndependantTester() { this->numAliveObjects--; }
bool ValueIndependantTester::evaluate(int val) { return false; }
NumberTester *ValueIndependantTester::clone() { return NULL; }
int ValueIndependantTester::getNumAliveObjects() { return numAliveObjects; }