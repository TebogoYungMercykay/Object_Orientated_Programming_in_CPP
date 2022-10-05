#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val){
    ValueDependantTester::value = val;
//    numAliveObjects = 0;
    ValueDependantTester::numAliveObjects++;
}
ValueDependantTester::~ValueDependantTester() {
    ValueDependantTester::numAliveObjects--;
}
int ValueDependantTester::getNumAliveObjects() {
    return numAliveObjects;
}
bool ValueDependantTester::evaluate(int val) {
    return false;
}
NumberTester* ValueDependantTester::clone() {
    return NULL;
}
