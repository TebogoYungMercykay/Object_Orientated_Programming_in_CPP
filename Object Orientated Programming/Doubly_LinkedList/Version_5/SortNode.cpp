#include "SortNode.h"
#include <sstream>
#include <string>
using namespace std;

template<typename T>
SortNode<T>::SortNode(T val){
    SortNode<T>::value = val;
    SortNode<T>::next =  NULL;
    SortNode<T>::prev = NULL;
}
template<typename T>
std::string SortNode<T>::print(){
    std::stringstream mValue;
    mValue << SortNode<T>::value;
    std::string sValue = "";
    mValue >> sValue;
    return sValue;
}
template<typename T>
T SortNode<T>::getValue(){
    return value;
}