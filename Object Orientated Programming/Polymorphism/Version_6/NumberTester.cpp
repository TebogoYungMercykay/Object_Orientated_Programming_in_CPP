#include "NumberTester.h"
int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester() {
//    numAliveObjects = 0;
    NumberTester::numAliveObjects++;
}
NumberTester::~NumberTester() {
    NumberTester::numAliveObjects--;
}
int NumberTester::getNumAliveObjects() {
    return numAliveObjects;
}
bool NumberTester::evaluate(int val) {
    return false;
}
NumberTester* NumberTester::clone() {
    return NULL;
}