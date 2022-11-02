#ifndef LAMB_H
#define LAMB_H
#include "Object.h"

class Lamb: public Object {
    public:
        Lamb(int x, int y);
        void update();
};
#endif