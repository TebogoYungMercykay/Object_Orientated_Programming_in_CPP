//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_CIRCULARLIST_H
#define ASSIGNMENT_4_CIRCULARLIST_H

#include "linearStructure.h"
#include "node.h"

template <class T> class CircularList;

template <class T> ostream &operator<<(ostream &, CircularList<T> &);

template <class T> class CircularList : public LinearStructure<T> {
public:
  friend ostream &operator<< <T>(ostream &, CircularList<T> &);
  CircularList();
  CircularList(const CircularList<T> &other);
  CircularList<T> &operator=(const CircularList<T> &other);
  virtual CircularList<T> *clone();
  virtual ~CircularList();
  virtual void insert(int index, T element);
  virtual T remove(int index);
  virtual T get(int index) const;
  virtual bool isEmpty();
  virtual void clear();
  Node<T> *getLeader();

protected:
  ostream &print(ostream &os);

private:
  int size() const;
  Node<T> *tail;
};

#endif // ASSIGNMENT_4_CIRCULARLIST_H
