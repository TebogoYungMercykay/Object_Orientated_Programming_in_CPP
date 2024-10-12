#ifndef Datalink_H
#define Datalink_H
#include "Layer.h"
#include "Message.h"
#include "Physical.h"
#include <string>

class Datalink : public Layer {
public:
  std::string type;
  Datalink();
  void execute(Message *message, bool sending = true);
};
#endif