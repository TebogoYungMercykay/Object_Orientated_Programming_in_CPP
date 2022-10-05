
#include "IsEvenOdd.h"

int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd()
{
    IsEvenOdd::numAliveObjects++;
}

IsEvenOdd::~IsEvenOdd()
{
    IsEvenOdd::numAliveObjects--;
}

bool IsEvenOdd::evaluate(int val)
{
    if (val % 2 == 0)
    {
        return true;
    }
    return false;
    
}

int IsEvenOdd::getNumAliveObjects()
{
    return IsEvenOdd::numAliveObjects;
}

NumberTester* IsEvenOdd::clone()
{
    NumberTester* ieo = new IsEvenOdd();
    return ieo;
}