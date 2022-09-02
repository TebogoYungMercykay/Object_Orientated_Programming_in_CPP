#include <iostream>

#include "matrix.h"
using namespace std;

//Do not change the displayMatrix() function
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
Matrix::Matrix(int in_rows, int in_columns){
    if(in_rows<1 || in_columns<1){
        this->columns = 3;
        this->rows = 3;
        this->matrix = new int**[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(1);
            }
        }
    }
    else{
        int temp2 = 0;
        this->columns = in_columns;
        this->rows = in_rows;
        this->matrix = new int**[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
        }
        int index = 0;
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(0);
            }
        }
    }
}
Matrix::~Matrix(){
    int k_iterator = 0;
    for(;k_iterator<this->rows;k_iterator++){
        int t_iterator = 0;for(;t_iterator<this->rows;t_iterator++){
            delete [] this->matrix[k_iterator][t_iterator];
        }
        delete [] this->matrix[k_iterator];
    }
    delete [] this->matrix;
    this->matrix = NULL;
    this->columns = 0;
    this->rows = 0;
}
void Matrix::resizeRows(int num_rows){
    if(num_rows<1){
        std::cout<<"Error: cannot have less than 1 row"<<std::endl;
    }
    else if(num_rows<this->rows){
        int ** arr = new int*[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            arr[k_iterator] = new int[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                arr[k_iterator][t_iterator]=*this->matrix[k_iterator][t_iterator];
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete [] this->matrix[k_iterator];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        int old = this->rows;
        this->rows = num_rows;
        this->matrix = new int**[this->rows];
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(arr[k_iterator][t_iterator]);
            }
        }
        k_iterator = 0;
        for(;k_iterator<old;k_iterator++){
            delete arr[k_iterator];
            arr[k_iterator] = NULL;
        }
        delete [] arr;
        arr = NULL;
    }
    else if(num_rows>this->rows){
        int ** arr = new int*[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            arr[k_iterator] = new int[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                arr[k_iterator][t_iterator]=*this->matrix[k_iterator][t_iterator];
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete [] this->matrix[k_iterator];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        int old = this->rows;
        int index = 0;
        this->rows = num_rows;
        this->matrix = new int**[this->rows];
        k_iterator = 0;
        for(;k_iterator<old;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(arr[k_iterator][t_iterator]);
            }
        }
        for(int k_iterator = old;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(0);
            }
        }
        k_iterator = 0;
        for(;k_iterator<old;k_iterator++){
            delete arr[k_iterator];
            arr[k_iterator] = NULL;
        }
        delete [] arr;
        arr = NULL;
    }
}
void Matrix::resizeColumns(int num_cols){
    if(num_cols<1){
        std::cout<<"Error: cannot have less than 1 column"<<std::endl;
    }
    else if(num_cols<this->columns){
        int ** arr = new int*[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            arr[k_iterator] = new int[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                arr[k_iterator][t_iterator]=*this->matrix[k_iterator][t_iterator];
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete [] this->matrix[k_iterator];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        this->columns = num_cols;
        int temp = 0;
        this->matrix = new int**[this->rows];
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(arr[k_iterator][t_iterator]);
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete arr[k_iterator];
            arr[k_iterator] = NULL;
        }
        delete [] arr;
        arr = NULL;
    }
    else if(num_cols>this->columns){
        int ** arr = new int*[this->rows];
        int k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            arr[k_iterator] = new int[this->columns];
            int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
                arr[k_iterator][t_iterator]=*this->matrix[k_iterator][t_iterator];
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete [] this->matrix[k_iterator];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        int old = this->columns;
        int index = 0;
        this->columns = num_cols;
        k_iterator = 0;
        k_iterator = 0;
        this->matrix = new int**[this->rows];
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            this->matrix[k_iterator] = new int*[this->columns];
            int t_iterator = 0;for(;t_iterator<old;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(arr[k_iterator][t_iterator]);
            }
            for(int t_iterator = old;t_iterator<this->columns;t_iterator++){
                this->matrix[k_iterator][t_iterator] = new int(0);
            }
        }
        k_iterator = 0;
        for(;k_iterator<this->rows;k_iterator++){
            delete arr[k_iterator];
            arr[k_iterator] = NULL;
        }
        delete [] arr;
        arr = NULL;
    }
}
void Matrix::setMatrix(){
    int k_iterator = 0;
    for(;k_iterator<this->rows;k_iterator++){
        int t_iterator = 0;for(;t_iterator<this->columns;t_iterator++){
            int store = 0;
            cin>>store;
            this->matrix[k_iterator][t_iterator]=new int(store);
        }
    }
}