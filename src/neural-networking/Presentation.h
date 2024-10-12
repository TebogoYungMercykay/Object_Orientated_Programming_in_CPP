#ifndef Presentation_H
#define Presentation_H
#include "Layer.h"
#include "Message.h"
#include "Transport.h"
#include <string>

class Presentation : public Layer {
private:
  std::string encoding;

public:
  std::string type;
  Presentation();
  void execute(Message *message, bool sending = true);
  void configure(config);
};
#endif