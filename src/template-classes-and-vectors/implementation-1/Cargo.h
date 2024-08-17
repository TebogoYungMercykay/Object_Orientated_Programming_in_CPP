#ifndef Cargo_H
#define Cargo_H
#include <sstream>
#include <string>

class Cargo {
public:
  Cargo(double weight, double value);
  double getWeight() const;
  double getValue() const;
  std::string describe();

private:
  double weight;
  double value;
};
#endif