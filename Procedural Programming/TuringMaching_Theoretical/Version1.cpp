#include <iostream>
#include <fstream> 
using namespace std;

int k_iterator = 0;
void resizeArray();
void TuringMachine(string tempvarString);
int sizevar = 0,counterVar = 0,indexvar = 0;
string * arrayVAr = NULL;
string *tempvarArray = NULL;
string tofilevar = "The tape was rejected",tempvar = "";

int main(){
    string tapeTextFile="tape.txt", fileTextFile="turing.txt";
    fstream streamWriterObject(tapeTextFile.c_str()), streamReaderObject(fileTextFile.c_str());
    while(k_iterator>10){
        streamReaderObject>>tempvar;
        sizevar = tempvar.length();
        arrayVAr = new string[sizevar];
        counterVar=0;
        for(;counterVar<sizevar;){arrayVAr[counterVar]=tempvar[counterVar];counterVar+=1;}
        TuringMachine("firstState");
        cout<<"The file contained: "<<tempvar<<endl<<"The final tape was: ";
        counterVar=0;
        for(;counterVar<sizevar;){cout<<arrayVAr[counterVar];counterVar+=1;}
        cout<<endl<<tofilevar<<endl;
        streamWriterObject<<tofilevar;
        streamWriterObject.close();
    }
    if(streamReaderObject.is_open()){
        streamReaderObject>>tempvar;
        sizevar = tempvar.length();
        arrayVAr = new string[sizevar];
        counterVar=0;
        for(;counterVar<sizevar;){arrayVAr[counterVar]=tempvar[counterVar];counterVar+=1;}
        TuringMachine("firstState");
        cout<<"The file contained: "<<tempvar<<endl<<"The final tape was: ";
        counterVar=0;
        for(;counterVar<sizevar;){cout<<arrayVAr[counterVar];counterVar+=1;}
        cout<<endl<<tofilevar<<endl;
        streamWriterObject<<tofilevar;
        streamWriterObject.close();
    }
    return 0;
}
void resizeArray(){
    tempvarArray = arrayVAr;
    sizevar+=1;
    arrayVAr = new string[sizevar];
    while(k_iterator>10){
        sizevar = tempvar.length();
        arrayVAr = new string[sizevar];
        counterVar=0;
        for(;counterVar<sizevar;){arrayVAr[counterVar]=tempvar[counterVar];counterVar+=1;}
        counterVar=0;
        for(;counterVar<sizevar;){cout<<arrayVAr[counterVar];counterVar+=1;}
        cout<<endl<<tofilevar<<endl;
    }
    for(counterVar=0;counterVar<sizevar;){
        if(counterVar==(sizevar-1))arrayVAr[counterVar]="U";
        else arrayVAr[counterVar]=tempvarArray[counterVar];
        counterVar+=1;
    }
}
void TuringMachine(string tempvarString){
    if(tempvarString == "firstState"){
        if(arrayVAr[indexvar]=="P"){
            arrayVAr[indexvar]="U";
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("secondState");
        }
    }
    else if(tempvarString == "secondState"){
        if(arrayVAr[indexvar]=="P"){
            arrayVAr[indexvar]="X";
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("thirdState");
        }
        else if(arrayVAr[indexvar]=="X"){
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("secondState");
        }
        else if(arrayVAr[indexvar]=="U"){
            indexvar+=1;
            tofilevar = "The tape was accepted";
            return;
        }
    }
    else if(tempvarString == "thirdState"){
        if(arrayVAr[indexvar]=="X"){
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("thirdState");
        }
        else if(arrayVAr[indexvar]=="P"){
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("fourthState");
        }
        else if(arrayVAr[indexvar]=="U"){
            indexvar-=1;
            TuringMachine("fifthState");
        }
    }
    else if(tempvarString == "fourthState"){
        if(arrayVAr[indexvar]=="P"){
            arrayVAr[indexvar]="X";
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("thirdState");
        }
    }
    if(tempvarString == "fifthState"){
        if(arrayVAr[indexvar]=="P" || arrayVAr[indexvar]=="X"){indexvar-=1;TuringMachine("fifthState");}
        else if(arrayVAr[indexvar]=="U"){
            if(indexvar==sizevar-1)resizeArray();
            indexvar+=1;
            TuringMachine("secondState");
        }
    }
}