#ifndef DLL_H
#define DLL_H

#include "SortNode.h"

//SortList class Implementation here
template<class T>
class SortList {
    public:
        // SortList Member functions
        SortList(bool val);
        void add(SortNode<T>* val);
        SortNode<T>* remove(T val);
        void setAsc(bool val);
        void sort();
        SortNode<T>* getHead();
        std::string debug();
        std::string print();
    protected:
    private:
        bool ascending;
        // SortNode Pointers
        SortNode<T>* head;
        SortNode<T>* tail;
};
#include "SortList.cpp"
#endif
