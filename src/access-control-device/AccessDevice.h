#ifndef ACCESSDEVICE_H
#define ACCESSDEVICE_H

#include <iostream>

#include "Exception.h"

class AccessDevice {
public:
  virtual string registerStudent(const string &) = 0;
  virtual string authenticateStudent(const string &) = 0;
};

#endif