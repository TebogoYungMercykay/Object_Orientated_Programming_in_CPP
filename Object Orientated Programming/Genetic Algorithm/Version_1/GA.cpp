#include "GA.h"

GA::GA(int populationSize, RandomGenerator* rand, int numGenes, int selectionSize)
{
    GA::populationSize = populationSize;
    GA::population = new Chromosome*[GA::populationSize];
    int p=0;
    while(p<GA::populationSize)
    {
        GA::population[p]=new Chromosome(numGenes, rand);
        p++;
    }
    GA::selectionSize = selectionSize;
}
GA::GA(GA* geneticAlgorithm)
{
    GA::population=NULL;
    GA::populationSize = 0;
    GA::selectionSize = 0;
    if(geneticAlgorithm)
    {
        GA::populationSize = geneticAlgorithm->populationSize;
        GA::population = new Chromosome*[GA::populationSize];
        int p=0;
        while(p<GA::populationSize)
        {
            GA::population[p]=new Chromosome(geneticAlgorithm->population[p]);
            p++;
        }
        GA::selectionSize = selectionSize;
    }
}
GA::~GA()
{
    GA::selectionSize=0;
    int p=0;
    while(p<GA::populationSize)
    {
        GA::population[p] = NULL;
        delete GA::population[p];
        p++;
    }
    GA::population = NULL;
    delete [] population;
    GA::populationSize=0;
}
void GA::setPopulation(Chromosome** geneticAlgorithm)
{
    GA::population = new Chromosome*[GA::populationSize];
    int p=0;
    while(p<GA::populationSize)
    {
        if(geneticAlgorithm[p])
        {
            int o = geneticAlgorithm[p]->getNumGenes();
            GA::population[p]=new Chromosome(geneticAlgorithm[p]->getGenes(),o);
        }
        p+=1;
    }
}
double** GA::run(FitnessFunction* fitnessFunction, int numGenerations)
{
    double **results = new double*[numGenerations];
    int q=0;
    while(numGenerations>q)
    {
        results[q++] = new double[3];
    }
    q=0;
    while(numGenerations>q)
    {
        GA::setPopulation(GA::run(fitnessFunction));
        results[q][0]=GA::calculateAvgAccuracy(fitnessFunction);
        results[q][1]=GA::calculateStd(fitnessFunction);
        results[q][2]=GA::calculateVariance();
        q++;
    }
    return results;
}
double GA::calculateAvgAccuracy(FitnessFunction* fitnessFunction)
{
    double avgAccuracy = 0;
    int p=0;
    while(p<GA::populationSize)
    {
        if(GA::population[p])
        {
            avgAccuracy+=GA::population[p]->fitness(fitnessFunction, GA::population[p], GA::population[p]->getNumGenes());
        }
        p++;
    }
    return avgAccuracy/GA::populationSize;
}
double GA::calculateStd(FitnessFunction* fitnessFunction)
{
    double avgAccuracy = calculateAvgAccuracy(fitnessFunction);
    int p=0;
    double stdAccuracy = 0;
    while(p<GA::populationSize)
    {
        if(GA::population[p])
        {
            stdAccuracy+=pow(((GA::population[p]->fitness(fitnessFunction, GA::population[p], GA::population[p]->getNumGenes()))-avgAccuracy),2);
        }
        p++;
    }
    return sqrt(stdAccuracy/GA::populationSize);
}
Chromosome** GA::crossOver(Chromosome* c1, Chromosome* c2)
{
    Chromosome** crossOverPopulation = new Chromosome*[2];
    crossOverPopulation[0] = new Chromosome(c1->crossOver(c2));
    crossOverPopulation[1] = new Chromosome(c2->crossOver(c1));
    return crossOverPopulation;
}
double GA::calculateVariance()
{
    double nh = 0;
    int p = 0;
    while((populationSize>p)==true)
    {
        int q= 0;
        while((p>(q+1)*this->populationSize || p>q)==true)
        {
            if(population[p]->toString() == population[q]->toString())break;
            q++;
        }
        if(p>(q+1)*this->populationSize || p==q)nh++;
        p++;
    }
    double var = (nh/populationSize);
    return var;
}
Chromosome** GA::inverseSelection(FitnessFunction* fitnessFunction)
{
    int indexInsert = 0;
    Chromosome** ty = new Chromosome*[populationSize];
    int p = GA::populationSize-1;
    while(0<=p)
    {
        ty[indexInsert] = selection(fitnessFunction)[p--];
        indexInsert++;
    }
    return ty;
}
Chromosome** GA::run(FitnessFunction* fitnessFunction)
{
    Chromosome** winners;
    winners = selection(fitnessFunction);
    Chromosome** losers;
    losers = inverseSelection(fitnessFunction);
    int p=0;
    int tempo=2*GA::selectionSize;
    Chromosome** offspring;
    offspring = new Chromosome*[3*GA::selectionSize];
    Chromosome** ty;
    ty = new Chromosome*[GA::populationSize];
    while((p<tempo)==true)
    {
        Chromosome** nChromosomes;
        nChromosomes = crossOver(winners[p], winners[p+1]);
        offspring[p] = nChromosomes[0];
        offspring[p+1] = nChromosomes[1];
        p++;
        int q = 0;
        while((2>q)==true)
        {
            nChromosomes[q] = NULL;
            delete nChromosomes[q];
            q++;
        }
        nChromosomes = NULL;
        delete[] nChromosomes;
        p++;
    }
    p=0;
    while((p<GA::selectionSize)==true)
    {
        offspring[p+2*GA::selectionSize] = new Chromosome(mutate(winners[p+2*GA::selectionSize]));
        p++;
    }
    ty = population;
    p=0;
    tempo=3*GA::selectionSize;
    while((tempo>p)==true)
    {
        Chromosome* dyingChromosome = losers[p];
        int q = 0;
        while((GA::populationSize>q)==true)
        {
            if((ty[q] == dyingChromosome)==true)
            {
                ty[q] = new Chromosome(offspring[p]);
                break;
            }
            q++;
        }
        delete dyingChromosome;
        p++;
    }
    p=0;
    while((p<GA::populationSize)==true)
    {
        winners[p] = NULL;
        delete winners[p];
        p++;
    }
    winners = NULL;
    delete [] winners;
    p=0;
    while(p<GA::populationSize)
    {
        losers[p] = NULL;
        delete losers[p];
        p++;
    }
    losers = NULL;
    delete [] losers;
    p=0;
    while(p<3*GA::selectionSize)
    {
        offspring[p] = NULL;
        delete offspring[p];
        p++;
    }
    offspring = NULL;
    delete [] offspring;
    return ty;
}
Chromosome** GA::selection(FitnessFunction* fitnessFunction)
{
    int indexInsert = 0;
    double insertValue = 0;
    double *fit = new double[populationSize];
    Chromosome** ty;
    ty = new Chromosome*[GA::populationSize];
    int p = 0;
    while(p<GA::populationSize)
    {
        fit[p] = population[p]->fitness(fitnessFunction, GA::population[p], population[p]->getNumGenes());
        ty[p] = GA::population[p];
        p++;
    }
    p = 0;
    while(p<GA::populationSize)
    {
        insertValue = fit[p];
        Chromosome* myChrome = ty[p];
        indexInsert = p-1;
        while(0<=indexInsert && insertValue>fit[indexInsert])
        {
            int pi = indexInsert+1;
            ty[pi] = ty[indexInsert];
            fit[pi] = fit[indexInsert];
            indexInsert--;
        }
        int pi = indexInsert+1;
        fit[pi] = insertValue;
        ty[pi] = myChrome;
        p++;
    }
    return ty;
}
Chromosome* GA::mutate(Chromosome* c1)
{
    return c1->mutate();
}