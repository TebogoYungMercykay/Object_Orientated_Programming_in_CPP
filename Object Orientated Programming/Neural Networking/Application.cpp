#include "Application.h"
#include <iostream>

Application::Application(): Layer(){
    Presentation* pres = new Presentation();
    down=pres;
    down->setUp(this);
}
void Application::execute(Message* message, bool sending){
    if(sending==true){down->execute(message,sending);}
    else{std::cout<<"Computer "<<Layer::computerName<<" Received message: "<<message->getData()<<std::endl;}
}
void Application::execute(std::string data, int contentLength){
    Message* myMessage = new Message(data);
    myMessage->setContentLength(contentLength);
    down->execute(myMessage,true);
}