#ifndef MESSAGE_H
#define MESSAGE_H
#include <string>

class Message {
    private:
        std::string text;
    public:
        Message* next;
        Message(std::string t);
        std::string getText();
};
#endif