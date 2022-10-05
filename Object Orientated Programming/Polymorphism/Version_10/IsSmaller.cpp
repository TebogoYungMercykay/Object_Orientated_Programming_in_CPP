#include "IsSmaller.h"

int IsSmaller::numAliveObjects = 0 ;

IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{
    numAliveObjects++;

}

IsSmaller::~IsSmaller()
{
    numAliveObjects--;
}

bool IsSmaller::evaluate(int val)
{
    if(val<value)
    {
        return true ;
    }
    else 
    {
        return false ;
    }
}

NumberTester * IsSmaller::clone()
{
    IsSmaller * valptr = new IsSmaller(value);
    return valptr ;
}

int IsSmaller::getNumAliveObjects()
{
    return numAliveObjects ;
}