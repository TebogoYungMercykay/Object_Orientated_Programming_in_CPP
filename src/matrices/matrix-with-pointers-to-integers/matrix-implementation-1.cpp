#include <iostream>

#include "matrix.h"
using namespace std;

Matrix::Matrix(int in_rows, int in_columns) {
  if (in_rows < 1 || in_columns < 1) {
    this->columns = this->rows = 3;
    int **a = new int *[this->rows];
    int temp = 0;

    while (temp < this->rows) {
      a[temp] = new int[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        a[temp][temp2] = 1;
        temp2 += 1;
      }
      temp += 1;
    }
    this->columns = this->rows = 3;
    this->matrix = new int **[this->rows];
    temp = 0;
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      temp += 1;
    }
    int index = 0;
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &a[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  } else {
    int temp2 = 0;
    this->columns = in_columns;
    this->rows = in_rows;
    int **a = new int *[this->rows];
    int temp = 0;
    while (temp < this->rows) {
      a[temp] = new int[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        a[temp][temp2] = 0;
        temp2 += 1;
      }
      temp += 1;
    }
    temp = 0;
    this->matrix = new int **[this->rows];
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      temp += 1;
    }
    temp = 0;
    int index = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &a[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  }
}
void Matrix::resizeColumns(int num_cols) {
  string post = "Error: cannot have less than 1 column";
  if (num_cols < 1) {
    std::cout << post << std::endl;
  } else if (num_cols < this->columns) {
    int **arr = new int *[this->rows];
    int temp = 0;
    while (temp < this->rows) {
      arr[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        arr[temp][temp2] = *this->matrix[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      delete[] this->matrix[temp];
      temp += 1;
    }
    delete[] this->matrix;
    this->matrix = NULL;
    this->columns = num_cols;
    this->matrix = new int **[this->rows];
    temp = 0;
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &arr[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  } else if (num_cols > this->columns) {
    int **arr = new int *[this->rows];
    int temp = 0;

    while (temp < this->rows) {
      arr[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        arr[temp][temp2] = *this->matrix[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      delete[] this->matrix[temp];
      temp += 1;
    }
    delete[] this->matrix;
    this->matrix = NULL;
    int old = this->columns;
    int index = 0;
    this->columns = num_cols;
    int **a = new int *[this->rows];
    temp = 0;
    while (temp < this->rows) {
      a[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        a[temp][temp2] = 0;
        temp2 += 1;
      }
      temp += 1;
    }
    this->matrix = new int **[this->rows];
    temp = 0;
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      int temp2 = 0;
      while (temp2 < old) {
        this->matrix[temp][temp2] = &arr[temp][temp2];
        temp2 += 1;
      }
      temp2 = old;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &a[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  }
}
Matrix::~Matrix() {
  int temp = 0;
  while (temp < this->rows) {
    delete[] this->matrix[temp];
    temp += 1;
  }
  delete[] this->matrix;
  this->matrix = NULL;
  this->columns = 0;
  this->rows = 0;
}
void Matrix::resizeRows(int num_rows) {
  string post = "Error: cannot have less than 1 row";
  if (num_rows < 1) {
    std::cout << post << std::endl;
  } else if (num_rows < this->rows) {
    int **arr = new int *[this->rows];
    int temp = 0;
    while (temp < this->rows) {
      arr[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        arr[temp][temp2] = *this->matrix[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
    this->rows = num_rows;
    this->matrix = new int **[this->rows];
    temp = 0;
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &arr[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  } else if (num_rows > this->rows) {
    int **arr = new int *[this->rows];
    int temp = 0;
    while (temp < this->rows) {
      arr[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        arr[temp][temp2] = *this->matrix[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
    int old = this->rows;
    int index = 0;
    this->rows = num_rows;
    int **a = new int *[this->rows];
    temp = 0;
    while (temp < this->rows) {
      a[temp] = new int[this->columns];
      temp += 1;
    }
    temp = 0;
    while (temp < this->rows) {
      int temp2 = 0;
      while (temp2 < this->columns) {
        a[temp][temp2] = 0;
        temp2 += 1;
      }
      temp += 1;
    }
    this->matrix = new int **[this->rows];
    temp = 0;
    while (temp < old) {
      this->matrix[temp] = new int *[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &arr[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
    temp = old;
    while (temp < this->rows) {
      this->matrix[temp] = new int *[this->columns];
      int temp2 = 0;
      while (temp2 < this->columns) {
        this->matrix[temp][temp2] = &a[temp][temp2];
        temp2 += 1;
      }
      temp += 1;
    }
  }
}
void Matrix::setMatrix() {
  int **a = new int *[this->rows];
  int temp = 0;

  while (temp < this->rows) {
    a[temp] = new int[this->columns];
    temp += 1;
  }
  temp = 0;
  while (temp < this->rows) {
    int temp2 = 0;
    while (temp2 < this->columns) {
      cin >> a[temp][temp2];
      temp2 += 1;
    }
    temp += 1;
  }
  temp = 0;
  while (temp < this->rows) {
    int temp2 = 0;
    while (temp2 < this->columns) {
      this->matrix[temp][temp2] = &a[temp][temp2];
      temp2 += 1;
    }
    temp += 1;
  }
}
// Do not change the displayMatrix() function
void Matrix::Matrix::displayMatrix() {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {

      cout << *matrix[i][j];

      if (j != columns - 1) {
        cout << " ";
      }
    }

    cout << endl;
  }
}