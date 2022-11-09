#include "MinusOperator.h"

template <typename T>
T MinusOperator<T>::operator()(T lhs, T rhs){
    T temp;
    temp = lhs-rhs;
    return temp;
}
template <typename T>
Operator<T>* MinusOperator<T>::clone(){
    MinusOperator* temp;
    temp = new MinusOperator();
    return temp;
}