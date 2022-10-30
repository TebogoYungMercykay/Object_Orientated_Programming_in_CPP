#include "SortList.h"
#include <iostream>
using namespace std;

template<class T>
SortList<T>::SortList(bool val){
    this->ascending = val;
    this->tail = this->head = NULL;
}
template<class T>
void SortList<T>::add(SortNode<T>* val){
    if(this->tail != NULL){
        val->prev = this->tail;
        this->tail->next = val;
        this->tail = val;
    }
    else{
        this->tail = val;
        this->head = val;
    }
}
template<class T>
void SortList<T>::setAsc(bool val){
    this->ascending = val;
    this->sort();
}
template<class T>
std::string SortList<T>::debug(){
    std::string temp_string("");
    for(SortNode<T>* Nodes = this->tail; Nodes != NULL; ){
        temp_string += Nodes->print() + ",";
        Nodes = Nodes->prev;
    }
    return temp_string.substr(0, temp_string.length()-1);
}
template<class T>
std::string SortList<T>::print(){
    std::string temp_string("");
    for(SortNode<T>* Nodes = this->head; Nodes != NULL; ){
        temp_string += Nodes->print() + ",";
        Nodes = Nodes->next;
    }
    return temp_string.substr(0, temp_string.length()-1);
}
template<class T>
SortNode<T>* SortList<T>::getHead(){
    return this->head;
}
template<class T>
SortNode<T>* SortList<T>::remove(T val){
    SortNode<T>* Nodes = this->head;
    for( ; Nodes != NULL && Nodes->getValue() != val ; ){
        Nodes = Nodes->next;
    }
    if(Nodes != NULL){
        if(Nodes == this->head || Nodes == this->tail){
            if(Nodes == this->head && Nodes == this->tail){
                this->head = this->head->next;
                this->tail = this->tail->next;
            }
            else if(Nodes == this->tail){
                this->tail = this->tail->prev;
                this->tail->next = Nodes->prev = NULL;
            }
            else{
                this->head = this->head->next;
                this->head->prev = Nodes->next = NULL;
            }
        }
        else if(Nodes != this->head && Nodes != this->tail){
            Nodes->prev->next = Nodes->next;
            Nodes->next->prev = Nodes->prev;
            Nodes->prev = Nodes->next = NULL;
        }
    }
    return Nodes;
}
template<class T>
void SortList<T>::sort(){
    SortList<T>* sorted_List;
    sorted_List = new SortList<T>(this->ascending);
    if(this->ascending != false){
        for( ; this->head != NULL ; ){
            SortNode<T>* Nodes;
            SortNode<T>* smallest_node;
            for(smallest_node = Nodes = this->head; Nodes != NULL; ){
                bool temp_bool = (Nodes->getValue() < smallest_node->getValue());
                if(temp_bool){
                    smallest_node = Nodes;
                }
                Nodes = Nodes->next;
            }
            smallest_node = this->remove(smallest_node->getValue());
            sorted_List->add(smallest_node);
        }
    }
    else{
        for( ; this->head != NULL ; ){
            SortNode<T>* Nodes;
            SortNode<T>* largest_node;
            for(largest_node = Nodes = this->head; Nodes != NULL; ){
                bool temp_bool = (Nodes->getValue() > largest_node->getValue());
                if(temp_bool){
                    largest_node = Nodes;
                }
                Nodes = Nodes->next;
            }
            largest_node = this->remove(largest_node->getValue());
            sorted_List->add(largest_node);
        }
    }
    this->tail = sorted_List->tail;
    this->head = sorted_List->head;
    delete sorted_List;
    sorted_List = NULL;
}