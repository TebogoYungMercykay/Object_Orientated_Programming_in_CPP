#include "Network.h"
#include <iostream>

Network::Network(): Layer(){
    Datalink* myDatalink = new Datalink();
    down=myDatalink;
    myDatalink->setUp(this);
}
void Network::execute(Message* message, bool sending){
    if(sending == true){
        // message->setOriginIP(ip);message->setDestinationIP(DestIP);
        if((message->setOriginIP(ip))==false){
            std::cout<<"ERROR OCCURRED WITH ORIGIN IP"<<std::endl;
            return;}
        else if((message->setDestinationIP(DestIP))==false){
            std::cout<<"ERROR OCCURRED WITH DESTINATION IP"<<std::endl;
            return;}
        down->execute(message,sending);
    }
    else{
        if((message->getDestinationIP()==ip)){
            std::cout<<"Message at Network layer"<<std::endl;
            up->execute(message,false);}
        else if((message->getOriginIP()==ip)){
            std::cout<<"Message has been returned to sender without finding the destination"<<std::endl;
            message->PrintMessage();}
        else{
            std::cout<<"Message at Network layer"<<std::endl;
            down->execute(message,true);
        }
    }
}
void Network::configure(config settings){
    ip = settings.ip;
    DestIP = settings.DestIP;
    Layer::configure(settings);   
}