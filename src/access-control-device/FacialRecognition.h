#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H

#include "ContactlessDevice.h"
#include <iostream>

using namespace std;

class FacialRecognition : public ContactlessDevice {
private:
  int stepSize;
  int *original;

public:
  FacialRecognition(const string &, const int &, int stepSize);
  ~FacialRecognition();
  void setStepSize(int);
  string generateHash(string);
  string registerStudent(const string &);
  string authenticateStudent(const string &);

protected:
  char hashChar(char);
};

#endif