#include "circularList.h"
//#include "linearStructure.h"
//#include <iostream>
using namespace std;

template <class T>
ostream &operator<<(ostream &myOut, CircularList<T> &myList) {
  myOut << "[";
  if (myList.tail == NULL) {
    myOut << "]";
    // cout<<"111111111111";
  } else if (myList.size() == 1) {
    // cout<<"size is 1";
    myOut << myList.tail->element;
    myOut << "]";
  } else {
    // cout<<"7777777777ahhhhhhhhhhhhhhh";
    Node<T> *myPointer = myList.tail->next;
    Node<T> *head = myList.tail->next;
    myList.tail->next = NULL;
    while (myPointer != NULL) {
      myOut << myPointer->element;
      if (myPointer->next != NULL)
        myOut << ",";
      myPointer = myPointer->next;
    }
    myOut << "]";
    myList.tail->next = head;
  }
  return myOut;
}

template <class T> CircularList<T>::CircularList() { tail = NULL; }

template <class T> CircularList<T>::CircularList(const CircularList<T> &other) {
  if (other.tail == NULL) {
    tail = NULL;
  } else {

    // setting tail to the same as the copy list
    T myTempData = other.tail->element;
    Node<T> *myNewNode = new Node<T>(myTempData);
    tail = myNewNode;
    // tail->next=tail;
    // checking if the other list is only one element to make completing the
    // circle easier
    if (other.size() == 1)
      tail->next = tail;
    else {
      // copying the rest of the nodes from the list
      Node<T> *myPointer = other.tail->next;
      Node<T> *myPrevious = myNewNode;
      while (myPointer != other.tail) {

        myTempData = myPointer->element;
        myNewNode = new Node<T>(myTempData);
        myPrevious->next = myNewNode;
        myPointer = myPointer->next;
        myPrevious = myPrevious->next;
      }
      myPrevious->next = tail;
    }
  }
}

template <class T>
CircularList<T> &CircularList<T>::operator=(const CircularList<T> &other) {
  Node<T> *myCopyFrom = other.tail;
  Node<T> *myCopyToo = tail;
  if (myCopyFrom == NULL) {
    tail = NULL; // check if this works or if we need to delete the nodes
    return *this;
  } else if (other.size() == 1) {
    tail = new Node<T>(other.tail->element);
    tail->next = tail;
    return *this;
  } else {
    if (tail == NULL) {
      tail = new Node<T>(other.tail->element);
      myCopyToo = tail;
      tail->next = tail;
    }
    while (myCopyFrom->next != other.tail) {
      if (myCopyFrom->element != myCopyToo->element)
        myCopyToo->element = myCopyFrom->element;

      if (myCopyFrom->next == other.tail)
        myCopyToo->next = tail;
      else if (myCopyFrom->next != other.tail && myCopyToo->next == tail) {
        myCopyToo->next = new Node<T>(1);
        myCopyToo->next->next = tail;
      }

      myCopyFrom = myCopyFrom->next;
      myCopyToo = myCopyToo->next;
    }
    myCopyToo->element = myCopyFrom->element;
  }
  return *this;
}

template <class T> CircularList<T> *CircularList<T>::clone() {
  CircularList<T> *myCircularList = new CircularList(*this);
  return myCircularList;
}

template <class T> CircularList<T>::~CircularList() {
  // cout<<"testing";
  if (tail) {
    Node<T> *myCurrent = tail->next;
    tail->next = NULL;
    tail = myCurrent;
    Node<T> *myNext;

    while (myCurrent != nullptr) {
      myNext = myCurrent->next;
      myCurrent->next = nullptr;
      delete myCurrent;
      myCurrent = myNext;
    }
    tail = NULL;
  }
}

template <class T> void CircularList<T>::insert(int index, T element) {
  // cout<<"7777777777ahhhhhhhhhhhhhhh";
  if ((tail == NULL) && (index == 0)) {
    tail = new Node<T>(element);
    tail->next = tail;
    // cout<<"first is success";
  } else if (tail == NULL && index != 0)
    throw "invalid index";
  // cout<<"1111111111111";
  else if (index < 0 || index > size()) {
    throw "invalid index";
    // cout<<"222222222";
  } else if (index == 0) {
    // cout<<"3333333333";
    Node<T> *myNewNode = new Node<T>(element);
    myNewNode->next = tail->next;
    tail->next = myNewNode;
  } else if (index == size()) {
    Node<T> *head = tail->next;
    Node<T> *myNewNode = NULL;
    myNewNode = new Node<T>(element);
    tail->next = myNewNode;
    myNewNode->next = head;
    tail = myNewNode;
  } else {

    Node<T> *myPointer = tail->next;
    Node<T> *myNewNode = NULL;
    for (int i = 0; i < index - 1; i++) {
      myPointer = myPointer->next;
    }

    myNewNode = new Node<T>(element);
    myNewNode->next = myPointer->next;
    myPointer->next = myNewNode;
  }
  // cout<<"end";
}

template <class T> T CircularList<T>::remove(int index) {

  if (index < 0 || index >= size())
    throw "empty structure";
  else if (index == 0) {
    T myPassData;
    if (size() != 1) {
      Node<T> *myPointer = tail->next->next;
      tail->next->next = NULL;
      myPassData = tail->next->element;
      delete tail->next;
      tail->next = myPointer;
      return myPassData;
    } else {
      myPassData = tail->element;
      tail->next = NULL;
      delete tail;
      tail = NULL;
      return myPassData;
    }

  } else {
    // converting to a linked list
    Node<T> *head = NULL;
    if (tail == NULL)
      head = NULL;
    else if (tail->next == tail) {
      head = tail;
      head->next = NULL;
    } else {
      head = tail->next;
      tail->next = NULL;
    }
    //=============end of conversion
    Node<T> *myPointer = head;
    Node<T> *myPrevious = NULL;
    for (int i = 0; i < index; i++) {
      myPrevious = myPointer;
      myPointer = myPointer->next;
    }
    T myPassData = myPointer->element;
    myPrevious->next = myPointer->next;
    myPointer->next = NULL;
    // delete myPointer; not sure if we need this
    // linking end of list to start to recreate circular linked list
    if (head != NULL) {
      Node<T> *myPointer = head;
      while (myPointer->next != NULL) {

        myPointer = myPointer->next;
      }
      myPointer->next = head;
      tail = myPointer;
    } else {
      tail = NULL;
    }
    // cout<<"end";
    return myPassData;
  }
}

template <class T> T CircularList<T>::get(int index) const {
  if (tail == NULL) {
    // cout<<"fuck";
    throw "empty structure";
  } else if (index < 0 || index >= size()) {
    throw "empty structure";
  } else {
    Node<T> *myPointer = tail->next;
    for (int i = 0; i < index; i++) {
      myPointer = myPointer->next;
    }
    return myPointer->element;
  }
}

template <class T> bool CircularList<T>::isEmpty() {
  if (tail == NULL)
    return true;
  else
    return false;
}

template <class T> void CircularList<T>::clear() { tail = NULL; }

template <class T> Node<T> *CircularList<T>::getLeader() {}

template <class T> ostream &CircularList<T>::print(ostream &os) {
  os << flush;
  // cout<<"here";
  os << "[";
  // cout<<"here";
  if (tail == NULL) {
    os << "]";
    // cout<<"111111111111";
  } else if (size() == 1) {
    // cout<<"size is 1";
    os << tail->element;
    os << "]";
  } else {
    // cout<<"7777777777ahhhhhhhhhhhhhhh";
    Node<T> *myPointer = tail->next;
    Node<T> *head = tail->next;
    tail->next = NULL;
    while (myPointer != NULL) {
      os << myPointer->element;
      if (myPointer->next != NULL)
        os << ",";
      myPointer = myPointer->next;
    }
    os << "]";
    tail->next = head;
  }

  return os;
}

template <class T> int CircularList<T>::size() const {

  int icount = 0;
  if (tail == NULL)
    return icount;
  Node<T> *head = tail->next;
  tail->next = NULL;
  Node<T> *myPointer = head;
  while (myPointer) {
    icount++;
    myPointer = myPointer->next;
  }
  tail->next = head;
  return icount;
}
