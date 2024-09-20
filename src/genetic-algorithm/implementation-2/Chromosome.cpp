#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator *rand) {
  if (numGenes < 0) {
    this->numGenes = 0;
  } else {
    this->numGenes = numGenes;
  }
  this->genes = new bool[this->numGenes];
  if (rand == NULL) {
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      genes[k_iterator] = false;
    }
  } else {
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      genes[k_iterator] = rand->randomBool();
    }
  }
}
Chromosome::Chromosome(Chromosome *chromosome) {
  this->genes = NULL;
  this->numGenes = 0;
  if (chromosome != NULL) {
    this->numGenes = chromosome->getNumGenes();
    this->genes = new bool[this->numGenes];
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      this->genes[k_iterator] = chromosome->getGenes()[k_iterator];
    }
  } else {
    int k_iterator = 0;
    Chromosome(k_iterator, NULL);
  }
}
Chromosome::Chromosome(bool *genes, int numGenes) {
  if (numGenes < 0) {
    this->numGenes = 0;
    this->genes = new bool[0];
  } else if (genes == NULL && numGenes >= 0) {
    this->numGenes = numGenes;
    this->genes = new bool[this->numGenes];
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      this->genes[k_iterator] = false;
    }
  } else {
    this->numGenes = numGenes;
    this->genes = new bool[this->numGenes];
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      this->genes[k_iterator] = genes[k_iterator];
    }
  }
}
Chromosome::~Chromosome() {
  this->genes = NULL;
  delete[] this->genes;
  this->numGenes = 0;
}
double Chromosome::fitness(FitnessFunction *fitnessFunction,
                           Chromosome *chromosome, int numGenes) {
  if (fitnessFunction == NULL || chromosome == NULL || numGenes <= 0) {
    return 0;
  }
  return fitnessFunction->calculateFitness(chromosome, numGenes);
}
int Chromosome::getNumGenes() { return this->numGenes; }
Chromosome *Chromosome::crossOver(Chromosome *c2) {
  if (c2 == NULL) {
    Chromosome *myTempChromosome = new Chromosome(this);
    return myTempChromosome;
  } else {
    int crossOverPoint = floor(c2->getNumGenes() / 2);
    bool *nGenes = new bool[this->getNumGenes()];
    for (int k_iterator = 0; k_iterator < crossOverPoint; k_iterator++) {
      nGenes[k_iterator] = this->genes[k_iterator];
    }
    for (int k_iterator = crossOverPoint; k_iterator < this->numGenes;
         k_iterator++) {
      nGenes[k_iterator] = c2->genes[k_iterator];
    }
    Chromosome *myTempChromosome = new Chromosome(nGenes, this->getNumGenes());
    delete[] nGenes;
    nGenes = NULL;
    return myTempChromosome;
  }
}
Chromosome *Chromosome::mutate() {
  bool *nGenes = new bool[this->getNumGenes()];
  for (int k_iterator = 0; k_iterator < this->getNumGenes(); k_iterator++) {
    nGenes[k_iterator] = !this->getGenes()[k_iterator];
  }
  Chromosome *myTempChromosome = new Chromosome(nGenes, this->getNumGenes());
  delete[] nGenes;
  nGenes = NULL;
  return myTempChromosome;
}
std::string Chromosome::toString() {
  std::string myReturnString = "";
  if (this->numGenes <= 0) {
    return "";
  } else {
    for (int k_iterator = 0; k_iterator < this->numGenes; k_iterator++) {
      if (this->genes[k_iterator]) {
        myReturnString += "1";
      } else {
        myReturnString += "0";
      }
    }
  }
  return myReturnString;
}
bool *Chromosome::getGenes() { return this->genes; }