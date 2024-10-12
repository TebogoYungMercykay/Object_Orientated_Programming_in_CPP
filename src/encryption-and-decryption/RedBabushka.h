#ifndef REDBABUSHKA_H
#define REDBABUSHKA_H
#include "Babushka.h"

class RedBabushka : public Babushka {
protected:
  unsigned int rotationAmount;

public:
  RedBabushka(const unsigned char *id, unsigned int rotationAmount);
  virtual void encrypt(unsigned char *data, int size);
  virtual void decrypt(unsigned char *data, int size);
};

#endif