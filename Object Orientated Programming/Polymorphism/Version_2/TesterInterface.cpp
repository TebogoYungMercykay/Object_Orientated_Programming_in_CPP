#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests){
    if(maxNumTests<1){
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
        this->testers = new NumberTester*[this->maxNumTesters];
    }else{
        this->maxNumTesters = maxNumTests;
        this->currNumTesters = 0;
        this->testers = new NumberTester*[this->maxNumTesters];
        for(int i=0; i<this->maxNumTesters; i++){
            this->testers[i] = NULL;
        }
    }
}
TesterInterface::TesterInterface(TesterInterface& other){
    this->currNumTesters = other.currNumTesters;
    this->maxNumTesters = other.maxNumTesters;
    this->testers = new NumberTester*[this->maxNumTesters];
    for(int i=0; i<this->maxNumTesters; i++){
        if(other.testers[i]==NULL){
            this->testers[i] = NULL;
        }else{
            this->testers[i] = other.testers[i]->clone();
        }
    }
}
TesterInterface::TesterInterface(TesterInterface* other){
    if(other == NULL){
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
        this->testers = new NumberTester*[this->maxNumTesters];
    }else{
        this->currNumTesters = other->currNumTesters;
        this->maxNumTesters = other->maxNumTesters;
        this->testers = new NumberTester*[this->maxNumTesters];
        for(int i=0; i<this->maxNumTesters; i++){
            if(other->testers[i]==NULL){
                this->testers[i] = NULL;
            }else{
                this->testers[i] = other->testers[i]->clone();
            }
        }
    }
}
TesterInterface::~TesterInterface(){
    for(int i=0; i<this->maxNumTesters; i++){
        if(!(this->testers[i]==NULL)){
            delete this->testers[i];
            this->testers[i] = NULL;
        }
    }
    delete [] testers;
    testers = NULL;
    this->maxNumTesters = 0;
    this->currNumTesters = 0;
}
int TesterInterface::addTester(NumberTester* tester){
    if(tester == NULL || this->currNumTesters == this->maxNumTesters) return -1;
    int index = 0;
    for(;index<this->maxNumTesters; index++){
        if(this->testers[index]==NULL){
            this->testers[index] = tester->clone();
            currNumTesters++;
            break;
        }
    }
    return index;
}
bool TesterInterface::removeTester(int pos){
    if(testers[pos] == NULL || pos<0 || pos>=maxNumTesters){
        return false;
    }else{
        delete testers[pos];
        testers[pos] = NULL;
        currNumTesters=currNumTesters-1;
    }
    return true;
}
bool TesterInterface::evaluate(int num){
    if(currNumTesters == 0){
        return false;
    }
    for(int i=0; i<this->maxNumTesters; i++){
        if(this->testers[i]){
            bool temp = this->testers[i]->evaluate(num);
            if(!temp){
                return false;
            }
        }
    }
    return true;
}
int* TesterInterface::failedTests(int num){
    int temp = numberOfFailedTests(num);
    int* myArray = new int[temp];
    temp = 0;
    for(int i=0; i<this->maxNumTesters; i++){
        if(this->testers[i]){
            if(this->testers[i]->evaluate(num)==false) myArray[temp++]=i;
        }
    }
    return myArray;
}
int TesterInterface::numberOfFailedTests(int num){
    int temp = 0;
    for(int i=0; i<this->maxNumTesters; i++){
        if(this->testers[i]){
            if(this->testers[i]->evaluate(num)==false) temp++;
        }
    }
    return temp;
}
NumberTester* TesterInterface::operator[](int pos){
    if(pos<0 || pos>=maxNumTesters){
        return NULL;
    }
    else{
        return testers[pos];
    }
}
int TesterInterface::getCurrNumTesters() const{
    return this->currNumTesters;
}
int TesterInterface::getMaxNumTesters() const{
    return this->maxNumTesters;
}