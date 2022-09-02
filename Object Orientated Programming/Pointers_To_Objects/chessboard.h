#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <iostream>
#include "chesspiece.h"

using namespace std;

class Chessboard {
private:
    int rows, columns;
    Chesspiece ***board;

public:

    Chessboard(Chessboard &obj);

    Chessboard(int in_rows, int in_columns);

    ~Chessboard();

    void addChesspiece(Chesspiece *piece, int row, int column);

    void removeChesspiece(int row, int column);

    Chesspiece &at(int row, int column) const;

//    Task 2


    Chessboard &operator=(const Chessboard &other);

    Chessboard &operator+=(const Chessboard &rhs);

    Chesspiece ***returnBoard() {
        return board;
    };

    void displayBoard() {

        string temp = "";

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                char c;

                if (board[i][j] != 0) {
                    if (at(i, j).getName() == "king" && at(i, j).getType())
                        c = 'X';
                    else if (at(i, j).getName() == "king")
                        c = 'x';
                    else if (at(i, j).getType())
                        c = toupper(at(i, j).getName()[0]);
                    else
                        c = tolower(at(i, j).getName()[0]);
                } else {
                    c = '*';
                }

                temp += c;

                if (columns != columns - 1) {
                    temp += " ";
                }
            }

            temp += "\n";
        }

        cout << temp;

    }
};


#endif //CHESSBOARD_H
