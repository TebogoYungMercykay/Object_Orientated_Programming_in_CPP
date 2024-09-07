//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_DYNAMICARRAY_H
#define ASSIGNMENT_4_DYNAMICARRAY_H

#include "linearStructure.h"

template <class T> class DynamicArray;

template <class T> ostream &operator<<(ostream &, DynamicArray<T> &);

template <class T> class DynamicArray : public LinearStructure<T> {
public:
  friend ostream &operator<< <T>(ostream &, DynamicArray<T> &);
  DynamicArray(int s);
  DynamicArray(const DynamicArray<T> &other);
  DynamicArray<T> &operator=(const DynamicArray<T> &other);
  virtual DynamicArray<T> *clone();
  virtual ~DynamicArray();
  virtual void insert(int index, T element);
  virtual T remove(int index);
  virtual T get(int index) const;
  virtual bool isEmpty();
  virtual void clear();

protected:
  ostream &print(ostream &os);

private:
  void resize(int howMuch);
  T **elements;
  int size;
  int numElements;
};

#endif // ASSIGNMENT_4_DYNAMICARRAY_H
