#ifndef Controller_H
#define Controller_H
#include "Plane.h"
#include "Passenger.h"
#include "Cargo.h"

template <class T> 
class Controller
{
    private:
        Plane<T>* plane;
    public:
        Controller(Plane<T>* plane);
        std::string loadOnPlane(T* temp);
        double getTotalValue();
        std::string getPlaneContents();
};
#include "Controller.cpp"
#endif