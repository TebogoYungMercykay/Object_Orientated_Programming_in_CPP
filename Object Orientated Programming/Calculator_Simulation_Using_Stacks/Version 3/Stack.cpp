#include "Stack.h"

template <class T>
Stack<T>::Stack(){
    Stack<T>::top = NULL;
}
template <class T>
Stack<T>::~Stack(){
    if (Stack<T>::getTop() != NULL){
        Node<T>* nextPtr = NULL;
        for (Node<T>* nodePtr = Stack<T>::getTop();
             nodePtr != NULL; nextPtr = nodePtr->getNext(), 
             delete nodePtr, nodePtr = nextPtr);
    }
}
template <class T>
int Stack<T>::size(){
    if (Stack<T>::getTop() != NULL){
        int total = 0;
        for (Node<T>* nodePtr = Stack<T>::getTop();
             nodePtr != NULL;
             total = total + 1, nodePtr = nodePtr->getNext());
        return total;
    }
    return 0;
}
template <class T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(getTop());
    top = newNode;
}
template <class T>
Node<T>* Stack<T>::pop(){
    if (Stack<T>::getTop() != NULL){
        Node<T>* nodePtr = Stack<T>::getTop();
        Stack<T>::top = Stack<T>::getTop()->getNext();
        return nodePtr;
    }
    return NULL;
}
template <class T>
bool Stack<T>::contains(T data){
    if (Stack<T>::getTop() != NULL){
        for (Node<T>* nodePtr = Stack<T>::getTop();
             nodePtr != NULL; nodePtr = nodePtr->getNext()){
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
    for (reversePtr->top = Stack<T>::getTop();
         reversePtr->getTop() != NULL;
         dataTemp = reversePtr->pop()->getData(), nodePtr->push(dataTemp));
    return nodePtr;
}
template <class T>
bool Stack<T>::isEmpty(){
    if(Stack<T>::top == NULL){
        return true;
    }
    return false;
}
template <class T>
Node<T>* Stack<T>::getTop(){
    return Stack<T>::top;
}