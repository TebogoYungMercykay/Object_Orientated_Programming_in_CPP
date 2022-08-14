#ifndef CONTACTLESSDEVICE_H
#define CONTACTLESSDEVICE_H

#include <iostream>
#include "AccessDevice.h"

using namespace std;

class ContactlessDevice : public AccessDevice 
{
    protected:
        int* keyword;
        int maxStudents;
        int currentStudent;
        int** rotor;
        string** studentDatabase;
        virtual char hashChar(char)=0;
        int length;

    public:
        string registerStudent(const string&);
        string authenticateStudent(const string&);
        int* setKeyword(const string&);
        void setRotor();
        int** getRotor();
        string** getStudentDatabase();
};

#endif