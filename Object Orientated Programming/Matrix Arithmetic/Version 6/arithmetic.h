//
// Created by ditli on 9/21/2022.
//

#ifndef ASSIGNMENT2TEST_ARITHMETIC_H
#define ASSIGNMENT2TEST_ARITHMETIC_H

#include <iostream>

using namespace std;

class Arithmetic {

public:
    Arithmetic();

    Arithmetic(const Arithmetic &rhs);

    virtual ~Arithmetic();

    virtual void print() = 0; //pure virtual

    virtual void readFile(istream &infile) = 0; //pure virtual

};

#endif //ASSIGNMENT2TEST_ARITHMETIC_H

