#ifndef PLAYER_H
#define PLAYER_H
#include "Object.h"
// Player uses the icon ’&’
class Player: public Object {
    public:
        Player(int x, int y);
        void move(int x, int y);
};
#endif