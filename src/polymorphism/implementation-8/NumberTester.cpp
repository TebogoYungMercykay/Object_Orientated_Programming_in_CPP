#include "NumberTester.h"
int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester() { this->numAliveObjects++; }
NumberTester::~NumberTester() { this->numAliveObjects--; }
bool NumberTester::evaluate(int val) { return false; }
NumberTester *NumberTester::clone() { return NULL; }
int NumberTester::getNumAliveObjects() { return numAliveObjects; }