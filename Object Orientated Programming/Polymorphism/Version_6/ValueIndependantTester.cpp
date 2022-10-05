#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester() {
    ValueIndependantTester::numAliveObjects++;
}
ValueIndependantTester::~ValueIndependantTester() {
    ValueIndependantTester::numAliveObjects--;
}
int ValueIndependantTester::getNumAliveObjects() {
    return numAliveObjects;
}

bool ValueIndependantTester::evaluate(int val) {
    return false;
}
NumberTester* ValueIndependantTester::clone(){
    return NULL;
}


