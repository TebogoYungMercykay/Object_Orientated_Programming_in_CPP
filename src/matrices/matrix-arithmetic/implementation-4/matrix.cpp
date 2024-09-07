#include "matrix.h"
#include <iomanip>
using namespace std;

// you forgot to implement this function
Matrix operator*(const double &m, const Matrix &rhs) {
  Matrix temp(rhs.rows, rhs.cols);
  for (int i = 0; i < rhs.rows; i++) {
    for (int j = 0; j < rhs.cols; j++) {
      // multiply the elements of Matrix rhs and m and store them in a
      // temp matrix
      temp.matrix[i][j] = rhs.matrix[i][j] * m;
    }
  }
  return temp;
}

Matrix::Matrix(unsigned r, unsigned c) {
  // CAN A MATRIX HAVE ZERO ROWS OR COLS
  // The if statements aren't really required.
  if (r < 0) {
    throw("Error: invalid row value");
  }
  if (c < 0) {
    throw("Error: invalid column value");
  } else {
    rows = r;
    cols = c;
  }
  matrix = new double *[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols];
    for (int j = 0; j < cols; j++) {
      matrix[i][j] = 0;
      // OR *(*(matrix + i) + j) =0;
      // The matrix[i][j] is not a pointer, This will not work ->
      // *matrix[i][j] = 0;
    }
  }
}
Matrix ::~Matrix() {
  if (matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      delete[] matrix[i];
      matrix[i] = NULL;
    }
  }
  delete[] matrix;
  matrix = NULL;
}

Matrix::Matrix(const Matrix &rhs) {
  rows = rhs.rows;
  cols = rhs.cols;
  matrix = new double *[rows];
  for (int i = 0; i < rows; i++) {
    matrix[i] = new double[cols];
    for (int j = 0; j < cols; j++) {
      // Copy even zeroes from rhs.matrix
      // if(rhs.matrix[i][j]!=0)
      // {
      //     matrix[i][j] = rhs.matrix[i][j];
      //     //IS THIS CORRECT?
      //     // Yes: It's the perfect way of assigning the corresponding
      //     values.
      // }
      matrix[i][j] = rhs.matrix[i][j];
    }
  }
}

const Matrix &Matrix::operator=(const Matrix &rhs) {
  if (this != &rhs) {
    // Deleting dynamic memory first
    if (matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
        matrix[i] = NULL;
      }
    }
    delete[] matrix;
    matrix = NULL;

    rows = rhs.rows;
    cols = rhs.cols;
    matrix = new double *[rows];
    for (int i = 0; i < rows; i++) {
      // You forgot to allocate memory for the cols
      matrix[i] = new double[cols];
      for (int j = 0; j < cols; j++) {
        matrix[i][j] = rhs.matrix[i][j];
      }
    }
  }
  return *this;
}
void Matrix::readFile(istream &infile) {
  // You do not need the if statement since they pass by reference, Meaning
  // infile cannot be null. infile has to be an existing object. And if it's
  // empty nothing will be stored with or without the if statement eitherway.
  if (infile) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        infile >> matrix[i][j];
        // IS THIS CORRECT?
        //  Yes it is:
        //  You can also use something like getline(infile,
        //  stringVariable, '
        //  '); Then convert the string to double using stringstream and
        //  store the value afterwads. OR store the val from infile and
        //  store them in a temp variable the set matrix[i][j] to be
        //  equal to the variable.
      }
    }
  }
}
void Matrix::print() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << setw(10) << setprecision(3);
      cout << matrix[i][j];
      // if(j!=cols-1)
      // {
      //     cout<<" ";
      // }
    }
    cout << endl;
  }
}
unsigned Matrix ::getRows() const { return rows; }
unsigned Matrix::getCols() const { return cols; }
// Access the individual elements

// Setter
double &Matrix ::operator()(const unsigned r, const unsigned c) {

  if (r >= rows || r < 0) {
    throw("Error: invalid row index");
  }
  if (c >= cols || c < 0) {
    throw("Error: invalid column index");
  }
  return matrix[r][c];
}

// Getter
const double &Matrix ::operator()(const unsigned r, const unsigned c) const {
  // CAN A MATRIX HAVE ZERO ROWS OR COLS
  if (r >= rows || r < 0) {
    throw("Error: invalid row index");
  }
  if (c >= cols || c < 0) {
    throw("Error: invalid column index");
  }
  return matrix[r][c];
}
Vector Matrix ::operator[](const unsigned r) const {
  if (r >= rows || r < 0) {
    throw("Error: invalid row index");
  }
  Vector temp(cols);
  for (int i = 0; i < cols; i++) {
    temp[i] = matrix[r][i];
  }
  return temp;
}

// Matrix addition
Matrix Matrix ::operator+(const Matrix &rhs) {
  Matrix temp(rows, cols);
  if (rows == rhs.rows && cols == rhs.cols) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // Add the corresponding elements of Matrix this and Matrix rhs
        // and store them in a temp matrix
        temp.matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
      }
    }

  } else {
    throw("Error: adding matrices of different dimensionality");
  }
  return temp;
}
Matrix &Matrix ::operator+=(const Matrix &rhs) {

  if (rows == rhs.rows && cols == rhs.cols) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {

        this->matrix[i][j] = this->matrix[i][j] + rhs.matrix[i][j];
      }
    }
  } else {
    throw("Error: adding matrices of different dimensionality");
  }
  return *this;
}

// Matrix Subtraction
Matrix Matrix ::operator-(const Matrix &rhs) {
  Matrix temp(rows, cols);
  if (rows == rhs.rows && cols == rhs.cols) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // Subtract the corresponding elements of Matrix this and Matrix
        // rhs and store them in a temp matrix
        temp.matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
      }
    }

  } else {
    throw("Error: subtracting matrices of different dimensionality");
  }
  return temp;
}
Matrix &Matrix ::operator-=(const Matrix &rhs) {
  if (rows == rhs.rows && cols == rhs.cols) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        // Subtract the corresponding elements of Matrix this and Matrix
        // rhs and store them in a temp matrix
        this->matrix[i][j] = this->matrix[i][j] - rhs.matrix[i][j];
      }
    }

  } else {
    throw("Error: subtracting matrices of different dimensionality");
  }
  return *this;
}
// Matrix scalar multiplication
Matrix Matrix ::operator*(const double &rhs) {
  Matrix temp(rows, cols);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      temp.matrix[i][j] =
          rhs * matrix[i][j]; // which is the same as temp.matrix[i][j] =
                              // matrix[i][j] * rhs;
    }
  }
  return temp;
}
Matrix &Matrix ::operator*=(const double &rhs) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      this->matrix[i][j] = rhs * this->matrix[i][j];
    }
  }

  return *this;
}
// Matrix scalar division
Matrix Matrix ::operator/(const double &rhs)

{
  Matrix temp(rows, cols);
  if (rhs == 0) {
    throw("Error: division by zero");
  } else {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < cols; j++) {
        temp.matrix[i][j] = matrix[i][j] / rhs;
      }
    }
  }
  return temp;
}

Matrix Matrix ::operator~() // transpose
{
  // Create a temp matrix with rows = this->cols  AND cols = this->rows
  unsigned newRows = this->cols;
  unsigned newCols = this->rows;
  Matrix temp(newRows, newCols);
  for (int i = 0; i < newRows; i++) {
    for (int j = 0; j < newCols; j++) {
      temp.matrix[i][j] = matrix[j][i];
    }
  }
  return temp;
}

Matrix Matrix ::operator^(int pow) {
  Matrix temp(*this);
  // Check if the matrix is square or not AND also check if pow is nonnegative
  if (pow < 0) {
    throw("Error: negative power is not supported");
  } else if (pow == 0) {
    // If it is a square matrix
    if (rows == cols) {
      // Convert it to an identity matrix
      unsigned newRows = this->cols;
      unsigned newCols = this->rows;
      // Matrix temp2(*this);
      for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
          temp.matrix[i][j] = 0;
          if (i == j) {
            temp.matrix[i][j] = 1;
          }
        }
      }
    } else {
      throw("Error: non-square matrix provided");
    }
  } else {
    // If it is a square matrix
    if (rows == cols) {
      // Multiply the matrix with itself
      //  Matrix temp(*this);
      for (int i = 1; i < pow; i++) {
        temp *= *this;
      }
    } else {
      throw("Error: non-square matrix provided");
    }
  }

  return temp;
}
Matrix &Matrix ::operator^=(int pow) {
  // Check if the matrix is square or not AND also check if pow is nonnegative
  if (pow < 0) {
    throw("Error: negative power is not supported");
  } else if (pow == 0) {
    // If it is a square matrix
    if (rows == cols) {
      // Convert it to an identity matrix
      unsigned newRows = this->cols;
      unsigned newCols = this->rows;
      Matrix temp(*this);
      for (int i = 0; i < newRows; i++) {
        for (int j = 0; j < newCols; j++) {
          this->matrix[i][j] = 0;
          if (i == j) {
            this->matrix[i][j] = 1;
          }
        }
      }
    } else {
      throw("Error: non-square matrix provided");
    }
  } else {
    // If it is a square matrix
    if (rows == cols) {
      // Multiply the matrix with itself
      Matrix temp(*this);
      for (int i = 1; i < pow; i++) {
        *this *= temp;
      }
    } else {
      throw("Error: non-square matrix provided");
    }
  }
  return *this;
}

Matrix Matrix ::operator*(const Matrix &rhs) {
  Matrix temp(rows, rhs.getCols());
  // First initialize the temp matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rhs.getCols(); j++) {
      temp.matrix[i][j] = 0;
    }
  }

  if (cols == rhs.rows) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rhs.cols; j++) {
        for (int k = 0; k < this->cols; k++) {
          temp.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
        }
      }
    }
  } else {
    throw("Error: invalid matrix multiplication");
  }
  return temp;
}
Matrix &Matrix ::operator*=(const Matrix &rhs) {
  // //Delete the current matrix and create a new one with new dimensions
  // if(matrix!=NULL)
  // {
  //     for(int i = 0; i < rows; i++)
  //     {
  //         delete [] matrix[i];
  //         matrix[i] = NULL;
  //     }
  // }
  // delete [] matrix;
  // matrix = NULL;

  // matrix = new double*[rows];
  // for(int i = 0; i < rows; i++)
  // {
  //     matrix[i] = new double[rhs.getCols()];
  //     for(int j = 0; j < rhs.getCols(); j++)
  //     {
  //         matrix[i][j] = 0;
  //         //OR *matrix[i][j] =0;
  //     }

  // }

  // if(cols==rhs.rows)
  // {
  //     for(int i = 0; i < rows; i++)
  //     {
  //         for(int j = 0; j < rhs.cols; j++)
  //         {
  //             for(int k = 0; k < this->cols ; k++)
  //             {
  //                 matrix[i][j]+=matrix[i][k] * rhs.matrix[k][j];
  //             }
  //         }
  //     }
  // }
  // else
  // {
  //     throw("Error: invalid matrix multiplication");
  // }
  Matrix temp(rows, rhs.getCols());
  // First initialize the temp matrix
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < rhs.getCols(); j++) {
      temp.matrix[i][j] = 0;
    }
  }

  if (cols == rhs.rows) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < rhs.cols; j++) {
        for (int k = 0; k < this->cols; k++) {
          temp.matrix[i][j] += matrix[i][k] * rhs.matrix[k][j];
        }
      }
    }
  } else {
    throw("Error: invalid matrix multiplication");
  }
  *this = temp;
  return *this;
}
Matrix Matrix::operator|(const Matrix &rhs) {
  if (rows == cols && (rhs.rows == rows && rhs.cols == 1)) {
    Matrix s(rhs);
    Matrix Ss(rhs);
    Matrix A(*this);
    Matrix Aa(*this);
    Aa |= Ss;
    bool augmented = true;
    for (int i = 0; i < A.rows; i++) {
      if (s[i][0] != Ss[i][0]) {
        augmented = false;
        break;
      }
      for (int j = 0; j < A.cols; j++) {
        if (A[i][j] != Aa[i][j]) {
          augmented = false;
          break;
        }
      }
    }
    if (augmented == false) {
      A |= s;
    }
    for (int i = rows - 1; i >= 0; i--) {
      for (int j = i + 1; j < rows; j++) {
        s(i, 0) = s[i][0] - A[i][j] * s(j, 0);
      }
      if (A(i, i) == 0) {
        throw "Error: division by zero";
      }
      s(i, 0) = s[i][0] / A[i][i];
    }
    return s;
  } else {
    if (rows != cols) {
      throw "Error: non-square matrix provided";
    } else {
      throw "Error: incorrect augmentation";
    }
  }
}
Matrix &Matrix ::operator|=(Matrix &rhs) {
  if (rows == cols && (rhs.rows == rows && rhs.cols == 1)) {
    Matrix temp_b(rhs);
    Matrix temp_A(*this);
    double temp_m;
    for (int i = 0; i < rows - 1; i++) {
      for (int j = i + 1; j < rows; j++) {
        if (temp_A[i][i] == 0) {
          throw "Error: division by zero";
        } else {
          temp_m = temp_A[j][i] / temp_A[i][i];
          for (int k = 0; k < cols; k++) {
            temp_A(j, k) = temp_A[j][k] - (temp_A[i][k] * temp_m);
          }
          temp_b(j, 0) = temp_b[j][0] - temp_m * temp_b(i, 0);
        }
      }
    }
    *this = temp_A;
    rhs = temp_b;
  } else {
    if (rows != cols) {
      throw "Error: non-square matrix provided";
    } else {
      throw "Error: incorrect augmentation";
    }
  }
  return *this;
}