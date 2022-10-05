#include "IsEvenOdd.h"

int IsEvenOdd::numAliveObjects = 0 ;

IsEvenOdd::IsEvenOdd()
{
    numAliveObjects++;
}

IsEvenOdd::~IsEvenOdd()
{
    numAliveObjects--;
}

bool IsEvenOdd::evaluate(int val)
{
    if(val%2 == 0 )
    {
        return true ;
    }
    else 
    {
        return false ;
    }
    
}

NumberTester * IsEvenOdd::clone()
{
    IsEvenOdd * val = new IsEvenOdd();
    return val ;
}

int IsEvenOdd::getNumAliveObjects()
{
    return numAliveObjects ;
}