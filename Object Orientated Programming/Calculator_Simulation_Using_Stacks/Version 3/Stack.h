#ifndef STACK_H
#define STACK_H
#include "Node.h"
template <typename T>
class Stack
{
    private:
        Node<T>* top;
    public:
        Stack();
        ~Stack();
        void push(T data);
        Node<T>* pop();
        Node<T>* getTop();
        int size();
        bool isEmpty();
        Stack<T>* reverse();
        bool contains(T data);
};
#include "Stack.cpp"
#endif