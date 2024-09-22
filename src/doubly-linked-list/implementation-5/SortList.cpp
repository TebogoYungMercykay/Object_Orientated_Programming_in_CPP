#include "SortList.h"
#include <iostream>
using namespace std;

template <typename T> SortList<T>::SortList(bool mValue) : ascending(mValue) {
  SortList<T>::tail = NULL, head = NULL;
}
template <typename T> void SortList<T>::add(SortNode<T> *mValue) {
  if (SortList<T>::tail) {
    mValue->prev = SortList<T>::tail;
    SortList<T>::tail->next = mValue;
    SortList<T>::tail = mValue;
  } else {
    SortList<T>::tail = mValue;
    SortList<T>::head = mValue;
  }
}
template <typename T> void SortList<T>::setAsc(bool mValue) {
  SortList<T>::ascending = mValue;
  SortList<T>::sort();
}
template <typename T> std::string SortList<T>::debug() {
  std::string temp_string("");
  for (SortNode<T> *jNode = SortList<T>::tail; jNode;) {
    temp_string += jNode->print() + ",";
    jNode = jNode->prev;
  }
  return temp_string.substr(0, temp_string.length() - 1);
}
template <typename T> std::string SortList<T>::print() {
  std::string temp_string("");
  for (SortNode<T> *jNode = SortList<T>::head; jNode;) {
    temp_string += jNode->print() + ",";
    jNode = jNode->next;
  }
  return temp_string.substr(0, temp_string.length() - 1);
}
template <typename T> SortNode<T> *SortList<T>::getHead() {
  return SortList<T>::head;
}
template <typename T> SortNode<T> *SortList<T>::remove(T mValue) {
  SortNode<T> *jNode = SortList<T>::head;
  bool b0 = jNode != NULL && jNode->getValue() != mValue;
  while (b0) {
    jNode = jNode->next;
    b0 = jNode != NULL && jNode->getValue() != mValue;
  }
  if (jNode) {
    bool b1 = jNode == SortList<T>::head, b2 = jNode == SortList<T>::tail;
    bool b3 = !b1, b4 = !b2;
    if (b1 || b2) {
      if (b1 && b2) {
        SortList<T>::head = SortList<T>::head->next;
        SortList<T>::tail = SortList<T>::tail->next;
      } else if (b2) {
        SortList<T>::tail = SortList<T>::tail->prev;
        SortList<T>::tail->next = jNode->prev = NULL;
      } else if (b1) {
        SortList<T>::head = SortList<T>::head->next;
        SortList<T>::head->prev = jNode->next = NULL;
      }
    } else if (b3 && b4) {
      jNode->prev->next = jNode->next;
      jNode->next->prev = jNode->prev;
      jNode->prev = jNode->next = NULL;
    }
  }
  return jNode;
}
template <typename T> void SortList<T>::sort() {
  SortList<T> *jList;
  jList = new SortList<T>(SortList<T>::ascending);
  if (SortList<T>::ascending) {
    for (; SortList<T>::head;) {
      SortNode<T> *jNode;
      SortNode<T> *jSort;
      jSort = jNode = SortList<T>::head;
      while (jNode) {
        T b1 = jNode->getValue(), b2 = jSort->getValue();
        bool b3 = (b1 < b2);
        if (b3) {
          jSort = jNode;
        }
        jNode = jNode->next;
      }
      jSort = SortList<T>::remove(jSort->getValue());
      jList->add(jSort);
    }
  } else {
    for (; SortList<T>::head;) {
      SortNode<T> *jNode;
      SortNode<T> *jSort;
      jSort = jNode = SortList<T>::head;
      while (jNode) {
        T b1 = jNode->getValue(), b2 = jSort->getValue();
        bool b3 = (b1 > b2);
        if (b3) {
          jSort = jNode;
        }
        jNode = jNode->next;
      }
      jSort = SortList<T>::remove(jSort->getValue());
      jList->add(jSort);
    }
  }
  SortList<T>::tail = jList->tail;
  SortList<T>::head = jList->head;
  delete jList;
  jList = NULL;
}