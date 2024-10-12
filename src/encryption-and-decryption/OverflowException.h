#ifndef OVERFLOWEXCEPTION_H
#define OVERFLOWEXCEPTION_H
#include "BabushkaException.h"

class OverflowException : public BabushkaException {
public:
  virtual void printMessage();
};
#endif