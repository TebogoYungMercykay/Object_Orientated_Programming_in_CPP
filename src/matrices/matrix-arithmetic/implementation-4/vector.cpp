#include "vector.h"
#include <iomanip>
using namespace std;

// you forgot to implement this function
Vector operator*(const double &m, const Vector &rhs) {
  Vector temp(rhs.size);
  for (int i = 0; i < rhs.size; i++) {
    temp.vector[i] = m * rhs.vector[i];
  }
  return temp;
}

Vector ::Vector(unsigned s) {
  // SHOULD I THROW AN EXCEPTION HERE INSTEAD?
  // SHOULD IT BE <0 OR <=0
  //  You do not need the if statement but it's okay the way it is.
  if (s < 0) {
    throw("Invalid vector size!");
  } else {
    size = s;
  }
  vector = new double[size];
  // You forgot to set indexes to zero.
  for (int i = 0; i < s; i++) {
    vector[i] = 0;
  }
}
Vector::~Vector() {
  delete[] vector;
  vector = NULL;
}
Vector::Vector(const Vector &rhs) {
  size = rhs.size;
  vector = new double[size];
  for (int i = 0; i < size; i++) {
    vector[i] = rhs.vector[i];
  }
}
const Vector &Vector ::operator=(const Vector &rhs) {
  if (this != &rhs) {
    delete[] vector;
    vector = NULL;
    size = rhs.size;
    vector = new double[size];
    for (int i = 0; i < size; i++) {
      vector[i] = rhs.vector[i];
    }
  }
  return *this;
}

void Vector::readFile(istream &infile) {
  // You do not need the if statement since they pass by reference, Meaning
  // infile cannot be null.
  if (infile) {
    for (int i = 0; i < size; i++) {
      infile >> vector[i];
    }
  }
}
void Vector ::print() {
  cout << setw(10) << setprecision(3) << vector[0];
  // the loop will go out f bounds
  // for (int i = 1; i <= size; i++)
  for (int i = 1; i < size; i++) {
    // IS THIS CORRECT?
    // Yes. It is
    cout << setw(10) << setprecision(3) << vector[i];
  }
  cout << endl;
}
unsigned Vector::getSize() const { return size; }
double &Vector ::operator[](const unsigned r) {
  if (r < 0 || r >= size) {
    throw("Error: invalid row index");
  }
  return vector[r];
}
const double &Vector ::operator[](const unsigned r) const

{
  if (r < 0 || r >= size) {
    throw("Error: invalid row index");
  }
  return vector[r];
}

// Vector addition
Vector Vector ::operator+(const Vector &rhs) {
  Vector temp(size);
  if (size == rhs.size) {
    for (int i = 0; i < size; i++) {
      temp.vector[i] = vector[i] + rhs.vector[i];
    }
  } else {
    throw("Error: adding vectors of different dimensionality");
  }
  return temp;
}
Vector &Vector ::operator+=(const Vector &rhs) {
  if (size == rhs.size) {
    for (int i = 0; i < size; i++) {
      this->vector[i] = this->vector[i] + rhs.vector[i];
    }
  } else {
    throw("Error: adding vectors of different dimensionality");
  }
  return *this;
}
// Vector subtraction
Vector Vector ::operator-(const Vector &rhs) {
  Vector temp(size);
  if (size == rhs.size) {
    for (int i = 0; i < size; i++) {
      temp.vector[i] = vector[i] - rhs.vector[i];
    }

  } else {
    throw("Error: subtracting vectors of different dimensionality");
  }
  return temp;
}
Vector &Vector::operator-=(const Vector &rhs) {
  if (size == rhs.size) {
    for (int i = 0; i < size; i++) {
      this->vector[i] = this->vector[i] - rhs.vector[i];
    }

  } else {
    throw("Error: subtracting vectors of different dimensionality");
  }
  return *this;
}
// Scalar multiplication
Vector Vector::operator*(const double &rhs) {
  Vector temp(size);
  for (int i = 0; i < size; i++) {
    temp.vector[i] =
        rhs *
        vector[i]; // which is the same as temp.vector[i] = vector[i] * rhs;
  }
  return temp;
}
Vector &Vector ::operator*=(const double &rhs) {
  for (int i = 0; i < size; i++) {
    this->vector[i] = rhs * this->vector[i];
  }
  return *this;
}
// Vector scalar division
Vector Vector ::operator/(const double &rhs) {
  Vector temp(size);
  if (rhs == 0) {
    throw("Error: division by zero");
  } else {
    for (int i = 0; i < size; i++) {
      temp.vector[i] = vector[i] / rhs;
    }
  }
  return temp;
}

Vector Vector ::operator~() // reverse
{
  Vector temp(size);
  int counter = size - 1;
  for (int i = 0; i < size; i++) {
    temp.vector[i] = vector[counter];
    counter--;
  }
  return temp;
}
Vector Vector::operator^(int pow) {
  Vector temp(*this);
  if (pow < 0) {
    throw("Error:negative power is not supported");
  }
  //  You forgot case pow: 0
  else if (pow == 0) {
    for (int i = 0; i < size; i++) {
      temp.vector[i] = 1;
    }
  } else {
    for (int i = 0; i < size; i++) {
      double temp2 = temp.vector[i];
      for (int j = 1; j < pow; j++) {
        temp.vector[i] *= temp2;
      }
    }
  }
  return temp;
}

Vector &Vector ::operator^=(int pow) {
  Vector temp(*this);
  if (pow < 0) {
    throw("Error:negative power is not supported");
  }
  //  You forgot case pow: 0
  else if (pow == 0) {
    for (int i = 0; i < size; i++) {
      temp.vector[i] = 1;
    }
  } else {
    for (int i = 0; i < size; i++) {
      double temp2 = temp.vector[i];
      for (int j = 1; j < pow; j++) {
        temp.vector[i] *= temp2;
      }
    }
  }
  *this = temp;
  return *this;
}