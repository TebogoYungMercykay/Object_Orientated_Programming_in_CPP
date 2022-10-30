#include "SortList.h"
#include <iostream>
using namespace std;

template<class T>
SortList<T>::SortList(bool t)
{
    ascending=t;
    tail=head=NULL;
}
template<class T>
void SortList<T>::add(SortNode<T>* t)
{
    if(tail!=NULL)
    {
        t->prev=tail;
        tail->next=t;
        tail=t;
    }
    else{
        tail=head=t;
    }
}
template<class T>
void SortList<T>::setAsc(bool t)
{
    ascending=t;
    sort();
}
template<class T>
string SortList<T>::debug()
{
    string st="";
    for(SortNode<T>* nopdePtr=tail; nopdePtr!=NULL; nopdePtr=nopdePtr->prev)
    {
        st += nopdePtr->print() + ",";
    }
    int k=st.length()-1;
    return st.substr(0, k);
}
template<class T>
SortNode<T>* SortList<T>::getHead()
{
    return head;
}
template<class T>
string SortList<T>::print()
{
    string st="";
    for(SortNode<T>* nopdePtr=head; nopdePtr!=NULL; nopdePtr=nopdePtr->next)
    {
        st += nopdePtr->print() + ",";
    }
    int k=st.length()-1;
    return st.substr(0, k);
}
template<class T>
void SortList<T>::sort()
{
    SortList<T>* List;
    List=new SortList<T>(ascending);
    if(ascending)
    {
        while(head!=NULL)
        {
            SortNode<T>* nopdePtr;
            SortNode<T>* xs;
            for(xs=head, nopdePtr=head; nopdePtr!=NULL; nopdePtr=nopdePtr->next)
            {
                T val1=nopdePtr->getValue();
                T val2=xs->getValue();
                if(val1 < val2)
                {
                    xs=nopdePtr;
                }
            }
            xs=remove(xs->getValue());
            List->add(xs);
        }
    }
    else{
        while(head!=NULL)
        {
            SortNode<T>* nopdePtr;
            SortNode<T>* xl;
            for(xl=head, nopdePtr=head; nopdePtr!=NULL; nopdePtr=nopdePtr->next)
            {
                T val1=nopdePtr->getValue();
                T val2=xl->getValue();
                if(val1 > val2)
                {
                    xl=nopdePtr;
                }
            }
            xl=remove(xl->getValue());
            List->add(xl);
        }
    }
    tail=List->tail;
    head=List->head;
    delete List;
    List=NULL;
}
template<class T>
SortNode<T>* SortList<T>::remove(T t)
{
    SortNode<T>* nopdePtr;
    for(nopdePtr=head; nopdePtr!=NULL && nopdePtr->getValue()!=t; nopdePtr=nopdePtr->next);
    bool condition1=nopdePtr==head;
    bool condition2=nopdePtr==tail;
    if(nopdePtr!=NULL)
    {
        if(condition1 || condition2)
        {
            if(condition1 && condition2)
            {
                head=head->next;
                tail=tail->next;
            }
            else if(condition2)
            {
                tail=tail->prev;
                tail->next=NULL;
                nopdePtr->prev=NULL;
            }
            else{
                head=head->next;
                head->prev=NULL;
                nopdePtr->next=NULL;
            }
        }
        else if(!condition1 && !condition2)
        {
            nopdePtr->prev->next=nopdePtr->next;
            nopdePtr->next->prev=nopdePtr->prev;
            nopdePtr->prev=nopdePtr->next=NULL;
        }
    }
    return nopdePtr;
}