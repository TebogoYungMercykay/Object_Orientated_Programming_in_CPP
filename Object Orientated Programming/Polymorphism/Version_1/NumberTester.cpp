#include "NumberTester.h"
int NumberTester::numAliveObjects = 0;

NumberTester::NumberTester(){
   NumberTester::numAliveObjects+=1;
}
NumberTester::~NumberTester(){
   NumberTester::numAliveObjects-=1;
}
bool NumberTester::evaluate(int val){
    return false;
}
NumberTester* NumberTester::clone(){
    return NULL;
}
int NumberTester::getNumAliveObjects(){
    return numAliveObjects;
}