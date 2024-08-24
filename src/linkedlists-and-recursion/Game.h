#ifndef GAME_H
#define GAME_H

#include <ctype.h>
#include <sstream>
#include <string>

// Part1
#include "Floor.h"
#include "Map.h"
#include "Player.h"
#include "Wall.h"

// Uncomment for Part 2
#include "Door.h"
#include "Exit.h"
#include "Lamp.h"
#include "MessageQueue.h"

class Game {
private:
  Map *map;
  Player *player;
  MessageQueue *messages;
  Exit *exit;

public:
  Game(int w, int h, std::string chars);
  std::string display();
  void update(char input);
  void playerInteract(Object *obj);
  ~Game();
};
#endif