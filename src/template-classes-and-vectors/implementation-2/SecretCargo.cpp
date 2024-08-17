// The SecretCargo implementation file
#include "SecretCargo.h"
using namespace std;

SecretCargo::SecretCargo(double weight) { SecretCargo::weight = weight; }
double SecretCargo::getWeight() const { return SecretCargo::weight; }