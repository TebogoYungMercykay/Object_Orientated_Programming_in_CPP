#include "MinusOperator.h"

template <class T>
T MinusOperator<T>::operator()(T lhs, T rhs){
    return lhs-rhs;
}
template <class T>
Operator<T>* MinusOperator<T>::clone(){
    return new MinusOperator();
}