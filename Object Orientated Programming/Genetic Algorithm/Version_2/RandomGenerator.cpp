#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed){
    srand(seed);
    this->seed = seed;
}
bool RandomGenerator::randomBool(){
    if(rand()%2 == 0){
        return false;
    }
    return true;
}