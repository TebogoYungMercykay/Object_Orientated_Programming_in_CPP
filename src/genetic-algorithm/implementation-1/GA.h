#ifndef GA_H
#define GA_H

#include <cmath>

#include "Chromosome.h"
#include "FitnessFunction.h"
#include "RandomGenerator.h"

class GA {
private:
  Chromosome **population;
  int populationSize;
  int selectionSize;
  // This is a number that will be used in the calculation of how many
  // chromosomes will need to be replaced.

public:
  GA(int populationSize, RandomGenerator *rand, int numGenes,
     int selectionSize);
  GA(GA *geneticAlgorithm);
  ~GA();
  Chromosome **run(FitnessFunction *fitnessFunction);
  double **run(FitnessFunction *fitnessFunction, int numGenerations);
  Chromosome **selection(FitnessFunction *fitnessFunction);
  Chromosome **inverseSelection(FitnessFunction *fitnessFunction);
  Chromosome **crossOver(Chromosome *c1, Chromosome *c2);
  Chromosome *mutate(Chromosome *c1);
  double calculateAvgAccuracy(FitnessFunction *fitnessFunction);
  double calculateStd(FitnessFunction *fitnessFunction);
  double calculateVariance();
  void setPopulation(Chromosome **p);
};

#endif // !GA_H