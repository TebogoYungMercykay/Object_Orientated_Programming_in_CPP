#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int Value): ValueDependantTester(Value){
    this->numAliveObjects+=1;
}
IsSmaller::~IsSmaller(){
    this->numAliveObjects-=1;
}
bool IsSmaller::evaluate(int val){
    bool Temp = val<this->value;
    return Temp;
}
NumberTester* IsSmaller::clone(){
    IsSmaller* Temp = new IsSmaller(this->value);
    return Temp;
}
int IsSmaller::getNumAliveObjects(){
    return numAliveObjects;
}