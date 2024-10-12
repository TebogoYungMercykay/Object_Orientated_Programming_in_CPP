#include "MultiplyOperator.h"

template <typename T> T MultiplyOperator<T>::operator()(T lhs, T rhs) {
  T temp;
  temp = lhs * rhs;
  return temp;
}
template <typename T> Operator<T> *MultiplyOperator<T>::clone() {
  MultiplyOperator *temp;
  temp = new MultiplyOperator();
  return temp;
}