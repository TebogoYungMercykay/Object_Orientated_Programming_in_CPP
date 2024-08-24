/******************************************************//*
	   Tebogo - Assignment 3 - Task 1 Testing Main 
       Do Not Include The Main In Your Submission 
	   The Expected Output Starts From Line: 176
*//*
	There is still a lot to test on your own! 
	 - Remember NOT to use namespace std; in h files
	 - If a class does not ask for a destructor, DO NOT MAKE ONE! 
	 - Check SPELLING!
*//*
	NB:= The Makefile deletes main.cpp if it's in the directory before creating the .tar file.
	makefile:

	main:
		g++ -g *.cpp -std=c++98 -pedantic -o main

	clean:
		rm -f *.o *.tar.gz main
		reset
		clear

	run:
		./main

	tar:
		rm -f main.cpp
		tar -cvz *.h *.cpp -f uXXXXXXXX_Assignment_3.tar.gz
*/
#include "Game.h"
#include <iostream>

using namespace std;
static void basicTest_Round_1();
static void basicTest_Round_2();
static void testing_Map_Class();
static void Game_Without_Player();
static void Game_With_Player();

int main() {
  basicTest_Round_1();
  basicTest_Round_2();
  testing_Map_Class();
  Game_Without_Player();
  Game_With_Player();
}

static void basicTest_Round_1() {
  cout << " ------ Creating (Horizontal) List : Dimension = False ------ "
       << endl;
  ObjectList list(0);
  list.add(new Player(6, 9));
  list.reset();
  cout << "---- Doing some bounds checking ----- " << endl;
  while (Object *p = list.iterate()) {
    if (p->getCoord(false) == 6 && p->getCoord(true) == 9) {
      if (p->getIcon() != '&') {
        cout << "-- Fix your Player Constructor/getIcon() --" << endl;
      } else {
        cout << "Icon: " << p->getIcon() << endl;
        cout << "xPos: " << p->getCoord(false) << endl;
        cout << "yPos: " << p->getCoord(true) << endl;
      }
      bool t = false;
      if ((p->getNext(false) != NULL) || (p->getNext(true) != NULL)) {
        t = true;
        cout << "Fix your getNext() method." << endl;
      }
      if ((p->getPrev(false) != NULL) || (p->getPrev(true) != NULL)) {
        t = true;
        cout << "Fix your getPrev() method." << endl;
      }
      Object *myW = NULL;
      p->setNext(myW, false);
      p->setNext(myW, true);
      p->setPrev(myW, false);
      p->setPrev(myW, true);
      if ((p->getNext(false) != NULL) || (p->getNext(true) != NULL)) {
        t = true;
        cout << "Fix your getNext() method." << endl;
      }
      if ((p->getPrev(false) != NULL) || (p->getPrev(true) != NULL)) {
        t = true;
        cout << "Fix your getPrev() method." << endl;
      }
      if (!t) {
        cout << "--- Everything works so Far - 1 ---" << endl;
      } else {
        cout << "Fix your getPrev()/getNext() method." << endl;
      }
      int tr = -17899;
      if (p != NULL) {
        tr = p->getNext(false)->getCoord(false);
        tr = p->getPrev(true)->getCoord(false);
        tr = p->getNext(true)->getCoord(false);
        tr = p->getPrev(false)->getCoord(false);
      }
      cout << tr << endl;
      cout << "--- Everything works so Far - 2 ---" << endl;
      cout << "---- Doing some bounds check on the Move method ----" << endl;
      Player *ptrPlayer = NULL;
      Player *ptrPlayer2 = new Player(3, 4);
      cout << "...." << endl;
      ptrPlayer->move(0, 1);
      cout << "...." << endl;
      ptrPlayer2->move(-2, 4);
      cout << "...." << endl;
      cout << "--- Done checking bounds for Move() ---" << endl;
      cout << "--- This Was just for Bounds Checking ---" << endl;
      cout << "--- Run Game_With_Player() to test functionality ---" << endl;
      break;
    } else {
      cout << "------ Fix your ObjectList constructor ------" << endl;
    }
  }
  cout << " ----------- D O N E ----------- " << endl;
}
static void basicTest_Round_2() {
  cout << " ----------- Testing ObjectList Constructor ----------- " << endl;
  cout << " --- (Horizontal) ----------- " << endl;
  ObjectList list(0);
  list.add(new Floor(0, 0));
  list.add(new Wall(1, 0));
  list.add(new Object(10, 5));
  list.add(new Floor(3, 1));
  list.add(new Wall(10, 1));
  list.add(new Object(4, 5));
  list.add(new Object(4, 8));
  list.add(new Floor(7, 8));
  cout << " --- (Vertical) ----------- " << endl;
  ObjectList list2(1);
  list2.add(new Floor(0, 9));
  list2.add(new Object(4, 5));
  list2.add(new Wall(4, 0));
  list2.add(new Floor(3, 1));
  list2.add(new Object(3, 3));
  list2.add(new Wall(10, 1));
  list2.add(new Object(4, 8));
  list2.add(new Wall(1, 0));
  list2.add(new Floor(7, 8));
  cout << " ----------- D O N E ----------- " << endl;
  cout << " ---- List 1 Testing - (Horizontal) ----------- " << endl;
  cout << " --- (Print) ----------- " << endl;
  cout << list.print() << endl << endl;
  cout << " --- (Debug) ----------- " << endl;
  cout << list.debug() << endl << endl;
  cout << " ---- List 2 Testing - (Vertical) ----------- " << endl;
  cout << " --- (Print) ----------- " << endl;
  cout << list2.print() << endl << endl;
  cout << " --- (Debug) ----------- " << endl;
  cout << list2.debug() << endl << endl;
  cout << " ---- Testing Add Function - (Horizontal) ----------- " << endl;
  list.reset();
  while (Object *p = list.iterate()) {
    if (p->prevHoriz != NULL) {
      cout << p->prevHoriz->getIcon() << " - ";
    } else {
      cout << "? - ";
    }
    cout << p->getIcon() << " - ";
    if (p->nextHoriz != NULL) {
      cout << p->nextHoriz->getIcon();
    } else {
      cout << "?";
    }
    cout << endl;
  }
  cout << endl;
  cout << " ----------- D O N E ----------- " << endl;
  cout << " ----------- Testing Add Function - (Vertical) ----------- " << endl;
  list2.reset();
  while (Object *p = list2.iterate()) {
    if (p->prevVert != NULL) {
      cout << p->prevVert->getIcon() << " - ";
    } else {
      cout << "? - ";
    }
    cout << p->getIcon() << " - ";
    if (p->nextVert != NULL) {
      cout << p->nextVert->getIcon();
    } else {
      cout << "?";
    }
    cout << endl;
  }
  cout << endl;
  cout << " ----------- D O N E ----------- " << endl;
}
static void testing_Map_Class() {
  cout << " ------------- Map Constructor ------------- " << endl;
  /*
  Example Map:
          ####
          #..#
          #&.#
          ####
  */
  cout << " ---- Tests both (rows) & (columns) --- " << endl;
  Map *mapPtr = new Map(4, 4);
  mapPtr->add(new Wall(3, 0));
  mapPtr->add(new Wall(3, 1));
  mapPtr->add(new Wall(3, 2));
  mapPtr->add(new Wall(3, 3));
  mapPtr->add(new Wall(0, 0));
  mapPtr->add(new Wall(0, 1));
  mapPtr->add(new Wall(0, 2));
  mapPtr->add(new Wall(0, 3));
  mapPtr->add(new Wall(1, 0));
  mapPtr->add(new Floor(1, 1));
  mapPtr->add(new Floor(1, 2));
  mapPtr->add(new Wall(1, 3));
  mapPtr->add(new Wall(2, 0));
  mapPtr->add(new Player(2, 1));
  mapPtr->add(new Floor(2, 2));
  mapPtr->add(new Wall(2, 3));
  cout << " ----------- (Print) ----------- " << endl;
  cout << mapPtr->print();
  cout << " ------------- Map Destructor ------------- " << endl;
  delete mapPtr;
  cout << "---- A bit of bounds checking for Map ----- " << endl;
  Map *mapPtr2 = new Map(0, 0);
  delete mapPtr2;
  cout << "...." << endl;
  Map *mapPtr3 = new Map(1, 1);
  cout << "...." << endl;
  // You can set ptr to null if it gives you problems
  Object *ptr = NULL;
  Object *ptr2 = NULL;
  mapPtr->add(ptr);
  cout << "...." << endl;
  mapPtr->add(ptr2);
  cout << "...." << endl;
  delete mapPtr3;
  cout << "...." << endl;
  cout << " ----------- D O N E ----------- " << endl;
}
static void Game_Without_Player() {
  cout << " ----------- Game Without Player ----------- " << endl;
  // Map without player
  const int w = 5;
  const int h = 5;
  string array = "#####"
                 "#...#"
                 "#.#.#"
                 "###.#"
                 "#####";
  cout << "Starting game" << endl;
  Game *game = new Game(w, h, array);
  cout << game->display();
  bool running = true;
  string mess = "";
  while (running) {
    char action;
    // cin>>action;
    action = 'q';
    if (action == 'q')
      break;
    try {
      game->update(action);
    } catch (string m) {
      mess = m;
      running = false;
    }
    cout << game->display();
  }
  if (mess == "") {
    cout << endl;
  } else {
    cout << endl << mess << endl;
  }
  cout << " ----------- D O N E ----------- " << endl;
}
static void Game_With_Player() {
  cout << " ----------- Game With Player ----------- " << endl;
  // Map with player
  // When testing, the player should always
  // appear at the top. So, the player should
  // always be visible, even on walls for Part 1
  const int w = 5;
  const int h = 5;
  string array = "#####"
                 "#...#"
                 ".&#.#"
                 "###.#"
                 "#####";
  cout << "Starting game" << endl;
  Game *game = new Game(w, h, array);
  cout << game->display();
  bool running = true;
  string mess = "";
  while (running) {
    char action;
    // cin>>action;
    action = 'q';
    if (action == 'q')
      break;
    try {
      game->update(action);
    } catch (string m) {
      mess = m;
      running = false;
    }
    cout << game->display();
  }
  if (mess == "") {
    cout << endl;
  } else {
    cout << endl << mess << endl;
  }
  cout << " ----------- D O N E ----------- " << endl;
}
/*
./main
 ------ Creating (Horizontal) List : Dimension = False ------
---- Doing some bounds checking -----
Icon: &
xPos: 6
yPos: 9
--- Everything works so Far - 1 ---
-1
--- Everything works so Far - 2 ---
---- Doing some bounds check on the Move method ----
....
....
....
--- Done checking bounds for Move() ---
--- This Was just for Bounds Checking ---
--- Run Game_With_Player() to test functionality ---
 ----------- D O N E -----------
 ----------- Testing ObjectList Constructor -----------
 --- (Horizontal) -----------
 --- (Vertical) -----------
 ----------- D O N E -----------
 ---- List 1 Testing - (Horizontal) -----------
 --- (Print) -----------
.#.?.#

 --- (Debug) -----------
Forward:
<.> at (0,0) Top:Y
<#> at (1,0) Top:Y
<.> at (3,1) Top:Y
<?> at (4,5) Top:Y
<.> at (7,8) Top:Y
<#> at (10,1) Top:Y
Back:
<#> at (10,1) Top:Y
<.> at (7,8) Top:Y
<?> at (4,5) Top:Y
<.> at (3,1) Top:Y
<#> at (1,0) Top:Y
<.> at (0,0) Top:Y


 ---- List 2 Testing - (Vertical) -----------
 --- (Print) -----------
#.#?..

 --- (Debug) -----------
Forward:
<#> at (1,0) Top:Y
<.> at (3,1) Top:Y
<#> at (10,1) Top:Y
<?> at (4,5) Top:Y
<.> at (7,8) Top:Y
<.> at (0,9) Top:Y
Back:
<.> at (0,9) Top:Y
<.> at (7,8) Top:Y
<?> at (4,5) Top:Y
<#> at (10,1) Top:Y
<.> at (3,1) Top:Y
<#> at (1,0) Top:Y


 ---- Testing Add Function - (Horizontal) -----------
? - . - #
. - # - .
# - . - ?
. - ? - .
? - . - #
. - # - ?

 ----------- D O N E -----------
 ----------- Testing Add Function - (Vertical) -----------
? - # - .
# - . - #
. - # - ?
# - ? - .
? - . - .
. - . - ?

 ----------- D O N E -----------
 ------------- Map Constructor -------------
 ---- Tests both (rows) & (columns) ---
 ----------- (Print) -----------
####
#..#
#&.#
####
 ------------- Map Destructor -------------
---- A bit of bounds checking for Map -----
....
....
....
....
....
 ----------- D O N E -----------
 ----------- Game Without Player -----------
Starting game
#####
#...#
#.#.#
###.#
#####
3
#####
#...#
#.#.#
###.#
#####
q

 ----------- D O N E -----------
 ----------- Game With Player -----------
Starting game
#####
#...#
.&#.#
###.#
#####
4
#####
#...#
&.#.#
###.#
#####
8
#####
#...#
&.#.#
###.#
#####
2
#####
#...#
&.#.#
###.#
#####
4
#####
#...#
&.#.#
###.#
#####
6
#####
#...#
.&#.#
###.#
#####
6
#####
#...#
.&#.#
###.#
#####
8
#####
#&..#
..#.#
###.#
#####
6
#####
#.&.#
..#.#
###.#
#####
6
#####
#..&#
..#.#
###.#
#####
2
#####
#...#
..#&#
###.#
#####
2
#####
#...#
..#.#
###&#
#####
2
#####
#...#
..#.#
###&#
#####
2
#####
#...#
..#.#
###&#
#####
q

 ----------- D O N E -----------
*/