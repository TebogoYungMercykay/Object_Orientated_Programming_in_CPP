//The Cargo implementation file
#include "Cargo.h"
using namespace std;

Cargo::Cargo(double weight, double value){
    Cargo::value = value * weight;
    Cargo::weight = weight;
}
double Cargo::getWeight() const{
    return Cargo::weight;
}
double Cargo::getValue() const{
    return Cargo::value;
}
string Cargo::describe(){
    std::stringstream ss;
    std::string Value = "";
    ss << Cargo::value;
    ss >> Value;
    ss.clear();
    std::string Weight = "";
    ss << Cargo::weight;
    ss >> Weight;
    return "Generic cargo <"+Value+"> ("+Weight+")";
}