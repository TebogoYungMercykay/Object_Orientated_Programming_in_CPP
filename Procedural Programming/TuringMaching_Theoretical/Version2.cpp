#include <iostream>
#include <fstream> 

std::string * statearray;
std::string *changesize = statearray = NULL;
std::string statevariable = "The tape was rejected";
std::string statetempvar = "";
std::string t;
std::string p = "The tape was accepted";
std::string printoutput = "The file contained: ";
std::string finaloutput = "The final tape was: ";
std::string fir = "firstState";
std::string sec = "secondState";
std::string thir = "thirdState";
std::string four = "fourthState";
std::string five = "fifthState";
std::string tapeTextFile="tape.txt";
std::string fileTextFile="turing.txt";
int k_iterator = 0;
int sizevar = 0;
int countState = 0;
int indexvar = 0;

void add_element(){
    changesize = statearray;
    sizevar+=1;
    statearray = new std::string[sizevar];
    std::string  k = "created a new Array";
    countState=0;
    while(countState<sizevar){
    if(countState==(sizevar-1))
    statearray[countState]="U";
    else
    statearray[countState]=changesize[countState];
    countState = countState + 1;
    }
}
void change_state(std::string changeState){
    if(changeState == fir){
        if(statearray[indexvar]=="P"){
        statearray[indexvar]="U";
        if(indexvar==sizevar-1)
        add_element();
        indexvar = indexvar + 1;
        change_state(sec);
        }
    }
    else if(changeState == four){
        if(statearray[indexvar]=="P"){
        statearray[indexvar]="X";
        if(indexvar==sizevar-1)
        add_element();
        indexvar = indexvar + 1;
        change_state(thir);
        }
    }
    else if(changeState == thir){
        if(statearray[indexvar]=="X"){
        if(indexvar==sizevar-1)add_element();
        indexvar = indexvar + 1;
        change_state(thir);
        }
        else if(statearray[indexvar]=="P"){
        if(indexvar==sizevar-1)add_element();
        indexvar = indexvar + 1;
        change_state(four);
        }
        else if(statearray[indexvar]=="U"){
        indexvar = indexvar - 1;
        change_state(five);
        }
    }
    else if(changeState == sec){
        if(statearray[indexvar]=="P"){
        statearray[indexvar]="X";
        if(indexvar==sizevar-1)
        add_element();
        indexvar = indexvar + 1;
        change_state(thir);
        }
        else if(statearray[indexvar]=="X"){
        if(indexvar==sizevar-1)
        add_element();
        indexvar = indexvar + 1;
        change_state(sec);
        }
        else if(statearray[indexvar]=="U"){
        indexvar = indexvar + 1;
        statevariable = "The tape was accepted";
        return;
        }
    }
    else if(changeState == five){
    if(statearray[indexvar]=="P" || statearray[indexvar]=="X"){indexvar = indexvar - 1;
    change_state(five);}
    else if(statearray[indexvar]=="U"){
    if(indexvar==sizevar-1)
    add_element();
    indexvar = indexvar + 1;
    change_state(sec);
    }
    }
}

int main()
{
    std::fstream streamWriterObject(tapeTextFile.c_str()), streamReaderObject(fileTextFile.c_str());
    if(streamReaderObject.is_open()){
    streamReaderObject>>statetempvar;
    sizevar = statetempvar.length();
    statearray = new std::string[sizevar];
    countState=0;
    while(countState<sizevar){statearray[countState]=statetempvar[countState];countState = countState + 1;}
    change_state(fir);
    std::cout<<printoutput;
    std::cout<<statetempvar;
    std::cout<<std::endl;
    std::cout<<finaloutput;
    countState=0;
    while(countState<sizevar){std::cout<<statearray[countState];countState = countState + 1;}
    std::cout<<std::endl;
    std::cout<<statevariable;
    std::cout<<std::endl;
    streamWriterObject<<statevariable;
    streamWriterObject.close();
    }
    return 0;
}