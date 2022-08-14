#ifndef piece_H
#define piece_H
#include <string>
#include <iostream>
#include <sstream>
using namespace std;
class  piece{
		std::string pieceType;
		char side;
		int xPos;
		int yPos;
public:
		piece();
		piece(std::string , char, int, int );
		piece(piece * newPiece);
		~piece();
		char getSide();
		std::string getPieceType();
		int getX();
		int getY();
		void setX(int );
		void setY(int );
		friend std::ostream& operator<<(std::ostream&, const piece&);
		void operator[](int);
		piece& operator+(std::string);
};
#endif  