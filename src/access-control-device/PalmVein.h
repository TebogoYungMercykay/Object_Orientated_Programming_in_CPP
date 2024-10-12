#ifndef PALMVEIN_H
#define PALMVEIN_H

#include "ContactlessDevice.h"
#include <iostream>
/*#include "AccessDevice.h"*/

using namespace std;

class PalmVein : public ContactlessDevice {
protected:
  char hashChar(char);

public:
  PalmVein(const string &, const int &);
  ~PalmVein();
  string registerStudent(const string &);
  string authenticateStudent(const string &);
};

#endif