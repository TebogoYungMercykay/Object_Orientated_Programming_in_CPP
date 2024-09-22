#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

// SortList class Implementation here
template <class T> class SortList {
private:
  bool ascending;
  SortNode<T> *head;
  SortNode<T> *tail;

protected:
public:
  SortList(bool val);
  void add(SortNode<T> *val);
  SortNode<T> *remove(T val);
  void setAsc(bool val);
  void sort();
  SortNode<T> *getHead();
  std::string debug();
  std::string print();
};
#include "SortList.cpp"
#endif
