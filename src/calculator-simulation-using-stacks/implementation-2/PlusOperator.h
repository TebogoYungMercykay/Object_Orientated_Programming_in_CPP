#ifndef PLUSOPERATOR_H
#define PLUSOPERATOR_H
#include "Operator.h"

template <typename T> class PlusOperator : public Operator<T> {
private:
public:
  T operator()(T lhs, T rhs);
  Operator<T> *clone();
};
#include "PlusOperator.cpp"
#endif