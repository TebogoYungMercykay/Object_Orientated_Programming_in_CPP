#ifndef PHYSICAL_H
#define PHYSICAL_H
#include "Layer.h"
#include "Message.h"
#include <string>

class Physical : public Layer {
public:
  Physical();
  void execute(Message *message, bool sending = true);
  ~Physical();
  void link(Layer *);
  Physical *getNext();
  void setNext(Physical *);
  void configure(config);

private:
  Physical *next;
};

#endif