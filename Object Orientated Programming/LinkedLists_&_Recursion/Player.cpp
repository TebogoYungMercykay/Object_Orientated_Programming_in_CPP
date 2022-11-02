#include "Player.h"
using namespace std;

Player::Player(int x, int y): Object(x, y){
    this->icon = '&';
}
void Player::move(int x, int y){
    // Must be implemented after the Map Class
}