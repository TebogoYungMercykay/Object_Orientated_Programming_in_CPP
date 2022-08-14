#ifndef Message_H
#define Message_H
#include <string>
#include <iostream>
#include <sstream>

class Message{
    public:
        Message(std::string);
        Message(Message*);
        ~Message();
        std::string getData();
        std::string getDestination();
        std::string getOrigin();
        std::string getOriginIP();
        std::string getOriginPort();
        std::string getEncoding();
        std::string getDestinationIP();
        std::string getDestinationPort();
        bool setOriginIP(std::string);
        bool setOriginPort(std::string);
        void setEncoding(std::string);
        bool setDestinationIP(std::string);
        bool setDestinationPort(std::string);
        void PrintMessage();
        int getContentLength();
        void setContentLength(int);
    private:
        std::string data;
        std::string Destination;
        std::string Origin;
        std::string Encoding;
        int contentLength;
};
#endif