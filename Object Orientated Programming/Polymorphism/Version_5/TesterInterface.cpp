#include "TesterInterface.h"
/*
*   This is the parameterized constructor for the TesterInterface class and should initialize all appropriate member variables.
*   If maxNumTests is less than 1 then initialize the array with a size of 0 and initialize maxNumTests with 0.
*/
    TesterInterface::TesterInterface(int maxNumTests)
    {
        this->currNumTesters = 0;
        if (maxNumTests < 1)
        {
            this->maxNumTesters = 0;
            testers = new NumberTester*[0];
        }
        else
        {
            this->maxNumTesters = maxNumTests;
            testers = new NumberTester*[maxNumTests];
        }
    }
/*
*   This is a copy constructor for the TesterInterface class.
*   This function should make a deep copy of the passed in parameter
*   If the passed in parameter is NULL initialize all the int variables with a value of 0 and the array with a size of 0.
*   Hint: remember there is a difference between a null array and an array with a size of 0
*/
    TesterInterface::TesterInterface(TesterInterface* other)
    {
        if (other == NULL)
        {
            this->currNumTesters = 0;
            this->maxNumTesters = 0;
            testers = new NumberTester*[0];
        }
        else
        {
            this->currNumTesters = other->currNumTesters;
            this->maxNumTesters = other->maxNumTesters;
            testers = new NumberTester*[this->maxNumTesters];
            for (int i = 0; i < this->maxNumTesters; i++)
            {
                if (other->testers[i] != NULL)
                    testers[i] = other->testers[i]->clone();
            }
        }
    }
/*
*   This is a copy constructor for the TesterInterface class.
*   This function should make a deep copy of the passed in parameter
*/
    TesterInterface::TesterInterface(TesterInterface& other)
    {
        this->currNumTesters = other.currNumTesters;
        this->maxNumTesters = other.maxNumTesters;
        testers = new NumberTester*[this->maxNumTesters];
        for (int i = 0; i < this->maxNumTesters; i++)
        {
            if (other.testers[i] != NULL)
                testers[i] = other.testers[i]->clone();
        }
    }
/*
*   This is the destructor for the TesterInterface class.
*   This function should deallocate all the dynamic memory allocated.
*/
    TesterInterface::~TesterInterface()
    {
        for (int i = 0; i < this->currNumTesters; i++)
        {
            delete testers[i];
        }
        delete [] testers;
    }
/*
*   This function should add a deep copy of the passed in NumberTester object to the first index containing null of the testers array and increment the currNumTesters.
*   The function should return the index that the new object was inserted into.
*   If the passed in parameter is null the function should return -1 and not alter the array.
*   If the array is full the function should return -1 and not alter the array.
*   Hint: use the clone function to make a deep copy of the passed in parameter
*/
    int TesterInterface::addTester(NumberTester* tester)
    {
        if (tester == NULL || this->currNumTesters == this->maxNumTesters)
            return -1;
        this->currNumTesters++;
        int i = 0;
        while (i < this->maxNumTesters)
        {
            if (this->testers[i] == NULL)
            {
                this->testers[i] = tester->clone();
                break;
            }
            i++;
        }
        return i;
    }
/*
*   This function should remove the NumberTester* at the passed in parameter’s index in the array and decrement the currNumTesters variable.
*   The NumberTester* object should be deleted and set to null.
*   If the function was able to succesfully remove the NumberTester then the function should return true.
*   If the passed in parameter’s index in the array is null then the function should return false.
*   If the passed in parameter’s index is outside the bounds of the array the function should return false.
*/
    bool TesterInterface::removeTester(int pos)
    {
        if (pos < 0 || pos >= this->maxNumTesters || this->testers[pos] == NULL)
            return false;
        delete testers[pos];
        testers[pos] = NULL;
        this->currNumTesters--;
        return true;
    }
/*
*   This function should iterate through all the NumberTesters currently in the testers array and pass the passed in parameter to the their evaluate function.
*   If all the NumberTesters in the array return true then the function should return true else it should return false.
*   If the array is empty the function should return false.
*/
    bool TesterInterface::evaluate(int num)
    {
        if (this->currNumTesters == 0) return false;
        for (int i = 0; i < this->maxNumTesters; i++)
        {
            if (this->testers[i] != NULL && !this->testers[i]->evaluate(num))
                return false;
        }
        return true;
    }
/*
*   This function should return an array containing all the indexes of tests that returned an evaluation result of false.
*   The array should be sized exactly to the number of tests that failed.
*   If no tests failed or if the array does not contain any NumberTesters the function should return an array of size 0.
*/
    int* TesterInterface::failedTests(int num)
    {
        int size = numberOfFailedTests(num);
        int* arr = new int[size];
        size = 0;
        for (int i = 0; i < this->maxNumTesters; i++)
        {
            if (this->testers[i] != NULL && !this->testers[i]->evaluate(num))
            {
                arr[size++] = i;
            }
        }
        return arr;
    }
/*
*   This function should return the amount of NumberTester’s evaulations that failed.
*   If no tests failed or if the array is empty the function should return 0.
*/
    int TesterInterface::numberOfFailedTests(int num)
    {
        int numberOfFail = 0;
        for (int i = 0; i < this->maxNumTesters; i++)
        {
            if (this->testers[i] != NULL && !this->testers[i]->evaluate(num))
                numberOfFail++;
        }
        return numberOfFail;
    }
/*
*   This is the overloaded form of the operator[].
*   This function should return the pointer at passed in index.
*   If the index is outside of the bounds of the array the function should return null.
*/
    NumberTester* TesterInterface::operator[](int pos)
    {
        if (pos < 0 || pos >= this->maxNumTesters)
            return NULL;
        return this->testers[pos];
    }
/*
*   This is a const function and should return the currNumTesters variable.
*   In the appropriate h file decalre the function as: int getCurrNumTesters() const.
*/
    int TesterInterface::getCurrNumTesters() const
    {
        return this->currNumTesters;
    }
/*
*   This is a const function and should return the maxNumTesters variable.
*   In the appropriate h file decalre the function as: int getMaxNumTesters() const.
*/
    int TesterInterface::getMaxNumTesters() const
    {
        return this->maxNumTesters;
    }