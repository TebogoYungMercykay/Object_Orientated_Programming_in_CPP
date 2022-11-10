/******************************************************//*
	   Tebogo - Assignment 3 - Part 2 Testing Main 
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
#include <iostream>
#include "Game.h"

using namespace std;
static void Message_X_MessageQueue();
static void testing_Map_Class();
static void Basic_Map();
static void Test_Walls();
static void More_Interesting_Map_For_Lighting();
static void Lights_And_A_Door();

int main(){
	Message_X_MessageQueue();
	testing_Map_Class();
	Basic_Map();
	Test_Walls();
	Lights_And_A_Door();
	More_Interesting_Map_For_Lighting();
}
void Message_X_MessageQueue(){
	cout<<" ------------- Message_X_MessageQueue ------------- "<<endl;
	//Feel free to comment out the Game reference in the main, and add tests for individual classes here
	//Before you put everything together
	MessageQueue queue(1);
	cout<<"0. "<<endl<<queue.print()<<endl;
	queue.addMessage(new Message("Message 1"));
	queue.addMessage(new Message("Message 2"));
	cout<<"1. "<<endl<<queue.print()<<endl;
	queue.addMessage(new Message("Message 3"));
	cout<<"2. "<<endl<<queue.print()<<endl;
	cout<<"3. "<<endl<<queue.print()<<endl;
	cout<<"4. "<<endl<<queue.print()<<endl;
	cout<<" ----------- D O N E ----------- "<<endl;
}
static void testing_Map_Class(){
	cout<<" ------------- testing_Map_Class ------------- "<<endl;
	cout<<" ---- Tests both (rows) & (columns) --- "<<endl;
	Map* mapPtr = new Map(4, 4);
	mapPtr->add(new Wall(3, 0));
	mapPtr->add(new Wall(3, 1));
	mapPtr->add(new Exit(3, 2));
	mapPtr->add(new Wall(3, 3));
	mapPtr->add(new Wall(0, 0));
	mapPtr->add(new Object(0, 1));
	mapPtr->add(new Lamp(0, 2));
	mapPtr->add(new Wall(0, 3));
	mapPtr->add(new Wall(1, 0));
	mapPtr->add(new Floor(1, 1));
	mapPtr->add(new Floor(1, 2));
	mapPtr->add(new Wall(1, 3));
	mapPtr->add(new Wall(2, 0));
	mapPtr->add(new Player(2, 1));
	mapPtr->add(new Floor(2, 2));
	mapPtr->add(new Wall(2, 3));
	cout<<" ----------- (Print) ----------- "<<endl;
	cout<<mapPtr->print();
	cout<<mapPtr->getAt(2,1)->getIcon() << endl;
	cout<<mapPtr->getAt(0,1)->getIcon() << endl;
	cout<<mapPtr->getAt(0,2)->getIcon() << endl;
	cout<<mapPtr->getAt(1,3)->getIcon() << endl;
	cout<<mapPtr->getAt(2,2)->getIcon() << endl;
	cout<<mapPtr->getAt(3,2)->getIcon() << endl;
	delete mapPtr;
	cout<<" ----------- D O N E ----------- "<<endl;
}
static void Basic_Map(){
	cout<<" ------------- Basic_Map ------------- "<<endl;
	const int w = 31;
	const int h = 12;
	string array =
	"###############################"
	"#.............................#"
	"#.............................#"
	"#........^....................#"
	"#.............................#"
	"#.............................#"
	"#.............................#"
	"#.............................#"
	"#..............^..............#"
	"#.............................#"
	"#.............................#"
	"###############################";

	Game* game = new Game(w, h, array);
	cout<<game->display()<<endl;
	bool running = true;
	string mess = "";
	while (running){
		char action;
		cin>>action;
		if (action == 'q') //Quit
			break;
		try{
			game->update(action);
		}
		catch(string m){
			mess = m;
			running = false;
		}
		cout<<game->display()<<endl;
	}
	cout<<endl<<mess<<endl;
	delete game;
	cout<<" ----------- D O N E ----------- "<<endl;
}
static void Test_Walls(){
	cout<<" ------------- Test_Walls ------------- "<<endl;
	const int w = 19;
	const int h = 7;
	string array =
	"###^###############"
	"#................^#"
	"###.#########....##"
	"#.....#.....#.....#"
	"#.....###.###.....#"
	"#.......#.#.......#"
	"#########^#########";

	Game* game = new Game(w, h, array);
	cout<<game->display()<<endl;
	bool running = true;
	string mess = "";
	while (running){
		char action;
		cin>>action;
		if (action == 'q') //Quit
			break;
		try{
			game->update(action);
		}
		catch(string m){
			mess = m;
			running = false;
		}
		cout<<game->display()<<endl;
	}
	cout<<endl<<mess<<endl;
	delete game;
	cout<<" ----------- D O N E ----------- "<<endl;
}
static void Lights_And_A_Door(){
	cout<<" ------------- Lights_And_A_Door ------------- "<<endl;
	const int w = 19;
	const int h = 4;
	string array =
	"###################"
	"^&......+.........@"
	"^.......#.........#"
	"#############^#####";

	Game* game = new Game(w, h, array);
	cout<<game->display()<<endl;
	bool running = true;
	string mess = "";
	while (running){
		char action;
		cin>>action;
		if (action == 'q') //Quit
			break;
		try{
			game->update(action);
		}
		catch(string m){
			mess = m;
			running = false;
		}
		cout<<game->display()<<endl;
	}
	cout<<endl<<mess<<endl;
	delete game;
	cout<<" ----------- D O N E ----------- "<<endl;
}
static void More_Interesting_Map_For_Lighting(){
	cout<<" ------------- More_Interesting_Map_For_Lighting ------------- "<<endl;
	const int w = 17;
	const int h = 6;
	string array =
	"#########^#######"
	"^&......#..+....^"
	"^....#..#..#....#"
	"^....#..#..#....@"
	"^....#..+..^..#+#"
	"###############^#";

	Game* game = new Game(w, h, array);
	cout<<game->display()<<endl;
	bool running = true;
	string mess = "";
	while (running){
		char action;
		cin>>action;
		if (action == 'q') //Quit
			break;
		try{
			game->update(action);
		}
		catch(string m){
			mess = m;
			running = false;
		}
		cout<<game->display()<<endl;
	}
	cout<<endl<<mess<<endl;
	delete game;
	cout<<" ----------- D O N E ----------- "<<endl;
}
//Expected output for:
/*
./main
 ------------- Message_X_MessageQueue ------------- 
0.

1.
Message 1
Message 2

2.
Message 2
Message 3

3.
Message 3

4.

 ----------- D O N E -----------
 ------------- testing_Map_Class -------------      
 ---- Tests both (rows) & (columns) ---
 ----------- (Print) -----------
####
?.&#
^..@
####
&
?
^
#
.
@
 ----------- D O N E -----------
 ------------- Basic_Map -------------
         #     #
        ...   ...
 ............................
#........^....................
 ............................
        ...   ...
        ...   ...
 .............................
#..............^..............#
 .............................
        ...   ...
         #     #

q


 ----------- D O N E -----------
 ------------- Test_Walls -------------
 ##^##############
#................^#
 ##.#########....#
  ...   ...
  ...   #.#
  ...   #.#
   #    #^#

6
Missing player
 ##^##############
#................^#
 ##.#########....#
  ...   ...
  ...   #.#
  ...   #.#
   #    #^#

q


 ----------- D O N E -----------
 ------------- Lights_And_A_Door -------------
########     #
^&......+   ...
^.......#   ...
########    #^#

6
########     #     
^.&.....+   ...
^.......#   ...
########    #^#

6 
########     #     
^..&....+   ...
^.......#   ...
########    #^#

6
########     #     
^...&...+   ...
^.......#   ...
########    #^#

6
########     #     
^....&..+   ...
^.......#   ...
########    #^#

6
########     #     
^.....&.+   ...
^.......#   ...
########    #^#

6
########     #     
^......&+   ...
^.......#   ...
########    #^#

e
You opened a door
###################
^......&=.........@
^.......#.........#
########    #^#

6
You opened a door
###################
^.......&.........@
^.......#.........#
########    #^#

6
You opened a door
###################
^.......=&........@
^.......#.........#
########    #^#

6
You opened a door
###################
^.......=.&.......@
^.......#.........#
########    #^#

6
###################
^.......=..&......@
^.......#.........#
########    #^#

6
###################
^.......=...&.....@
^.......#.........#
########    #^#

6
###################
^.......=....&....@
^.......#.........#
########    #^#

6
###################
^.......=.....&...@
^.......#.........#
########    #^#

6
###################
^.......=......&..@
^.......#.........#
########    #^#

6
###################
^.......=.......&.@
^.......#.........#
########    #^#

6
###################
^.......=........&@
^.......#.........#
########    #^#

6
###################
^.......=.........&
^.......#.........#
########    #^#


You reached the exit!
 ----------- D O N E -----------
 ------------- More_Interesting_Map_For_Lighting -------------
#########^# #####
^&......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
#########^# #####
^.&.....#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
#########^# #####
^..&....#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
#########^# #####
^...&...#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
#########^# #####
^....&..#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
#########^# #####
^.....&.#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

2
#########^# #####
^.......#..+....^
^....#&.#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

2
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

2
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

e
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

2
Walked into something
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

e
Walked into something
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

6
Walked into something
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..
^....#  +..^..#+
#####    ######^#

e
Walked into something
You opened a door
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#..#..#..
^....#.&=..^..#+
##### #########^#

6
You opened a door
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#..#..#..
^....#..&..^..#+
##### #########^#

6
You opened a door
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#..#..#..
^....#..=&.^..#+
##### #########^#

8
You opened a door
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#..#&.#..
^....#..=..^..#+
##### #########^#

8
You opened a door
#########^# #####
^.......#..+....^
^....#..#&. ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

8
#########^# #####
^.......#&.+....^
^....#..#.. ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

2
#########^# #####
^.......#..+....^
^....#..#&. ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

6
#########^# #####
^.......#..+....^
^....#..#.& ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

6
Walked into something
#########^# #####
^.......#..+....^
^....#..#.& ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

8
Walked into something
#########^# #####
^.......#.&+....^
^....#..#.. ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

8
Walked into something
Walked into something
#########^# #####
^.......#.&+....^
^....#..#.. ....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

e
Walked into something
You opened a door
#########^#######
^.......#.&=....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

6
Walked into something
You opened a door
#########^#######
^.......#..&....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

6
Walked into something
You opened a door
#########^#######
^.......#..=&...^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

2
Walked into something
You opened a door
#########^#######
^.......#..=....^
^....#..#..#&...#
^....#..#..#..
^....#..=..^..#+
##### #########^#

2
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#&.
^....#..=..^..#+
##### #########^#

6
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#.&
^....#..=..^..#+
##### #########^#

6
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

2
You opened a door
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

6
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

2
Walked into something
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#..
^....#..=..^..#+
##### #########^#

e
Walked into something
Walked into something
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#...&@
^....#..=..^..#=#
##### #########^#

2
Walked into something
Walked into something
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#....@
^....#..=..^..#&#
##### #########^#

2 
Walked into something
You opened a door
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#....@
^....#..=..^..#&#
##### #########^#

8
Walked into something
You opened a door
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#...&@
^....#..=..^..#=#
##### #########^#

6
Walked into something
You opened a door
Walked into something
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#....&
^....#..=..^..#=#
##### #########^#


You reached the exit!
 ----------- D O N E -----------
*/