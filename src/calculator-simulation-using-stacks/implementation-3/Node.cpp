#include "Node.h"

template <class T> Node<T>::Node(T Data) {
  Node<T>::data = Data;
  Node<T>::next = NULL;
}
template <class T> T Node<T>::getData() { return Node<T>::data; }
template <class T> Node<T> *Node<T>::getNext() { return Node<T>::next; }
template <class T> void Node<T>::setNext(Node<T> *ptr) { Node<T>::next = ptr; }