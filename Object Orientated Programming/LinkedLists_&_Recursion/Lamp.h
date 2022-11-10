#ifndef LAMP_H
#define LAMP_H
#include "Object.h"

class Lamp: public Object {
    public:
        Lamp(int x, int y);
        void update();
};
#endif