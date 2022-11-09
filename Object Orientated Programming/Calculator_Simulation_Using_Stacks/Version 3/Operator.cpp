#include "Operator.h"

template <class T>
Operator<T>::Operator(){

}
template <class T>
T Operator<T>::operator()(T lhs, T rhs){
    return 0;
}
template <class T>
Operator<T>* Operator<T>::clone(){
    return NULL;
}
template <class T>
Operator<T>::~Operator(){

}