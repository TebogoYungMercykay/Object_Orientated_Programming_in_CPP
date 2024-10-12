#include "RandomGenerator.h"

RandomGenerator::RandomGenerator(int seed) {
  RandomGenerator::seed = seed;
  srand(seed);
}
bool RandomGenerator::randomBool() {
  int Random = rand();
  if (Random % 2 != 0) {
    return true;
  }
  return false;
}