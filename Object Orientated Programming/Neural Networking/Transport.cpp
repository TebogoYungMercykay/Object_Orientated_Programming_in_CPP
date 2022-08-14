#include "Transport.h"
#include <iostream>

Transport::Transport(): Layer(){
    Network* myNetwork = new Network();
    down=myNetwork;
    myNetwork->setUp(this);
}
void Transport::execute(Message* message, bool sending){
    if(sending == true){
        // message->setOriginPort(port);message->setDestinationPort(DestPort);
        if((message->setOriginPort(port))==false){
            std::cout<<"ERROR OCCURRED WITH ORIGIN PORT"<<std::endl;
            return;}
        else if((message->setDestinationPort(DestPort))==false){
            std::cout<<"ERROR OCCURRED WITH DESTINATION PORT"<<std::endl;
            return;}
        down->execute(message,sending);
    }
    else{
        if(message->getDestinationPort()!=port){std::cout<<"Message sent to wrong port"<<std::endl;
        message->PrintMessage();}
        else if(message->getContentLength()!=(message->getData()).length()){
            std::cout<<"Content Length error"<<std::endl;
            message->PrintMessage();}
        else{std::cout<<"Message at Transport layer"<<std::endl;up->execute(message,false);}
    }
}
void Transport::configure(config settings){
    port = settings.port;
    DestPort = settings.DestPort;
    Layer::configure(settings);
}