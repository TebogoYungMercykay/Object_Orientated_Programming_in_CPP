#include "FitnessFunction.h"

double FitnessFunction::calculateFitness(Chromosome *chromosome, int numGenes) {
  double count_True = 0;
  if (chromosome != NULL) {
    for (int k_iterator = 0; k_iterator < numGenes; k_iterator++) {
      if (chromosome->getGenes()[k_iterator] == true) {
        count_True += 1;
      }
    }
  }
  double fitness = count_True / numGenes;
  return fitness;
}