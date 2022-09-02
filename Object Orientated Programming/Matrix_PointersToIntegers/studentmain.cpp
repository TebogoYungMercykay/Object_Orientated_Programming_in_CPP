#include "matrix.h"

#include <iostream>

using namespace std;

int main() {
    // cout<<"In Here=="<<endl;
    Matrix m = Matrix(0, 0);
    m.displayMatrix();
    int p = 0;

    cout <<"======== "<<p++<<" ========"<< endl;

    Matrix m2 = Matrix(6, 6);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    
    // Resize to large array
    m2.resizeRows(9);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(9);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Resize to small array
    m2.resizeRows(3);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(3);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Resize to small array
    m2.resizeRows(5);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(1);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Resize to same size
    m2.resizeRows(3);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(1);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Resize to same size
    m2.resizeRows(1);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Resize to small array
    m2.resizeRows(3);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(3);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // Populating the mattrix
    m2.setMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeColumns(10);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;
    m2.resizeRows(10);
    m2.displayMatrix();
    cout <<"======== "<<p++<<" ========"<< endl;

    // m2.resizeColumns(1000);
    // m2.displayMatrix();
    // cout <<"======== "<<p++<<" ========"<< endl;
    // m2.resizeRows(1000);
    // m2.displayMatrix();
    // cout <<"======== "<<p++<<" ========"<< endl;

    cout<<"In Here=="<<endl;
    m2.resizeRows(-1);
    m2.resizeColumns(-1);
   
    return 0;

}
// If You Manage to see this right after 10k zeroes submit immediately

/*
In Here==
Error: cannot have less than 1 row
Error: cannot have less than 1 column
*/
