// The Controller implementation file
#include "Controller.h"
using namespace std;

template <class T> Controller<T>::Controller(Plane<T> *plane) {
  Controller<T>::plane = plane;
}
template <class T> string Controller<T>::loadOnPlane(T *var) {
  try {
    Controller<T>::plane->add(var);
    return "Success";
  } catch (AboveWeightEx exception) {
    std::string temp(""), temp1 = "Could not load item, above max weight by ";
    double temp2 = (exception.getDifference());
    std::stringstream ss;
    ss << temp2;
    ss >> temp;
    return "Could not load item, above max weight by " + temp;
  }
}
template <class T> string Controller<T>::getPlaneContents() {
  try {
    return Controller<T>::plane->getDescription();
  } catch (EmptyEx exception) {
    return "Nothing to report";
  } catch (UnauthorisedEx exception) {
    return "Not permitted";
  }
}
template <class T> double Controller<T>::getTotalValue() {
  try {
    return Controller<T>::plane->calculateValue();
  } catch (UndervaluedEx<T> exception) {
    Controller<T>::plane->remove(exception.getUndervalued());
    return exception.getSum();
  } catch (...) {
    return 0;
  }
}