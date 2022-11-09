#include "PlusOperator.h"

template <typename T>
T PlusOperator<T>::operator()(T lhs, T rhs){
    return lhs+rhs;
}
template <typename T>
Operator<T>* PlusOperator<T>::clone(){
    return new PlusOperator();
}