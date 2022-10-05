#include "IsEvenOdd.h"
int IsEvenOdd::numAliveObjects = 0;

IsEvenOdd::IsEvenOdd(){
    IsEvenOdd::numAliveObjects+=1;
}
IsEvenOdd::~IsEvenOdd(){
    IsEvenOdd::numAliveObjects-=1;
}
bool IsEvenOdd::evaluate(int val){
    return val%2 == 0;
}
NumberTester* IsEvenOdd::clone(){
    return new IsEvenOdd();
}
int IsEvenOdd::getNumAliveObjects(){
    return numAliveObjects;
}