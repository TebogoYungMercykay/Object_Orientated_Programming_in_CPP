#ifndef Layer_H
#define Layer_H
#include "Message.h"
#include <string>
struct config{
    std::string encoding;
    std::string ip;
    std::string port;
    std::string DestIP;
    std::string computerName;
    std::string DestPort;
};
class Layer{
    public:
        Layer();
        virtual void execute(Message* message, bool sending = true) = 0;
        virtual ~Layer();
        void setUp(Layer* up);
        virtual void configure(config);
        virtual void link(Layer*);
        Layer* getDown();
    protected:
        std::string computerName;
        Layer* up;
        Layer* down;
};
#endif