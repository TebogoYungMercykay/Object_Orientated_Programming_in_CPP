#include "Layer.h"

Layer::Layer() {
  up = NULL;
  down = NULL;
}
void Layer::execute(Message *message, bool sending) {}
Layer::~Layer() {
  // delete up;
  // up=NULL;
  if (down) {
    delete down;
    down = NULL;
  }
}
void Layer::setUp(Layer *Up) { up = Up; }
void Layer::configure(config settings) {
  computerName = settings.computerName;
  down->configure(settings);
}
void Layer::link(Layer *linkStack) { down->link(linkStack); }
Layer *Layer::getDown() { return down; }