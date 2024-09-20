#include "FitnessFunction.h"

double FitnessFunction::calculateFitness(Chromosome *chromosome, int numGenes) {
  double Fit = 0;
  int Fitness2 = 0;
  if (!chromosome)
    Fit = 0.0;
  else {
    double Fitness2 = 0;
    int i = 0;
    while (i < numGenes) {
      if (chromosome->getGenes()[i] != false) {
        Fitness2 += 1.0;
      }
      i += 1;
    }
    Fit = Fitness2 / numGenes;
  }
  return Fit;
}