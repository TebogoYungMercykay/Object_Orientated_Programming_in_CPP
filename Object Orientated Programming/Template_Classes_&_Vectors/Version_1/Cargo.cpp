#include "Cargo.h"
using namespace std;

Cargo::Cargo(double weight, double value){
    this->weight = weight;
    this->value = this->weight*value;
}
double Cargo::getWeight() const{
    return this->weight;
}
double Cargo::getValue() const{
    return this->value;
}
string Cargo::describe(){
    stringstream ss;
    string Value = "";
    ss << this->value;
    ss >> Value;
    ss.clear();
    string Weight = "";
    ss << this->weight;
    ss >> Weight;
    return "Generic cargo <"+Value+"> ("+Weight+")";
}