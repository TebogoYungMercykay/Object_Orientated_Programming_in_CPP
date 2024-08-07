
#include "TesterInterface.h"
#include "NumberTester.h"

TesterInterface::TesterInterface(int mnt) {
  this->currNumTesters = 0;

  if (mnt < 1) {
    this->maxNumTesters = 0;
  } else {
    this->maxNumTesters = mnt;
  }

  testers = new NumberTester *[maxNumTesters];
  for (int i = 0; i < maxNumTesters; i++) {
    testers[i] = NULL;
  }
}

TesterInterface::TesterInterface(TesterInterface *other) {
  if (other == NULL) {
    this->maxNumTesters = 0;
    this->currNumTesters = 0;
    testers = new NumberTester *[0];
  } else {
    this->maxNumTesters = other->maxNumTesters;
    this->currNumTesters = other->currNumTesters;

    testers = new NumberTester *[maxNumTesters];
    for (int i = 0; i < maxNumTesters; i++) {
      if (other->testers[i] != NULL) {
        testers[i] = other->testers[i]->clone();
      }
    }
  }
}

TesterInterface::TesterInterface(TesterInterface &other) {
  this->maxNumTesters = other.maxNumTesters;
  this->currNumTesters = other.currNumTesters;

  testers = new NumberTester *[maxNumTesters];
  for (int i = 0; i < maxNumTesters; i++) {
    if (other.testers[i] != NULL) {
      testers[i] = other.testers[i]->clone();
    }
  }
}

TesterInterface::~TesterInterface() {
  if (this->testers != NULL) {
    for (int i = 0; i < maxNumTesters; i++) {
      if (testers[i] != NULL) {
        delete testers[i];

        testers[i] = NULL;
      }
    }
    delete testers;

    testers = NULL;
  }
}

int TesterInterface::addTester(NumberTester *tester) {
  if (tester == NULL) {
    return -1;
  }

  int c = -1;

  for (int i = 0; i < maxNumTesters; i++) {
    if (testers[i] == NULL) {
      c = i;
      break;
    }
  }

  if (c == -1) {
    return -1;
  } else {
    this->testers[c] = tester->clone();
    this->currNumTesters++;
    return c;
  }
}

bool TesterInterface::removeTester(int pos) {
  if (currNumTesters == 0) {
    return false;
  }
  if (pos >= 0 && pos < maxNumTesters && testers[pos] != NULL) {

    delete testers[pos];
    testers[pos] = NULL;
    this->currNumTesters--;
    return true;
  }
  return false;
}

bool TesterInterface::evaluate(int n) {
  int c = 0;
  if (currNumTesters == 0)
    return false;
  if (n < 0 && n >= maxNumTesters) {
    return false;
  } else {
    for (int i = 0; i < maxNumTesters; i++) {
      if (this->testers[i] != NULL && this->testers[i]->evaluate(n) == false) {
        return false;
      } else if (this->testers[i] != NULL &&
                 this->testers[i]->evaluate(n) == true) {
        c++;
      }
    }
  }

  if (c == currNumTesters) {
    return true;
  }

  return false;
}

int *TesterInterface::failedTests(int num) {
  int count = 0;

  for (int i = 0; i < maxNumTesters; i++) {
    if (testers[i] != NULL) {
      if (testers[i]->evaluate(num) == false) {
        count++;
      }
    }
  }

  int *ind = new int[count];

  if (count == 0) {
    return ind;
  } else {
    int c = 0;

    for (int i = 0; i < maxNumTesters; i++) {
      if (testers[i] != NULL) {
        if (testers[i]->evaluate(num) == false) {
          ind[c] = i;
          c++;
        }
      }
    }
  }

  return ind;
}

int TesterInterface::numberOfFailedTests(int num) {
  int count = 0;

  for (int i = 0; i < maxNumTesters; i++) {
    if (this->testers[i] != NULL && this->testers[i]->evaluate(num) == false) {
      count++;
    }
  }
  return count;
}

NumberTester *TesterInterface::operator[](int p) {
  if (p >= 0 && p < maxNumTesters) {
    if (testers[p] != NULL) {
      return testers[p];
    }
  }
  return NULL;
}

int TesterInterface::getCurrNumTesters() const { return this->currNumTesters; }

int TesterInterface::getMaxNumTesters() const { return this->maxNumTesters; }