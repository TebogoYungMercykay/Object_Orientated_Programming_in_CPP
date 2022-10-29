#ifndef ASSIGNMENT2TEST_MATRIX_H
#define ASSIGNMENT2TEST_MATRIX_H

#include "arithmetic.h"
#include "vector.h"
#include <fstream>

using namespace std;

class Matrix : public Arithmetic
{
  friend Matrix operator* (const double&, const Matrix&);
  
 public:
  Matrix(unsigned r, unsigned c);
  Matrix(const Matrix& rhs);
  ~Matrix();

  void print();
  void readFile(istream &infile);


  // Insert overloaded = operator signature
  const Matrix& operator=(const Matrix& rhs);

  // Matrix mathematical operations
  Matrix operator+(const Matrix& rhs);
  Matrix& operator+=(const Matrix& rhs);
  Matrix operator-(const Matrix& rhs);
  Matrix& operator-=(const Matrix& rhs);
  Matrix operator*(const Matrix& rhs);
  Matrix& operator*=(const Matrix& rhs);
  Matrix operator^(int pow);
  Matrix& operator^=(int pow);
  Matrix operator~(); // transpose
  

  // Matrix/scalar operations
  Matrix operator*(const double& rhs);
  Matrix& operator*=(const double& rhs);
  Matrix operator/(const double& rhs);


  // Access the individual elements
  double& operator()(const unsigned r, const unsigned c);
  const double& operator()(const unsigned r, const unsigned c) const;
  Vector operator[](const unsigned r) const;


  // Getters and setters:
  unsigned getRows() const; // Return number of rows
  unsigned getCols() const; // Return number of columns

  // Linear equations:
  Matrix operator|(const Matrix& rhs);
  Matrix& operator|=(Matrix& rhs);

 private:
  // Insert helper function signatures if necessary

  double ** matrix; // the matrix array
  unsigned rows; // # rows
  unsigned cols; // # columns
};

#endif
