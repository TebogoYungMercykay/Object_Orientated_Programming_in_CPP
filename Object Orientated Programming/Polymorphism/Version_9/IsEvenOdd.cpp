#include "IsEvenOdd.h"
int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd()
{
    this->numAliveObjects++;
}
IsEvenOdd::~IsEvenOdd()
{
    this->numAliveObjects--;
}
bool IsEvenOdd::evaluate(int val)
{
    if(val%2==0)
    {return true;}
    return false;
}
NumberTester* IsEvenOdd::clone()
{
    IsEvenOdd*ptr=new IsEvenOdd();
    // ptr=NULL;
    return ptr;
}
int IsEvenOdd::getNumAliveObjects()
{
    return numAliveObjects;
}