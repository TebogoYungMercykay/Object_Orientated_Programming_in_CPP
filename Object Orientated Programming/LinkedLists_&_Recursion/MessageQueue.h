#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H
#include "Message.h"
#include <string>

class MessageQueue {
    private:
        std::string text;
    public:
        int timeout;
        int current;
        Message* head;
        Message* tail;
        MessageQueue(int timeOut);
        std::string print();
        void addMessage(Message* m);
        ~MessageQueue();
};
#endif