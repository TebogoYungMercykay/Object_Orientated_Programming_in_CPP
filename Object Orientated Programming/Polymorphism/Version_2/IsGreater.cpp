#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int Value): ValueDependantTester(Value){
    this->numAliveObjects++;
}
IsGreater::~IsGreater(){
    this->numAliveObjects--;
}
bool IsGreater::evaluate(int val){
    return (val > this->value);
}
NumberTester* IsGreater::clone(){
    return new IsGreater(this->value);
}
int IsGreater::getNumAliveObjects(){
    return numAliveObjects;
}