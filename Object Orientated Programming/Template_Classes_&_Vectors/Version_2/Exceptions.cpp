//Exception implementations
#include "Exceptions.h"
using namespace std;

AboveWeightEx::AboveWeightEx(double weight){
    AboveWeightEx::weightDiff = weight;
}
double AboveWeightEx::getDifference() const{
    return AboveWeightEx::weightDiff;
}

template <class E>
NotFoundEx<E>::NotFoundEx(E* miss){
    NotFoundEx<E>::missing = miss;
}
template <class E>
E* NotFoundEx<E>::getNotFound() const{
    return NotFoundEx<E>::missing;
}

template <class E>
UndervaluedEx<E>::UndervaluedEx(E* val, double sum){
    UndervaluedEx<E>::underVal = val;
    UndervaluedEx<E>::sum = sum;
}
template <class E>
E* UndervaluedEx<E>::getUndervalued() const{
    return UndervaluedEx<E>::underVal;
}
template <class E>
double UndervaluedEx<E>::getSum() const{
    return UndervaluedEx<E>::sum;
}