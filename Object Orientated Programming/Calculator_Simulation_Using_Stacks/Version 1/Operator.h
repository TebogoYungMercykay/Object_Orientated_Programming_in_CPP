#ifndef OPERATOR_H
#define OPERATOR_H

template <typename T>
class Operator
{
    public:
        Operator();
        virtual T operator()(T lhs, T rhs) = 0;
        virtual Operator<T>* clone() = 0;
        virtual ~Operator();
};
#include "Operator.cpp"
#endif