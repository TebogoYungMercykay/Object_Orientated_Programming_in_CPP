#ifndef DISPLACEMENTEXCEPTION_H
#define DISPLACEMENTEXCEPTION_H
#include "BabushkaException.h"

class DisplacementException : public BabushkaException {
public:
  virtual void printMessage();
};
#endif