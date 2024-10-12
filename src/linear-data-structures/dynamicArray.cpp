#include "dynamicArray.h"
using namespace std;

template <class T>
ostream &operator<<(ostream &myOutput, DynamicArray<T> &myArray) {

  myOutput << '[';

  for (int i = 0; i < (myArray.size) - 1; i++) {
    if (myArray.elements[i] == NULL) {
      myOutput << '*';
    } else
      myOutput << myArray.elements[i][0];
    myOutput << ",";
  }
  if (myArray.elements[myArray.size - 1] == NULL)
    myOutput << '*';
  else
    myOutput << myArray.elements[myArray.size - 1][0];
  myOutput << "]";

  return myOutput;
}

template <class T> DynamicArray<T>::DynamicArray(int s) {

  size = s;
  numElements = 0;
  elements = new T *[size];
  for (int i = 0; i < s; i++) {
    elements[i] = new T[1];
  }
  for (int i = 0; i < size; i++)
    elements[i] = NULL;
}

template <class T> DynamicArray<T>::DynamicArray(const DynamicArray<T> &other) {
  size = other.size;
  numElements = other.numElements;
  elements = new T *[size];
  for (int i = 0; i < size; i++) {
    if (other.elements[i] == NULL)
      elements[i] = NULL;
    else {
      elements[i] = new T[1];
      elements[i][0] = other.elements[i][0];
    }
    // cout<<"the element just copied is" <<other.elements[i][0];
  }
}

template <class T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other) {

  resize(other.size);

  numElements = other.numElements;

  for (int i = 0; i < size; i++) {
    if (other.elements[i] == NULL)
      elements[i] = NULL;
    else {
      elements[i] = new T[1];
      elements[i][0] = other.elements[i][0];
    }
  }
  return *this;
}

template <class T> DynamicArray<T> *DynamicArray<T>::clone() {
  DynamicArray<T> *myCopy = new DynamicArray(*this);

  return myCopy;
}

template <class T> DynamicArray<T>::~DynamicArray() {
  // cout<<"shissssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssst";
  for (int i = 0; i < size; i++)
    delete[] elements[i];
  delete[] elements;
}

template <class T> void DynamicArray<T>::insert(int index, T element) {

  // cout<<"123123hhhhhhhhhhhhhhh";
  if (index < 0) {
    // cout<<"1\n";
  } else if (index + 1 > size) {
    // cout<<"2\n";
    resize(index + 1);
  }
  if (elements[index] == NULL) {
    elements[index] = new T[1];
    elements[index][0] = element;
    // cout<<"the element im adding during insert is"<<element;
    numElements++;
  } else {
    if (elements[index] != NULL && elements[size - 1] != NULL) {
      resize(size + 1);
    }

    if (elements[index] != NULL && elements[size - 1] == NULL) {
      elements[size - 1] = new T
          [1]; ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      for (int i = size - 1; i > index; i--) {
        if (elements[i - 1] == NULL) {
          elements[i] = NULL;
        } else {
          if (elements[i] == NULL)
            elements[i] = new T[1];
          elements[i][0] = elements[i - 1][0];
        }
      }
      elements[index][0] = element;
      numElements++;
    }
  }
}

template <class T> T DynamicArray<T>::remove(int index) {

  // cout<<"size is"<<size<<endl;
  if (elements[index] == NULL) {

    throw "empty structure";
  }
  T myTemp = elements[index][0];
  if (index == (size - 1)) {
    elements[size - 1] = NULL;
  } else {
    for (int i = index; i < size - 1; i++) {
      if (elements[i + 1] == NULL) {
        elements[i] = NULL;
      } else if (elements[i] == NULL) {
        elements[i] = new T[1];
        elements[i][0] = elements[i + 1][0];
      } else {
        elements[i][0] = elements[i + 1][0];
      }
    }
    if (elements[size - 1] != NULL)
      elements[size - 1] = NULL;
  }

  numElements--;
  return myTemp;
}

template <class T> T DynamicArray<T>::get(int index) const {
  if (elements[index] == NULL)
    throw "empty structure";
  T myTemp = elements[index][0];

  return myTemp;
}

template <class T> bool DynamicArray<T>::isEmpty() {
  if (numElements == 0)
    return true;
  else
    return false;
}

template <class T> void DynamicArray<T>::clear() {
  for (int i = 0; i < size; i++)
    elements[i] = NULL;
  numElements = 0;
}

template <class T> ostream &DynamicArray<T>::print(ostream &os) {

  os << '[';

  for (int i = 0; i < (size)-1; i++) {
    if (elements[i] == NULL) {
      os << '*';
    } else
      os << elements[i][0];
    os << ",";
  }
  if (elements[size - 1] == NULL)
    os << '*';
  else
    os << elements[size - 1][0];
  os << "]";

  return os;
}

template <class T> void DynamicArray<T>::resize(int howMuch) {

  T **myTemp = NULL;

  if (howMuch > size) {
    // cout<<"hi";
    myTemp = new T *[howMuch];
    for (int i = 0; i < howMuch; i++) {
      // myTemp[i]=new T[1];
      myTemp[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
      if (elements[i] != NULL) {
        myTemp[i] = new T[1];
        myTemp[i][0] = elements[i][0];
      }
    }
  }

  else {
    myTemp = new T *[size];
    for (int i = 0; i < size; i++) {

      myTemp[i] = NULL;
    }
    for (int i = 0; i < size; i++) {
      if (elements[i] != NULL) {
        myTemp[i] = new T[1];
        myTemp[i][0] = elements[i][0];
      }
    }
  }

  size = howMuch;

  elements = new T *[howMuch];
  for (int i = 0; i < howMuch; i++) {
    elements[i] = new T[1];
    if (myTemp[i] != NULL) {
      elements[i] = new T[1];
      elements[i][0] = myTemp[i][0];
    } else
      elements[i] = NULL;

    // cout<<elements[i][0];
  }
}
