#ifndef OBJECTLIST_H
#define OBJECTLIST_H
#include "Object.h"
#include <string>

class ObjectList {
private:
  bool dimension;
  Object *head;
  Object *current;

protected:
public:
  ObjectList(bool dimension);
  void add(Object *obj);
  Object *getHead();
  std::string print();
  void reset();
  Object *iterate();
  std::string debug();
};
#endif