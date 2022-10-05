#ifndef TesterInterface_H
#define TesterInterface_H
#include <cstddef>
#include "NumberTester.h"

class TesterInterface
{
    private:
    /*
    *   This is the maximum number of testers that can be held by the interface.
    *   This is also the size of the testers array.
    */
        int maxNumTesters;
    /*
    *   This is the current amount of tests held by the interface.
    */
        int currNumTesters;
    /*
    *   This is a dynamic array of dynamic NumberTester objects.
    *   The array should initially be populated with nulls.
    */
        NumberTester** testers;

    public:
    /*
    *   This is the parameterized constructor for the TesterInterface class and should initialize all appropriate member variables.
    *   If maxNumTests is less than 1 then initialize the array with a size of 0 and initialize maxNumTests with 0.
    */
        TesterInterface(int maxNumTests);
    /*
    *   This is a copy constructor for the TesterInterface class.
    *   This function should make a deep copy of the passed in parameter
    *   If the passed in parameter is NULL initialize all the int variables with a value of 0 and the array with a size of 0.
    *   Hint: remember there is a difference between a null array and an array with a size of 0
    */
        TesterInterface(TesterInterface* other);
    /*
    *   This is a copy constructor for the TesterInterface class.
    *   This function should make a deep copy of the passed in parameter
    */
        TesterInterface(TesterInterface& other);
    /*
    *   This is the destructor for the TesterInterface class.
    *   This function should deallocate all the dynamic memory allocated.
    */
        ~TesterInterface();
    /*
    *   This function should add a deep copy of the passed in NumberTester object to the first index containing null of the testers array and increment the currNumTesters.
    *   The function should return the index that the new object was inserted into.
    *   If the passed in parameter is null the function should return -1 and not alter the array.
    *   If the array is full the function should return -1 and not alter the array.
    *   Hint: use the clone function to make a deep copy of the passed in parameter
    */
        int addTester(NumberTester* tester);
    /*
    *   This function should remove the NumberTester* at the passed in parameter’s index in the array and decrement the currNumTesters variable.
    *   The NumberTester* object should be deleted and set to null.
    *   If the function was able to succesfully remove the NumberTester then the function should return true.
    *   If the passed in parameter’s index in the array is null then the function should return false.
    *   If the passed in parameter’s index is outside the bounds of the array the function should return false.
    */
        bool removeTester(int pos);
    /*
    *   This function should iterate through all the NumberTesters currently in the testers array and pass the passed in parameter to the their evaluate function.
    *   If all the NumberTesters in the array return true then the function should return true else it should return false.
    *   sIf the array is empty the function should return false.
    */
        bool evaluate(int num);
    /*
    *   This function should return an array containing all the indexes of tests that returned an evaluation result of false.
    *   The array should be sized exactly to the number of tests that failed.
    *   If no tests failed or if the array does not contain any NumberTesters the function should return an array of size 0.
    */
        int* failedTests(int num);
    /*
    *   This function should return the amount of NumberTester’s evaulations that failed.
    *   If no tests failed or if the array is empty the function should return 0.
    */
        int numberOfFailedTests(int num);
    /*
    *   This is the overloaded form of the operator[].
    *   This function should return the pointer at passed in index.
    *   If the index is outside of the bounds of the array the function should return null.
    */
        NumberTester* operator[](int pos);
    /*
    *   This is a const function and should return the currNumTesters variable.
    *   In the appropriate h file decalre the function as: int getCurrNumTesters() const.
    */
        int getCurrNumTesters() const;
    /*
    *   This is a const function and should return the maxNumTesters variable.
    *   In the appropriate h file decalre the function as: int getMaxNumTesters() const.
    */
        int getMaxNumTesters() const;
};
#endif