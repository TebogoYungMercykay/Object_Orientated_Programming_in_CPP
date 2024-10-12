#include "Physical.h"
#include <iostream>

Physical::Physical() : Layer() { next = NULL; }
void Physical::execute(Message *message, bool sending) {
  if (sending == true) {
    if (next == NULL) {
      std::cout << "NOT CONNECTED TO A NETWORK" << std::endl;
      message->PrintMessage();
    } else {
      next->execute(message, false);
    }
  } else {
    std::cout << "Message at Physical layer of computer: "
              << Layer::computerName << std::endl;
    up->execute(message, false);
  }
}
Physical::~Physical() {
  // destructor should decouple the current physical object from the network
  //  Physical* my_Pointer=this;
  //  while(my_Pointer->getNext()!=this){my_Pointer=my_Pointer->getNext();}
  //  my_Pointer->next=next;
  //  next=NULL;
  if (next == NULL) {
    return;
  } else if (next != NULL && next != this) {
    Physical *myNode_Ptr = this;
    while (this != myNode_Ptr->next) {
      myNode_Ptr = myNode_Ptr->next;
    }
    myNode_Ptr->next = next;
    next = NULL;
  } else if (next == this) {
    next = NULL;
  }
}
void Physical::link(Layer *LinkStack) {
  Layer *my_Pointer = LinkStack;
  Layer *previous_Pointer = NULL;
  while (my_Pointer) {
    previous_Pointer = my_Pointer;
    my_Pointer = my_Pointer->getDown();
  }
  if (getNext() == NULL) {
    setNext(dynamic_cast<Physical *>(previous_Pointer));
    dynamic_cast<Physical *>(previous_Pointer)->setNext(this);
  } else {
    dynamic_cast<Physical *>(previous_Pointer)->setNext(getNext());
    setNext(dynamic_cast<Physical *>(previous_Pointer));
  }
}
Physical *Physical::getNext() { return next; }
void Physical::setNext(Physical *newNext) { next = newNext; }
void Physical::configure(config settings) {
  Layer::computerName = settings.computerName;
}