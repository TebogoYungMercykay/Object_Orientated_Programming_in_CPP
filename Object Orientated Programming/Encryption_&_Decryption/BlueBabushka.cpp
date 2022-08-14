#include "BlueBabushka.h"

BlueBabushka::BlueBabushka(const unsigned char* id, unsigned int amount) : Babushka(id){
    this->amount = amount;
}
void BlueBabushka::encrypt(unsigned char* data, int size){
}
void BlueBabushka::decrypt(unsigned char* data, int size){
}