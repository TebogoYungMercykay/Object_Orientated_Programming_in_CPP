#ifndef Controller_H
#define Controller_H
#include "Cargo.h"
#include "Passenger.h"
#include "Plane.h"

template <class T> class Controller {
private:
  Plane<T> *plane;

public:
  Controller(Plane<T> *plane);
  std::string loadOnPlane(T *temp);
  double getTotalValue();
  std::string getPlaneContents();
};
#include "Controller.cpp"
#endif