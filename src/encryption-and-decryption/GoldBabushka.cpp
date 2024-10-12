#include "GoldBabushka.h"
#include "OverflowException.h"
#include "UnderflowException.h"
#include <iostream>
GoldBabushka::GoldBabushka(const unsigned char *id, unsigned char xorValue)
    : Babushka(id) {
  this->xorValue = xorValue;
}
void GoldBabushka::encrypt(unsigned char *data, int size) {
  UnderflowException underflowException;
  OverflowException overflowException;
  for (int i = 0; i < size; i++) {
    if ((data[i] ^ this->xorValue) > MAX_VALUE_INCLUSIVE)
      throw overflowException;
    else if ((data[i] ^ this->xorValue) < MIN_VALUE_INCLUSIVE)
      throw underflowException;
    data[i] = (data[i] ^ this->xorValue);
  }
}
void GoldBabushka::decrypt(unsigned char *data, int size) {
  this->encrypt(data, size);
}