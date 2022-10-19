#ifndef EVENT_H
#define EVENT_H

#include <string>
#include "Utils.h"

using namespace std;

class Event {
    public:
        long int start;
        long int end;
        int id;
        string type;
        Event* next;
        ~Event();
        Event(long int start, long int end, int id, string type);
        friend ostream& operator<<(ostream& out, Event& event);
    protected:
    private:
};
#endif // EVENT_H