#ifndef SN_H
#define SN_H

#include <sstream>
#include <string>

// SortNode class implementation here
template <class T> class SortNode {
public:
  // SortNode Pointers
  SortNode<T> *next;
  SortNode<T> *prev;
  // SortNode Member functions
  SortNode(T val);
  std::string print();
  T getValue();

protected:
  T value;

private:
};
#include "SortNode.cpp"
#endif
