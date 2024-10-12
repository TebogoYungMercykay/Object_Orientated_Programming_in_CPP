#include "matrix.h"

#include <fstream>
#include <iomanip>
#include <iostream>

Matrix::Matrix(unsigned r, unsigned c) {
  rows = r;
  cols = c;

  matrix = new double *[rows];

  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];

    for (int c = 0; c < cols; c++) {
      matrix[r][c] = 0;
    }
  }
}

Matrix::Matrix(const Matrix &rhs) {
  this->rows = rhs.rows;
  this->cols = rhs.cols;

  matrix = new double *[rows];

  for (int r = 0; r < rows; r++) {
    matrix[r] = new double[cols];

    for (int c = 0; c < cols; c++) {
      matrix[r][c] = rhs.matrix[r][c];
    }
  }
}

Matrix::~Matrix() {
  for (int r = 0; r < rows; r++) {
    delete[] matrix[r];
    matrix[r] = NULL;
  }

  delete[] matrix;
  matrix = NULL;
}

const Matrix &Matrix::operator=(const Matrix &rhs) {
  if (this != &rhs) {
    for (int r = 0; r < rows; r++) {
      delete[] matrix[r];
      matrix[r] = NULL;
    }

    delete[] matrix;
    matrix = NULL;

    this->rows = rhs.rows;
    this->cols = rhs.cols;

    matrix = new double *[rows];

    for (int r = 0; r < rows; r++) {
      matrix[r] = new double[cols];

      for (int c = 0; c < cols; c++) {
        matrix[r][c] = rhs.matrix[r][c];
      }
    }
  }

  return *this;
}

void Matrix::readFile(istream &infile) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      infile >> matrix[r][c];
    }
  }
}

void Matrix::print() {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      cout << setw(10) << setprecision(3) << matrix[r][c];
    }
    cout << endl;
  }
}

Vector Matrix::operator[](const unsigned r) const {
  Vector vec(cols);

  for (int c = 0; c < cols; c++) {
    vec[c] = matrix[r][c];
  }

  return vec;
}

double &Matrix::operator()(const unsigned r, const unsigned c) {
  if (r >= rows || r < 0) {
    throw "Error: invalid row index";
  }

  if (c >= cols || c < 0) {
    throw "Error: invalid column index";
  }

  return matrix[r][c];
}

const double &Matrix::operator()(const unsigned r, const unsigned c) const {
  if (r >= rows || r < 0) {
    throw "Error: invalid row index";
  }

  if (c >= cols || c < 0) {
    throw "Error: invalid column index";
  }

  return matrix[r][c];
}

unsigned Matrix::getRows() const { return rows; }

unsigned Matrix::getCols() const { return cols; }

Matrix operator*(const double &j, const Matrix &k) {
  Matrix mat(k.rows, k.cols);

  for (int r = 0; r < k.rows; r++) {
    for (int c = 0; c < k.cols; c++) {
      mat.matrix[r][c] = j * k.matrix[r][c];
    }
  }

  return mat;
}

Matrix Matrix::operator*(const double &rhs) {
  Matrix mat(rows, cols);

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      mat.matrix[r][c] = rhs * matrix[r][c];
    }
  }

  return mat;
}

Matrix &Matrix::operator*=(const double &rhs) {
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      matrix[r][c] = rhs * matrix[r][c];
    }
  }

  return *this;
}

Matrix Matrix::operator/(const double &rhs) {
  Matrix mat(rows, cols);

  if (rhs == 0) {
    throw "Error: division by zero";
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat.matrix[r][c] = matrix[r][c] / rhs;
      }
    }
  }

  return mat;
}

Matrix Matrix::operator+(const Matrix &rhs) {
  Matrix mat(rows, cols);

  if (rows != rhs.getRows() || cols != rhs.getCols()) {
    throw "Error: adding matrices of different dimensionality";

    return rhs;
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat.matrix[r][c] = matrix[r][c] + rhs.matrix[r][c];
      }
    }
  }

  return mat;
}

Matrix &Matrix::operator+=(const Matrix &rhs) {
  if (rows != rhs.getRows() || cols != rhs.getCols()) {
    throw "Error: adding matrices of different dimensionality";

    return *this;
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        matrix[r][c] = matrix[r][c] + rhs.matrix[r][c];
      }
    }
  }

  return *this;
}

Matrix Matrix::operator-(const Matrix &rhs) {
  Matrix mat(rows, cols);

  if (rows != rhs.getRows() || cols != rhs.getCols()) {
    throw "Error: subtracting matrices of different dimensionality";

    return rhs;
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat.matrix[r][c] = matrix[r][c] - rhs.matrix[r][c];
      }
    }
  }

  return mat;
}

Matrix &Matrix::operator-=(const Matrix &rhs) {
  if (rows != rhs.getRows() || cols != rhs.getCols()) {
    throw "Error: subtracting matrices of different dimensionality";

    return *this;
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        matrix[r][c] = matrix[r][c] - rhs.matrix[r][c];
      }
    }
  }

  return *this;
}

// CHECK THIS FUNCTION AGAIN
Matrix Matrix::operator*(const Matrix &rhs) {
  Matrix mat(rows, rhs.getCols());

  if (cols != rhs.getRows()) {
    throw "Error: minvalid matrix multiplication";

    return rhs;
  }

  else {
    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < rhs.getCols(); c++) {
        for (int i = 0; i < cols; i++) {
          mat.matrix[r][c] += matrix[r][i] * rhs.matrix[i][c];
        }
      }
    }
  }

  return mat;
}

Matrix &Matrix::operator*=(const Matrix &rhs) {
  if (cols != rhs.getRows()) {
    throw "Error: invalid matrix multiplication";

    return *this;
  }

  else {
    Matrix mat(rows, rhs.getCols());

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < rhs.getCols(); c++) {
        for (int i = 0; i < cols; i++) {
          mat.matrix[r][c] += matrix[r][i] * rhs.matrix[i][c];
        }
      }
    }

    *this = mat;
  }

  return *this;
}

Matrix Matrix::operator^(int pow) {
  if (this->rows != this->cols) {
    throw "Error: non-square matrix provided";

    return *this;
  }

  if (pow < 0) {
    throw "Error: negative power is not supported";

    return *this;
  }

  if (pow == 0) {
    Matrix mat(rows, cols);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (r == c) {
          mat.matrix[r][c] = 1;
        }

        else {
          mat.matrix[r][c] = 0;
        }
      }
    }

    return mat;
  }

  else {
    Matrix mat(rows, cols);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat.matrix[r][c] = matrix[r][c];
      }
    }

    for (int i = 1; i < pow; i++) {
      mat *= *this;
    }

    return mat;
  }
}

Matrix &Matrix::operator^=(int pow) {
  if (this->rows != this->cols) {
    throw "Error: non-square matrix provided";

    return *this;
  }

  if (pow < 0) {
    throw "Error: negative power is not supported";

    return *this;
  }

  if (pow == 0) {
    Matrix mat(rows, cols);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        if (r == c) {
          mat.matrix[r][c] = 1;
        }

        else {
          mat.matrix[r][c] = 0;
        }
      }
    }

    *this = mat;
  }

  else {
    Matrix mat(rows, cols);

    for (int r = 0; r < rows; r++) {
      for (int c = 0; c < cols; c++) {
        mat.matrix[r][c] = matrix[r][c];
      }
    }

    for (int i = 1; i < pow; i++) {
      mat *= *this;
    }

    *this = mat;
  }

  return *this;
}

Matrix Matrix::operator~() {
  Matrix mat(cols, rows);

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      mat.matrix[c][r] = matrix[r][c];
    }
  }

  return mat;
}

Matrix &Matrix::operator|=(Matrix &rhs) {
  double d;

  if (rhs.cols != 1 && rhs.rows != rows) {
    throw "Error: incorrect augmentation";
  }

  if (cols != rows) {
    throw "Error: non-square matrix provided";
  }

  for (int i = 0; i < rows - 1; i++) {
    for (int j = i + 1; j < rows; j++) {
      if (matrix[i][i] == 0)
        throw "Error: division by zero";

      d = matrix[j][i] / matrix[i][i];

      for (int q = 0; q < rows; q++) {
        matrix[j][q] = matrix[j][q] - d * matrix[i][q];
      }

      rhs.matrix[j][0] = rhs.matrix[j][0] - d * rhs.matrix[i][0];
    }
  }

  return *this;
}

Matrix Matrix::operator|(const Matrix &rhs) {
  if (rhs.cols != 1 || rhs.rows != rows) {
    throw "Error: incorrect augmentation";
  }

  if (cols != rows) {
    throw "Error: non-square matrix provided";
  }

  Matrix mat(*this);
  Matrix rMat(rhs);

  mat.operator|=(rMat);

  for (int i = mat.rows - 1; i > -1; i--) {
    for (int j = i + 1; j < mat.rows; j++) {
      if (mat.matrix[i][i] == 0)
        throw "Error: division by zero";

      rMat.matrix[i][0] =
          rMat.matrix[i][0] - mat.matrix[i][j] * rMat.matrix[j][0];
    }
    rMat.matrix[i][0] = rMat.matrix[i][0] / mat.matrix[i][i];
  }

  return rMat;
}