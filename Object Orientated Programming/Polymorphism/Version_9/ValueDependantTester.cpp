#include "ValueDependantTester.h"
int ValueDependantTester::numAliveObjects = 0;

ValueDependantTester::ValueDependantTester(int val)
{
    this->value = val;
    this->numAliveObjects++;
}
ValueDependantTester::~ValueDependantTester()
{
    this->numAliveObjects--;
}
bool ValueDependantTester::evaluate(int val)
{
    return false;
}
NumberTester* ValueDependantTester::clone()
{
    return NULL;
}
int ValueDependantTester::getNumAliveObjects()
{
    return numAliveObjects;
}