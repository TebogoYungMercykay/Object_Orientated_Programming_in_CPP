#ifndef CHROMOSOME_H
#define CHROMOSOME_H

#include <cmath>
#include <string>

#include "FitnessFunction.h"
#include "RandomGenerator.h"

class FitnessFunction;

class Chromosome {
private:
  bool *genes;
  int numGenes;

public:
  Chromosome(int numGenes, RandomGenerator *rand);
  Chromosome(Chromosome *chromosome);
  Chromosome(bool *genes, int numGenes);
  ~Chromosome();
  static double fitness(FitnessFunction *fitnessFunction,
                        Chromosome *chromosome, int numGenes);
  int getNumGenes();
  Chromosome *crossOver(Chromosome *c2);
  Chromosome *mutate();
  std::string toString();
  bool *getGenes();
};

#endif // !CHROMOSOME_H