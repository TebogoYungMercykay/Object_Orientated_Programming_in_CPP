#include "IsPrimeNumber.h"

int IsPrimeNumber::numAliveObjects = 0 ;

IsPrimeNumber::IsPrimeNumber()
{
    numAliveObjects++;
}

IsPrimeNumber::~IsPrimeNumber()
{
    numAliveObjects--;
}

bool IsPrimeNumber::evaluate(int val)
{
    if(val == 0 || val == 1 )
    {
        return false ;
    }
    else 
    {
        for(int x = 2 ; x < val ; x++)
        {
            if(val%x == 0)
            {
                return false ;
            }
        }
    }
    
    return true ;
}

NumberTester * IsPrimeNumber::clone()
{
    IsPrimeNumber * val = new IsPrimeNumber();
    return val ;
}

int IsPrimeNumber::getNumAliveObjects()
{
    return numAliveObjects ;
}