#include "citizen.h"

Citizen::Citizen() {
  Citizen::Name = "";
  Citizen::Address = "";
}
Citizen::~Citizen() {}
const string &Citizen::getName() const { return Citizen::Name; }
void Citizen::setName(const string &name) { Citizen::Name = name; }
const string &Citizen::getAddress() const { return Citizen::Address; }
void Citizen::setAddress(const string &address) { Citizen::Address = address; }