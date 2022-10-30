#include "SortNode.h"
#include <sstream>
#include <string>
using namespace std;

template<class T>
SortNode<T>::SortNode(T val){
    value = val;
    next = prev = NULL;
}
template<class T>
string SortNode<T>::print(){
    stringstream temp_ss;
    temp_ss << value;
    string temp;
    temp_ss >> temp;
    return temp;
}
template<class T>
T SortNode<T>::getValue(){
    return value;
}