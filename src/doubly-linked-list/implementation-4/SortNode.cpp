#include "SortNode.h"
#include <sstream>
#include <string>
using namespace std;

template <class T> SortNode<T>::SortNode(T val) {
  SortNode<T>::value = val;
  SortNode<T>::next = NULL;
  SortNode<T>::prev = NULL;
}
template <class T> std::string SortNode<T>::print() {
  std::stringstream tStream;
  tStream << value;
  std::string t;
  tStream >> t;
  return t;
}
template <class T> T SortNode<T>::getValue() { return SortNode<T>::value; }