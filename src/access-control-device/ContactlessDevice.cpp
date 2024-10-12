#include "ContactlessDevice.h"
#include "AccessDevice.h"
#include "Exception.h"
#include <iostream>
#include <sstream>
#include <string>

int *ContactlessDevice::setKeyword(const string &k) {
  int size = k.length();
  length = size;

  for (int i = 0; i < size; i++) {
    if (k[i] < '0' || k[i] > '9')
      throw Exception("Invalid input");
  }

  for (int i = 0; i < size; i++) {
    keyword = new int[size];

    for (int j = 0; j < size; j++) {
      keyword[j] = k[j] - '0';
    }
  }

  return keyword;
}

void ContactlessDevice::setRotor() {
  rotor = new int *[10];

  for (int i = 0; i < 10; i++)
    rotor[i] = new int[length];
  int sum = 0;
  for (int i = 0; i < length; i++) {
    sum += keyword[i];
    if (sum <= 9) {

      rotor[0][i] = sum;
    } else {
      rotor[0][i] = sum - 10;
      sum = sum - 10;
    }
  }

  for (int i = 1; i < 10; i++) {
    for (int j = 0; j < length; j++) {
      int num = rotor[0][j];
      int entered = num + i;

      if (entered > 9) {
        rotor[i][j] = entered - 10;
        num = 0;
      } else {
        rotor[i][j] = entered;
      }
    }
  }
}

int **ContactlessDevice::getRotor() { return rotor; }

string **ContactlessDevice::getStudentDatabase() { return studentDatabase; }

string ContactlessDevice::registerStudent(const string &h) {
  if (maxStudents == currentStudent)
    throw(Exception("Student Database is full"));

  for (int i = 0; i < maxStudents; i++) {
    if (studentDatabase[i][0] == h)
      throw(Exception("Student already exist"));
  }

  string thehash = "";

  for (int i = 0; i < h.length(); i++) {
    thehash += hashChar(h[i]);
  }

  studentDatabase[currentStudent][0] = h;
  studentDatabase[currentStudent][1] = thehash;
  currentStudent++;

  return thehash;
}

string ContactlessDevice::authenticateStudent(const string &a) {
  string thehash = "";

  for (int i = 0; i < a.length(); i++) {
    thehash += hashChar(a[i]);
  }

  string found = "";

  for (int i = 0; i < currentStudent; i++) {
    for (int j = 0; j < 2; j++) {
      if (studentDatabase[i][0] == a || studentDatabase[0][j] == thehash)
        found = a;
    }
  }

  string boolean;

  if (found != "")
    boolean = "true";
  else
    boolean = "false";

  return thehash + boolean;
}