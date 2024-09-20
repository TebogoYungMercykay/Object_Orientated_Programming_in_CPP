#include "Babushka.h"

Babushka::Babushka(const unsigned char *id) { this->id = id; }
Babushka::~Babushka() { delete this->id; }
const int Babushka::getIdLength() { return this->ID_LENGTH; }
const unsigned char *Babushka::getId() { return this->id; }
void Babushka::encrypt(unsigned char *id, int size) {}
void Babushka::decrypt(unsigned char *id, int size) {}