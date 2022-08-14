#include <iostream>
#include <fstream> 

using namespace std;

// Code For The Four Different TAPE MOTIONS
string print_F();
void resize_Array();
void q0();
void q1();
void q2();
void q3();
void q4();
string final_state = "The tape was rejected";
string * my_Array;
int size_of_rray = 0;
string my_temp_String = "";
int index = 0;

int main(){
    string tapename("tape.txt.txt");
    string filename("turing.txt");
    fstream Write_to_file(tapename.c_str());
    fstream input_file(filename.c_str());
    if(!input_file.is_open()){ return 0;} 
    else{
        getline(input_file,my_temp_String);
    }
    size_of_rray = my_temp_String.length();
    my_Array = new string[size_of_rray];
    for(int k=0;k<size_of_rray;k++){
        my_Array[k]=my_temp_String[k];
    }
    // cout<<Checking if the array contains the correct data:<<endl;
    // for(int k=0;k<my_temp_String.length();k++)
    // {
    //     cout<<my_Array[k]<<"  ";
    // }
    // cout<<endl;
    q0();
    cout<<"The file contained: "<<my_temp_String<<endl;
    cout<<"The final tape was: "<<print_F()<<endl;
    cout<<final_state<<endl;
    // Now writting the stuff to a file
    if(final_state!="The tape was rejected"){
        Write_to_file<<final_state;
    }
    else{
        Write_to_file<<final_state;
    }
    Write_to_file.close();
    return 0;
}
// This function prints the final tape
string print_F(){
    string tape="";
    for(int k=0;k<size_of_rray;k++){
        tape+=my_Array[k];
    }
    return tape;
}
// This function resizes the array and adds a new empty character
void resize_Array(){
    string *tempArray = my_Array;
    size_of_rray+=1;
    my_Array = new string[size_of_rray];
    for(int k=0;k<size_of_rray;k++){
        if(k==(size_of_rray-1)){ my_Array[k]="U";}
        else{ my_Array[k]=tempArray[k];}
    }
}
void q0(){
    if(my_Array[index]=="P"){
        my_Array[index]="U";
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q1();
    }
}
void q1(){
    if(my_Array[index]=="P"){
        my_Array[index]="X";
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q2();
    }
    else if(my_Array[index]=="X"){
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q1();
    }
    else if(my_Array[index]=="U"){
        index++;
        final_state = "The tape was accepted";
        return;
    }
}
void q2(){
    if(my_Array[index]=="X"){
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q2();
    }
    else if(my_Array[index]=="P"){
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q3();
    }
    else if(my_Array[index]=="U"){
        index--;
        q4();
    }
}
void q3(){
    if(my_Array[index]=="P"){
        my_Array[index]="X";
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q2();
    }
}
void q4(){
    if(my_Array[index]=="P" || my_Array[index]=="X"){
        index--;
        q4();
    }
    else if(my_Array[index]=="U"){
        if(index==size_of_rray-1){resize_Array();}
        index++;
        q1();
    }
}