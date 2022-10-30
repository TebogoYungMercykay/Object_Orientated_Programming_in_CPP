#include "SortList.h"
#include <iostream>
using namespace std;

template<class T>
SortList<T>::SortList(bool t){
    SortList<T>::ascending = t;
    SortList<T>::head = NULL;
    SortList<T>::tail = NULL;
}
template<class T>
void SortList<T>::add(SortNode<T>* t){
    if(SortList<T>::tail == NULL){
        SortList<T>::head = t;
        SortList<T>::tail = t;
    }
    else{
        t->prev = SortList<T>::tail;
        SortList<T>::tail->next = t;
        SortList<T>::tail = t;
    }
}
template<class T>
void SortList<T>::setAsc(bool t){
    SortList<T>::ascending=t;
    SortList<T>::sort();
}
template<class T>
std::string SortList<T>::debug(){
    SortNode<T>* nodePtr = SortList<T>::tail;
    std::string str = ",";
    while(nodePtr != NULL){
        str = str + nodePtr->print() + ",";
        nodePtr = nodePtr->prev;
    }
    return str.substr(1, str.length()-2);
}
template<class T>
SortNode<T>* SortList<T>::getHead(){
    return SortList<T>::head;
}
template<class T>
std::string SortList<T>::print(){
    SortNode<T>* nodePtr = SortList<T>::head;
    std::string str = ",";
    while(nodePtr != NULL){
        str = str + nodePtr->print() + ",";
        nodePtr = nodePtr->next;
    }
    return str.substr(1, str.length()-2);
}
template<class T>
void SortList<T>::sort(){
    SortList<T>* tSorted = new SortList<T>(SortList<T>::ascending);
    if(SortList<T>::ascending == true){
        while(SortList<T>::head != NULL){
            SortNode<T>* nodePtr = SortList<T>::head;
            SortNode<T>* tmin = SortList<T>::head;
            while(nodePtr != NULL){
                if(!(nodePtr->getValue() > tmin->getValue())){
                    tmin = nodePtr;
                } nodePtr = nodePtr->next;
            }
            tmin = SortList<T>::remove(tmin->getValue());
            tSorted->add(tmin);
        }
    }
    else{
        while(SortList<T>::head != NULL){
            SortNode<T>* nodePtr = SortList<T>::head;
            SortNode<T>* tmax = SortList<T>::head;
            while(nodePtr != NULL)
            {
                if(!(nodePtr->getValue() < tmax->getValue())){
                    tmax = nodePtr;
                } nodePtr = nodePtr->next;
            }
            tmax = SortList<T>::remove(tmax->getValue());
            tSorted->add(tmax);
        }
    }
    SortList<T>::head = tSorted->head;
    SortList<T>::tail = tSorted->tail;
    delete tSorted;
    tSorted = NULL;
}
template<class T>
SortNode<T>* SortList<T>::remove(T t){
    SortNode<T>* nodePtr = SortList<T>::tail;
    nodePtr = this->head;
    while(nodePtr != NULL && nodePtr->getValue() != t){
        nodePtr = nodePtr->next;
    }
    if(nodePtr != NULL){
        if(nodePtr == this->head && nodePtr == this->tail){
            this->head = this->head->next;
            this->tail = tail->next;
        }
        else if(nodePtr == this->head){
            this->head = this->head->next;
            this->head->prev = NULL;
            nodePtr->next = NULL;
        }
        else if(nodePtr == this->tail){
            this->tail = tail->prev;
            this->tail->next = NULL;
            nodePtr->prev = NULL;
        }
        else{
            nodePtr->prev->next = nodePtr->next;
            nodePtr->next->prev = nodePtr->prev;
            nodePtr->prev = NULL;
            nodePtr->next = NULL;
        }
    }
    return nodePtr;
}