//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_PRIORITYQUEUE_H
#define ASSIGNMENT_4_PRIORITYQUEUE_H


#include "queue.h"
#include "linearStructure.h"

template<class T>
class PriorityQueue : public Queue<T>
{
public:
    PriorityQueue(LinearStructure<T>* c);
    PriorityQueue(const PriorityQueue<T>& other);
    virtual PriorityQueue<T>& operator=(const PriorityQueue<T>& other);
    virtual ~PriorityQueue();
    virtual void insert(T el);
    virtual void reverse();

private:
    bool ascend;
};


#endif //ASSIGNMENT_4_PRIORITYQUEUE_H
