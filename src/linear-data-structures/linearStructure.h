//
// Created Tebogo YungMercyKay on 10/29/2020.
//

#ifndef ASSIGNMENT_4_LINEARSTRUCTURE_H
#define ASSIGNMENT_4_LINEARSTRUCTURE_H
#include <iostream>

using namespace std;

template <class T> class LinearStructure;

template <class T> ostream &operator<<(ostream &, LinearStructure<T> &);

template <class T> class LinearStructure {
public:
  friend ostream &operator<< <T>(ostream &os, LinearStructure<T> &l);
  virtual ~LinearStructure() {}
  virtual LinearStructure<T> *clone() = 0;
  virtual void insert(int index, T element) = 0;
  virtual T remove(int index) = 0;
  virtual T get(int index) const = 0;
  virtual bool isEmpty() = 0;
  virtual void clear() = 0;

protected:
  virtual ostream &print(ostream &os) = 0;
};
template <class T> ostream &operator<<(ostream &os, LinearStructure<T> &l) {
  l.print(os);
  return os;
}
#endif // ASSIGNMENT_4_LINEARSTRUCTURE_H
