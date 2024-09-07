#include "vector.h"
#include <iomanip>
using namespace std;

Vector operator*(const double &m, const Vector &rhs) {
  Vector tempVector(rhs);
  int c = 0;
  for (; c < tempVector.size;) {
    tempVector.vector[c] = m * tempVector.vector[c];
    c++;
  }
  return tempVector;
}

Vector::Vector(unsigned s) {
  const int tempSize = s;
  vector = new double[tempSize];
  int c = 0;
  for (; c < tempSize;) {
    vector[c] = 0;
    c++;
  }
  size = tempSize;
}

Vector::Vector(const Vector &rhs) {
  const int tempSize = rhs.size;
  vector = new double[tempSize];
  int c = 0;
  for (; c < tempSize;) {
    vector[c] = rhs.vector[c];
    c++;
  }
  size = tempSize;
}

Vector::~Vector() {
  delete[] vector;
  vector = NULL;
}

void Vector::print() {
  const int tempSize = size;
  int c = 0;
  for (; c < tempSize;) {
    cout << setw(10) << vector[c] << setprecision(3);
    c++;
  }
  cout << endl;
}
void Vector::readFile(istream &infile) {
  const int tempSize = size;
  int c = 0;
  for (; c < tempSize;) {
    infile >> vector[c];
    c++;
  }
}

// Insert overloaded = operator signature
const Vector &Vector::operator=(const Vector &rhs) {
  if (this == &rhs) {
    return *this;
  } else {
    size = rhs.size;
    vector = new double[rhs.size];
    int c = 0;
    for (; c < rhs.size;) {
      vector[c] = rhs.vector[c];
      c++;
    }
  }
  return *this;
}

// Vector mathematical operations
Vector Vector::operator+(const Vector &rhs) {
  if (size != rhs.size) {
    throw "Error: adding vectors of different dimensionality";
  } else {
    const int tempSize = rhs.size;
    Vector tempVector(tempSize);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = vector[c] + rhs.vector[c];
      c++;
    }
    return tempVector;
  }
}
Vector &Vector::operator+=(const Vector &rhs) {
  if (size != rhs.size) {
    throw "Error: adding vectors of different dimensionality";
  } else {
    const int tempSize = rhs.size;
    Vector tempVector(tempSize);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = vector[c] + rhs.vector[c];
      c++;
    }
    *this = tempVector;
    return *this;
  }
}
Vector Vector::operator-(const Vector &rhs) {
  if (size != rhs.size) {
    throw "Error: subtracting vectors of different dimensionality";
  } else {
    const int tempSize = rhs.size;
    Vector tempVector(tempSize);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = vector[c] - rhs.vector[c];
      c++;
    }
    return tempVector;
  }
}
Vector &Vector::operator-=(const Vector &rhs) {
  if (size != rhs.size) {
    throw "Error: subtracting vectors of different dimensionality";
  } else {
    const int tempSize = rhs.size;
    Vector tempVector(tempSize);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = vector[c] - rhs.vector[c];
      c++;
    }
    *this = tempVector;
    return *this;
  }
}
Vector Vector::operator^(int pow) {
  if (pow == 0) {
    const int tempSize = size;
    Vector tempVector(*this);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = 1;
      c++;
    }
    return tempVector;
  }
  if (pow < 0) {
    throw "Error: negative power is not supported";
  } else {
    const int tempSize = size;
    Vector tempVector(*this);
    int c = 0;
    for (; c < tempSize;) {
      double temp1 = tempVector.vector[c], temp2 = temp1;
      int c2 = 0;
      for (; c2 < pow - 1;) {
        temp1 *= temp2;
        c2++;
      }
      tempVector.vector[c] = temp1;
      c++;
    }
    return tempVector;
  }
  Vector tempVector(*this);
  return tempVector;
}
Vector &Vector::operator^=(int pow) {
  if (pow == 0) {
    const int tempSize = size;
    Vector tempVector(*this);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = 1;
      c++;
    }
    *this = tempVector;
  }
  if (pow < 0) {
    throw "Error: negative power is not supported";
  } else {
    const int tempSize = size;
    Vector tempVector(*this);
    int c = 0;
    for (; c < tempSize; c++) {
      double temp1 = tempVector.vector[c], temp2 = temp1;
      int c2 = 0;
      for (; c2 < pow - 1;) {
        temp1 *= temp2;
        c2++;
      }
      tempVector.vector[c] = temp1;
      c++;
    }
    *this = tempVector;
  }
  return *this;
}

// Vector/scalar operations
Vector Vector::operator*(const double &rhs) {
  const int tempSize = size;
  Vector tempVector(tempSize);
  int c = 0;
  for (; c < tempSize;) {
    tempVector.vector[c] = vector[c] * rhs;
    c++;
  }
  return tempVector;
}
Vector &Vector::operator*=(const double &rhs) {
  const int tempSize = size;
  Vector tempVector(tempSize);
  int c = 0;
  for (; c < tempSize;) {
    tempVector.vector[c] = vector[c] * rhs;
    c++;
  }
  *this = tempVector;
  return *this;
}
Vector Vector::operator/(const double &rhs) {
  if (rhs == 0) {
    throw "Error: division by zero";
  } else {
    const int tempSize = size;
    Vector tempVector(tempSize);
    int c = 0;
    for (; c < tempSize;) {
      tempVector.vector[c] = vector[c] / rhs;
      c++;
    }
    return tempVector;
  }
}

// Access the individual elements
double &Vector::operator[](const unsigned r) {
  if (r < 0 || r >= size) {
    throw "Error: invalid row i";
  }
  return vector[r];
}
const double &Vector::operator[](const unsigned r) const {
  if (r < 0 || r >= size) {
    throw "Error: invalid row i";
  }
  return vector[r];
}

unsigned Vector::getSize() const { return size; }

Vector Vector::operator~() {
  const int tempSize = size;
  Vector tempVector(tempSize);
  int c = 0;
  for (; c < tempSize;) {
    tempVector.vector[c] = vector[(size - 1) - c];
    c++;
  }
  return tempVector;
}