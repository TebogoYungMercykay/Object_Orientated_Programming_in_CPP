#include <iostream>
#include <sstream>
//ostream piece::&operator<<(ostream& output, const piece& pieces);
/*Hey There I'm Empty (>_<)*/
piece::piece(){
}
/*The copy constructor after the default one*/
piece::piece(piece* newPiece){
	this->pieceType=newPiece->pieceType;
	this->side=newPiece->side;
	this->xPos=newPiece->xPos;
	this->yPos=newPiece->yPos;
}
//This is the value based constructor.
piece::piece(std::string pType, char sides, int x,int y){
	this->pieceType = pType;
	this->side = sides;
	this->xPos = x;
	this->yPos = y;
}
//destructor now(>_<)...
piece::~piece(){
	std::cout<<"("<<this->xPos<<","<<this->yPos<<") "<<this->side<<" "<<this->pieceType <<" deleted"<<"\n";
}
std::string piece::getPieceType(){
	return this->pieceType;
}
int piece::getX(){
	return this->xPos;
}
int piece::getY(){
	return this->yPos;	
}
char piece::getSide(){
	return this->side;
}
void piece::setX(int x){	
	if(x>=0 && x<9){
		this->xPos=x;
	}
}
void piece::setY(int y){
	if(y>=0 && y<9){
		this->yPos=y;
	}
}
/*void piece::operator<<()
{
	std::cout<<side<<" "<<pieceType <<" at "<<"["<<xPos<<","<<yPos<<"]"<<"\n";	
}*/
void piece::operator[](int pos){
	if(pos!=0 && pos!=1){
		std::cout<<"Invalid Index"<<std::endl;
	}
	else{
		if(pos==0){
			std::cout<<"x coord: "<<this->getX()<<std::endl;
		}
		else{
			std::cout<<"y coord: "<<this->getY()<<std::endl;
		}
	}
}
piece& piece::operator+(std::string move){
	if(move!=""){
		std::stringstream temp(move);
		int p,k;
		getline(temp,move,',');
		std::stringstream ss(move);
		ss>>p;
		temp>>k;
		if(p>=0 && p<9 && k>=0 && k<9){
			this->xPos = p;
			this->yPos = k;
		}
		temp.clear();
		ss.clear();
	}
	return *this;
}
//The print function now(>_<)..
std::ostream& operator<<(std::ostream& output, const piece& pieces){
	output<<pieces.side<<" "<<pieces.pieceType <<" at "<<"["<<pieces.xPos<<","<<pieces.yPos<<"]"<<"\n";
	return output;
}
/*piece& piece::operator+(string move){
	piece* mPiece = NULL;
	if(move!=""){
		stringstream temp(move);
		int p,k;
		getline(temp,move,',');
		stringstream ss(move);
		ss>>p;
		temp>>k;
		if(p>=0 && p<9 && k>=0 && k<9){
			mPiece->setX(p);
			mPiece->setY(k);
		}
		temp.clear();
		ss.clear();
	}
	return *this;
}