#include "PlusOperator.h"

template <typename T> T PlusOperator<T>::operator()(T lhs, T rhs) {
  T temp;
  temp = lhs + rhs;
  return temp;
}
template <typename T> Operator<T> *PlusOperator<T>::clone() {
  PlusOperator *temp;
  temp = new PlusOperator();
  return temp;
}