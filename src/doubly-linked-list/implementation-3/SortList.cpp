#include "SortList.h"
using namespace std;
#include <iostream>

template <typename T> SortList<T>::SortList(bool ascend) {
  ascending = ascend;
  head = NULL;
  tail = NULL;
}
template <typename T> string SortList<T>::print() {
  SortNode<T> *nodePtr = head;
  string str = "";
  string tempStr = ",";
  while (nodePtr) {
    str += nodePtr->print();
    if (nodePtr->next) {
      str = str + tempStr;
    }
    nodePtr = nodePtr->next;
  }
  return str;
}
template <typename T> SortNode<T> *SortList<T>::getHead() { return head; }
template <typename T> string SortList<T>::debug() {
  SortNode<T> *nodePtr = tail;
  string str = "";
  string tempStr = ",";
  while (nodePtr) {
    str += nodePtr->print();
    if (nodePtr->next) {
      str = str + tempStr;
    }
    nodePtr = nodePtr->prev;
  }
  return str;
}
template <typename T> void SortList<T>::add(SortNode<T> *Sort) {
  if (tail == NULL) {
    this->head = Sort;
    tail = Sort;
  } else {
    Sort->prev = tail;
    tail->next = Sort;
    tail = Sort;
  }
}
template <typename T> void SortList<T>::setAsc(bool a) {
  ascending = a;
  sort();
}
template <typename T> SortNode<T> *SortList<T>::remove(T val) {
  SortNode<T> *nodePtr = head;
  while (nodePtr && nodePtr->getValue() != val) {
    nodePtr = nodePtr->next;
  }
  if (nodePtr) {
    if (nodePtr != head && nodePtr != tail) {
      nodePtr->prev->next = nodePtr->next;
      nodePtr->next->prev = nodePtr->prev;
      nodePtr->prev = NULL;
      nodePtr->next = NULL;
    } else if (nodePtr == head && nodePtr == tail) {
      head = head->next;
      tail = tail->next;
    } else if (nodePtr == head) {
      head = head->next;
      head->prev = NULL;
      nodePtr->next = NULL;
    } else {
      tail = tail->prev;
      tail->next = NULL;
      nodePtr->prev = NULL;
    }
  }
  return nodePtr;
}
template <typename T> void SortList<T>::sort() {
  SortList<T> *nodePtrSorted = new SortList<T>(ascending);
  if (ascending) {
    while (head) {
      SortNode<T> *nodePtr;
      SortNode<T> *Small_nodePtr;
      nodePtr = head;
      Small_nodePtr = head;
      while (nodePtr && nodePtr->getValue()) {
        if (nodePtr->getValue() < Small_nodePtr->getValue()) {
          Small_nodePtr = nodePtr;
        }
        nodePtr = nodePtr->next;
      }
      T value_node = Small_nodePtr->getValue();
      Small_nodePtr = remove(value_node);
      nodePtrSorted->add(Small_nodePtr);
    }
  } else {
    while (head) {
      SortNode<T> *nodePtr;
      SortNode<T> *Large_nodePtr;
      nodePtr = head;
      Large_nodePtr = head;
      while (nodePtr && nodePtr->getValue()) {
        if (nodePtr->getValue() > Large_nodePtr->getValue()) {
          Large_nodePtr = nodePtr;
        }
        nodePtr = nodePtr->next;
      }
      T value_node = Large_nodePtr->getValue();
      Large_nodePtr = remove(value_node);
      nodePtrSorted->add(Large_nodePtr);
    }
  }

  head = nodePtrSorted->head;
  tail = nodePtrSorted->tail;
  delete nodePtrSorted;
  nodePtrSorted = NULL;
}