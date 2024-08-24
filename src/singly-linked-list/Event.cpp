#include "Event.h"

using namespace std;

Event::~Event() {}

Event::Event(long int start, long int end, int id, string type) {
  this->next = NULL;
  this->start = start;
  this->end = end;
  this->id = id;
  this->type = type;
}

ostream &operator<<(ostream &out, Event &event) {
  out << event.type << " ";
  out << unix_to_string(event.start) << "->";
  out << unix_to_string(event.end);
  return out;
}