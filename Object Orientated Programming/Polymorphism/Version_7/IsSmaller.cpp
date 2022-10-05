
#include "IsSmaller.h"

int IsSmaller::numAliveObjects = 0;

IsSmaller::IsSmaller(int value) : ValueDependantTester(value)
{
    IsSmaller::numAliveObjects++;
}

IsSmaller::~IsSmaller()
{
    IsSmaller::numAliveObjects--;
}

bool IsSmaller::evaluate(int val)
{
    if (val < ValueDependantTester::value)
    {
        return true;
    }
    return false;
}

int IsSmaller::getNumAliveObjects()
{
    return IsSmaller::numAliveObjects;
}

NumberTester* IsSmaller::clone()
{
    NumberTester* ism = new IsSmaller(value);
    return ism;
}