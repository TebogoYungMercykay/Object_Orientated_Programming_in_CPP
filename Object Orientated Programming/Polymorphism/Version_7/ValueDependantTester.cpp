
#include "ValueDependantTester.h"

int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val)
{
    this->value = val;
    ValueDependantTester::numAliveObjects++;
}

ValueDependantTester::~ValueDependantTester()
{
    ValueDependantTester::numAliveObjects--;
}

int ValueDependantTester::getNumAliveObjects()
{
    return ValueDependantTester::numAliveObjects;
}