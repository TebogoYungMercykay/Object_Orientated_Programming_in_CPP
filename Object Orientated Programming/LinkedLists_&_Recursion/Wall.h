#ifndef WALL_H
#define WALL_H
#include "Object.h"
// Wall uses the icon ’#’
class Wall: public Object {
    public:
        Wall(int x, int y);
        // Part 2
        void updateLight(char direction, int intensity);
};
#endif