#include "Datalink.h"
#include <iostream>

Datalink::Datalink() : Layer() {
  Physical *myPhysical = new Physical();
  down = myPhysical;
  down->setUp(this);
}
void Datalink::execute(Message *message, bool sending) {
  if (sending == true) {
    down->execute(message, sending);
  } else {
    std::cout << "Message at Datalink layer" << std::endl;
    up->execute(message, sending);
  }
}