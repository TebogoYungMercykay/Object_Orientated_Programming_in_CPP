#ifndef YELLOWBABUSHKA_H
#define YELLOWBABUSHKA_H
#include "Babushka.h"

class YellowBabushka : public Babushka {
public:
  YellowBabushka(const unsigned char *id);
  virtual void encrypt(unsigned char *data, int size);
  virtual void decrypt(unsigned char *data, int size);
};

#endif