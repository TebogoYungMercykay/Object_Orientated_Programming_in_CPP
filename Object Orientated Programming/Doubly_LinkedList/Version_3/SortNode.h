#ifndef SN_H
#define SN_H

#include <string>
#include <sstream>

//SortNode class implementation here
template<typename T>
class SortNode
{
    protected:
        T value;
    public:
        SortNode<T>* next;
        SortNode<T>* prev;
        SortNode(T val);
        std::string print();
        T getValue();
};
#include "SortNode.cpp"
#endif
 