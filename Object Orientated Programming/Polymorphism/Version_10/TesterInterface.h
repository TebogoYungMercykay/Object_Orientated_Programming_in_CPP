// The TesterInterface class

// # directives....
#ifndef TesterInterface_H // include guard
#define TesterInterface_H
#include <cstddef>
#include "NumberTester.h"
// Do not add any more #includes
// TesterInterface.h
class TesterInterface
{
    private:
        int maxNumTesters;
        int currNumTesters;
        NumberTester** testers;
    protected:
    public:
        TesterInterface(int maxNumTests);
        TesterInterface(TesterInterface* other);
        TesterInterface(TesterInterface& other);
        ~TesterInterface();
        int addTester(NumberTester* tester);
        bool removeTester(int pos);
        bool evaluate(int num);
        int* failedTests(int num);
        int numberOfFailedTests(int num);
        NumberTester* operator[](int pos);
        int getCurrNumTesters() const;
        int getMaxNumTesters() const;
};
#endif /* TesterInterface_H */