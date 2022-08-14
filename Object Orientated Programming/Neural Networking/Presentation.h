#ifndef Presentation_H
#define Presentation_H
#include "Message.h"
#include "Layer.h"
#include "Transport.h"
#include <string>

class Presentation: public Layer{
    private:
        std::string encoding;
    public:
        std::string type;
        Presentation();
        void execute(Message* message, bool sending = true);
        void configure(config);
};
#endif