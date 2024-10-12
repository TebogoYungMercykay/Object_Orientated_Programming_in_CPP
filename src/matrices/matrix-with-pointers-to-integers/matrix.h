#ifndef PRAC2CODE_MATRIX_H
#define PRAC2CODE_MATRIX_H

#include <iostream>

class Matrix {
private:
  int ***matrix;
  int rows, columns;

public:
  Matrix(int in_rows, int in_columns);

  ~Matrix();

  void resizeRows(int num_rows);

  void resizeColumns(int num_cols);

  void setMatrix();

  void displayMatrix();
};

#endif // PRAC2CODE_MATRIX_H
