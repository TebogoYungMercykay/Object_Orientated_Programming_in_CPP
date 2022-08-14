#ifndef Datalink_H
#define Datalink_H
#include "Message.h"
#include "Layer.h"
#include "Physical.h"
#include <string>

class Datalink: public Layer{
    public:
        std::string type;
        Datalink();
        void execute(Message* message, bool sending = true);
};
#endif