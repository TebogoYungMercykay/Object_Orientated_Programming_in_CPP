//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_NODE_H
#define ASSIGNMENT_4_NODE_H


template<class T>
class Node
{
public:
    Node(T data, Node<T>* n = 0)
    {
        element = data;
        next = n;
    }

    ~Node()
    {
        next = 0;
    }

    //The element stored in the node
    T element;
    //The next node in the list
    Node<T>* next;
};


#endif //ASSIGNMENT_4_NODE_H
