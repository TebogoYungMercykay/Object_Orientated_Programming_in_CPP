#include "Presentation.h"
#include <iostream>

Presentation::Presentation(): Layer(){
    Transport* myTrasport = new Transport();
    down=myTrasport;
    down->setUp(this);
}
void Presentation::execute(Message* message, bool sending){
    if(sending == true){message->setEncoding(encoding);
        down->execute(message,sending);}
    else{
        if(encoding == message->getEncoding()){
            std::cout<<"Message at Presentation layer on computer: "<<Layer::computerName<<std::endl;
            up->execute(message,sending);}
        else{
            std::cout<<"Encoding type mismatch on computer: "<<Layer::computerName<<" Expected: "<<encoding<<std::endl;message->PrintMessage();}
    }
}
void Presentation::configure(config settings){
    encoding = settings.encoding;
    //Layer::encoding = settings.encoding;
    Layer::configure(settings);
}