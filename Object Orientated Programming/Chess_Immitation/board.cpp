#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "piece.h"
#include "board.h"

using namespace std; 
#include "piece.h"
#include <fstream>

board::board(std::string pieceList){
	std::string line_string="";
	std::ifstream my_inputFile;
	my_inputFile.open(pieceList.c_str());
	getline(my_inputFile,line_string);
	this->sideToMove=line_string[0];
	line_string="";
	getline(my_inputFile,this->move);
	this->numWhitePieces=0;
	this->numBlackPieces=0;
	while(getline(my_inputFile,line_string)){
		std::string type="";
		std::stringstream ss(line_string);
		if(line_string[0]=='w'){
			this->numWhitePieces++;
		}
		else if(line_string[0]=='b'){
		 	this->numBlackPieces++;
		}
	}
	my_inputFile.close();
	my_inputFile.open(pieceList.c_str());
	getline(my_inputFile,line_string);
	getline(my_inputFile,line_string);
	this->whitePieces=new piece*[this->numWhitePieces];
	this->blackPieces=new piece*[this->numBlackPieces];	
	int wIndex=0;
	int bIndex=0;
	this->chessboard= new std::string*[8];
	for(int x_index=0; x_index<8; x_index++){
		this->chessboard[x_index]= new std::string[8];
		for(int y_inde=0; y_inde<8;y_inde++){
			this->chessboard[x_index][y_inde]="-";
		}
	}
	while(getline(my_inputFile,line_string)){
		std::string type="";
		std::stringstream ss(line_string);
		int x_inde=0,y_inde=0;
		if(line_string[0]=='w'){
			int counter_var=0;
			while(ss.good()){
				std::string sub;
        		getline(ss, sub, ',');
        		if(counter_var==1){
					type=sub;
				}
        		else if(counter_var==2){
					std::stringstream sur (sub);
					sur>>x_inde;
					sur.clear();
				}
        		else if(counter_var==3){
					std::stringstream sur (sub);
					sur>>y_inde;
					sur.clear();
				}
        		counter_var++;
			}
			if(type=="king"){
				this->chessboard[x_inde][y_inde]="wK";
			}
			else{
				this->chessboard[x_inde][y_inde]="w"+type.substr(0,1);
			}
			this->whitePieces[wIndex]=new piece(type,line_string[0], x_inde, y_inde);
			wIndex++;
		}
		else if(line_string[0]=='b'){
		 	int counter_var=0;
			while(ss.good()){
				std::string sub;
        		getline(ss, sub, ',');
        		if(counter_var==1){
					type=sub;
				}
        		else if(counter_var==2){
					std::stringstream sur (sub);
					sur>>x_inde;
					sur.clear();
				}
        		else if(counter_var==3){
					std::stringstream sur (sub);
					sur>>y_inde;
					sur.clear();
				}
        		counter_var++;
			}
			if(type=="king"){
				this->chessboard[x_inde][y_inde]="bK";
			}
			else{
				this->chessboard[x_inde][y_inde]="b"+type.substr(0,1);
			}
			this->blackPieces[bIndex]=new piece(type,line_string[0],x_inde,y_inde);
			bIndex++;
		}
	}
	/*this->operator++();
	for(int k=0;k<8;k++){
		for(int u=0;u<8;u++){
			cout<<this->chessboard[k][u]<<" ";
		}
		cout<<endl;
	}
	for(int k=0;k<numBlackPieces;k++){
		if(blackPieces[k]){
			cout<<this->blackPieces[k]->getX()<<"  "<<this->blackPieces[k]->getY()<<"  "<<this->blackPieces[k]->getSide()<<endl;
		}
	}
	cout<<"Black Pieces: "<<numBlackPieces<<endl;
	for(int k=0;k<numWhitePieces;k++){
		if(whitePieces[k]){
			cout<<this->whitePieces[k]->getX()<<"  "<<this->whitePieces[k]->getY()<<"  "<<this->whitePieces[k]->getSide()<<endl;
		}
	}
	cout<<"White Pieces: "<<numWhitePieces<<endl;*/
	my_inputFile.close();
}
board::~board(){
	int iterator_RowCoord=0;
	while(iterator_RowCoord<this->numBlackPieces){
		if(this->blackPieces[iterator_RowCoord]!=NULL){
			delete this->blackPieces[iterator_RowCoord];
			this->blackPieces[iterator_RowCoord]=NULL;
		}
		iterator_RowCoord+=1;
	}
	delete[] blackPieces;
	blackPieces=NULL;
	iterator_RowCoord=0;
	while(iterator_RowCoord<this->numWhitePieces){
		if(this->whitePieces[iterator_RowCoord]!=NULL){
			delete this->whitePieces[iterator_RowCoord];
			this->whitePieces[iterator_RowCoord]=NULL;
		}
		iterator_RowCoord+=1;
	}
	delete[] this->whitePieces;
	this->whitePieces=NULL;
	iterator_RowCoord=0;
	while(iterator_RowCoord<8){
		delete[] this->chessboard[iterator_RowCoord];
		iterator_RowCoord+=1;
	}
	delete[] this->chessboard;
	this->chessboard=NULL;
	std::cout<<"Num Pieces Removed: "<<(this->numBlackPieces+this->numWhitePieces)<<"\n";
	this->numWhitePieces=0;
	this->numBlackPieces=0;
}
board& board::operator++(){
	int oldX_index=0;
	int oldY_index=0;
	int newX_index=0;
	int newY_index=0;
	//cout<<move<<endl;
	std::stringstream osos_stream_temp (this->move);
	int index_counter_var=0;
	std::string line_string_temp;
	while(getline(osos_stream_temp,line_string_temp,',')){
		std::stringstream as_stream_temp (line_string_temp);
		if(index_counter_var==0){
			as_stream_temp>>oldX_index;
		}
		else if(index_counter_var==1){
			as_stream_temp>>oldY_index;
		}
		else if(index_counter_var==2){
			as_stream_temp>>newX_index;
		}
		else if(index_counter_var==3){
			as_stream_temp>>newY_index;
		}
		index_counter_var++;
	}
	this->chessboard[newX_index][newY_index]=this->chessboard[oldX_index][oldY_index];
	this->chessboard[oldX_index][oldY_index]="-";
	int iterator_black_white=0;
	if(this->sideToMove=='w'){
		iterator_black_white=0;
		while(iterator_black_white<this->numWhitePieces){
			if(this->whitePieces[iterator_black_white]!=NULL){
				if(this->whitePieces[iterator_black_white]->getX()==oldX_index && this->whitePieces[iterator_black_white]->getY()==oldY_index){
					this->whitePieces[iterator_black_white]->setX(newX_index);
					this->whitePieces[iterator_black_white]->setY(newY_index);
					break;
				}
			}
			iterator_black_white+=1;
		}
	}
	else{
		iterator_black_white=0;
		while(iterator_black_white<this->numBlackPieces){
			if(this->blackPieces[iterator_black_white]!=NULL){
				if(this->blackPieces[iterator_black_white]->getX()==oldX_index && this->blackPieces[iterator_black_white]->getY()==oldY_index){
					this->blackPieces[iterator_black_white]->setX(newX_index);
					this->blackPieces[iterator_black_white]->setY(newY_index);
					break;
				}
			}
			iterator_black_white+=1;
		}
	}
	return *this;
}
bool board::checkIfPieceHasCheck(std::string pieceType, int xPosi, int yPosi, int kingX, int kingY){
	int iteratorX_Coordinate=0;
	int iteratorY_Coordinate=0;
	if(pieceType=="pawn"){
		if((xPosi-1==kingX && yPosi-1==kingY)||(xPosi-1==kingX && yPosi+1==kingY)||(xPosi+1==kingX && yPosi-1==kingY)||(xPosi+1==kingX && yPosi+1==kingY)){
			return true;
		}	
	}
	else if(pieceType=="bishop"){
		if(xPosi<kingX && yPosi<kingX){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate<=kingY,iteratorX_Coordinate<=kingX;iteratorX_Coordinate++,iteratorY_Coordinate++){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi<kingX && yPosi>kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate>=kingY,iteratorX_Coordinate<=kingX;iteratorX_Coordinate++,iteratorY_Coordinate--){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi>kingX && yPosi<kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate<=kingY,iteratorX_Coordinate>=kingX;iteratorX_Coordinate--,iteratorY_Coordinate++){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi>kingX && yPosi>kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate>=kingY,iteratorX_Coordinate>=kingX;iteratorX_Coordinate--,iteratorY_Coordinate--){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
	}
	else if(pieceType=="queen"){
		if(xPosi<kingX && yPosi<kingX){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate<=kingY,iteratorX_Coordinate<=kingX;iteratorX_Coordinate++,iteratorY_Coordinate++){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi<kingX && yPosi>kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate>=kingY,iteratorX_Coordinate<=kingX;iteratorX_Coordinate++,iteratorY_Coordinate--){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi>kingX && yPosi<kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate<=kingY,iteratorX_Coordinate>=kingX;iteratorX_Coordinate--,iteratorY_Coordinate++){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi>kingX && yPosi>kingY){
			for(iteratorX_Coordinate=xPosi,iteratorY_Coordinate=yPosi;iteratorY_Coordinate>=kingY,iteratorX_Coordinate>=kingX;iteratorX_Coordinate--,iteratorY_Coordinate--){
				if(this->chessboard[iteratorX_Coordinate][iteratorY_Coordinate]!="-"){
					if(iteratorX_Coordinate==kingX && iteratorY_Coordinate==kingY){
						return true;
					}
					else if(iteratorX_Coordinate!=kingX && iteratorY_Coordinate!=kingY){
						return false;
					}
				}
			}
		}
		else if(xPosi==kingX && yPosi>kingY){
			iteratorY_Coordinate=yPosi;
			while(iteratorY_Coordinate>=0){
				if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate==kingY){
					return true;
				}
				else if(this->chessboard[xPosi][iteratorY_Coordinate]!="-"){
					return false;
				}
				iteratorY_Coordinate-=1;
			}
		}
		else if(xPosi==kingX && yPosi<kingY){
			iteratorY_Coordinate=yPosi;
			while(iteratorY_Coordinate<8){
				if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate==kingY){
					return true;
				}
				else if(this->chessboard[xPosi][iteratorY_Coordinate]!="-"){
					return false;
				}
				iteratorY_Coordinate+=1;
			}
		}
		else if(xPosi>kingX && yPosi==kingY){
			iteratorX_Coordinate=xPosi;
			while(iteratorX_Coordinate>=0){
				if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorX_Coordinate==kingX){
					return true;
				}
				else if(this->chessboard[iteratorX_Coordinate][yPosi]!="-"){
					return false;
				}
				iteratorX_Coordinate-=1;
			}
		}
		else if(xPosi<kingX && yPosi==kingY){
			iteratorX_Coordinate=xPosi;
			while(iteratorX_Coordinate<8){
				if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorX_Coordinate==kingX){
					return true;
				}
				else if(this->chessboard[iteratorX_Coordinate][yPosi]!="-"){
					return false;
				}
				iteratorX_Coordinate+=1;
			}
		}
		
	}
	else if(pieceType=="knight"){
		if(xPosi>kingX && yPosi>kingY){
			if((xPosi-1==kingX && yPosi-2==kingY) || (xPosi-2==kingX && yPosi-1==kingY)){
				return true;
			}
		}
		else if(xPosi<kingX && yPosi<kingY){
			if((xPosi+1==kingX && yPosi+2==kingY) || (xPosi+2==kingX && yPosi+1==kingY)){
				return true;
			}
		}
		else if(xPosi<kingX && yPosi>kingY){
			if((xPosi+1==kingX && yPosi-2==kingY) || (xPosi+2==kingX && yPosi-1==kingY)){
				return true;
			}
		}
		else if(xPosi>kingX && yPosi<kingY){
			if((xPosi-1==kingX && yPosi+2==kingY) || (xPosi-2==kingX && yPosi+1==kingY)){
				return true;
			}
		}
	}
	else if(pieceType=="rook"){
		if(xPosi==kingX && yPosi>kingY){
			iteratorY_Coordinate=yPosi;
			while(iteratorY_Coordinate>=0){
				if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate==kingY){
					return true;
				}
				else if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate!=kingY){
					return false;
				}
				iteratorY_Coordinate-=1;
			}
		}
		else if(xPosi==kingX && yPosi<kingY){
			iteratorY_Coordinate=yPosi;
			while(iteratorY_Coordinate<8){
				if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate==kingY){
					return true;
				}
				else if(this->chessboard[xPosi][iteratorY_Coordinate]!="-" && iteratorY_Coordinate!=kingY){
					return false;
				}
				iteratorY_Coordinate+=1;
			}
		}
		else if(xPosi>kingX && yPosi==kingY){
			iteratorX_Coordinate=xPosi;
			while(iteratorX_Coordinate>=0){
				if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorX_Coordinate==kingX){
					return true;
				}
				else if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorY_Coordinate!=kingY){
					return false;
				}
				iteratorX_Coordinate-=1;
			}
		}
		else if(xPosi<kingX && yPosi==kingY){
			iteratorX_Coordinate=xPosi;
			while(iteratorX_Coordinate<8){
				if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorX_Coordinate==kingX){
					return true;
				}
				else if(this->chessboard[iteratorX_Coordinate][yPosi]!="-" && iteratorY_Coordinate!=kingY){
					return false;
				}
				iteratorX_Coordinate+=1;
			}
		}
	}
	iteratorX_Coordinate=0;
	iteratorY_Coordinate=0;
	return false;
}
board& board::operator--(){
	this->operator++();
	int whiteKing_Y = 0;int whiteKing_X = 0;int blackKing_X = 0;int blackKing_Y = 0;int iteratorX = 0;int iteratorY = 0;
	for(int kteratorX=0;kteratorX<8;kteratorX++){
		for(int fteratorX=0;fteratorX<8;fteratorX++){
			if(this->chessboard[kteratorX][fteratorX]=="wK"){
				whiteKing_X = kteratorX;
				whiteKing_Y = fteratorX;
			}
			else if(this->chessboard[kteratorX][fteratorX]=="bK"){
				blackKing_X = kteratorX;
				blackKing_Y = fteratorX;
			}
		}
	}
	if(this->sideToMove=='b'){
		bool array[9];
		for(int k_iterator=0;k_iterator<9;k_iterator++){
			array[k_iterator]=false;
		}
		int bool_iterator=0;
		for(iteratorX=(whiteKing_X-1);iteratorX<=whiteKing_X+1;iteratorX++){
			for(iteratorY=(whiteKing_Y-1);iteratorY<=whiteKing_Y+1;iteratorY++){
				if((iteratorX>=0 && iteratorX<=7)&&(iteratorY>=0 && iteratorY<=7)){
					for(int iterator_black_white = 0;iterator_black_white<this->numBlackPieces;iterator_black_white+=1){
						if(this->blackPieces[iterator_black_white]!=NULL){
							if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]!="-"){
								if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]=="bp"){
									if(checkIfPieceHasCheck(this->blackPieces[iterator_black_white]->getPieceType(),this->blackPieces[iterator_black_white]->getX(),this->blackPieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								else if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]=="bb"){
									if(checkIfPieceHasCheck(this->blackPieces[iterator_black_white]->getPieceType(),this->blackPieces[iterator_black_white]->getX(),this->blackPieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]=="rp"){
									if(checkIfPieceHasCheck(this->blackPieces[iterator_black_white]->getPieceType(),this->blackPieces[iterator_black_white]->getX(),this->blackPieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]=="bk"){
									if(checkIfPieceHasCheck(this->blackPieces[iterator_black_white]->getPieceType(),this->blackPieces[iterator_black_white]->getX(),this->blackPieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->blackPieces[iterator_black_white]->getX()][this->blackPieces[iterator_black_white]->getY()]=="bq"){
									if(checkIfPieceHasCheck(this->blackPieces[iterator_black_white]->getPieceType(),this->blackPieces[iterator_black_white]->getX(),this->blackPieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
							}
						}
					}	
				}
			}
		}
		int squaresCount=0;
		for(iteratorX=(whiteKing_X-1);iteratorX<=(whiteKing_X+1);iteratorX++){
			for(iteratorY=(whiteKing_Y-1);iteratorY<=(whiteKing_Y+1);iteratorY++){
				if((iteratorX>=0 && iteratorX<=7)&&(iteratorY>=0 && iteratorY<=7)){
					for(int k_iterator=0;k_iterator<9;k_iterator++){
						if(array[k_iterator]==false){
							array[k_iterator]=true;
							break;
						}
					}	
					squaresCount++;
				}
			}
		}
		int checkIfCheckmate=0;
		for(int k_iterator=0;k_iterator<9;k_iterator++){
			if(array[k_iterator]!=false){
				checkIfCheckmate+=1;
			}
		}
		//cout<<checkIfCheckmate <<"  "<< squaresCount<<endl;
		for(int k = 0 ; k < 8;k++){
			for(int j = 0 ; j < 8; j++){
				if( chessboard[k][j] == "wK"){
					cout<<"Success: Checkmate of w King at ["<<k<<","<<j<<"]"<<endl;
				}
			}
		}
	}
	else if(sideToMove=='w'){
		bool array[9];
		for(int k_iterator=0;k_iterator<9;k_iterator++){
			array[k_iterator]=false;
		}
		int bool_iterator=0;
		iteratorX=(blackKing_X-1);iteratorY=(blackKing_Y-1);
		for(iteratorX=(blackKing_X-1);iteratorX<=(blackKing_X+1);iteratorX++){
			for(iteratorY=(blackKing_Y-1);iteratorY<=(blackKing_Y+1);iteratorY++){
				if((iteratorX>=0 && iteratorX<=7)&&(iteratorY>=0 && iteratorY<=7)){
					for(int iterator_black_white = 0;iterator_black_white<this->numWhitePieces;iterator_black_white+=1){
						if(this->whitePieces[iterator_black_white]!=NULL){
							if(this->chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]!="-"){
								if(chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]=="bp"){
									if(checkIfPieceHasCheck("pawn",this->whitePieces[iterator_black_white]->getX(),this->whitePieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								else if(this->chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]=="bb"){
									if(checkIfPieceHasCheck("bishop",this->whitePieces[iterator_black_white]->getX(),this->whitePieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]=="rp"){
									if(checkIfPieceHasCheck("rook",this->whitePieces[iterator_black_white]->getX(),this->whitePieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]=="bk"){
									if(checkIfPieceHasCheck("knight",this->whitePieces[iterator_black_white]->getX(),this->whitePieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
								if(this->chessboard[this->whitePieces[iterator_black_white]->getX()][this->whitePieces[iterator_black_white]->getY()]=="bq"){
									if(checkIfPieceHasCheck("queen",this->whitePieces[iterator_black_white]->getX(),this->whitePieces[iterator_black_white]->getY(),iteratorX,iteratorY)){
										array[bool_iterator]=true;
										bool_iterator+=1;
									}
								}
							}
						}	
					}
				}
			}
		}
		int squaresCount = 0;
		for(iteratorX=(blackKing_X-1);iteratorX<=(blackKing_X+1);iteratorX++){
			for(iteratorY=(blackKing_Y-1);iteratorY<=(blackKing_Y+1);iteratorY++){
				if((iteratorX>=0 && iteratorX<=7)&&(iteratorY>=0 && iteratorY<=7)){
					for(int k_iterator=0;k_iterator<9;k_iterator++){
						if(array[k_iterator]==false){
							array[k_iterator]=true;
							break;
						}
					}
					squaresCount++;	
				}
			}
		}
		int checkIfCheckmate=0;
		for(int k_iterator=0;k_iterator<9;k_iterator++){
			if(array[k_iterator]!=false){
				checkIfCheckmate+=1;
			}
		}
		//cout<<checkIfCheckmate <<"  "<< squaresCount<<endl;
		for(int k = 0 ; k < 8;k++){
			for(int j = 0 ; j < 8; j++){
				if( chessboard[k][j] == "bK"){
					cout<<"Success: Checkmate of b King at ["<<k<<","<<j<<"]"<<endl;
				}
			}
		}
	}
	return *this;
}