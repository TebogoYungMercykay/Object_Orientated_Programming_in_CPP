#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int value): ValueDependantTester(value) {
    IsSmaller::numAliveObjects++;
    // ValueDependantTester::value= IsSmaller::value;
}
IsSmaller::~IsSmaller() {
//    numAliveObjects = 0;
   numAliveObjects--;
}
bool IsSmaller::evaluate(int val) {
    if( val < ValueDependantTester::value )
    {
        return true;
    }
    else
    {
        return false;
    }
}
NumberTester* IsSmaller::clone() {
    IsSmaller* smaller;
    smaller= new IsSmaller(this->value);
    return smaller;
}
int IsSmaller::getNumAliveObjects() {
    return numAliveObjects;
}
