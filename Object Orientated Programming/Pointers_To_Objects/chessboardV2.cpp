#include "chessboard.h"
#include "chesspiece.h"

Chessboard::Chessboard(Chessboard &obj){
    const int row = obj.rows;
    const int col = obj.columns;
    board = new Chesspiece**[row];
    for(int i = 0;i<row;i+=1){
        board[i] = new Chesspiece*[col];
        for(int j = 0;j<col;j+=1){
            if(obj.board[i][j]){
                board[i][j] = new Chesspiece(*obj.board[i][j]);
            }
            else{
                board[i][j] = NULL;
            }
        }
    }
    rows = row;
    columns = col;
}

Chessboard::Chessboard(int in_rows, int in_columns){
    const int row = in_rows;
    const int col = in_columns;
    board = new Chesspiece**[row];
    for(int i = 0;i<row;i+=1){
        board[i] = new Chesspiece*[col];
        for(int j = 0;j<col;j+=1){
            board[i][j] = NULL;
        }
    }
    rows = row;
    columns = col;
}

Chessboard::~Chessboard(){
    const int row = rows;
    const int col = columns;
    for(int i = 0;i<row;i+=1){
        for(int j = 0;j<col;j+=1){
            delete board[i][j];
        }
        delete[] board[i];
    }
    delete [] board;
    board = NULL;
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column){
    board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column){
    delete board[row][column];
    board[row][column] = NULL;
}

Chesspiece& Chessboard::at(int row, int column) const{
    return (*board[row][column]);
}

//    Task 2

Chessboard& Chessboard::operator=(const Chessboard &other){
    const int row = other.rows;
    const int col = other.columns;
    board = new Chesspiece**[row];
    for(int i = 0;i<row;i+=1){
        board[i] = new Chesspiece*[col];
        for(int j = 0;j<col;j+=1){
            if(other.board[i][j]){
                board[i][j] = new Chesspiece(*other.board[i][j]);
            }
            else{
                board[i][j] = NULL;
            }
        }
    }
    rows=row;
    columns=col;
    return *this;
}

Chessboard& Chessboard::operator+=(const Chessboard &other){
    const int row = other.rows;
    const int col = other.columns;
    for(int i = 0;i<row;i+=1){
        for(int j = 0;j<col;j+=1){
            if(!board[i][j] && other.board[i][j]){
                board[i][j] = new Chesspiece(*other.board[i][j]);
            }
        }
    }
    rows=row;
	columns=col;
    return *this;
}