#include "Controller.h"
using namespace std;

template <class T>
Controller<T>::Controller(Plane<T>* plane){
    this->plane = plane;
}
template <class T>
double Controller<T>::getTotalValue(){
    try{
        double val = this->plane->calculateValue();
        return val;
    }
    catch(UndervaluedEx<T> Exception_ptr_access){
        T* U = Exception_ptr_access.getUndervalued();
        this->plane->remove(U);
        double s = Exception_ptr_access.getSum();
        return s;
    }
    catch(...){
        return 0;
    }
}
template <class T>
string Controller<T>::loadOnPlane(T* var){
    try{
        this->plane->add(var);
        return "Success";
    }
    catch(AboveWeightEx Exception_ptr_access){
        string s;
        string weightDifference = "Could not load item, above max weight by ";
        stringstream ss;
        ss << Exception_ptr_access.getDifference();
        ss >> s;
        return weightDifference+s;
    }
    catch(...){
        return "Unexpected Error";
    }
}
template <class T>
string Controller<T>::getPlaneContents(){
    try{
        string var = this->plane->getDescription();
        return var;
    }
    catch(EmptyEx Exception_ptr_access){ 
        return "Nothing to report";
    }
    catch(UnauthorisedEx Exception_ptr_access){
        return "Not permitted";
    }
    catch(...){
        return "Unexpected Error";
    }
}