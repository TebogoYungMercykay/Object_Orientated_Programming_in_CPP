#include "TesterInterface.h"
#include <iostream>
TesterInterface::TesterInterface(int maxNumTests) {
  this->maxNumTesters = this->currNumTesters = 0;
  this->testers = new NumberTester *[0];
  if (maxNumTests >= 1) {
    this->maxNumTesters = maxNumTests;
    this->testers = new NumberTester *[maxNumTests];
    for (int i = 0; i < maxNumTests; i += 1) {
      this->testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface &other) {
  this->maxNumTesters = other.maxNumTesters;
  this->currNumTesters = other.currNumTesters;
  this->testers = new NumberTester *[other.maxNumTesters];
  int i = 0;
  for (; i < this->maxNumTesters; i += 1) {
    if (other.testers[i] != NULL) {
      this->testers[i] = other.testers[i]->clone();
    } else {
      this->testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface *other) {
  if (other) {
    this->maxNumTesters = other->maxNumTesters;
    this->currNumTesters = other->currNumTesters;
    this->testers = new NumberTester *[other->maxNumTesters];
    int i = 0;
    for (; i < this->maxNumTesters; i += 1) {
      if (other->testers[i] != NULL) {
        this->testers[i] = other->testers[i]->clone();
      } else {
        this->testers[i] = NULL;
      }
    }
  } else {
    this->maxNumTesters = this->currNumTesters = 0;
    this->testers = new NumberTester *[this->maxNumTesters];
  }
}
int TesterInterface::getCurrNumTesters() const { return this->currNumTesters; }
int TesterInterface::getMaxNumTesters() const { return this->maxNumTesters; }
TesterInterface::~TesterInterface() {
  int i = 0;
  for (; i < this->maxNumTesters; i += 1) {
    if (this->testers[i] != NULL) {
      delete this->testers[i];
      this->testers[i] = NULL;
    }
  }
  if (testers != NULL) {
    delete[] testers;
    testers = NULL;
  }
  this->currNumTesters = this->maxNumTesters = 0;
}
int TesterInterface::addTester(NumberTester *tester) {
  int Temp = 0;
  if (tester == NULL) {
    return -1;
  } else if (this->currNumTesters == this->maxNumTesters) {
    return -1;
  } else {
    int i = 0;
    for (; i < this->maxNumTesters; i += 1) {
      if (!(this->testers[i] != NULL)) {
        this->testers[i] = tester->clone();
        Temp = i;
        currNumTesters += 1;
        break;
      }
    }
  }
  return Temp;
}
bool TesterInterface::removeTester(int pos) {
  if (pos >= maxNumTesters) {
    return false;
  }
  if (pos < 0) {
    return false;
  }
  if (pos >= maxNumTesters) {
    return false;
  } else {
    delete testers[pos];
    testers[pos] = NULL;
    currNumTesters--;
  }
  return true;
}
bool TesterInterface::evaluate(int num) {
  if (currNumTesters == 0)
    return false;
  int Temp = 0;
  for (int i = 0; i < this->maxNumTesters; i += 1) {
    if (this->testers[i] != NULL) {
      if (!(this->testers[i]->evaluate(num))) {
        return false;
      }
    }
  }
  return true;
}
int *TesterInterface::failedTests(int num) {
  int *myArray = new int[numberOfFailedTests(num)];
  int i = 0, temp2 = 0;
  for (; i < this->maxNumTesters; i += 1) {
    if (this->testers[i] != NULL) {
      bool Temp = this->testers[i]->evaluate(num);
      if (Temp == false) {
        myArray[temp2] = i;
        temp2 += 1;
      }
    }
  }
  return myArray;
}
int TesterInterface::numberOfFailedTests(int num) {
  if (currNumTesters == 0)
    return 0;
  int Temp2 = 0, i = 0;
  for (; i < this->maxNumTesters; i += 1) {
    if (this->testers[i] != NULL) {
      bool Temp = this->testers[i]->evaluate(num);
      if (Temp == false)
        Temp2 += 1;
    }
  }
  return Temp2;
}
NumberTester *TesterInterface::operator[](int pos) {
  if (pos < 0) {
    return NULL;
  } else if (pos >= maxNumTesters) {
    return NULL;
  } else {
    return testers[pos];
  }
}