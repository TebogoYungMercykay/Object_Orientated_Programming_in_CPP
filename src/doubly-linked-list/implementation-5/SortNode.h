#ifndef SN_H
#define SN_H

#include <sstream>
#include <string>

// SortNode class implementation here
template <class T> class SortNode {
private:
protected:
  T value;

public:
  SortNode<T> *next;
  SortNode<T> *prev;
  SortNode(T val);
  std::string print();
  T getValue();
};
#include "SortNode.cpp"
#endif
