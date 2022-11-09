#include "Stack.h"

template <typename T>
Stack<T>::Stack(){
    this->top = NULL;
}
template <typename T>
Stack<T>::~Stack(){
    if(top!=NULL){
        Node<T>* temp = top;
        Node<T>* nextNode;
        while(temp){
            nextNode = temp->getNext();
            delete temp;
            temp = nextNode;
        }
    }
}
template <typename T>
void Stack<T>::push(T data){
    Node<T>* newNode = new Node<T>(data);
    newNode->setNext(this->top);
    this->top = newNode;
}
template <typename T>
Node<T>* Stack<T>::pop(){
    if(this->top == NULL){
        return NULL;
    }
    Node<T>* temp = this->top;
    this->top = this->top->getNext();
    return temp;
}
template <typename T>
Node<T>* Stack<T>::getTop(){
    if(this->top == NULL){
        return NULL;
    }
    return this->top;
}
template <typename T>
int Stack<T>::size(){
    if(this->top == NULL){
        return 0;
    }
    int count = 0;
    Node<T>* temp = this->top;
    while(temp != NULL){
        count+=1;
        temp = temp->getNext();
    }
    return count;
}
template <typename T>
bool Stack<T>::isEmpty(){
    if(this->top == NULL){
        return true;
    }
    return false;
}
template <typename T>
Stack<T>* Stack<T>::reverse(){
    Stack<T>* this_clone = new Stack<T>();
    this_clone->top = this->top;
    Stack<T>* temp = new Stack<T>();
    while(this_clone->top != NULL){
        temp->push(this_clone->pop()->getData());
    }
    return temp;
}
template <typename T>
bool Stack<T>::contains(T data){
    if(this->top == NULL){
        return false;
    }
    Node<T>* temp = this->top;
    while(temp != NULL){
        if(temp->getData() == data){
            return true;
        }
        temp = temp->getNext();
    }
    return false;
}