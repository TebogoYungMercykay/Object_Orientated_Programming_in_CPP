#include "MinusOperator.h"

template <typename T>
T MinusOperator<T>::operator()(T lhs, T rhs){
    return lhs-rhs;
}
template <typename T>
Operator<T>* MinusOperator<T>::clone(){
    return new MinusOperator();
}