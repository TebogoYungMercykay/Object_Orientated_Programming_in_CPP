#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val){
    this->value = val;
    this->numAliveObjects+=1;
}
ValueDependantTester::~ValueDependantTester(){
    this->numAliveObjects-=1;
}
bool ValueDependantTester::evaluate(int val){
    // This is a pure virtual function.
    return true;
}
NumberTester* ValueDependantTester::clone(){
    // This is a pure virtual function.
    return NULL;
}
int ValueDependantTester::getNumAliveObjects(){
    return numAliveObjects;
}