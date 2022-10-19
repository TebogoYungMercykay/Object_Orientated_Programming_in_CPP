#ifndef Plane_H
#define Plane_H
#include <vector>
#include <string>
#include "Exceptions.h"
#include "SecretCargo.h"

template <class T>
class Plane
{
    private:
        double maxWeight;
        std::vector<T*> cargo;
    public:
        Plane(double weight);
        ~Plane();
        void add(T* temp);
        void remove(T* temp);
        double calculateValue();
        std::string getDescription();
};
#include "Plane.cpp"
#endif