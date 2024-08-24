#include "Wall.h"
using namespace std;

Wall::Wall(int x, int y) : Object(x, y) { this->icon = '#'; }
// Part 2
void Wall::updateLight(char direction, int intensity) {}