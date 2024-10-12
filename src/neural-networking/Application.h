#ifndef Application_H
#define Application_H
#include "Layer.h"
#include "Message.h"
#include "Presentation.h"
#include <string>

class Application : public Layer {
public:
  Application();
  void execute(Message *message, bool sending = true);
  void execute(std::string, int);
};
#endif