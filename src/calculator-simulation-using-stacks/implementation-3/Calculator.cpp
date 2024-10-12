#include "Calculator.h"
#include <cstddef>

template <class T> Calculator<T>::Calculator() {
  Calculator<T>::valueStack = new Stack<T>();
  Calculator<T>::operatorStack = new Stack<Operator<T> *>();
}
template <class T> void Calculator<T>::addValue(T val) {
  Calculator<T>::valueStack->push(val);
}
template <class T> Calculator<T>::~Calculator() {
  bool E1 = Calculator<T>::operatorStack->isEmpty();
  bool E2 = Calculator<T>::valueStack->isEmpty();
  if (!E1 == true) {
    delete operatorStack;
  }
  if (!E2 == true) {
    delete valueStack;
  }
}
template <class T> void Calculator<T>::addOperator(Operator<T> *op) {
  Calculator<T>::operatorStack->push(op->clone());
}
template <class T> T Calculator<T>::removeValue() {
  if (Calculator<T>::valueStack->getTop() == NULL) {
    return NULL;
  }
  Node<T> *val = Calculator<T>::valueStack->pop();
  return val->getData();
}
template <class T> Operator<T> *Calculator<T>::removeOperator() {
  if (Calculator<T>::operatorStack->getTop() == NULL) {
    return NULL;
  }
  Node<Operator<T> *> *op = Calculator<T>::operatorStack->pop();
  return op->getData();
}
template <class T> int Calculator<T>::numValues() {
  return Calculator<T>::valueStack->size();
}
template <class T> int Calculator<T>::numOperators() {
  return Calculator<T>::operatorStack->size();
}
template <class T> T Calculator<T>::calculate() {
  int size0 = Calculator<T>::valueStack->size();
  int size1 = Calculator<T>::operatorStack->size();
  int size2 = size0 - 1;
  if (!(size1 >= 1) || (size2 != size1)) {
    return NULL;
  }
  while (this->operatorStack->getTop() != NULL) {
    T value1 = this->valueStack->pop()->getData();
    T value2 = this->valueStack->pop()->getData();
    Operator<T> *operator1 = this->removeOperator();
    T intermediate = operator1->operator()(value1, value2);
    this->addValue(intermediate);
  }
  return Calculator<T>::valueStack->getTop()->getData();
}