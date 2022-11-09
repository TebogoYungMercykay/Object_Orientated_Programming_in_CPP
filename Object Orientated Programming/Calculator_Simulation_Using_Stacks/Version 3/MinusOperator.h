#ifndef MINUSOPERATOR_H
#define MINUSOPERATOR_H
#include "Operator.h"

template <typename T>
class MinusOperator: public Operator<T>
{
    private:
    public:
        T operator()(T lhs, T rhs);
        Operator<T>* clone();
};
#include "MinusOperator.cpp"
#endif