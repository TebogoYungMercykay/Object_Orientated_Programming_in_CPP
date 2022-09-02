#include "chessboard.h"
#include "chesspiece.h"

Chessboard::Chessboard(Chessboard &obj)
{
    Chessboard::rows = obj.rows;
    Chessboard::columns = obj.columns;
    Chessboard::board = new Chesspiece**[Chessboard::rows];
    for(int k_iterator = 0;k_iterator<Chessboard::rows;k_iterator++)
    {
        Chessboard::board[k_iterator] = new Chesspiece*[Chessboard::columns];
        for(int t_iterator = 0;t_iterator<Chessboard::columns;t_iterator++)
        {
            if(!obj.board[k_iterator][t_iterator])
            {
                Chessboard::board[k_iterator][t_iterator] = NULL;
            }
            else
            {
                Chessboard::board[k_iterator][t_iterator] = new Chesspiece(*obj.board[k_iterator][t_iterator]);
            }
        }
    }
}

Chessboard::Chessboard(int in_rows, int in_columns)
{
    Chessboard::rows = in_rows;
    Chessboard::columns = in_columns;
    Chessboard::board = new Chesspiece**[Chessboard::rows];
    for(int k_iterator = 0;k_iterator<Chessboard::rows;k_iterator++)
    {
        Chessboard::board[k_iterator] = new Chesspiece*[Chessboard::columns];
        for(int t_iterator = 0;t_iterator<Chessboard::columns;t_iterator++)
        {
            Chessboard::board[k_iterator][t_iterator] = NULL;
        }
    }
}

Chessboard::~Chessboard()
{
    for(int k_iterator = 0;k_iterator<Chessboard::rows;k_iterator++)
    {
        for(int t_iterator = 0;t_iterator<Chessboard::columns;t_iterator++)
        {
            delete Chessboard::board[k_iterator][t_iterator];
        }
        delete [] Chessboard::board[k_iterator];
    }
    delete [] Chessboard::board;
    Chessboard::board = NULL;
}

void Chessboard::addChesspiece(Chesspiece *piece, int row, int column)
{
    Chessboard::board[row][column] = piece;
}

void Chessboard::removeChesspiece(int row, int column)
{
    delete Chessboard::board[row][column];
    Chessboard::board[row][column] = NULL;
}

Chesspiece& Chessboard::at(int row, int column) const{
    return (*Chessboard::board[row][column]);
}

//    Task 2


Chessboard& Chessboard::operator=(const Chessboard &other)
{
    Chessboard::rows=other.rows;
    Chessboard::columns=other.columns;
    Chessboard::board = new Chesspiece**[rows];
    for(int k_iterator = 0;k_iterator<rows;k_iterator++)
    {
        Chessboard::board[k_iterator] = new Chesspiece*[columns];
        for(int t_iterator = 0;t_iterator<columns;t_iterator++)
        {
            if(!other.board[k_iterator][t_iterator])
            {
                Chessboard::board[k_iterator][t_iterator] = NULL;
            }
            else
            {
                Chessboard::board[k_iterator][t_iterator] = new Chesspiece(*other.board[k_iterator][t_iterator]);
            }
        }
    }
    return *this;
}

Chessboard& Chessboard::operator+=(const Chessboard &other)
{
    Chessboard::rows=other.rows;
	Chessboard::columns=other.columns;
    for(int k_iterator = 0;k_iterator<Chessboard::rows;k_iterator++)
    {
        for(int t_iterator = 0;t_iterator<Chessboard::columns;t_iterator++)
        {
            if(!Chessboard::board[k_iterator][t_iterator] && other.board[k_iterator][t_iterator])
            {
                Chessboard::board[k_iterator][t_iterator] = new Chesspiece(*other.board[k_iterator][t_iterator]);
            }
        }
    }
    return *this;
}