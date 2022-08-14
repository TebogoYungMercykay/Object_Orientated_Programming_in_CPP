//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_ORDEREDCONTAINER_H
#define ASSIGNMENT_4_ORDEREDCONTAINER_H

#include "linearStructure.h"

template<class T>
class OrderedContainer
{

public:
    OrderedContainer(LinearStructure<T>* c);
    OrderedContainer(const OrderedContainer<T>& other);
    virtual OrderedContainer<T>& operator=(const OrderedContainer<T>& other);
    virtual ~OrderedContainer();
    virtual T remove() = 0;
    virtual T next() = 0;
    virtual void insert(T el) = 0;
    virtual bool isEmpty();
    virtual void reverse() = 0;
    virtual LinearStructure<T>* getImplementation();

protected:
    LinearStructure<T>* dataStructure;
};


#endif //ASSIGNMENT_4_ORDEREDCONTAINER_H
