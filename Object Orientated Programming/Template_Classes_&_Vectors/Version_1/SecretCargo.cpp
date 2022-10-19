#include "SecretCargo.h"
using namespace std;

SecretCargo::SecretCargo(double weight){
    this->weight = weight;
}
double SecretCargo::getWeight() const{
    return this->weight;
}