//The Passenger implementation file
#include "Passenger.h"
using namespace std;

Passenger::Passenger(string ID, double weight, double ticketPrice){
    Passenger::ID = ID;;
    Passenger::weight = weight;
    Passenger::ticketPrice = ticketPrice;
}
double Passenger::getWeight() const{
    return Passenger::weight;
}
double Passenger::getValue() const{
    return Passenger::ticketPrice;
}
string Passenger::describe(){
    stringstream ss;
    string Ticket = "";
    ss << Passenger::ticketPrice;
    ss >> Ticket;
    ss.clear();
    string Weight = "";
    ss << Passenger::weight;
    ss >> Weight;
    return ID+" <"+Ticket+"> ("+Weight+")";
}