#include "IsDivisible.h"

int IsDivisible::numAliveObjects = 0;


IsDivisible::IsDivisible(int value) : ValueDependantTester(value)
{
    IsDivisible::numAliveObjects++;
}

IsDivisible::~IsDivisible()
{
    IsDivisible::numAliveObjects--;
}

bool IsDivisible::evaluate(int val)
{
    if (ValueDependantTester::value != 0 && val % ValueDependantTester::value == 0)
    {
        return true;
    }
    return false;
}

int IsDivisible::getNumAliveObjects()
{
    return IsDivisible::numAliveObjects;
}

NumberTester* IsDivisible::clone()
{
    NumberTester* isd = new IsDivisible(value);
    return isd;
}