/**********************************************************************************************/
/********************* Intensified From The StudentFiles Main By @TEBOGO **********************/
/**************************************** (X66411X178) ****************************************/
/**********************************************************************************************/
#include <iostream>
#include <ctime>
#include "Chromosome.h"
#include "FitnessFunction.h"
#include "GA.h"
#include "RandomGenerator.h"
using namespace std;

void GA_CLASS();
void studentMain();
void CHROMOSOME_CLASS();
void GA_GLASS_EXTENDED();
void test_EditBenchMark();
double avg(double** arr, int d, int size);
void benchMark(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults);
void benchMark_GA_CLASS(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults);

int main()
{
    // 1: uncomment This Function Call To Run The A Thorough Test.
    CHROMOSOME_CLASS();
    GA_CLASS();
    GA_GLASS_EXTENDED();

    // 2: uncomment This Function Call To Run The Provided Main Without EDITS.
    // studentMain();

    // 3: uncomment This Function Call And Edit BenchMairk Values For Testing.
    // test_EditBenchMark();
    return 0;
}

double avg(double** arr, int d, int size){
    double sum = 0;
    for (int i = 0; i<size; i++)sum += arr[i][d];
    return sum/size;
}
void benchMark_GA_CLASS(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults) {
    RandomGenerator* randomGenerator = new RandomGenerator(seed);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(popSize, randomGenerator, numGenes, selectionSize);
    clock_t startTime = clock();
    std::cout<<"-run(fitnessFunction,numGenerations) LOADING...-"<<std::endl;
    double** results = ga->run(fitnessFunction, numGenerations);
    std::cout<<"--------------- DONE LOADING!! -----------------"<<std::endl;
    clock_t endTime = clock();
    std::cout<<"---------- PRINTING THE GENERATIONS: -----------"<<std::endl;
    if (generationResults) {
        for (int i = 0; i < numGenerations; i++) {
            std::cout<<"Gen "<<i<<endl;
            std::cout<<"Avg accuracy: "<<results[i][0]<<endl;
            std::cout<<"Std: "<<results[i][1]<<endl;
            std::cout<<"Variance: "<<results[i][2]<<endl;
            std::cout<<"-------------------------------------------------"<<std::endl;
        }
    }
    std::cout<<"-------------------- DONE!! --------------------"<<std::endl;
    std::cout<<"------------ PRINTING THE SUMMARY: -------------"<<std::endl;
    std::cout<<"Your Avg avg: "<<avg(results, 0, numGenerations)<<" -> "<<"Expected Avg avg: 0.692"<<endl;
    std::cout<<"Your Avg std: "<<avg(results, 1, numGenerations)<<" -> "<<"Expected Avg std: 0.169021"<<endl;
    std::cout<<"Your Avg var: "<<avg(results, 2, numGenerations)<<" -> "<<"Expected Avg var: 0.41"<<endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"----- If you got those values then your:= ------"<<std::endl;
    std::cout<<"----- run(fitnessFunction, numGenerations) -----"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"---- Testing : Time Efficiency Of Your Code ----"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    if(timeResults)
        std::cout<<"Execution time: "<<difftime(endTime, startTime)/1000<<"ms"<<endl;
    for (int i = 0; i < numGenerations; i++) {
        delete[] results[i];
    }
    delete[] results;
    delete ga;
    delete fitnessFunction;
    delete randomGenerator;
    std::cout<<"--------------------- Done !! ------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"------------------------------- END OF GA CLASS -------------------------------"<<std::endl;
    std::cout<<"------- THIS MAIN DOESN'T NECESARILY GUARANTEE FULL MARKS BUT... (*_*) --------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
}
void CHROMOSOME_CLASS() {
    std::cout<<"--------------------------------- START ---------------------------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    RandomGenerator* rand = new RandomGenerator(12345);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    std::cout<<"--------------------------- TESTING CHROMOSOME CLASS --------------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"------- Testing Constructor & toString()--------"<<std::endl;
    std::cout<<"-------- The Accessors are tested also ---------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    Chromosome * myC1 = new Chromosome(10, rand);
    std::cout<<"There Are: "<<myC1->getNumGenes()<<" -> 10 genes"<<std::endl;
    for (int i = 0; i < 10; i++) {
        std::cout<<myC1->getGenes()[i];
    }
    std::cout<<" -> "<<myC1->toString()<<endl;
    std::cout<<"---Testing :Chromosome(Chromosome* chromosome)--"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    Chromosome * myC2 = new Chromosome(myC1);
    for (int i = 0; i < 10; i++) {
        std::cout<<myC2->getGenes()[i];
    }
    std::cout<<" -> "<<myC2->toString()<<endl;
    std::cout<<"-Testing :Chromosome(bool* genes, int numGenes)-"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    Chromosome * myC3 = new Chromosome(myC1->getGenes(),myC1->getNumGenes());
    for (int i = 0; i < 10; i++) {
        std::cout<<myC3->getGenes()[i];
    }
    std::cout<<" -> "<<myC3->toString()<<endl;
    std::cout<<"--------- Testing : fitness function -----------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"0.6 -> "<<myC3->fitness(fitnessFunction, myC2, myC2->getNumGenes())<<endl;
    std::cout<<"-------- Testing : crossOver Function ----------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    Chromosome * myC4 = myC1->crossOver(myC2);
    Chromosome * myC5 = myC2->crossOver(myC3);
    std::cout<<"1111101000 -> ";
    for (int i = 0; i < 10; i++) {
        std::cout<<myC5->getGenes()[i];
    }
    std::cout<<endl;
    std::cout<<"1111101000 -> ";
    for (int i = 0; i < 10; i++) {
        std::cout<<myC4->getGenes()[i];
    }
    std::cout<<endl;
    std::cout<<"---------- Testing : mutate Function -----------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    Chromosome * myC6 = myC5->mutate();
    std::cout<<"0000010111 -> ";
    for (int i = 0; i < 10; i++) {
        std::cout<<myC6->getGenes()[i];
    }
    std::cout<<endl;
    std::cout<<"---------- Testing : The Destructor ------------"<<std::endl;
    delete myC1;
    delete myC2;
    delete myC3;
    delete myC4;
    delete myC5;
    delete myC6;
    delete rand;
    delete fitnessFunction;
    std::cout<<"--------------------- Done !! ------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"-------------------------- END OF CHROMOSOME CLASS ----------------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"--if You See This, Your Chromosome,RandomGenerator and FitnessFunction Work!!--"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
}
void GA_CLASS() {
    std::cout<<"-------------------------- NOW TESTING THE GA CLASS ---------------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    Chromosome** p = new Chromosome * [10];
    for (int i = 0; i < 10; i++) {
        bool* arr = new bool[10];
        for (int j = 0; j < 10; j++) {
            arr[j] = j%2;
            if (j == i) {
                arr[j] = false;
            }
        }
        p[i] = new Chromosome(arr, 10);
        delete[] arr;
    }
    RandomGenerator* rand = new RandomGenerator(12345);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    std::cout<<"---- Testing Constructor 1 & setPopulation -----"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    GA* ga = new GA(10, rand, 10, 1);
    ga->setPopulation(p);
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<" -> 0.45"<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<" -> 0.05" <<endl;
    std::cout<<ga->calculateVariance()<<" -> 0.6" <<endl;
    std::cout<<"------------ Testing: Constructor 2 ------------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"-- Using: class * objName1 = objName2 ----------"<<std::endl;
    GA* gb = ga;
    std::cout<<gb->calculateAvgAccuracy(fitnessFunction)<<" -> 0.45"<<endl;
    std::cout<<gb->calculateStd(fitnessFunction)<<" -> 0.05" <<endl;
    std::cout<<gb->calculateVariance()<<" -> 0.6" <<endl;
    std::cout<<"-- Using: class * objName1(objName2) -----------"<<std::endl;
    GA* gc(ga);
    std::cout<<gc->calculateAvgAccuracy(fitnessFunction)<<" -> 0.45"<<endl;
    std::cout<<gc->calculateStd(fitnessFunction)<<" -> 0.05" <<endl;
    std::cout<<gc->calculateVariance()<<" -> 0.6" <<endl;
    GA* gd = new GA(ga);
    std::cout<<"- Using: className *objName1 = new className(objName2)--"<<std::endl;
    std::cout<<gd->calculateAvgAccuracy(fitnessFunction)<<" -> 0.45"<<endl;
    std::cout<<gd->calculateStd(fitnessFunction)<<" -> 0.05" <<endl;
    std::cout<<gd->calculateVariance()<<" -> 0.6" <<endl;
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"------------------ Testing:= -------------------"<<std::endl;
    std::cout<<"----- run(FitnessFunction* fitnessFunction) ----"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    p = ga->run(fitnessFunction);
    ga->setPopulation(p);
    std::cout<<"------ DXNE!! DXNE!! DXNE!! DXNE!! DXNE!! ------"<<std::endl;
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<" -> 0.48"<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<" -> 0.04" <<endl;
    std::cout<<ga->calculateVariance()<<" -> 0.4" <<endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"----- If you got those values then your:= ------"<<std::endl;
    std::cout<<"----- run(FitnessFunction* fitnessFunction) ----"<<std::endl;
    std::cout<<"----------------- selection --------------------"<<std::endl;
    std::cout<<"-------------- InverseSelection ----------------"<<std::endl;
    std::cout<<"------------ calculateAvgAccuracy --------------"<<std::endl;
    std::cout<<"---------------- calculateStd ------------------"<<std::endl;
    std::cout<<"---------------calculateVariance ---------------"<<std::endl;
    std::cout<<"-------- and your Constructors work !!! --------"<<std::endl;
    std::cout<<"------------------------------------------------"<<std::endl;
    std::cout<<"---------- Testing: The Destructors ------------"<<std::endl;
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    p = NULL;
    std::cout<<"------------------ LOADING.... -----------------"<<std::endl;
    delete gc;
    delete gd;
    delete ga;
    delete rand;
    delete fitnessFunction;
    std::cout<<"--------------- DONE LOADING!! -----------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    std::cout<<"----------------------------------- Done !! -----------------------------------"<<std::endl;
}
void GA_GLASS_EXTENDED(){
    std::cout<<"---- NOW TESTING: run(FitnessFunction* fitnessFunction,int numGenerations) ----"<<std::endl;
    std::cout<<"------------------------ Mutate AND crossOver functions -----------------------"<<std::endl;
    std::cout<<"-------------------------------------------------------------------------------"<<std::endl;
    benchMark_GA_CLASS(100, 100, 5, 10, 1, true, true);
}
void benchMark(int numGenerations, int popSize, int selectionSize, int numGenes, long seed, bool generationResults, bool timeResults) {
    RandomGenerator* randomGenerator = new RandomGenerator(seed);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(popSize, randomGenerator, numGenes, selectionSize);
    clock_t startTime = clock();
    double** results = ga->run(fitnessFunction, numGenerations);
    clock_t endTime = clock();
    std::cout<<"---"<<endl;
    if (generationResults) {
        for (int i = 0; i < numGenerations; i++) {
            std::cout<<"Gen "<<i<<endl;
            std::cout<<"Avg accuracy: "<<results[i][0]<<endl;
            std::cout<<"Std: "<<results[i][1]<<endl;
            std::cout<<"Variance: "<<results[i][2]<<endl;
            std::cout<<"---"<<endl;
        }
    }

    std::cout<<"Run summary: "<<endl;
    std::cout<<"Avg avg: "<<avg(results, 0, numGenerations)<<endl;
    std::cout<<"Avg std: "<<avg(results, 1, numGenerations)<<endl;
    std::cout<<"Avg var: "<<avg(results, 2, numGenerations)<<endl;
    if(timeResults)
        std::cout<<"Execution time: "<<difftime(endTime, startTime)/1000<<"ms"<<endl;

    for (int i = 0; i < numGenerations; i++) {
        delete[] results[i];
    }
    delete[] results;
    results = NULL;
    delete ga;
    delete fitnessFunction;
    delete randomGenerator;
}
void studentMain() {
    Chromosome** p = new Chromosome * [10];
    for (int i = 0; i < 10; i++) {
        bool* arr = new bool[10];
        for (int j = 0; j < 10; j++) {
            arr[j] = j%2;
            if (j == i) {
                arr[j] = false;
            }
        }
        p[i] = new Chromosome(arr, 10);
        delete[] arr;
    }
    RandomGenerator* rand = new RandomGenerator(12345);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(10, rand, 10, 1);
    ga->setPopulation(p);
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<endl;
    std::cout<<ga->calculateVariance()<<endl;
    p = ga->run(fitnessFunction);
    ga->setPopulation(p);
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<endl;
    std::cout<<ga->calculateVariance()<<endl;
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    delete ga;
    delete rand;
    delete fitnessFunction;
    benchMark(10, 10, 1, 10, 500, true, true);
}
void test_EditBenchMark(){
    Chromosome** p = new Chromosome * [10];
    for (int i = 0; i < 10; i++) {
        bool* arr = new bool[10];
        for (int j = 0; j < 10; j++) {
            arr[j] = j%2;
            if (j == i) {
                arr[j] = false;
            }
        }
        p[i] = new Chromosome(arr, 10);
        delete[] arr;
    }
    RandomGenerator* rand = new RandomGenerator(12345);
    FitnessFunction* fitnessFunction = new FitnessFunction();
    GA* ga = new GA(10, rand, 10, 1);
    ga->setPopulation(p);
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<endl;
    std::cout<<ga->calculateVariance()<<endl;
    p = ga->run(fitnessFunction);
    ga->setPopulation(p);
    std::cout<<ga->calculateAvgAccuracy(fitnessFunction)<<endl;
    std::cout<<ga->calculateStd(fitnessFunction)<<endl;
    std::cout<<ga->calculateVariance()<<endl;
    for (int i = 0; i < 10; i++) {
        delete p[i];
    }
    delete[] p;
    delete ga;
    delete rand;
    delete fitnessFunction;
    benchMark(100, 100, 5, 10, 1, true, true);
}