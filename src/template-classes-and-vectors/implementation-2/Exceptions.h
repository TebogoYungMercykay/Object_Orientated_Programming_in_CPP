#ifndef Exception_H
#define Exception_H
#include <sstream>

template <class E> class UndervaluedEx {
private:
  E *underVal;
  double sum;

public:
  UndervaluedEx(E *UnderVal1, double sum);
  E *getUndervalued() const;
  double getSum() const;
};
template <class E> class NotFoundEx {
private:
  E *missing;

public:
  NotFoundEx(E *mising1);
  E *getNotFound() const;
};
class UnauthorisedEx {};
class EmptyEx {};
class AboveWeightEx {
private:
  double weightDiff;

public:
  AboveWeightEx(double weightDiff1);
  double getDifference() const;
};
#include "Exceptions.cpp"
#endif