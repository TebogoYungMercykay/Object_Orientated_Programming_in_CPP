// The Plane implementation file
#include "Plane.h"
using namespace std;

template <class T>
Plane<T>::Plane(double maxWeight){
    Plane<T>::maxWeight = maxWeight;
}
template <class T>
void Plane<T>::remove(T* var){
    bool found = false;
    int index = -1*Plane<T>::cargo.size();
    if(Plane<T>::cargo.empty() == !false){
        throw EmptyEx();
    }
    for(int i=0, n = Plane<T>::cargo.size(); i< n; i++){
        if(Plane<T>::cargo[i]==var){
            index = i;
            found = true;
            break;
        }
    }
    if(found == false){
        throw NotFoundEx<T>(var);
    }
    else{
        Plane<T>::cargo.erase(Plane<T>::cargo.begin() + index);
    }
}
template <class T>
string Plane<T>::getDescription(){
    if(Plane<T>::cargo.empty() == !false){
        throw EmptyEx();
    }
    else{
        string returned = "";
        for(int k=0, n = Plane<T>::cargo.size(); k< n; k++){
            if(Plane<T>::cargo[k]){
                returned += Plane<T>::cargo[k]->describe() + "\n";
            }
        }
        int len = returned.length()-1;
        return returned.substr(len-(returned.length()-1), len);
    }
    return "";
}
template <>
string Plane<SecretCargo>::getDescription(){
    if(Plane<SecretCargo>::cargo.empty() == !false){
        throw EmptyEx();
    }
    else{
        throw UnauthorisedEx();
    }
}
template <class T>
double Plane<T>::calculateValue(){
    if(Plane<T>::cargo.empty() == !false){
        throw EmptyEx();
    }
    else{
        const int size = Plane<T>::cargo.size();
        double* leastValues = new double[size];
        double totalValue = 0;
        int leastIndex = -1, secondLeastIndex = -1;
        for(int i = 0; i < size; i++){
            if(Plane<T>::cargo[i] == NULL){
                leastValues[i] = 7888888;
            }
            else{
                leastValues[i] = Plane<T>::cargo[i]->getValue();
                totalValue += Plane<T>::cargo[i]->getValue();
            }
        }
        for(int i = 0; i < size-1; i++){
            for(int k = size-1; k > i; --k){
                if(leastValues[k] < leastValues[k - 1]){
                    double tmpVal = leastValues[k];
                    leastValues[k] = leastValues[k - 1];
                    leastValues[k - 1] = tmpVal;
                }
            }
        }
        for(int i = 0; i < size; i++){
            if(Plane<T>::cargo[i]){
                if(Plane<T>::cargo[i]->getValue()<=leastValues[0]){
                    leastIndex = i;
                    break;
                }
            }
        }
        for(int i = 0; i < size; i++){
            if(Plane<T>::cargo[i]){
                if(Plane<T>::cargo[i]->getValue()>leastValues[0]){
                    secondLeastIndex = i;
                    break;
                }
            }
        }
        for(int i = 0; i < size; i++){
            if(Plane<T>::cargo[i]->getValue()>Plane<T>::cargo[leastIndex]->getValue() && Plane<T>::cargo[i]->getValue()<Plane<T>::cargo[secondLeastIndex]->getValue()){
                secondLeastIndex = i;
            }
        }
        if(Plane<T>::cargo[leastIndex]->getValue() < (Plane<T>::cargo[secondLeastIndex]->getValue())/2){
            totalValue = totalValue-Plane<T>::cargo[leastIndex]->getValue();
            throw UndervaluedEx<T>(Plane<T>::cargo[leastIndex], totalValue);
        }
        return totalValue;
    }
    return 0;
}
template <class T>
Plane<T>::~Plane(){
    cargo.clear();
}
template <class T>
void Plane<T>::add(T* var){
    double weightTotal = var->getWeight();
    for(int i=0, n = Plane<T>::cargo.size(); i< n; i++){
        if(Plane<T>::cargo[i]){
            weightTotal += Plane<T>::cargo[i]->getWeight();
        }
    }
    if(weightTotal > Plane<T>::maxWeight){
        double weightTotalDiff = weightTotal - Plane<T>::maxWeight;
        throw AboveWeightEx(weightTotalDiff);
    }
    else{
        Plane<T>::cargo.push_back(var);
    }
}
template <>
double Plane<SecretCargo>::calculateValue()
{
    if(Plane<SecretCargo>::cargo.empty() == !false){
        throw EmptyEx();
    }
    else{
        throw UnauthorisedEx();
    }
}