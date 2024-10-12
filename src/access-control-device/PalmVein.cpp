#include "PalmVein.h"
#include "AccessDevice.h"
#include "ContactlessDevice.h"
#include "Exception.h"
#include <iostream>
#include <sstream>
#include <string>

PalmVein::PalmVein(const string &key, const int &maxStud) {
  this->setKeyword(key);
  this->maxStudents = maxStud;
  currentStudent = 0;

  if (key.length() < 1)
    throw Exception("The keyword provided is not going to generate a safe "
                    "encryption\n");

  for (int i = 0; i < key.length(); i++) {
    if (key[i] == ' ')
      throw Exception("The keyword provided is not going to generate a "
                      "safe encryption\n");
  }

  studentDatabase = new string *[maxStudents];

  for (int i = 0; i < maxStudents; i++)
    studentDatabase[i] = new string[2];

  for (int i = 0; i < maxStudents; i++) {
    for (int j = 0; j < 2; j++)
      studentDatabase[i][j] = "z";
  }
}

PalmVein::~PalmVein() {
  delete[] keyword;

  for (int i = 0; i < length; i++)
    delete[] rotor[i];

  delete[] rotor;

  for (int i = 0; i < 2; i++)
    delete[] studentDatabase[i];

  delete[] studentDatabase;
}

char PalmVein::hashChar(char c) {
  for (int i = 0; i < 10; i++) {
    if (rotor[i][length - 1] + '0' == c) {
      return i + '0';
    }
  }
}
string PalmVein::registerStudent(const string &h) {
  if (maxStudents == currentStudent)
    throw Exception("Student Database is full");

  for (int i = 0; i < maxStudents; i++) {
    if (studentDatabase[i][0] == h)
      throw Exception("Student already exist");
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

string PalmVein::authenticateStudent(const string &a) {
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