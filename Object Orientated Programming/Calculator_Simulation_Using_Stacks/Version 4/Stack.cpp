#include "Stack.h"

template <class T>
Stack<T>::Stack(){
    top = NULL;
}
template <class T>
bool Stack<T>::isEmpty(){
    return (top == NULL);
}
template <class T>
Node<T>* Stack<T>::getTop(){
    return top;
}
template <class T>
int Stack<T>::size(){
    if (top != NULL){
        int total = 0;
        for(Node<T>* nodePtr = top; nodePtr != NULL; nodePtr = nodePtr->getNext()){
            total++;
        }
        return total;
    }
    return 0;
}
template <class T>
Stack<T>::~Stack(){
    if (top != NULL){
        Node<T>* nextPtr = NULL;
        for(Node<T>* nodePtr = top; nodePtr != NULL; nodePtr = nextPtr){
            nextPtr = nodePtr->getNext();
            delete nodePtr;
        }
    }
}
template <class T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(top);
    top = newNode;
}
template <class T>
Node<T>* Stack<T>::pop(){
    if (top != NULL){
        Node<T>* nodePtr = top;
        top = top->getNext();
        return nodePtr;
    }
    return NULL;
}
template <class T>
bool Stack<T>::contains(T data){
    if (top != NULL){
        for(Node<T>* nodePtr = top; nodePtr != NULL; nodePtr = nodePtr->getNext()){
            if (nodePtr->getData() == data){
                return true;
            }
        }
    }
    return false;
}
template <class T>
Stack<T>* Stack<T>::reverse(){
    Stack<T>* reversePtr = new Stack<T>();
    Stack<T>* nodePtr = new Stack<T>();
    T dataTemp;
    for(reversePtr->top = top; reversePtr->getTop() != NULL; nodePtr->push(dataTemp)){
        dataTemp = reversePtr->pop()->getData();
    }
    return nodePtr;
}