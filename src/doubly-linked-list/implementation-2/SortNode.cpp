#include "SortNode.h"
#include <sstream>
#include <string>
using namespace std;

template <class T> SortNode<T>::SortNode(T val) {
  this->value = val;
  this->next = this->prev = NULL;
}
template <class T> std::string SortNode<T>::print() {
  std::string temp("");
  std::stringstream temp_ss;
  temp_ss << this->value;
  temp_ss >> temp;
  return temp;
}
template <class T> T SortNode<T>::getValue() { return this->value; }