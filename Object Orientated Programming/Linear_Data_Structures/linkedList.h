//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_LINKEDLIST_H
#define ASSIGNMENT_4_LINKEDLIST_H


#include "linearStructure.h"
#include "node.h"

template<class T>
class LinkedList;

template<class T>
ostream& operator<<(ostream&,LinkedList<T>&);

template<class T>
class LinkedList : public LinearStructure<T>
{
public:
    friend ostream& operator<< <T>(ostream&,LinkedList<T>&);
    LinkedList();
    LinkedList(const LinkedList<T>& other);
    LinkedList<T>& operator=(const LinkedList<T>& other);
    virtual LinkedList<T>* clone();
    virtual ~LinkedList();
    virtual void insert(int index, T element);
    virtual T remove(int index);
    virtual T get(int index) const;
    virtual bool isEmpty();
    virtual void clear();
    Node<T>* getLeader();

protected:
    ostream& print(ostream& os);

private:
    int size() const;
    Node<T>* head;
};


#endif //ASSIGNMENT_4_LINKEDLIST_H
