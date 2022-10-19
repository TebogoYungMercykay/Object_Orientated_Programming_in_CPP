#include "Exceptions.h"
using namespace std;

template <class E>
UndervaluedEx<E>::UndervaluedEx(E* U, double s){
    this->underVal = U;
    this->sum = s;
}
template <class E>
E* UndervaluedEx<E>::getUndervalued() const{
    return this->underVal;
}
template <class E>
double UndervaluedEx<E>::getSum() const{
    return this->sum;
}
AboveWeightEx::AboveWeightEx(double w){
    this->weightDiff = w;
}
double AboveWeightEx::getDifference() const{
    return this->weightDiff;
}
template <class E>
NotFoundEx<E>::NotFoundEx(E* m){
    this->missing = m;
}
template <class E>
E* NotFoundEx<E>::getNotFound() const{
    return this->missing;
}