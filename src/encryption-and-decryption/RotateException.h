#ifndef RotateException_H
#define RotateException_H
#include "BabushkaException.h"

class RotateException : public BabushkaException {
public:
  void printMessage();
};
#endif