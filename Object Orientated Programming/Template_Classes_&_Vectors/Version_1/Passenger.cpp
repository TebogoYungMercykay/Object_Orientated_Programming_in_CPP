#include "Passenger.h"
using namespace std;

Passenger::Passenger(string ID, double weight, double ticketPrice){
    this->ID = ID;;
    this->weight = weight;
    this->ticketPrice = ticketPrice;
}
double Passenger::getWeight() const{
    return this->weight;
}
double Passenger::getValue() const{
    return this->ticketPrice;
}
string Passenger::describe(){
    stringstream ss;
    string Ticket = "";
    ss << this->ticketPrice;
    ss >> Ticket;
    ss.clear();
    string Weight = "";
    ss << this->weight;
    ss >> Weight;
    return ID+" <"+Ticket+"> ("+Weight+")";
}