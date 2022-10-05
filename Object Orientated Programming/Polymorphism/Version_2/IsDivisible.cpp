#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int Value): ValueDependantTester(Value){
    this->numAliveObjects++;
}
IsDivisible::~IsDivisible(){
    this->numAliveObjects--;
}
bool IsDivisible::evaluate(int val){
    return ((val%this->value)==0);
}
NumberTester* IsDivisible::clone(){
    return new IsDivisible(this->value);
}
int IsDivisible::getNumAliveObjects(){
    return this->numAliveObjects;
}