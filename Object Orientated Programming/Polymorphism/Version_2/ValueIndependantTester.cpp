#include "ValueIndependantTester.h"
int ValueIndependantTester::numAliveObjects = 0;

ValueIndependantTester::ValueIndependantTester(){
    this->numAliveObjects++;
}
ValueIndependantTester::~ValueIndependantTester(){
    this->numAliveObjects--;
}
bool ValueIndependantTester::evaluate(int val){
    // This is a pure virtual function.
    return true;
}
NumberTester* ValueIndependantTester::clone(){
    // This is a pure virtual function.
    return NULL;
}
int ValueIndependantTester::getNumAliveObjects(){
    return numAliveObjects;
}