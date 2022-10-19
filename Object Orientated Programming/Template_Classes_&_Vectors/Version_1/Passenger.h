#ifndef Passenger_H
#define Passenger_H
#include <sstream>
#include <string>

class Passenger{
    public:
        Passenger(std::string ID, double weight, double ticketPrice);
        double getWeight() const;
        double getValue() const;
        std::string describe();
    private:
        std::string ID;
        double weight;
        double ticketPrice;
};
#endif