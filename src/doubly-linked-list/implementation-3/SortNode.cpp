#include "SortNode.h"
using namespace std;

template <typename T> SortNode<T>::SortNode(T val) {
  value = val;
  prev = NULL;
  next = NULL;
}
template <typename T> string SortNode<T>::print() {
  string val = "";
  stringstream ss;
  ss << value;
  ss >> val;
  return val;
}
template <typename T> T SortNode<T>::getValue() { return value; }