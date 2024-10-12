#include "FacialRecognition.h"
#include "ContactlessDevice.h"
#include "Exception.h"
#include <iostream>
#include <sstream>
#include <string>

FacialRecognition::FacialRecognition(const string &key, const int &maxStudents,
                                     int stepSize) {
  this->setKeyword(key);
  this->maxStudents = maxStudents;
  this->stepSize = stepSize;

  currentStudent = 0;

  studentDatabase = new string *[maxStudents];

  for (int i = 0; i < maxStudents; i++)
    studentDatabase[i] = new string[2];

  for (int i = 0; i < maxStudents; i++) {
    for (int j = 0; j < 2; j++)
      studentDatabase[i][j] = "z";
  }

  original = new int[length];
  for (int i = 0; i < length; i++) {
    original[i] = this->keyword[i];
  }
}

FacialRecognition::~FacialRecognition() {
  delete keyword;

  for (int i = 0; i < length; i++)
    delete[] rotor[i];

  delete[] rotor;

  for (int i = 0; i < 2; i++)
    delete[] studentDatabase[i];

  delete[] studentDatabase;

  delete original;
}

void FacialRecognition::setStepSize(int s) {
  if (s < 0)
    throw Exception("Negative number provided");

  stepSize = s;
}

char FacialRecognition::hashChar(char h) {
  for (int i = 0; i < 10; i++) {
    this->setRotor();
    if (rotor[i][length - 1] + '0' == h)
      return i + '0';
  }
}

string FacialRecognition::generateHash(string h) {
  string thehash = "";
  int count = 0;
  int lenOfPlain = h.length();

  while (count < lenOfPlain) {
    string thekey = "";

    if (count == 1) {
      int newkey = keyword[0] + stepSize;

      if (newkey > 9)
        keyword[0] = newkey - 10;
      else
        keyword[0] = newkey;

      this->setRotor();
    }

    if (count > 1) {
      int newkey = keyword[0] + stepSize;

      if (newkey > 9)
        keyword[0] = newkey - 10;
      else
        keyword[0] = newkey;

      for (int i = 1; i < length; i++)
        keyword[i] = rotor[0][i];

      this->setRotor();
    }

    thehash += hashChar(h[count]);

    count++;
  }

  return thehash;
}

string FacialRecognition::registerStudent(const string &h) {

  if (maxStudents == currentStudent)
    throw Exception("Student Database is full");

  for (int i = 0; i < maxStudents; i++) {
    if (studentDatabase[i][0] == h)
      throw Exception("Student already exist");
  }

  string thehash = generateHash(h);

  for (int i = 0; i < length; i++)
    keyword[i] = original[i];

  studentDatabase[currentStudent][0] = h;
  studentDatabase[currentStudent][1] = thehash;
  currentStudent++;

  return thehash;
}

string FacialRecognition::authenticateStudent(const string &a) {

  string thehash = generateHash(a);

  for (int i = 0; i < length; i++)
    keyword[i] = original[i];

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