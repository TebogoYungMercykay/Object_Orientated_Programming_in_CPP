#include "Calculator.h"
#include <cstddef>

template <class T>
Calculator<T>::Calculator(){
    valueStack = new Stack<T>();
    operatorStack = new Stack<Operator<T>*>();
}
template <class T>
void Calculator<T>::addValue(T val){
    valueStack->push(val);
}
template <class T>
Calculator<T>::~Calculator(){
    if(operatorStack) delete operatorStack;
    if(valueStack) delete valueStack;
}
template <class T>
void Calculator<T>::addOperator(Operator<T>* op){
    operatorStack->push(op->clone());
}
template <class T>
T Calculator<T>::removeValue(){
    if (valueStack->getTop() == NULL){
        return NULL;
    }
    return valueStack->pop()->getData();
}
template <class T>
Operator<T>* Calculator<T>::removeOperator(){
    if (operatorStack->getTop() == NULL){
        return NULL;
    }
    return operatorStack->pop()->getData();
}
template <class T>
int Calculator<T>::numValues(){
    return valueStack->size();
}
template <class T>
int Calculator<T>::numOperators(){
    return operatorStack->size();
}
template <class T>
T Calculator<T>::calculate(){
    T operatorVal;
    int size0 = valueStack->size();
    int size1 = operatorStack->size();
    if ((size1 < 1) || ((size0 - 1) != size1)){
        return NULL;
    }
    for(Operator<T>* operatorPtr = NULL ; operatorStack->getTop() != NULL; addValue(operatorVal)){
        T fVal = valueStack->pop()->getData();
        T sVal = valueStack->pop()->getData();
        operatorPtr = removeOperator();
        operatorVal = (*operatorPtr)(fVal, sVal);
    }
    return valueStack->getTop()->getData();
}