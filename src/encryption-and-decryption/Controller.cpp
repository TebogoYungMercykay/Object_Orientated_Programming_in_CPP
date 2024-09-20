#include "Controller.h"
#include "Babushka.h"
#include "BlueBabushka.h"
#include "ControllerException.h"
#include "DarkBlueBabushka.h"
#include "GoldBabushka.h"
#include "GreenBabushka.h"
#include "LightBlueBabushka.h"
#include "RedBabushka.h"
#include "ReturnStruct.h"
#include "YellowBabushka.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

Controller::Controller(std::string filepath) {
  std::fstream my_InputFile;
  my_InputFile.open(filepath.c_str());
  std::string holder_thingie;
  getline(my_InputFile, holder_thingie);
  std::stringstream ss_temp1(holder_thingie);
  getline(ss_temp1, holder_thingie, ':');
  ss_temp1 >> this->numBabushkas;
  this->babushkaArr = new Babushka *[this->numBabushkas];
  int counter_var = 0;
  while (getline(my_InputFile, holder_thingie)) {
    if (counter_var < this->numBabushkas) {
      std::stringstream ss_temp(holder_thingie);
      unsigned int temp_un = 0;
      getline(ss_temp, holder_thingie, ':');
      if (holder_thingie == "yellow") {
        getline(ss_temp, holder_thingie);
        unsigned char *my_array = new unsigned char[10];
        int k_var = 0;
        while (k_var < 10) {
          my_array[k_var] = holder_thingie[k_var];
          k_var++;
        }
        this->babushkaArr[counter_var] = new YellowBabushka(my_array);
        counter_var += 1;
      } else {
        std::string lastVue = "";
        std::string temp = "";
        std::string differentVAriable = "";
        getline(ss_temp, differentVAriable, ':');
        getline(ss_temp, lastVue);
        unsigned char *my_array = new unsigned char[10];
        for (int k = 0; k < 10; k++)
          my_array[k] = differentVAriable[k];
        if (holder_thingie == "gold") {
          this->babushkaArr[counter_var] =
              new GoldBabushka(my_array, lastVue[0]);
          counter_var += 1;
        } else if (holder_thingie == "green") {
          std::stringstream k_temp_int(lastVue);
          k_temp_int >> temp_un;
          this->babushkaArr[counter_var] = new GreenBabushka(my_array, temp_un);
          counter_var += 1;
        } else if (holder_thingie == "red") {
          std::stringstream k_temp_int(lastVue);
          k_temp_int >> temp_un;
          this->babushkaArr[counter_var] = new RedBabushka(my_array, temp_un);
          counter_var += 1;
        } else if (holder_thingie == "lightblue") {
          std::stringstream k_temp_int(lastVue);
          k_temp_int >> temp_un;
          this->babushkaArr[counter_var] =
              new LightBlueBabushka(my_array, temp_un);
          counter_var += 1;
        } else if (holder_thingie == "darkblue") {
          std::stringstream k_temp_int(lastVue);
          k_temp_int >> temp_un;
          this->babushkaArr[counter_var] =
              new DarkBlueBabushka(my_array, temp_un);
          counter_var += 1;
        }
      }
    }
  }
  my_InputFile.close();
}
Controller::~Controller() {
  for (int i = 0; i < this->numBabushkas; i++)
    if (this->babushkaArr[i]) {
      delete this->babushkaArr[i];
    }
  delete[] this->babushkaArr;
  this->babushkaArr = NULL;
}
ReturnStruct Controller::encrypt(const unsigned char *array, int size) {
  try {
    unsigned char *copy = new unsigned char[size];
    int i = 0;
    while (i < size) {
      copy[i] = array[i];
      i++;
    }
    this->printArray(copy, size);
    ReturnStruct stre;
    stre.arraySize = size;
    stre.returnArray = copy;
    i = 0;
    while (i < this->numBabushkas) {
      stre = this->expandArray(stre.returnArray, stre.arraySize,
                               this->babushkaArr[i]->getId(),
                               this->babushkaArr[i]->getIdLength());
      this->babushkaArr[i]->encrypt(stre.returnArray, stre.arraySize);
      this->printArray(stre.returnArray, stre.arraySize);
      i++;
    }
    return stre;
  } catch (BabushkaException &exception) {
    throw ControllerException(exception, "encrypt exception");
  }
}
ReturnStruct Controller::decrypt(const unsigned char *array, int size) {
  try {
    unsigned char *copy = new unsigned char[size];
    int i = 0;
    while (i < size) {
      copy[i] = array[i];
      i++;
    }
    this->printArray(copy, size);
    ReturnStruct stre;
    stre.arraySize = size;
    stre.returnArray = copy;
    i = this->numBabushkas - 1;
    while (i >= 0) {
      this->babushkaArr[i]->decrypt(stre.returnArray, stre.arraySize);
      stre = this->reduceArray(stre.returnArray, stre.arraySize,
                               this->babushkaArr[i]->getId(),
                               this->babushkaArr[i]->getIdLength());
      this->printArray(stre.returnArray, stre.arraySize);
      i--;
    }
    return stre;
  } catch (BabushkaException &exception) {
    throw ControllerException(exception, "encrypt exception");
  }
}
void Controller::printArray(unsigned char *array, int size) {
  std::cout << '[';
  for (int i = 0; i < size - 1; i++)
    std::cout << array[i] << ',';
  std::cout << array[size - 1] << ']' << std::endl;
}
ReturnStruct Controller::expandArray(unsigned char *array, int currentSize,
                                     const unsigned char *id, int idSize) {
  int newSize = currentSize + 2 * idSize;
  unsigned char *newArray = new unsigned char[newSize];
  for (int i = idSize, j = 0; i < idSize + currentSize; i++, j++)
    newArray[i] = array[j];
  delete array;
  array = NULL;
  for (int i = 0; i < idSize; i++)
    newArray[i] = id[i];
  for (int i = idSize + currentSize, j = 0; i < newSize; i++, j++)
    newArray[i] = id[j];
  ReturnStruct stre;
  stre.arraySize = newSize;
  stre.returnArray = newArray;
  return stre;
}
ReturnStruct Controller::reduceArray(unsigned char *array, int currentSize,
                                     const unsigned char *expectedId,
                                     int idSize) {
  int newSize = currentSize - (idSize * 2);
  ReturnStruct stre;
  unsigned char *newArray = new unsigned char[newSize];
  bool match = true;
  for (int i = 0; i < idSize; i++) {
    if (array[i] != expectedId[i]) {
      match = false;
      break;
    }
  }
  if (newSize < 0)
    throw ControllerException("size exception");
  else if (!match)
    throw ControllerException("id mismatch exception");
  else {
    int newSize = currentSize - (idSize * 2);
    ReturnStruct stre;
    unsigned char *newArray = new unsigned char[newSize];
    for (int i = idSize, j = 0; i < currentSize - idSize; i++, j++)
      newArray[j] = array[i];
    delete array;
    array = NULL;
    stre.arraySize = newSize;
    stre.returnArray = newArray;
    return stre;
  }
  return stre;
}