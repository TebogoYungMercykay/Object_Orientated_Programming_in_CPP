#include "TesterInterface.h"
#include <iostream>
TesterInterface::TesterInterface(int maxNumTests) {
  TesterInterface::maxNumTesters = TesterInterface::currNumTesters = 0;
  TesterInterface::testers = new NumberTester *[0];
  if (maxNumTests >= 1) {
    TesterInterface::maxNumTesters = maxNumTests;
    TesterInterface::testers = new NumberTester *[maxNumTests];
    for (int i = 0; i < maxNumTests; i += 1) {
      TesterInterface::testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface &other) {
  TesterInterface::maxNumTesters = other.maxNumTesters;
  TesterInterface::currNumTesters = other.currNumTesters;
  TesterInterface::testers = new NumberTester *[other.maxNumTesters];
  int i = 0;
  for (; i < TesterInterface::maxNumTesters; i += 1) {
    if (other.testers[i] != NULL) {
      TesterInterface::testers[i] = other.testers[i]->clone();
    } else {
      TesterInterface::testers[i] = NULL;
    }
  }
}
TesterInterface::TesterInterface(TesterInterface *other) {
  if (other) {
    TesterInterface::maxNumTesters = other->maxNumTesters;
    TesterInterface::currNumTesters = other->currNumTesters;
    TesterInterface::testers = new NumberTester *[other->maxNumTesters];
    int i = 0;
    for (; i < TesterInterface::maxNumTesters; i += 1) {
      if (other->testers[i] != NULL) {
        TesterInterface::testers[i] = other->testers[i]->clone();
      } else {
        TesterInterface::testers[i] = NULL;
      }
    }
  } else {
    TesterInterface::maxNumTesters = TesterInterface::currNumTesters = 0;
    TesterInterface::testers =
        new NumberTester *[TesterInterface::maxNumTesters];
  }
}
int TesterInterface::getCurrNumTesters() const {
  return TesterInterface::currNumTesters;
}
int TesterInterface::getMaxNumTesters() const {
  return TesterInterface::maxNumTesters;
}
TesterInterface::~TesterInterface() {
  int i = 0;
  for (; i < TesterInterface::maxNumTesters; i += 1) {
    if (TesterInterface::testers[i] != NULL) {
      delete TesterInterface::testers[i];
      TesterInterface::testers[i] = NULL;
    }
  }
  if (testers != NULL) {
    delete[] testers;
    testers = NULL;
  }
  TesterInterface::currNumTesters = TesterInterface::maxNumTesters = 0;
}
int TesterInterface::addTester(NumberTester *tester) {
  int var = 0;
  if (tester == NULL) {
    return -1;
  } else if (TesterInterface::currNumTesters ==
             TesterInterface::maxNumTesters) {
    return -1;
  } else {
    int i = 0;
    for (; i < TesterInterface::maxNumTesters; i += 1) {
      if (!(TesterInterface::testers[i] != NULL)) {
        TesterInterface::testers[i] = tester->clone();
        currNumTesters = currNumTesters + 1;
        var = i;
        break;
      }
    }
  }
  return var;
}
bool TesterInterface::removeTester(int pos) {
  if (pos >= 0 && pos < maxNumTesters && testers[pos] != NULL) {
    delete testers[pos];
    testers[pos] = NULL;
    currNumTesters--;
    return true;
  }
  return false;
}
bool TesterInterface::evaluate(int num) {
  if (currNumTesters == 0) {
    return false;
  }
  int var = 0;
  for (int i = 0; i < TesterInterface::maxNumTesters; i += 1) {
    if (TesterInterface::testers[i] != NULL) {
      if ((TesterInterface::testers[i]->evaluate(num)) == false) {
        return false;
      }
    }
  }

  return true;
}
int *TesterInterface::failedTests(int num) {
  int *myArray = new int[numberOfFailedTests(num)];
  int var2 = 0;
  for (int i = 0; i < TesterInterface::maxNumTesters; i += 1) {
    if (TesterInterface::testers[i] != NULL) {
      if (TesterInterface::testers[i]->evaluate(num) == false) {
        myArray[var2] = i;
        var2 += 1;
      }
    }
  }
  return myArray;
}
int TesterInterface::numberOfFailedTests(int num) {
  if (currNumTesters == 0)
    return 0;
  int var2 = 0;
  for (int i = 0; i < TesterInterface::maxNumTesters; i += 1) {
    if (TesterInterface::testers[i] != NULL) {
      if (TesterInterface::testers[i]->evaluate(num) == false)
        var2 += 1;
    }
  }
  return var2;
}
NumberTester *TesterInterface::operator[](int pos) {
  if (pos >= 0 && pos < maxNumTesters) {
    return testers[pos];
  }
  return NULL;
}