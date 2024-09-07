//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_QUEUE_H
#define ASSIGNMENT_4_QUEUE_H

#include "linearStructure.h"
#include "orderedContainer.h"

template <class T> class Queue : public OrderedContainer<T> {
public:
  Queue(LinearStructure<T> *c);
  Queue(const Queue<T> &other);
  Queue<T> &operator=(const Queue<T> &other);
  virtual ~Queue();
  virtual T remove();
  virtual T next();
  virtual void insert(T el);
  virtual void reverse();

protected:
  int front;
  int rear;
};

#endif // ASSIGNMENT_4_QUEUE_H
