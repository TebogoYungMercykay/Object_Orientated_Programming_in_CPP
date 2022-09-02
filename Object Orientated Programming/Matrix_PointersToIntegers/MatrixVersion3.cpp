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
Matrix::Matrix(int fg, int gh){
    if(fg<1 || gh<1){
        this->columns = 3;
        this->rows = 3;
        int **gbhh = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            gbhh[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                gbhh[j][c] = 1;
            }
        }
        this->matrix = new int**[this->rows];
        for(int j = 0;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
        }
        int index = 0;
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &gbhh[j][c];
            }
        }
    }
    else{
        int temp2 = 0;
        this->columns = gh;
        this->rows = fg;
        int **gbhh = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            gbhh[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                gbhh[j][c] = 0;
            }
        }
        this->matrix = new int**[this->rows];
        for(int j = 0;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
        }
        int index = 0;
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &gbhh[j][c];
            }
        }
    }
}
Matrix::~Matrix(){
    for(int j = 0;j<this->rows;j++){
        // for(int c = 0;c<this->rows;c++){
        //     delete [] this->matrix[j][c];
        // }
        delete [] this->matrix[j];
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
        for(int j = 0;j<this->rows;j++){
            arr[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                arr[j][c]=*this->matrix[j][c];
            }
        }
        for(int j = 0;j<this->rows;j++){
            delete [] this->matrix[j];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        this->rows = num_rows;
        this->matrix = new int**[this->rows];
        for(int j = 0;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &arr[j][c];
            }
        }
    }
    else if(num_rows>this->rows){
        int ** arr = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            arr[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                arr[j][c]=*this->matrix[j][c];
            }
        }
        for(int j = 0;j<this->rows;j++){
            delete [] this->matrix[j];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        int old = this->rows;
        int index = 0;
        this->rows = num_rows;
        int **gbhh = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            gbhh[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                gbhh[j][c] = 0;
            }
        }
        this->matrix = new int**[this->rows];
        for(int j = 0;j<old;j++){
            this->matrix[j] = new int*[this->columns];
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &arr[j][c];
            }
        }
        for(int j = old;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &gbhh[j][c];
            }
        }
    }
}
void Matrix::resizeColumns(int num_cols){
    if(num_cols<1){
        std::cout<<"Error: cannot have less than 1 column"<<std::endl;
    }
    else if(num_cols<this->columns){
        int ** arr = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            arr[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                arr[j][c]=*this->matrix[j][c];
            }
        }
        for(int j = 0;j<this->rows;j++){
            delete [] this->matrix[j];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        this->columns = num_cols;
        int temp = 0;
        this->matrix = new int**[this->rows];
        for(int j = 0;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
            for(int c = 0;c<this->columns;c++){
                this->matrix[j][c] = &arr[j][c];
            }
        }
    }
    else if(num_cols>this->columns){
        int ** arr = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            arr[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                arr[j][c]=*this->matrix[j][c];
            }
        }
        for(int j = 0;j<this->rows;j++){
            delete [] this->matrix[j];
        }
        delete [] this->matrix;
        this->matrix = NULL;
        int old = this->columns;
        int index = 0;
        this->columns = num_cols;
        int **gbhh = new int*[this->rows];
        for(int j = 0;j<this->rows;j++){
            gbhh[j] = new int[this->columns];
        }
        for(int j = 0;j<this->rows;j++){
            for(int c = 0;c<this->columns;c++){
                gbhh[j][c] = 0;
            }
        }
        this->matrix = new int**[this->rows];
        for(int j = 0;j<this->rows;j++){
            this->matrix[j] = new int*[this->columns];
            for(int c = 0;c<old;c++){
                this->matrix[j][c] = &arr[j][c];
            }
            for(int c = old;c<this->columns;c++){
                this->matrix[j][c] = &gbhh[j][c];
            }
        }
    }
}
void Matrix::setMatrix(){
    int **gbhh = new int*[this->rows];
    for(int j = 0;j<this->rows;j++){
        gbhh[j] = new int[this->columns];
    }
    for(int j = 0;j<this->rows;j++){
        for(int c = 0;c<this->columns;c++){
            cin>>gbhh[j][c];
        }
    }
    for(int j = 0;j<this->rows;j++){
        for(int c = 0;c<this->columns;c++){
            this->matrix[j][c]=&gbhh[j][c];
        }
    }
}