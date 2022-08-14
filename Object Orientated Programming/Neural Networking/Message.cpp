#include "Message.h"
#include <iostream>
#include <sstream>

Message::Message(std::string MessageData){
    this->Origin = "";
    this->Encoding = "";
    this->Destination = "";
    this->data = MessageData;
    this->contentLength = MessageData.length();
}
Message::Message(Message* msg){
    this->data = msg->getData();
}
Message::~Message(){
    std::cout<<"Deleted message containing: "<<this->data<<std::endl;
}
std::string Message::getData(){
    return this->data;
}
bool IsIntergerNumber(std::string myS){
    for(int k_iterator=0;k_iterator<myS.length();k_iterator++){
        char myArr[] = "abcdefghijklmnopqrstuvwxyz";
        char myArr2[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for(int p_iterator=0;p_iterator<26;p_iterator++){
            if(myS[k_iterator]==myArr[p_iterator] || myS[k_iterator]==myArr2[p_iterator]){
                return false;}
        }
    }
    return true;
}
std::string Message::getDestination(){
    if(this->Destination!="" && this->Destination!="\0"){
        std::stringstream St (this->Destination);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            if(IsIntergerNumber(store_iterator)){myArray[k_iterator]=store_iterator;}
            k_iterator+=1;}
        getline(St,store_iterator,':');
        if(IsIntergerNumber(store_iterator)){myArray[3]=store_iterator;}
        St>>store_iterator;
        if(IsIntergerNumber(store_iterator)){myArray[4]=store_iterator;}
        if(myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="" && myArray[4]!=""){
            return this->Destination;}
    }
    return "ERROR: INCOMPLETE ADDRESS";
}
std::string Message::getOrigin(){
    if(this->Origin!="" && this->Origin!="\0"){
        std::stringstream St (this->Origin);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            if(IsIntergerNumber(store_iterator)){myArray[k_iterator]=store_iterator;}
            k_iterator+=1;}
        getline(St,store_iterator,':');
        if(IsIntergerNumber(store_iterator)){myArray[3]=store_iterator;}
        St>>store_iterator;
        if(IsIntergerNumber(store_iterator)){myArray[4]=store_iterator;}
        if(myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="" && myArray[4]!=""){
            return this->Origin;}
    }
    return "ERROR: INCOMPLETE ADDRESS";
}
std::string Message::getOriginIP(){
    if(this->Origin!="" && this->Origin!="\0"){
        std::stringstream St (this->Origin);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            if(IsIntergerNumber(store_iterator)){myArray[k_iterator]=store_iterator;}
            k_iterator+=1;}
        getline(St,store_iterator,':');
        if(IsIntergerNumber(store_iterator)){myArray[3]=store_iterator;}
        St>>store_iterator;
        if(IsIntergerNumber(store_iterator)){myArray[4]=store_iterator;}
        if((myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="")){
            return myArray[0]+"."+myArray[1]+"."+myArray[2]+"."+myArray[3];}
    }
    return "ERROR: IPV4 NOT SET";
}
std::string Message::getOriginPort(){
    if(this->Origin!="" && this->Origin!="\0"){
        std::stringstream St (this->Origin);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            myArray[k_iterator]=store_iterator;
            k_iterator+=1;}
        getline(St,store_iterator,':');
        myArray[3]=store_iterator;
        St>>myArray[4];
        if(myArray[4]!="" && IsIntergerNumber(myArray[4])){
            return myArray[4];}
    }
    return "ERROR: PORT NOT SET";
}
std::string Message::getEncoding(){
    if(this->Encoding!="" && this->Encoding!="\0"){
        return this->Encoding;}
    return "";
}
std::string Message::getDestinationIP(){
    if(this->Destination!="" && this->Destination!="\0"){
        std::stringstream St (this->Destination);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            if(IsIntergerNumber(store_iterator)){myArray[k_iterator]=store_iterator;}
            k_iterator+=1;}
        getline(St,store_iterator,':');
        if(IsIntergerNumber(store_iterator)){myArray[3]=store_iterator;}
        St>>store_iterator;
        if(IsIntergerNumber(store_iterator)){myArray[4]=store_iterator;}
        if((myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="")){
            return myArray[0]+"."+myArray[1]+"."+myArray[2]+"."+myArray[3];}
    }
    return "ERROR: IPV4 NOT SET";
}
std::string Message::getDestinationPort(){
    if(this->Destination!="" && this->Destination!="\0"){
        std::stringstream St (this->Destination);
        std::string store_iterator;
        std::string myArray[5]= {"","","","",""};
        int k_iterator=0;
        while( k_iterator<3 && getline(St,store_iterator,'.')){
            myArray[k_iterator]=store_iterator;
            k_iterator+=1;}
        getline(St,store_iterator,':');
        myArray[3]=store_iterator;
        St>>myArray[4];
        if(myArray[4]!="" && IsIntergerNumber(myArray[4])){
            return myArray[4];}
    }
    return "ERROR: PORT NOT SET";
}
void Message::setEncoding(std::string Econding){
    this->Encoding = Econding;
}
bool Message::setOriginIP(std::string OriginIP){
    if(this->getOriginIP()=="ERROR: IPV4 NOT SET"){
        if(OriginIP!=""){
            int counter=0;
            std::stringstream St (OriginIP);
            std::string store_iterator;
            std::string myArray[4]= {"","","",""};
            int k_iterator=0;
            while( k_iterator<3 && getline(St,store_iterator,'.')){
                myArray[k_iterator]=store_iterator;
                k_iterator+=1;}
            St>>myArray[3];
            int A = -1, B = -1, C = -1, D = -1;
            if (IsIntergerNumber(myArray[0]) && IsIntergerNumber(myArray[1])&& IsIntergerNumber(myArray[2])&& IsIntergerNumber(myArray[3]))
            {
                std::stringstream convert(myArray[0]);
                convert >> A;
                std::stringstream convertB(myArray[1]);
                convertB >> B;
                std::stringstream convertC(myArray[2]);
                convertC >> C;
                std::stringstream convertD(myArray[3]);
                convertD >> D;
                if (A >= 0 && A <= 255 && B >= 0 && B <= 255 && C >= 0 && C <= 255 && D >= 0 && D <= 255 ){
                    std::string port = this->Origin;
                    this->Origin = OriginIP + ":" + port;
                    return true;
                }
            }
            // for(int k_iterator = 0;k_iterator<4;k_iterator++){
            //     int k_const=-2;
            //     if(IsIntergerNumber(myArray[k_iterator])){
            //     std::stringstream temp (myArray[k_iterator]);
            //     temp>>k_const;}
            //     if(k_const>=0 && k_const<=255){counter+=1;}
            // }
            // if(counter == 4 && (myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="")){
            //     this->Origin=myArray[0]+"."+myArray[1]+"."+myArray[2]+"."+myArray[3];
            //     return true;}
            //     else{return false;}
        }
    }
    return false;
}
bool Message::setOriginPort(std::string OriginPort){
    if(this->getOriginPort()=="ERROR: PORT NOT SET" && IsIntergerNumber(OriginPort)){
        int k_const;
        std::stringstream temp (OriginPort);
        temp>>k_const;
        if(k_const>=0 && k_const<=65535){
            this->Origin=OriginPort;
            return true;}
        else{return false;}
    }
    return false;
}
bool Message::setDestinationIP(std::string DestinatioIP){
    if(this->getDestinationIP()=="ERROR: IPV4 NOT SET"){
        if(DestinatioIP!=""){
            int counter=0;
            std::stringstream St (DestinatioIP);
            std::string store_iterator;
            std::string myArray[4]= {"","","",""};
            int k_iterator=0;
            while( k_iterator<3 && getline(St,store_iterator,'.')){
                myArray[k_iterator]=store_iterator;
                k_iterator+=1;}
            St>>myArray[3];
            int A = -1, B = -1, C = -1, D = -1;
            if (IsIntergerNumber(myArray[0]) && IsIntergerNumber(myArray[1])&& IsIntergerNumber(myArray[2])&& IsIntergerNumber(myArray[3]))
            {
                std::stringstream convert(myArray[0]);
                convert >> A;
                std::stringstream convertB(myArray[1]);
                convertB >> B;
                std::stringstream convertC(myArray[2]);
                convertC >> C;
                std::stringstream convertD(myArray[3]);
                convertD >> D;
                if (A >= 0 && A <= 255 && B >= 0 && B <= 255 && C >= 0 && C <= 255 && D >= 0 && D <= 255 ){
                    std::string port = this->Destination;
                    this->Destination = DestinatioIP + ":" + port;
                    return true;
                }
            }
            // for(int k_iterator = 0;k_iterator<4;k_iterator++){
            //     int k_const=-2;
            //     if(IsIntergerNumber(myArray[k_iterator])){
            //     std::stringstream temp (myArray[k_iterator]);
            //     temp>>k_const;}
            //     if(k_const>=0 && k_const<=255){counter+=1;}
            // }
            // if(counter == 4 && (myArray[0]!="" && myArray[1]!="" && myArray[2]!="" && myArray[3]!="")){
            //     this->Destination=myArray[0]+"."+myArray[1]+"."+myArray[2]+"."+myArray[3];
            //     return true;}
            // else{return false;}
        }
    }
    return false;
}
bool Message::setDestinationPort(std::string DestinatioPort){
    if(this->getDestinationPort()=="ERROR: PORT NOT SET" && IsIntergerNumber(DestinatioPort)){
        int k_const;
        std::stringstream temp (DestinatioPort);
        temp>>k_const;
        if(k_const>=0 && k_const<=65535){
            this->Destination=DestinatioPort;
            return true;}
        else{return false;}
    }
    return false;
}
void Message::PrintMessage(){
    std::cout<<"Data: "<<this->getData()<<std::endl;
    std::cout<<"Destination: "<<this->getDestination()<<std::endl;
    std::cout<<"Destination IPV4: "<<this->getDestinationIP()<<std::endl;
    std::cout<<"Destination Port: "<<this->getDestinationPort()<<std::endl;
    std::cout<<"Origin: "<<this->getOrigin()<<std::endl;
    std::cout<<"Origin IPV4: "<<this->getOriginIP()<<std::endl;
    std::cout<<"Origin Port: "<<this->getOriginPort()<<std::endl;
    std::cout<<"Encoding: "<<this->getEncoding()<<std::endl;
}
int Message::getContentLength(){
    return this->contentLength;
}
void Message::setContentLength(int ContentLength){
     this->contentLength = ContentLength;
}
// #include <iostream>
// #include <sstream>
// #include <string>
// int main() {
//     // Write C++ code here
//     std::cout << "Hello world!";
//     int a,s,d,f,g;
//     char l;
//     std::string k = " 127.34.4.13:8800";
//     std::stringstream St (k);
//     St>>a>>l>> s>>l>> d>>l>> f>>l >>g;
//     std::cout<<a<<" - "<<s<<" - "<<d<<" - "<<f<<" - "<<g<<std::endl;
//     return 0;
// }