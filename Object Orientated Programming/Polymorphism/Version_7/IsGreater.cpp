
#include "IsGreater.h"

int IsGreater::numAliveObjects = 0;

IsGreater::IsGreater(int value) : ValueDependantTester(value)
{
    IsGreater::numAliveObjects++;
}

IsGreater::~IsGreater()
{
    IsGreater::numAliveObjects--;
}

bool IsGreater::evaluate(int val)
{
    if (val > ValueDependantTester::value)
    {
        return true;
    }
    return false;
    
}

int IsGreater::getNumAliveObjects()
{
    return IsGreater::numAliveObjects;
}

NumberTester* IsGreater::clone()
{
    NumberTester* ig = new IsGreater(value);
    return ig;
}