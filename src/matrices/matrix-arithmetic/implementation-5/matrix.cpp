#include "matrix.h"
#include <iomanip>
using namespace std;

Matrix operator*(const double &multipler, const Matrix &rhs) {
  Matrix obj(rhs.getRows(), rhs.getCols());
  for (int r = 0; r < rhs.getRows(); r++) {
    for (int c = 0; c < rhs.getCols(); c++) {
      obj.matrix[r][c] = multipler * rhs.matrix[r][c];
    }
  }
  return obj;
}

Matrix::Matrix(unsigned r, unsigned c) {
  this->rows = r;
  this->cols = c;
  this->matrix = new double *[rows];
  for (int F = 0; F < this->rows; F++) {
    this->matrix[F] = new double[this->cols];
  }
  for (int P = 0; P < this->rows; P++) {
    int D = 0;
    for (int x = 0; x < this->cols; x++) {
      this->matrix[P][x] = 0;
    }
  }
}
Matrix::Matrix(const Matrix &rhs) {
  this->rows = rhs.rows;
  this->cols = rhs.cols;
  this->matrix = new double *[this->rows];
  for (int F = 0; F < this->rows; F++) {
    this->matrix[F] = new double[this->cols];
  }
  for (int B = 0; B < this->rows; B++) {
    for (int v = 0; v < this->cols; v++) {
      this->matrix[B][v] = rhs.matrix[B][v];
    }
  }
}
Matrix::~Matrix() {
  if (this->matrix != NULL) {
    for (int V = 0; V < getRows(); V++) {
      delete[] this->matrix[V];
      this->matrix[V] = NULL;
    }
    delete[] this->matrix;
    this->matrix = NULL;
  }
}

void Matrix::print() {
  for (int U = 0; U < this->getRows(); U++) {
    for (int G = 0; G < this->getCols(); G++) {
      std::cout << setw(10);
      std::cout << this->matrix[U][G] << setprecision(3);
    }
    std::cout << "\n";
  }
}
void Matrix::readFile(istream &infile) {
  for (int U = 0; U < this->getRows(); U++) {
    for (int G = 0; G < this->getCols(); G++) {
      infile >> this->matrix[U][G];
    }
  }
}

// Insert overloaded = operator signature
const Matrix &Matrix::operator=(const Matrix &rhs) {
  if (this == &rhs)
    return *this;
  this->rows = rhs.rows;
  this->cols = rhs.cols;
  this->matrix = new double *[this->rows];
  for (int F = 0; F < this->rows; F++) {
    this->matrix[F] = new double[this->cols];
  }
  for (int B = 0; B < this->rows; B++) {
    for (int v = 0; v < this->cols; v++) {
      this->matrix[B][v] = rhs.matrix[B][v];
    }
  }
  return *this;
}

// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix &rhs) {
  if (this->rows != rhs.getRows() || this->cols != rhs.getCols()) {
    throw "Error: adding matrices of different dimensionality";
  } else {
    Matrix Mat_Array(rhs.getRows(), rhs.getCols());
    for (int counter = 0; counter < rhs.getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        Mat_Array.matrix[counter][Index] =
            this->matrix[counter][Index] + rhs.matrix[counter][Index];
      }
    }
    return Mat_Array;
  }
}
Matrix &Matrix::operator+=(const Matrix &rhs) {
  if (this->rows != rhs.getRows() || this->cols != rhs.getCols()) {
    throw "Error: adding matrices of different dimensionality";
  } else {
    for (int counter = 0; counter < rhs.getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        this->matrix[counter][Index] =
            this->matrix[counter][Index] + rhs.matrix[counter][Index];
      }
    }
    return *this;
  }
}
Matrix Matrix::operator-(const Matrix &rhs) {
  if (this->rows != rhs.getRows() || this->cols != rhs.getCols()) {
    throw "Error: subtracting matrices of different dimensionality";
  } else {
    Matrix Mat_Array(rhs.getRows(), rhs.getCols());
    for (int counter = 0; counter < rhs.getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        Mat_Array.matrix[counter][Index] =
            this->matrix[counter][Index] - rhs.matrix[counter][Index];
      }
    }
    return Mat_Array;
  }
}
Matrix &Matrix::operator-=(const Matrix &rhs) {
  if (this->rows != rhs.getRows() || this->cols != rhs.getCols()) {
    throw "Error: subtracting matrices of different dimensionality";
  } else {
    for (int counter = 0; counter < rhs.getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        this->matrix[counter][Index] =
            this->matrix[counter][Index] - rhs.matrix[counter][Index];
      }
    }
    return *this;
  }
}

// Matrix/scalar operations
Matrix Matrix::operator*(const double &rhs) {
  Matrix Mat_Array(this->getRows(), this->getCols());
  for (int counter = 0; counter < this->getRows(); counter++) {
    for (int Index = 0; Index < this->getCols(); Index++) {
      Mat_Array.matrix[counter][Index] = this->matrix[counter][Index] * rhs;
    }
  }
  return Mat_Array;
}
Matrix &Matrix::operator*=(const double &rhs) {
  for (int counter = 0; counter < this->getRows(); counter++) {
    for (int Index = 0; Index < this->getCols(); Index++) {
      this->matrix[counter][Index] = this->matrix[counter][Index] * rhs;
    }
  }
  return *this;
}
Matrix Matrix::operator/(const double &rhs) {
  if (rhs == 0) {
    throw "Error: division by zero";
  } else {
    Matrix Mat_Array(this->getRows(), this->getCols());
    for (int Dj = 0; Dj < this->getRows(); Dj++) {
      for (int Counter = 0; Counter < this->getCols(); Counter++) {
        Mat_Array.matrix[Dj][Counter] = this->matrix[Dj][Counter] / rhs;
      }
    }
    return Mat_Array;
  }
}

Matrix Matrix::operator*(const Matrix &rhs) {
  if (this->cols != rhs.getRows()) {
    throw "Error: invalid matrix multiplication";
  } else {
    Matrix Temp(this->getRows(), rhs.cols);
    for (int counter = 0; counter < this->getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        double Temp2 = 0;
        for (int Index2 = 0; Index2 < rhs.getRows(); Index2++) {
          Temp2 += this->matrix[counter][Index2] * rhs.matrix[Index2][Index];
        }
        Temp.matrix[counter][Index] = Temp2;
      }
    }
    return Temp;
  }
}
Matrix &Matrix::operator*=(const Matrix &rhs) {
  if (this->cols != rhs.getRows()) {
    throw "Error: invalid matrix multiplication";
  } else {
    Matrix Temp(this->getRows(), rhs.cols);
    for (int counter = 0; counter < this->getRows(); counter++) {
      for (int Index = 0; Index < rhs.getCols(); Index++) {
        double Temp2 = 0;
        for (int Index2 = 0; Index2 < rhs.getRows(); Index2++) {
          Temp2 += this->matrix[counter][Index2] * rhs.matrix[Index2][Index];
        }
        Temp.matrix[counter][Index] = Temp2;
      }
    }
    delete this->matrix;
    this->cols = Temp.getCols();
    this->rows = Temp.getRows();
    this->matrix = new double *[this->rows];
    for (int F = 0; F < this->rows; F++) {
      this->matrix[F] = new double[this->cols];
    }
    for (int B = 0; B < this->rows; B++) {
      for (int v = 0; v < this->cols; v++) {
        this->matrix[B][v] = Temp.matrix[B][v];
      }
    }
  }
  return *this;
}
Matrix Matrix::operator^(int pow) {
  Matrix Mat_Array2(*this);
  if (this->getRows() != this->getCols()) {
    throw "Error: non-square matrix provided";
  } else if (pow < 0) {
    throw "Error: negative power is not supported";
  } else {
    if (pow == 0) {
      for (int counter = 0; counter < this->getRows(); counter++) {
        for (int Index = 0; Index < this->getCols(); Index++) {
          if (counter == Index) {
            Mat_Array2.matrix[counter][Index] = 1;
          } else {
            Mat_Array2.matrix[counter][Index] = 0;
          }
        }
      }
      return Mat_Array2;
    } else if (pow == 1) {
      return Mat_Array2;
    } else if (pow > 1) {
      for (int Index4 = 0; Index4 < (pow - 1); Index4++) {
        Mat_Array2 *= *this;
      }
    }
  }
  return Mat_Array2;
}
Matrix &Matrix::operator^=(int pow) {
  if (this->getRows() != this->getCols()) {
    throw "Error: non-square matrix provided";
  } else if (pow < 0) {
    throw "Error: negative power is not supported";
  } else {
    if (pow == 0) {
      for (int counter = 0; counter < this->getRows(); counter++) {
        for (int Index = 0; Index < this->getCols(); Index++) {
          if (counter == Index) {
            this->matrix[counter][Index] = 1;
          } else {
            this->matrix[counter][Index] = 0;
          }
        }
      }
      return *this;
    } else if (pow == 1) {
      return *this;
    } else if (pow > 1) {
      Matrix Mat_Array2(*this);
      for (int Index4 = 0; Index4 < (pow - 1); Index4++) {
        Mat_Array2 *= *this;
      }
      *this = Mat_Array2;
      return *this;
    }
  }
  return *this;
}

// Access the individual elements
double &Matrix::operator()(const unsigned r, const unsigned c) {
  if (r < 0 || r >= this->rows) {
    throw "Error: invalid row index";
  } else if (c < 0 || c >= this->cols) {
    throw "Error: invalid column index";
  }
  return matrix[r][c];
}
const double &Matrix::operator()(const unsigned r, const unsigned c) const {
  if (r < 0 || r >= this->rows) {
    throw "Error: invalid row index";
  } else if (c < 0 || c >= this->cols) {
    throw "Error: invalid column index";
  }
  return matrix[r][c];
}
Vector Matrix::operator[](const unsigned r) const {
  if (r < 0 || r >= this->rows)
    throw "Error: invalid row index";
  Vector v1(this->getCols());
  for (int Cols = 0; Cols < this->getCols(); Cols++) {
    v1[Cols] = this->matrix[r][Cols];
  }
  return v1;
}

// Getters and setters:
unsigned Matrix::getRows() const { return rows; } // Return number of rows
unsigned Matrix::getCols() const { return cols; } // Return number of columns

//  Matrix transpose
Matrix Matrix::operator~() {
  Matrix Temp(this->getCols(), this->getRows());
  for (int Dj = 0; Dj < this->getRows(); Dj++) {
    for (int Counter = 0; Counter < this->getCols(); Counter++) {
      Temp.matrix[Counter][Dj] = this->matrix[Dj][Counter];
    }
  }
  return Temp;
} // transpose

// Linear equations:
Matrix Matrix::operator|(const Matrix &rhs) {
  Matrix Temp3(rhs);
  if (this->getCols() != this->getRows()) {
    throw "Error: non-square matrix provided";
  } else if (rhs.getRows() != this->getRows() || rhs.getCols() != 1) {
    throw "Error: incorrect augmentation";
  } else {
    const int size = rhs.getRows();
    bool reduced = true;
    Matrix Temp(*this);
    Matrix Temp_Vals_2(rhs);
    for (int j = 0; j < (size - 1); j++) {
      for (int i = j + 1; i < size; i++) {
        if (Temp.matrix[i][j] != 0) {
          reduced = false;
          break;
        }
      }
    }
    Matrix Temp2(*this);
    Matrix Temp_Vals_22(rhs);
    reduced = true;
    Temp2 |= Temp_Vals_22;
    for (int j = 0; j < (size); j++) {
      for (int i = 0; i < size; i++) {
        if (Temp.matrix[j][i] != Temp2.matrix[j][i]) {
          reduced = false;
          break;
        }
      }
    }
    for (int j = 0; j < Temp_Vals_22.getRows(); j++) {
      for (int i = 0; i < Temp_Vals_22.getCols(); i++) {
        if (Temp_Vals_2.matrix[j][i] != Temp_Vals_22.matrix[j][i]) {
          reduced = false;
          break;
        }
      }
    }
    if (reduced == false) {
      Temp |= Temp_Vals_2;
    }
    //  Performing back-substitution and obtaining solutions.
    for (int i = size - 1; i >= 0; i--) {
      for (int j = i + 1; j < size; j++) {
        Temp_Vals_2.matrix[i][0] = Temp_Vals_2.matrix[i][0] -
                                   Temp.matrix[i][j] * Temp_Vals_2.matrix[j][0];
      }
      if (Temp.matrix[i][i] == 0) {
        throw "Error: division by zero";
      } else {
        Temp_Vals_2.matrix[i][0] = Temp_Vals_2.matrix[i][0] / Temp.matrix[i][i];
      }
    }
    return Temp_Vals_2;
  }
  return Temp3;
}

Matrix &Matrix::operator|=(Matrix &rhs) {
  if (this->getCols() != this->getRows()) {
    throw "Error: non-square matrix provided";
  } else if (rhs.getRows() != this->getRows() || rhs.getCols() != 1) {
    throw "Error: incorrect augmentation";
  } else {
    const int size = rhs.getRows();
    double m = 0;
    for (int j = 0; j < (size - 1); j++) {
      for (int i = j + 1; i < size; i++) {
        if (this->matrix[j][j] == 0) {
          throw "Error: division by zero";
        } else {
          m = this->matrix[i][j] / this->matrix[j][j];
          for (int k = 0; k < size; k++) {
            this->matrix[i][k] = this->matrix[i][k] - m * this->matrix[j][k];
          }
          rhs.matrix[i][0] = rhs.matrix[i][0] - m * rhs.matrix[j][0];
        }
      }
    }
  }
  return *this;
}