#include "IsDivisible.h"
int IsDivisible::numAliveObjects = 0;

IsDivisible::IsDivisible(int Value): ValueDependantTester(Value)
{
    this->numAliveObjects++;
}
IsDivisible::~IsDivisible()
{
    this->numAliveObjects--;
}
bool IsDivisible::evaluate(int val)
{
    if(this->value != 0){
        if(val%this->value==0){return true;}
        else{return false;}
    }
    return false;
}
NumberTester* IsDivisible::clone()
{
    IsDivisible*ptr=new IsDivisible(this->value);
    return ptr;
}
int IsDivisible::getNumAliveObjects()
{
    return numAliveObjects;
}