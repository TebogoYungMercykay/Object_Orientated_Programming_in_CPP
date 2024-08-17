#include "Plane.h"
using namespace std;

template <class T> Plane<T>::Plane(double maxWeight) {
  this->maxWeight = maxWeight;
}
template <class T> void Plane<T>::add(T *var) {
  double weightTotal = var->getWeight();
  const int vecSize = this->cargo.size();

  for (int i = 0; i < vecSize; i++) {
    if (!(this->cargo[i] == NULL)) {
      weightTotal += this->cargo[i]->getWeight();
    }
  }
  if (this->maxWeight >= weightTotal) {
    this->cargo.push_back(var);
  } else {
    double weightTotalDiff = weightTotal - this->maxWeight;
    throw AboveWeightEx(weightTotalDiff);
  }
}
template <class T> void Plane<T>::remove(T *var) {
  bool FoundEx = false;
  const int vecSize = this->cargo.size();
  int index = -1;
  if (this->cargo.empty() != false) {
    throw EmptyEx();
  }
  for (int i = 0; i < vecSize; i++) {
    if (this->cargo[i] != var) {
      continue;
    } else {
      FoundEx = true;
      index = i;
      break;
    }
  }
  if (FoundEx) {
    this->cargo.erase(this->cargo.begin() + index);
  } else {
    throw NotFoundEx<T>(var);
  }
}
template <class T> double Plane<T>::calculateValue() {
  if (this->cargo.empty() != false) {
    throw EmptyEx();
  } else {
    const int vecSize = this->cargo.size();
    double *leastValues = new double[vecSize];
    double total = 0, tmpVal = -1;
    int index2 = -1, index3 = -1;
    for (int i = 0; i < vecSize; i++) {
      if (!this->cargo[i]) {
        leastValues[i] = 34555;
      } else {
        leastValues[i] = this->cargo[i]->getValue();
        total += this->cargo[i]->getValue();
      }
    }
    int tempVecSize = vecSize - 1;
    for (int i = 0; i < tempVecSize; i++) {
      for (int k = tempVecSize; k > i; --k) {
        if (leastValues[k - 1] > leastValues[k]) {
          tmpVal = leastValues[k - 1];
          leastValues[k - 1] = leastValues[k];
          leastValues[k] = tmpVal;
        }
      }
    }
    for (int i = 0; i < vecSize; i++) {
      if (!this->cargo[i]) {
        continue;
      } else {
        if (this->cargo[i]->getValue() > leastValues[0]) {
          continue;
        } else {
          index2 = i;
          break;
        }
      }
    }
    for (int i = 0; i < vecSize; i++) {
      if (!this->cargo[i]) {
        continue;
      } else {
        if (this->cargo[i]->getValue() <= leastValues[0]) {
          continue;
        } else {
          index3 = i;
          break;
        }
      }
    }
    for (int i = 0; i < vecSize; i++) {
      bool var1 =
          (this->cargo[index2]->getValue() < this->cargo[i]->getValue() &&
           this->cargo[index3]->getValue() > this->cargo[i]->getValue());
      if (var1) {
        index3 = i;
      }
    }
    double var2 = (this->cargo[index3]->getValue()) / 2;
    if (var2 > this->cargo[index2]->getValue()) {
      throw UndervaluedEx<T>(this->cargo[index2],
                             total - this->cargo[index2]->getValue());
    }
    return total;
  }
  return 0;
}

template <> double Plane<SecretCargo>::calculateValue() {
  if (this->cargo.empty() != false) {
    throw EmptyEx();
  } else {
    throw UnauthorisedEx();
  }
}
template <class T> string Plane<T>::getDescription() {
  const int vecSize = this->cargo.size();
  if (this->cargo.empty() != false) {
    throw EmptyEx();
  } else {
    string val = "";
    for (int k = 0; k < vecSize; k++) {
      if (this->cargo[k]) {
        val += this->cargo[k]->describe() + "\n";
      }
    }
    return val.substr(vecSize - this->cargo.size(), val.length() - 1);
  }
  return "";
}

template <> string Plane<SecretCargo>::getDescription() {
  if (this->cargo.empty() != false) {
    throw EmptyEx();
  } else {
    throw UnauthorisedEx();
  }
}
template <class T> Plane<T>::~Plane() { cargo.clear(); }