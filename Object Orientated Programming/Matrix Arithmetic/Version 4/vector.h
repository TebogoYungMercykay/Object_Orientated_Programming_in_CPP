#ifndef ASSIGNMENT2TEST_VECTOR_H
#define ASSIGNMENT2TEST_VECTOR_H

#include <iostream>
#include "arithmetic.h"
#include <fstream>

using namespace std;

class Vector : public Arithmetic
{
  friend Vector operator* (const double&, const Vector&);
 public:
  Vector(unsigned s);
  Vector(const Vector& rhs);
  ~Vector();

  void print();
  void readFile(istream &infile);

  // Insert overloaded = operator signature
  const Vector& operator=(const Vector& rhs);

  // Vector mathematical operations
  Vector operator+(const Vector& rhs);
  Vector& operator+=(const Vector& rhs);
  Vector operator-(const Vector& rhs);
  Vector& operator-=(const Vector& rhs);
  Vector operator^(int pow);
  Vector& operator^=(int pow);
  Vector operator~(); // reverse
  

  // Vector/scalar operations
  Vector operator*(const double& rhs);
  Vector& operator*=(const double& rhs);
  Vector operator/(const double& rhs);


  // Access the individual elements
  double& operator[](const unsigned r);
  const double& operator[](const unsigned r) const;

    
  // Getters and setters:
  unsigned getSize() const; // Return number of rows

 private:
  // Insert helper function signatures if necessary

  double * vector; // the vector array
  unsigned size; // # size
};

#endif
