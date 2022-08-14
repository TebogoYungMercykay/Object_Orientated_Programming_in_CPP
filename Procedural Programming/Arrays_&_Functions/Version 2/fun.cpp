#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string input;
int count =-1;

fstream reece ("values2.txt");
string echo(string x);
string echo(string x, int count)
{
	if(count%2==0)
	{
		cout<<x<<count<<endl;
	}
	else
	{
		cout<<count<<x<<endl;
	}
}
int main()
{
	while(getline(reece , input))
	{
		count +=1;
		cout<< echo(input)<<endl;
		echo(input, count);
	}
	reece.close();
	return 0;
}
string echo(string x)
{
	return x;
}
