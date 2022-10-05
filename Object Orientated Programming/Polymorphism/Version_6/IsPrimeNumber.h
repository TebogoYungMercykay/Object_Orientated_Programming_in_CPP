#ifndef ISPRIMENUMBER_H
#define ISPRIMENUMBER_H

#include<cstddef>
#include "ValueIndependantTester.h"


class IsPrimeNumber: public ValueIndependantTester
{
private:
    static int numAliveObjects;
public:
    IsPrimeNumber();
    ~IsPrimeNumber();
    bool evaluate(int val);
    NumberTester* clone();
    static int getNumAliveObjects();
};
#endif