#include "dog.h"

Dog::Dog(){
    Dog::Name = "";
    Dog::Age = 0;
    Dog::owner = new Citizen();
}
Dog::~Dog(){
    owner = NULL;
    delete owner;
}
const string& Dog::getName() const{
    return Dog::Name;
}
void Dog::setName(const string &name){
    Dog::Name = name;
}
int Dog::getAge() const{
    return Dog::Age;
}
void Dog::setAge(int age){
    Dog::Age = age;
}
Citizen* Dog::getCitizen(){
    return Dog::owner;
}
void Dog::setCitizen(Citizen* citizen){
    Citizen* temp = new Citizen();
    temp->setAddress(citizen->getAddress());
    temp->setName(citizen->getName());
    Dog::owner = temp;
}