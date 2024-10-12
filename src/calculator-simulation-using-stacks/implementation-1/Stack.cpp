#include "Stack.h"

template <typename T> Stack<T>::Stack() { top = NULL; }
template <typename T> Stack<T>::~Stack() {
  Node<T> *temp = top;
  Node<T> *nextNode = NULL;
  while (temp != NULL) {
    nextNode = temp->getNext();
    delete temp;
    temp = nextNode;
  }
}
template <typename T> void Stack<T>::push(T data) {
  Node<T> *nodePtr;
  nodePtr = new Node<T>(data);
  nodePtr->setNext(top);
  top = nodePtr;
}
template <typename T> Node<T> *Stack<T>::pop() {
  Node<T> *temp = top;
  if (temp == NULL) {
    // Do nothing
    return NULL;
  } else {
    Node<T> *temp = top;
    top = top->getNext();
  }
  return temp;
}
template <typename T> Node<T> *Stack<T>::getTop() {
  Node<T> *temp = top;
  if (temp == NULL) {
    // Do nothing
    return NULL;
  }
  return temp;
}
template <typename T> int Stack<T>::size() {
  int sizee = 0;
  Node<T> *temp = top;
  while (temp != NULL) {
    sizee++;
    temp = temp->getNext();
  }
  return sizee;
}
template <typename T> bool Stack<T>::isEmpty() {
  if (top == NULL) {
    return true;
  }
  return false;
}
template <typename T> Stack<T> *Stack<T>::reverse() {
  Stack<T> *store = new Stack<T>();
  Stack<T> *temp = new Stack<T>();
  store->top = top;
  while (store->top != NULL) {
    T dataTemp = store->pop()->getData();
    temp->push(dataTemp);
  }
  return temp;
}
template <typename T> bool Stack<T>::contains(T data) {
  Node<T> *temp = top;
  while (temp != NULL) {
    if (temp->getData() == data) {
      return true;
    }
    temp = temp->getNext();
  }
  return false;
}