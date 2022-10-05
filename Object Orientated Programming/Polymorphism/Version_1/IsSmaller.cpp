#include "IsSmaller.h"
int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int Value): ValueDependantTester(Value){
    IsSmaller::numAliveObjects+=1;
}
IsSmaller::~IsSmaller(){
    IsSmaller::numAliveObjects-=1;
}
bool IsSmaller::evaluate(int val){
    return val<IsSmaller::value;
}
NumberTester* IsSmaller::clone(){
    return new IsSmaller(IsSmaller::value);
}
int IsSmaller::getNumAliveObjects(){
    return numAliveObjects;
}