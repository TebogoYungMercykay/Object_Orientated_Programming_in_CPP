#include "Calculator.h"
#include <cstddef>

template <typename T> Calculator<T>::Calculator() {
  this->valueStack = new Stack<T>();
  this->operatorStack = new Stack<Operator<T> *>();
}
template <typename T> Calculator<T>::~Calculator() {
  if (!this->operatorStack->isEmpty()) {
    delete this->operatorStack;
  }
  if (!this->valueStack->isEmpty()) {
    delete this->valueStack;
  }
}
template <typename T> void Calculator<T>::addValue(T val) {
  this->valueStack->push(val);
}
template <typename T> void Calculator<T>::addOperator(Operator<T> *op) {
  this->operatorStack->push(op->clone());
}
template <typename T> T Calculator<T>::removeValue() {
  if (valueStack->getTop() == NULL) {
    return NULL;
  }
  return this->valueStack->pop()->getData();
}
template <typename T> Operator<T> *Calculator<T>::removeOperator() {
  if (operatorStack->getTop() == NULL) {
    return NULL;
  }
  return this->operatorStack->pop()->getData();
}
template <typename T> int Calculator<T>::numValues() {
  return this->valueStack->size();
}
template <typename T> int Calculator<T>::numOperators() {
  return this->operatorStack->size();
}
template <typename T> T Calculator<T>::calculate() {
  if (this->operatorStack->size() < 1) {
    return NULL;
  } else if ((this->valueStack->size() - 1) != this->operatorStack->size()) {
    return NULL;
  }
  while (this->operatorStack->getTop() != NULL) {
    T firstValue = this->valueStack->pop()->getData();
    T secondValue = this->valueStack->pop()->getData();
    Operator<T> *appropriateOperator = this->removeOperator();
    T intermediate = appropriateOperator->operator()(firstValue, secondValue);
    this->addValue(intermediate);
  }
  return this->valueStack->getTop()->getData();
}