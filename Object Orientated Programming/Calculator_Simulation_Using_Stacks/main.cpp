/*   Tebogo - Testing Main - Practical 9   */
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
/*Do not remove this unless you want endless amounts of errors*/
// #include "Operator.cpp"
// #include "MinusOperator.cpp"
// #include "MultiplyOperator.cpp"
// #include "PlusOperator.cpp"
// #include "Node.cpp"
// #include "Stack.cpp"
// #include "Calculator.cpp"
// Include cpp files in the .h files for this linking style to work.
// Eg.
/*
#ifndef Something
#define Something
class another { }
#include "another.cpp"
#endif
*/
#include "Operator.h"
#include "MinusOperator.h"
#include "MultiplyOperator.h"
#include "PlusOperator.h"
#include "Node.h"
#include "Stack.h"
#include "Calculator.h"

static void test1();
static void test2();
static void test3();
static void test4();

int main(){
    test1();
    test2();
    test3();
    test4();
}

static void test1(){
    cout << "------------- TESTING STACK ---------------" << endl;
    Stack<int>* this_clone = new Stack<int>();
    if(this_clone->getTop() == NULL && this_clone->isEmpty()){
        cout << "Constructor Works and isEmpty." << endl;
    }
    else{
        cout << "Fix Constructor and isEmpty" << endl;
    }
    cout << "The Stack Size: " << this_clone->size() << endl;
    if(this_clone->contains(3) == false){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    this_clone->push(7);
    this_clone->push(98);
    if(this_clone->contains(7)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Printing the Stack: ";
    Node<int>* temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl << "Testing pop: " << this_clone->pop()->getData() << endl;
    this_clone->push(9);
    this_clone->push(2);
    this_clone->push(34);
    this_clone->push(47);
    this_clone->push(68);
    cout << "Done pushing" << endl;
    cout << "Printing the Stack: ";
    temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    Stack<int>* this_clone2 = this_clone->reverse();
    cout << "Printing the Reversed Stack: ";
    temp = this_clone2->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    cout << "Printing the Stack to check if it was altered: ";
    temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    if(this_clone->contains(47)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Testing pop: " << this_clone->pop()->getData() << endl;
    cout << "Testing pop1: " << this_clone->pop()->getData() << endl;
    cout << "Testing pop2: " << this_clone->pop()->getData() << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    cout << "------------------ DONE --------------------" << endl;
    delete temp;
    delete this_clone;
    delete this_clone2;
}
static void test2(){
    cout << "------------- TESTING CALCULATOR ---------------" << endl;
    MinusOperator<int>* MinusOp = new MinusOperator<int>();
    PlusOperator<int>* PlusOp = new PlusOperator<int>();
    Calculator<int>* CalcPtr = new Calculator<int>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3);
    CalcPtr->addValue(2);
    CalcPtr->addValue(1);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    CalcPtr->addOperator(PlusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
    int calculateVal = CalcPtr->calculate();
    cout << "Calculator Value: " << calculateVal << endl;
    cout << "Calculator Value 1: " << CalcPtr->removeValue() << endl;
    cout << "-------------------- DONE ----------------------" << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
}
static void test3(){
    cout << "------------- TESTING STACK - T->Double ---------------" << endl;
    Stack<double>* this_clone = new Stack<double>();
    if(this_clone->getTop() == NULL && this_clone->isEmpty()){
        cout << "Constructor Works and isEmpty." << endl;
    }
    else{
        cout << "Fix Constructor and isEmpty" << endl;
    }
    cout << "The Stack Size: " << this_clone->size() << endl;
    if(this_clone->contains(3) == false){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    this_clone->push(7);
    this_clone->push(98);
    if(this_clone->contains(7)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Prdoubleing the Stack: ";
    Node<double>* temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl << "Testing pop: " << this_clone->pop()->getData() << endl;
    this_clone->push(9);
    this_clone->push(2);
    this_clone->push(34);
    this_clone->push(47);
    this_clone->push(68);
    cout << "Done pushing" << endl;
    cout << "Prdoubleing the Stack: ";
    temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    Stack<double>* this_clone2 = this_clone->reverse();
    cout << "Prdoubleing the Reversed Stack: ";
    temp = this_clone2->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    cout << "Prdoubleing the Stack to check if it was altered: ";
    temp = this_clone->getTop();
    while(temp){
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    if(this_clone->contains(47)){
        cout << "Contains Works" << endl;
    }
    else{
        cout << "Fix Contain Method" << endl;
    }
    cout << "Testing pop: " << this_clone->pop()->getData() << endl;
    cout << "Testing pop1: " << this_clone->pop()->getData() << endl;
    cout << "Testing pop2: " << this_clone->pop()->getData() << endl;
    cout << "The Stack Size: " << this_clone->size() << endl;
    delete temp;
    delete this_clone;
    delete this_clone2;
    cout << "-------------------- DONE ----------------------" << endl;
}
static void test4(){
    cout << "------------- TESTING CALCULATOR - T->Double ---------------" << endl;
    MinusOperator<double>* MinusOp = new MinusOperator<double>();
    PlusOperator<double>* PlusOp = new PlusOperator<double>();
    Calculator<double>* CalcPtr = new Calculator<double>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3);
    CalcPtr->addValue(2);
    CalcPtr->addValue(1);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    CalcPtr->addOperator(PlusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
    double calculateVal = CalcPtr->calculate();
    cout << "Calculator Value: " << calculateVal << endl;
    cout << "Calculator Value 1: " << CalcPtr->removeValue() << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
    cout << "-------------------- DONE ----------------------" << endl;
}
static void test5(){
    cout << "------------- TESTING CALCULATOR - T->Double ---------------" << endl;
    MinusOperator<double>* MinusOp = new MinusOperator<double>();
    PlusOperator<double>* PlusOp = new PlusOperator<double>();
    Calculator<double>* CalcPtr = new Calculator<double>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3);
    CalcPtr->addValue(2);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    CalcPtr->addOperator(PlusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
    double calculateVal = CalcPtr->calculate();
    cout << "Calculator Value: " << calculateVal << endl;
    cout << "Calculator Value 1: " << CalcPtr->removeValue() << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
    cout << "-------------------- DONE ----------------------" << endl;
}
static void test6(){
    cout << "------------- TESTING CALCULATOR - T->Double ---------------" << endl;
    MinusOperator<double>* MinusOp = new MinusOperator<double>();
    PlusOperator<double>* PlusOp = new PlusOperator<double>();
    Calculator<double>* CalcPtr = new Calculator<double>();
    cout << "Testing addValue" << endl;
    CalcPtr->addValue(3);
    CalcPtr->addValue(2);
    CalcPtr->addValue(1);
    cout << "Testing addOperator" << endl;
    CalcPtr->addOperator(MinusOp);
    cout << "Testing numValues" << CalcPtr->numValues() << endl;
    cout << "Testing numOperators" << CalcPtr->numOperators() << endl;
    cout << "----------- Testing Calculate -----------" << endl;
    double calculateVal = CalcPtr->calculate();
    cout << "Calculator Value: " << calculateVal << endl;
    cout << "Calculator Value 1: " << CalcPtr->removeValue() << endl;
    delete MinusOp;
    delete PlusOp;
    delete CalcPtr;
    cout << "-------------------- DONE ----------------------" << endl;
}