//There is a lot to test on your own!
//Also remember NOT to use namespace std; in h files
//If a class does not ask for a destructor, DO NOT MAKE ONE!
//Check SPELLING!

#include <iostream>
#include "Game.h"

using namespace std;

void basicTest()
{
	cout<<"List 1 debug"<<endl;
	ObjectList list(0);
	list.add(new Floor(0, 0));
	list.add(new Object(4, 5));
	list.add(new Floor(3, 1));
	list.add(new Wall(10, 1));
	list.add(new Wall(1, 0));
	list.add(new Floor(7, 8));

	cout<<list.debug()<<endl<<endl;


	cout<<"List 2 debug"<<endl;
	ObjectList list2(1);
	list2.add(new Floor(0, 9));
	list2.add(new Object(4, 5));
	list2.add(new Floor(3, 1));
	list2.add(new Wall(10, 1));
	list2.add(new Wall(1, 0));
	list2.add(new Floor(7, 8));

	cout<<list2.debug()<<endl<<endl;

	cout<<"List 1 iteration"<<endl;
	list.reset();
	while (Object* p = list.iterate())
		cout<<p->getIcon()<<endl;

	cout<<endl;

}

int main()
{
//Map without player

	const int w = 5;
	const int h = 5;
	string array =
	"#####"
	"#...#"
	"#.#.#"
	"###.#"
	"#####";

//Map with player
//When testing, the player should always
//appear at the top. So, the player should
//always be visible, even on walls for Part 1
/*
	const int w = 5;
	const int h = 5;
	string array =
	"#####"
	"#...#"
	"#&#.#"
	"###.#"
	"#####";
*/

	basicTest();


	cout<<"Starting game"<<endl;
	Game* game = new Game(w, h, array);


	cout<<game->display();
	bool running = true;
	string mess = "";
	while (running)
	{
		char action;
		cin>>action;
		if (action == 'q')
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
		
		cout<<game->display();
	}

	cout<<endl<<mess<<endl;
	

}

//Expected output, Part 1 (without character)
/*
List 1 debug
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


List 2 debug
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


List 1 iteration
.
#
.
?
.
#

Starting game
#####
#...#
#.#.#
###.#
#####

*/
