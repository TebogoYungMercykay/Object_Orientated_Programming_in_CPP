#include "Chromosome.h"

Chromosome::Chromosome(int numGenes, RandomGenerator *rand) {
  if (numGenes < 0) {
    Chromosome::numGenes = 0;
    Chromosome::genes = new bool[0];
  } else {
    Chromosome::numGenes = numGenes;
    Chromosome::genes = new bool[Chromosome::numGenes];
  }
  if (!rand) {
    int m = 0;
    while (m < Chromosome::numGenes) {
      genes[m] = false;
      m++;
    }
  } else {
    int m = 0;
    while (m < Chromosome::numGenes) {
      genes[m] = rand->randomBool();
      m++;
    }
  }
}
Chromosome::Chromosome(Chromosome *chromosome) {
  if (chromosome) {
    Chromosome::numGenes = chromosome->getNumGenes();
    Chromosome::genes = new bool[Chromosome::numGenes];
    int m = 0;
    while (m < Chromosome::numGenes) {
      Chromosome::genes[m] = chromosome->getGenes()[m];
      m++;
    }
  } else {
    Chromosome::genes = NULL;
    Chromosome::numGenes = 0;
    int m = 0;
    Chromosome::genes = new bool[0];
  }
}
Chromosome::Chromosome(bool *genes, int numGenes) {
  if (!genes && numGenes >= 0) {
    Chromosome::numGenes = numGenes;
    Chromosome::genes = new bool[Chromosome::numGenes];
    int m = 0;
    while (m < Chromosome::numGenes) {
      Chromosome::genes[m] = false;
      m++;
    }
  } else {
    if (0 > numGenes) {
      Chromosome::numGenes = 0;
      Chromosome::genes = new bool[0];
    } else {
      Chromosome::numGenes = numGenes;
      Chromosome::genes = new bool[numGenes];
      int m = 0;
      while (m < numGenes) {
        Chromosome::genes[m] = genes[m];
        m++;
      }
    }
  }
}
Chromosome::~Chromosome() {
  Chromosome::genes = NULL;
  Chromosome::numGenes = 0;
  delete[] Chromosome::genes;
}
double Chromosome::fitness(FitnessFunction *fitnessFunction,
                           Chromosome *chromosome, int numGenes) {
  if (!fitnessFunction) {
    return 0;
  } else if (numGenes <= 0) {
    return 0;
  } else if (!chromosome) {
    return 0;
  }
  return fitnessFunction->calculateFitness(chromosome, numGenes);
}
int Chromosome::getNumGenes() { return Chromosome::numGenes; }
Chromosome *Chromosome::crossOver(Chromosome *c2) {
  if (!c2) {
    Chromosome *c;
    c = new Chromosome(this);
    return c;
  } else {
    int crossOverPoint = floor(c2->getNumGenes() / 2);
    bool *gs = new bool[Chromosome::getNumGenes()];
    int m = 0;
    while (m < crossOverPoint) {
      gs[m] = Chromosome::genes[m];
      m++;
    }
    m = crossOverPoint;
    while (m < Chromosome::numGenes) {
      gs[m] = c2->genes[m];
      m++;
    }
    Chromosome *c;
    c = new Chromosome(gs, Chromosome::getNumGenes());
    delete[] gs;
    gs = NULL;
    return c;
  }
}
Chromosome *Chromosome::mutate() {
  bool *gs;
  gs = new bool[Chromosome::getNumGenes()];
  int m = 0;
  while (m < Chromosome::getNumGenes()) {
    gs[m] = !Chromosome::getGenes()[m];
    m++;
  }
  Chromosome *c;
  c = new Chromosome(gs, Chromosome::getNumGenes());
  delete[] gs;
  gs = NULL;
  return c;
}
std::string Chromosome::toString() {
  std::string s("");
  if (Chromosome::numGenes <= 0) {
    return "";
  } else {
    int m = 0;
    while (m < Chromosome::numGenes) {
      if (Chromosome::genes[m] == !false) {
        s += "1";
      } else if (!false) {
        s += "0";
      }
      m++;
    }
  }
  return s;
}
bool *Chromosome::getGenes() { return Chromosome::genes; }