#include "IsGreater.h"
int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int Value): ValueDependantTester(Value){
    IsGreater::numAliveObjects+=1;
}
IsGreater::~IsGreater(){
    IsGreater::numAliveObjects-=1;
}
bool IsGreater::evaluate(int val){
    return val>IsGreater::value;
}
NumberTester* IsGreater::clone(){
    return new IsGreater(IsGreater::value);
}
int IsGreater::getNumAliveObjects(){
    return numAliveObjects;
}