#include "MultiplyOperator.h"

template <typename T> T MultiplyOperator<T>::operator()(T lhs, T rhs) {
  return lhs * rhs;
}
template <typename T> Operator<T> *MultiplyOperator<T>::clone() {
  return new MultiplyOperator();
}