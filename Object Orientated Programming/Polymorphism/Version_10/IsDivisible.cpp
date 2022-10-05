#include "IsDivisible.h"

int IsDivisible::numAliveObjects = 0 ;

IsDivisible::IsDivisible(int value) : ValueDependantTester (value)
{
    numAliveObjects++ ;
}

IsDivisible::~IsDivisible()
{
    numAliveObjects--;
}

bool IsDivisible::evaluate(int val)
{
    if(val%value == 0)
    {
        return true ;
    }
    else
    {
        return false ;
    }
}

NumberTester * IsDivisible::clone()
{
    IsDivisible * valPtr ;
    valPtr = new IsDivisible(value);
    return valPtr ;
}

int IsDivisible::getNumAliveObjects()
{
    return numAliveObjects ;
}
