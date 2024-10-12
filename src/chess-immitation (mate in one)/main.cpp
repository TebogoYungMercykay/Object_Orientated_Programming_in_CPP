#include "board.h"
#include "piece.h"
#include "solver.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

/***************************************************************************/
/************************* COPY RIGHTS RESERVED ****************************/
/******************** DO NOT FOWARD THIS IN ANY WAY ************************/
/************************ Marion_PD#7499 On Discord ************************/
/***************************************************************************/

int main(int arg, const char *argv[]) {
  /*cout<<"..........................................................."<<endl;
  cout<<"...................... T A S K - 1 ........................"<<endl;
  cout<<"..........................................................."<<endl;
piece* piece0 = new piece("king", 'b', 0, 7);
piece* piece1 = new piece(piece0);
const piece* piece2 = new piece("queen", 'w', 2,2);
cout<<"........... Testing operator<< on piece2 .................."<<endl;
  cout<<"..........................................................."<<endl;
cout<<*piece2;
cout<<"........... Moving piece1 ................................."<<endl;
  cout<<"..........................................................."<<endl;
*piece1=*piece1+"1,1";
cout<<*piece1;
cout<<"........... Performing an invalid move on piece1 .........."<<endl;
  cout<<"..........................................................."<<endl;
*piece1+"18,1";
cout<<*piece1;
  cout<<"........... Testing the Default Constructor(#For Fun) ....."<<endl;
  cout<<"..........................................................."<<endl;
  piece chessgame2;
  cout<<chessgame2;
  cout<<"........... Testing the Par Constructor and operator<< ...."<<endl;
  cout<<"..........................................................."<<endl;
  piece *chessgame = new piece("king",'w' ,6,1);
  cout<<*chessgame;
  piece* piece4=new piece("rook", 'b', 0, 0);
  cout<<*piece4;
  cout<<"........... Expected Output ..............................."<<endl;
  cout<<"..........................................................."<<endl;
  cout<<"w king at [6,1]"<<endl<<"b rook at [0,0]"<<endl;
  cout<<"........... Now testing the operator[] ...................."<<endl;
  cout<<"..........................................................."<<endl;
  piece *chessgame1 = new piece("king",'b' ,7,1);
  chessgame1->operator[](0);
  chessgame1->operator[](1);
  cout<<"........... Now testing the operator+ ....................."<<endl;
  cout<<"..........................................................."<<endl;
  piece *chessgame3= new piece("queen",'w' ,6,2);
  cout<<".....Before operation........."<<endl;
  cout<<*chessgame3;
  string move = "3,4";
  chessgame3->operator+(move);
  cout<<".....After operation.........."<<endl;
  cout<<*chessgame3;
  cout<<"X-Value: "<<chessgame3->getX()<<endl;
  cout<<"Y-Value: "<<chessgame3->getY()<<endl;
  cout<<"........... Testing the Copy Constructor .................."<<endl;
  cout<<"..........................................................."<<endl;
  piece *chessgame4 = new piece(chessgame3);
  cout<<*chessgame4;
  cout<<"..........................................................."<<endl;
  cout<<".................... T A S K - 2 .........................."<<endl;
  //******************** U may Use these Textfiles:= ************************
  //************** game1.txt Should be like:= **********************
  // w
  // 6,3,5,3
  // w,rook,6,3
  // b,pawn,1,1
  // b,pawn,1,5
  // b,pawn,5,5
  // b,king,3,3
  // w,king,7,7
  //*************** game2.txt can be like:= ************************
  // w
  // 6,6,5,4
  // b,knight,1,2
  // b,king,3,3
  // b,pawn,3,4
  // b,pawn,4,3
  // w,pawn,5,3
  // w,king,6,6
  // w,rook,2,7
  // w,queen,0,5
  // w,bishop,5,0
  //*************** game3.txt can be like:= ************************
  // w
  // 2,4,1,2
  // b,king,0,0
  // b,pawn,1,0
  // b,pawn,1,1
  // b,rook,0,1
  // w,king,7,6
  // w,bishop,7,5
  // w,knight,2,4
  //*************** game4.txt can be like:= ************************
  // game2.txt,5
  // game1.txt,1
  // game3.txt,11
  cout<<"..........................................................."<<endl;
  cout<<"......... Testing the checkIfPieceHasCheck function ......."<<endl;
  board* newBoard=new board("game1.txt");
  cout<<"..........................................................."<<endl;
  cout<<"...........Pawn IOIUG......................................"<<endl;
  cout<<"....True...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",4,4,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",2,4,3,3)<<"\n";
  cout<<"....False...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",4,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",2,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",2,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("pawn",4,1,3,3)<<"\n";
  cout<<"..........................................................."<<endl;
  cout<<"...........Knight IOIUG...................................."<<endl;
  cout<<"....True...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("knight",1,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("knight",4,1,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("knight",5,4,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("knight",4,5,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("knight",2,5,3,3)<<"\n";
  cout<<"....False...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("knight",0,6,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("knight",4,4,3,3)<<"\n";
  cout<<"..........................................................."<<endl;
  cout<<"...........Bishop IOIUG...................................."<<endl;
  cout<<"....True...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",6,0,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",4,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",2,4,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",2,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",4,4,3,3)<<"\n";
  cout<<"....False...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",0,0,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("bishop",6,6,3,3)<<"\n";
  cout<<"..........................................................."<<endl;
  cout<<"...........Rook IOIUG......................................"<<endl;
  cout<<"....True...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("rook",1,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",3,1,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",3,7,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",3,5,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",4,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",0,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",3,2,3,3)<<"\n";
  cout<<"....False...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("rook",7,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("rook",2,4,3,3)<<"\n";
  cout<<"..........................................................."<<endl;
  cout<<"...........Queen IOIUG....................................."<<endl;
  cout<<"....True...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("queen",6,0,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",4,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",2,4,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",2,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",4,4,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",1,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",3,1,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",3,7,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",3,5,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",4,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",0,3,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",3,2,3,3)<<"\n";
  cout<<"....False...."<<endl;
  std::cout<<newBoard->checkIfPieceHasCheck("queen",0,0,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",6,6,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",6,2,3,3)<<"\n";
  std::cout<<newBoard->checkIfPieceHasCheck("queen",7,3,3,3)<<"\n";
  cout<<"..........................................................."<<endl;
  cout<<"............ Testing Operator--() ........................."<<endl;
  cout<<"..........................................................."<<endl;
  cout<<".....Shouldn't be Checkmate:=......"<<endl;
  cout<<"..........................................................."<<endl;
  newBoard->operator--();
  cout<<"..........................................................."<<endl;
  cout<<".....Should be Checkmate:=........."<<endl;
  cout<<"..........................................................."<<endl;
  board* newBoard2=new board("game2.txt");
  newBoard2->operator--();
  cout<<"..........................................................."<<endl;
  cout<<".....Should be Checkmate:=........."<<endl;
  cout<<"..........................................................."<<endl;
  board* newBoard3=new board("game3.txt");
  newBoard3->operator--();*/
  cout << "..........................................................." << endl;
  cout << ".................... T A S K - 3 .........................." << endl;
  cout << "..........................................................." << endl;
  cout << "... First one is not checkmate,But second and third are ..." << endl;
  solver *my_Solve = new solver("game4.txt");
  cout << "..........................................................." << endl;
  cout << "........... D O N E  T E S T I N G ........................" << endl;
  cout << "..........................................................." << endl;
  cout << true << endl;
  cout << "..........................................................." << endl;
  cout << "........... The Destructors now ..........................." << endl;
  cout << "..........................................................." << endl;
  // Comment Out The "delete x" Lines Of Code To Test Your Destructors:=
  //  delete piece0;
  //  delete piece1;
  //  delete piece2;
  //  delete piece4;
  //  delete newBoard;
  //  delete newBoard2;
  //  delete newBoard3;
  //  delete my_Solve;
  return 0;
}