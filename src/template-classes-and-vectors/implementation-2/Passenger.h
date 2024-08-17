#ifndef Passenger_H
#define Passenger_H
#include <sstream>
#include <string>

class Passenger {
private:
  std::string ID;
  double weight;
  double ticketPrice;

public:
  Passenger(std::string ID, double weight, double ticketPrice);
  double getWeight() const;
  double getValue() const;
  std::string describe();
};
#endif