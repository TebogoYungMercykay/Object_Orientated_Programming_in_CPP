#include "Node.h"

template <typename T> Node<T>::Node(T d) {
  next = NULL;
  data = d;
}
template <typename T> void Node<T>::setNext(Node<T> *n) { next = n; }
template <typename T> T Node<T>::getData() {
  T temp;
  temp = data;
  return temp;
}
template <typename T> Node<T> *Node<T>::getNext() {
  Node<T> *temp;
  temp = next;
  return temp;
}