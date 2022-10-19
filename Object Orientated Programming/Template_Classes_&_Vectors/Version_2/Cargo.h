#ifndef Cargo_H
#define Cargo_H
#include <sstream>
#include <string>

class Cargo
{
    private:
        double weight;
        double value;
    public:
        Cargo(double weight, double value);
        double getWeight() const;
        double getValue() const;
        std::string describe();
};
#endif