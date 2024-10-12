#include "Operator.h"

template <typename T> Operator<T>::Operator() {}
template <typename T> T Operator<T>::operator()(T lhs, T rhs) { return 0; }
template <typename T> Operator<T> *Operator<T>::clone() { return NULL; }
template <typename T> Operator<T>::~Operator() {}