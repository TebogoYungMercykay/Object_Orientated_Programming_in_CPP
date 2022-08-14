#ifndef Network_H
#define Network_H
#include "Message.h"
#include "Layer.h"
#include "Datalink.h"
#include <string>

class Network: public Layer{
    private:
        std::string ip;
        std::string DestIP;
    public:
        std::string type;
        Network();
        void execute(Message* message, bool sending = true);
        void configure(config);
};
#endif