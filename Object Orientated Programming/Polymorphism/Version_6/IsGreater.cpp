#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value){
    IsGreater::numAliveObjects++;
//    ValueDependantTester::value = IsGreater::value;
}
IsGreater::~IsGreater() {
    IsGreater::numAliveObjects--;
}
bool IsGreater::evaluate(int val){
    if( val > ValueDependantTester::value )
    {
        return true;
    }
    else
    {
        return false;
    }
}
NumberTester* IsGreater::clone() {
    IsGreater* greater;
    greater = new IsGreater(this->value);
    return greater;
}
int IsGreater::getNumAliveObjects() {
    return numAliveObjects;
}