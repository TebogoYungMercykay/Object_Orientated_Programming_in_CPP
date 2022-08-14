#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
string name;
	cout << "Please enter your name: ";
	getline( cin ,name);
cout<<"Howdy: "<<setw(8)<<setfill('*')<<name<< endl;
	
	return 0;
}
