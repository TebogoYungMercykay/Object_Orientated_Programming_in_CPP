#include "TesterInterface.h"
#include <iostream>
TesterInterface::TesterInterface(int maxNumTests) {
  maxNumTesters = currNumTesters = 0;
  testers = new NumberTester *[0];
  if (maxNumTests >= 1) {
    maxNumTesters = maxNumTests;
    testers = new NumberTester *[getMaxNumTesters()];
    for (int i = 0; i < getMaxNumTesters(); i += 1) {
      testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface &other) {
  maxNumTesters = other.getMaxNumTesters();
  currNumTesters = other.getCurrNumTesters();
  testers = new NumberTester *[other.getMaxNumTesters()];
  int i = 0;
  for (; i < getMaxNumTesters(); i += 1) {
    if (other.testers[i] != NULL) {
      testers[i] = other.testers[i]->clone();
    } else {
      testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface *other) {
  if (other) {
    maxNumTesters = other->getMaxNumTesters();
    currNumTesters = other->getCurrNumTesters();
    testers = new NumberTester *[other->getMaxNumTesters()];
    int i = 0;
    for (; i < getMaxNumTesters(); i += 1) {
      if (other->testers[i] != NULL) {
        testers[i] = other->testers[i]->clone();
      } else {
        testers[i] = NULL;
      }
    }
  } else {
    maxNumTesters = currNumTesters = 0;
    testers = new NumberTester *[getMaxNumTesters()];
  }
}
int TesterInterface::getCurrNumTesters() const { return currNumTesters; }
int TesterInterface::getMaxNumTesters() const { return maxNumTesters; }
TesterInterface::~TesterInterface() {
  int i = 0;
  for (; i < getMaxNumTesters(); i += 1) {
    if (testers[i] != NULL) {
      delete testers[i];
      testers[i] = NULL;
    }
  }
  if (testers != NULL) {
    delete[] testers;
    testers = NULL;
  }
  currNumTesters = maxNumTesters = 0;
}
int TesterInterface::addTester(NumberTester *tester) {
  int Temp = 0;
  if (tester == NULL) {
    return -1;
  } else if (getCurrNumTesters() == getMaxNumTesters()) {
    return -1;
  } else {
    int i = 0;
    for (; i < getMaxNumTesters(); i += 1) {
      if (!(testers[i] != NULL)) {
        testers[i] = tester->clone();
        Temp = i;
        currNumTesters += 1;
        break;
      }
    }
  }
  return Temp;
}
bool TesterInterface::removeTester(int pos) {
  if (pos < 0 || pos >= getMaxNumTesters() || testers[pos] == NULL)
    return false;
  delete testers[pos];
  testers[pos] = NULL;
  currNumTesters--;
  return true;
}
bool TesterInterface::evaluate(int num) {
  if (getCurrNumTesters() == 0)
    return false;
  for (int i = 0; i < getMaxNumTesters(); i++) {
    if (testers[i] != NULL && !testers[i]->evaluate(num)) {
      return false;
    }
  }
  return true;
}
int *TesterInterface::failedTests(int num) {
  int *myArray = new int[numberOfFailedTests(num)];
  int i = 0, temp2 = 0;
  for (; i < getMaxNumTesters(); i += 1) {
    if (testers[i] != NULL) {
      bool Temp = testers[i]->evaluate(num);
      if (Temp == false) {
        myArray[temp2] = i;
        temp2 += 1;
      }
    }
  }
  return myArray;
}
int TesterInterface::numberOfFailedTests(int num) {
  if (getCurrNumTesters() == 0)
    return 0;
  int Temp2 = 0, i = 0;
  for (; i < getMaxNumTesters(); i += 1) {
    if (testers[i] != NULL) {
      bool Temp = testers[i]->evaluate(num);
      if (Temp == false)
        Temp2 += 1;
    }
  }
  return Temp2;
}
NumberTester *TesterInterface::operator[](int pos) {
  if (pos >= 0 && pos < getMaxNumTesters()) {
    return testers[pos];
  }
  return NULL;
}