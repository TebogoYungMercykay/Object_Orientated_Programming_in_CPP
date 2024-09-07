//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_STACK_H
#define ASSIGNMENT_4_STACK_H

#include "linearStructure.h"
#include "orderedContainer.h"

template <class T> class Stack : public OrderedContainer<T> {
public:
  Stack(LinearStructure<T> *c);
  Stack(const Stack<T> &other);
  Stack<T> &operator=(const Stack<T> &other);
  virtual ~Stack();
  virtual T remove();
  virtual T next();
  virtual void insert(T el);
  virtual void reverse();

private:
  int stackTop;
};

#endif // ASSIGNMENT_4_STACK_H
