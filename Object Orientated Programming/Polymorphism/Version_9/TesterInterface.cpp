#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests)
{
    if(maxNumTests >= 1)
    {
        this->maxNumTesters = maxNumTests;
        this->currNumTesters = 0;
        this->testers =  new NumberTester*[this->maxNumTesters];
        for(int i = 0; i < this->maxNumTesters; i++)
            this->testers[i] = NULL;
    }
    else
    {
        this->maxNumTesters = 0;
        this->currNumTesters = 0;
        this->testers =  new NumberTester*[this->maxNumTesters];
    }
}
TesterInterface::TesterInterface(TesterInterface& other)
{
    this->maxNumTesters = other.maxNumTesters;
    this->testers = new NumberTester*[other.maxNumTesters];
    this->currNumTesters = other.currNumTesters;
    for(int i=0; i<this->maxNumTesters; i++)
    {
        if(other.testers[i]!=NULL)
        {
            this->testers[i] = other.testers[i]->clone();
        }
        else
        {
            this->testers[i] = NULL;
        }
    }
}
TesterInterface::TesterInterface(TesterInterface* other)
{
    if(other)
    {
        this->maxNumTesters = other->maxNumTesters;
        this->testers = new NumberTester*[this->maxNumTesters];
        this->currNumTesters = other->currNumTesters;
        for(int j = 0; j < this->maxNumTesters; j++)
        {
            if((other->testers[j]==NULL)==true)
            {
                this->testers[j] = NULL;
            }
            else
            {
                this->testers[j] = other->testers[j]->clone();
            }

        }
    }
    else
    {
        this->maxNumTesters = 0;
        this->testers =  new NumberTester*[this->maxNumTesters];
        this->currNumTesters = 0;
    }
}
int TesterInterface::getCurrNumTesters() const{
    return this->currNumTesters;
}
int TesterInterface::getMaxNumTesters() const{
    return this->maxNumTesters;
}
TesterInterface::~TesterInterface()
{
    for(int i=0; i<this->maxNumTesters; i++)
    {
        if(this->testers[i]!=NULL)
        {
            delete this->testers[i];
            this->testers[i] = NULL;
        }
    }
    delete [] this->testers;
    this->testers = NULL;
    this->currNumTesters = 0;
    this->maxNumTesters = 0;
}
int TesterInterface::addTester(NumberTester* tester)
{
    if((tester != NULL) && (this->currNumTesters < this->maxNumTesters))
    {
        for(int i = 0;i<this->maxNumTesters; i++)
        {
            if(this->testers[i] == NULL)
            {
                this->testers[i] = tester->clone();
                this->currNumTesters++;
                return i;
            }
        }
        return 0;
    }
    return -1;
}
bool TesterInterface::removeTester(int pos)
{
    if(pos>=0 && pos<this->maxNumTesters && this->testers[pos]!=NULL)
    {
        delete this->testers[pos];
        this->testers[pos] = NULL;
        this->currNumTesters--;
        return true;
    }
    return false;
}
bool TesterInterface::evaluate(int num)
{
    if(this->currNumTesters > 0)
    {
        for(int i=0; i<this->maxNumTesters; i++)
        {
            if(this->testers[i]!=NULL)
            {
                if((this->testers[i]->evaluate(num))==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}
int* TesterInterface::failedTests(int num)
{
    int temp = 0;
    int* myArray = new int[numberOfFailedTests(num)];
    for(int i=0; i<this->maxNumTesters; i++)
    {
        if(this->testers[i]!=NULL)
        {
            if(this->testers[i]->evaluate(num) == false)
            {
                myArray[temp]=i;
                temp++;
            }
        }
    }
    return myArray;
}
int TesterInterface::numberOfFailedTests(int num)
{
    if(currNumTesters > 0)
    {
        int temp = 0;
        for(int i=0; i<this->maxNumTesters; i+=1)
        {
            if(this->testers[i] != NULL)
            {
                if(this->testers[i]->evaluate(num) == false){temp++;}
            }
        }
        return temp;
    }
    return 0;
}
NumberTester* TesterInterface::operator[](int pos)
{
    if(pos>=0 && pos<maxNumTesters)
    {
        return testers[pos];
    }
    return NULL;
}