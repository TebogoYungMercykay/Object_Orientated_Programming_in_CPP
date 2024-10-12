#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>

using namespace std;

class Exception {
protected:
  string error;

public:
  Exception(const string &e) { error = e; }
  string getError() { return error; }
};

#endif