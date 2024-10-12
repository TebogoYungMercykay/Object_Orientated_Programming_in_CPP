#include "ControllerException.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

ControllerException::ControllerException(std::string customMessage) {
  this->customMessage = customMessage;
  this->hasBabushka = false;
}
ControllerException::ControllerException(BabushkaException &babushkaException,
                                         std::string customMessage) {
  this->hasBabushka = true;
  this->babushkaException = &babushkaException;
  this->customMessage = customMessage;
}
void ControllerException::printMessage() {
  std::cout << this->customMessage;
  std::cout << std::endl;
  if (this->hasBabushka == true) {
    this->babushkaException->printMessage();
  }
}