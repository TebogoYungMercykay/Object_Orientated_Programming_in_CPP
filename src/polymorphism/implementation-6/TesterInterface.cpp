#include "TesterInterface.h"

TesterInterface::TesterInterface(int maxNumTests) {

  if (maxNumTests < 1) {
    TesterInterface::maxNumTesters = 0;
    TesterInterface::currNumTesters = 0;
    TesterInterface::testers = new NumberTester *[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
      TesterInterface::testers[i] = NULL;
  } else {
    TesterInterface::maxNumTesters = maxNumTests;
    TesterInterface::currNumTesters = 0;
    TesterInterface::testers = new NumberTester *[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++)
      TesterInterface::testers[i] = NULL;
  }
}
TesterInterface::TesterInterface(TesterInterface *other) {
  NumberTester **temp;
  if (other == NULL) {
    maxNumTesters = 0;
    currNumTesters = 0;
    TesterInterface::testers = new NumberTester *[maxNumTesters];
  } else {
    maxNumTesters = other->maxNumTesters;
    currNumTesters = other->currNumTesters;
    TesterInterface::testers = new NumberTester *[other->maxNumTesters];
    for (int j = 0; j < other->maxNumTesters; j++) {
      if (other->testers[j] != NULL) {
        testers[j] = other->testers[j]->clone();
      } else {
        testers[j] = NULL;
      }
    }
  }
}
TesterInterface::TesterInterface(TesterInterface &other) {
  maxNumTesters = other.maxNumTesters;
  currNumTesters = other.currNumTesters;
  TesterInterface::testers = new NumberTester *[other.maxNumTesters];
  for (int j = 0; j < other.maxNumTesters; j++) {
    if (other.testers[j] != NULL) {
      testers[j] = other.testers[j]->clone();
    } else {
      testers[j] = NULL;
    }
  }
}
TesterInterface::~TesterInterface() {
  for (int i = 0; i < maxNumTesters; ++i) {
    delete testers[i];
    testers[i] = NULL;
  }
  delete[] testers;
  testers = NULL;
  TesterInterface::maxNumTesters = 0;
  TesterInterface::currNumTesters = 0;
}
int TesterInterface::addTester(NumberTester *tester) {
  int count = 0;
  if (tester == NULL) {
    return -1;
  }
  if (currNumTesters >= maxNumTesters) {
    return -1;
  }
  for (int j = 0; j < maxNumTesters; j++) {
    if (testers[j] == NULL) {
      testers[j] = tester->clone();
      currNumTesters++;
      count = j;
      break;
    }
  }
  return count;
}
bool TesterInterface::removeTester(int pos) {
  if (pos >= maxNumTesters || pos < 0) {
    return false;
  }
  if (testers[pos] == NULL) {
    return false;
  }

  delete testers[pos];
  testers[pos] = NULL;
  currNumTesters--;
  return true;
}
bool TesterInterface::evaluate(int num) {
  if (currNumTesters == 0) {
    return false;
  }
  for (int j = 0; j < maxNumTesters; j++) {
    if (testers[j] != NULL) {
      if (testers[j]->evaluate(num) == false) {
        return false;
      }
    }
  }
  return true;
}
int *TesterInterface::failedTests(int num) {
  const int failed = numberOfFailedTests(num);
  int *array = new int[failed];
  if (currNumTesters == 0) {
    return new int[0];
  }
  if (failed == 0) {
    return new int[0];
  }
  int count = 0;
  for (int j = 0; j < maxNumTesters; j++) {
    if (testers[j] != NULL) {
      if (testers[j]->evaluate(num) == false) {
        array[count] = j;
        count++;
      }
    }
  }
  return array;
}
int TesterInterface::numberOfFailedTests(int num) {
  if (currNumTesters == 0) {
    return 0;
  }
  int count = 0;
  for (int j = 0; j < maxNumTesters; j++) {
    if (testers[j] != NULL) {
      if (testers[j]->evaluate(num) == false) {
        count++;
      }
    }
  }
  return count;
}
NumberTester *TesterInterface::operator[](int pos) {
  if (pos >= maxNumTesters || pos < 0) {
    return NULL;
  }
  return testers[pos];
}
int TesterInterface::getCurrNumTesters() const { return currNumTesters; }
int TesterInterface::getMaxNumTesters() const { return maxNumTesters; }