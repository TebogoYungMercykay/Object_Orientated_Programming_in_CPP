#include <iostream>
#include "Game.h"

using namespace std;

void runTest()
{
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

}

int main()
{
	runTest();

//Basic Map (large room)

	const int w = 30;
	const int h = 12;
	string array =
	"##############################"
	"#............................#"
	"#............................#"
	"#........^...................#"
	"#............................#"
	"#............................#"
	"#............................#"
	"#............................#"
	"#..............^.............#"
	"#............................#"
	"#............................#"
	"##############################";

//Test walls
/*
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
*/

//3 lights and a door
/*
	const int w = 19;
	const int h = 4;
	string array =
	"###################"
	"^&......+.........@"
	"^.......#.........#"
	"#############^#####";
*/

//More interesting map for lighting
/*
	const int w = 17;
	const int h = 6;
	string array =
	"#########^#######"
	"^&......#..+....^"
	"^....#..#..#....#"
	"^....#..#..#....@"
	"^....#..+..^..#+#"
	"###############^#";
*/

	Game* game = new Game(w, h, array);


	cout<<game->display()<<endl;
	bool running = true;
	string mess = "";
	while (running)
	{
		char action;
		cin>>action;

		if (action == 'q') //Quit
			break;

		try
		{
			game->update(action);
		}
		catch(string m)
		{
			mess = m;
			running = false;
		}
		
		cout<<game->display()<<endl;
	}

	cout<<endl<<mess<<endl;
	

}
//Expected output for:
//runTest()
/*
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

*/

//Basic Map (start, then entering '5')
/*
         #     #              
        ...   ...             
 ...........................  
#........^................... 
 ...........................  
        ...   ...             
        ...   ...             
 ............................ 
#..............^.............#
 ............................ 
        ...   ...             
         #     #              

5
Missing player
         #     #              
        ...   ...             
 ...........................  
#........^................... 
 ...........................  
        ...   ...             
        ...   ...             
 ............................ 
#..............^.............#
 ............................ 
        ...   ...             
         #     #              


*/
//Test Walls
/*
 ##^############## 
#................^#
 ##.#########....# 
  ...   ...        
  ...   #.#        
  ...   #.#        
   #    #^#        

*/

//3 lights and a door
//a) Start
/*
########     #     
^&......+   ...    
^.......#   ...    
########    #^#    

*/
//b) Open Door
/*
e
You opened a door
###################
^......&=.........@
^.......#.........#
########    #^#    

*/
//c) Reached exit
/*
6
###################
^.......=.........&
^.......#.........#
########    #^#    

You reached the exit!
*/

//More interesting map for lighting
//a) Start
/*
#########^# #####
^&......#..+....^
^....#..#.. ....#
^....#  #..#..   
^....#  +..^..#+ 
#####    ######^#

*/
//b) Standing in front of first door
/*
2
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#  #..#..   
^....#  +..^..#+ 
#####    ######^#

*/
//c) Opened first door
/*
e
You opened a door
#########^# #####
^.......#..+....^
^....#..#.. ....#
^....#..#..#..   
^....#.&=..^..#+ 
##### #########^#

*/
//d) Opened second door
/*
e
You opened a door
#########^#######
^.......#.&=....^
^....#..#..#....#
^....#..#..#..   
^....#..=..^..#+ 
##### #########^#

*/
//e) Opened third door
/*
e
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#...&@
^....#..=..^..#=#
##### #########^#

*/
//f) At exit
/*
6
You opened a door
#########^#######
^.......#..=....^
^....#..#..#....#
^....#..#..#....&
^....#..=..^..#=#
##### #########^#

You reached the exit!
*/
