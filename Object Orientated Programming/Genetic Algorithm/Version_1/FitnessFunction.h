#ifndef FitnessFunction_H
#define FitnessFunction_H

#include "Chromosome.h"

class Chromosome;

class FitnessFunction
{
public:
	double calculateFitness(Chromosome* chromosome, int numGenes);
};

#endif // !FitnessFunction