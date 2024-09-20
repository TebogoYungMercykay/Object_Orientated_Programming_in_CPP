#include "YellowBabushka.h"
#include <iostream>
YellowBabushka::YellowBabushka(const unsigned char *id) : Babushka(id) {}
void YellowBabushka::encrypt(unsigned char *data, int size) {
  unsigned char *temp;
  temp = new unsigned char[size];
  int xnh = 0;
  int kh = size - 1;
  while (kh >= 0) {
    temp[xnh] = data[kh];
    xnh++;
    kh--;
  }
  int gh = 0;
  while (gh < size) {
    data[gh] = temp[gh];
    gh += 1;
  }
}
void YellowBabushka::decrypt(unsigned char *data, int size) {
  this->encrypt(data, size);
}