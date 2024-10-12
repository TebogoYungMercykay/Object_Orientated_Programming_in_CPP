#include "Calculator.h"
#include <cstddef>

template <typename T> Calculator<T>::Calculator() {
  Stack<T> *temp;
  temp = new Stack<T>();
  valueStack = temp;
  Stack<Operator<T> *> *temp1;
  temp1 = new Stack<Operator<T> *>();
  operatorStack = temp1;
}
template <typename T> void Calculator<T>::addOperator(Operator<T> *op) {
  if (op != NULL) {
    operatorStack->push(op->clone());
  }
}
template <typename T> void Calculator<T>::addValue(T val) {
  valueStack->push(val);
}
template <typename T> Calculator<T>::~Calculator() {
  if (operatorStack != NULL && !operatorStack->isEmpty()) {
    delete operatorStack;
  }
  if (valueStack != NULL && !valueStack->isEmpty()) {
    delete valueStack;
  }
}
template <typename T> T Calculator<T>::removeValue() {
  T temp;
  if (valueStack->getTop() == NULL) {
    return NULL;
  }
  temp = valueStack->pop()->getData();
  return temp;
}
template <typename T> Operator<T> *Calculator<T>::removeOperator() {
  Operator<T> *temp;
  if (operatorStack->getTop() == NULL) {
    return NULL;
  }
  temp = operatorStack->pop()->getData();
  return temp;
}
template <typename T> int Calculator<T>::numValues() {
  int temp = valueStack->size();
  return temp;
}
template <typename T> int Calculator<T>::numOperators() {
  int temp = operatorStack->size();
  return temp;
}
template <typename T> T Calculator<T>::calculate() {
  if ((operatorStack->size() < 1) ||
      ((valueStack->size() - 1) != operatorStack->size())) {
    return NULL;
  }
  while (operatorStack->getTop() != NULL) {
    T fVal = valueStack->pop()->getData();
    T sVal = valueStack->pop()->getData();
    Operator<T> *remOP = removeOperator();
    T op_val = remOP->operator()(fVal, sVal);
    addValue(op_val);
  }
  return valueStack->getTop()->getData();
}