#include "Node.h"

template <typename T>
Node<T>::Node(T data){
    this->data = data;
    this->next = NULL;
}
template <typename T>
T Node<T>::getData(){
    return this->data;
}
template <typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}
template <typename T>
void Node<T>::setNext(Node<T>* ptr){
    this->next = ptr;
}