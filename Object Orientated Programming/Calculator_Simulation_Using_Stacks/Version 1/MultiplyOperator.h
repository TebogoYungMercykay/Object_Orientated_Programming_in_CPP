#ifndef MULTIPLYOPERATOR_H
#define MULTIPLYOPERATOR_H
#include "Operator.h"

template <typename T>
class MultiplyOperator: public Operator<T>
{
    public:
        T operator()(T lhs, T rhs);
        Operator<T>* clone();
};
#include "MultiplyOperator.cpp"
#endif