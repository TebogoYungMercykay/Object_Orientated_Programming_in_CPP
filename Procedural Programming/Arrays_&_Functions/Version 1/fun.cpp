#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
using namespace std;
string N;
string echo(string ="echo");
string echo(string x, int r);
int main()
{
	fstream inputfile ("values2.txt");
	int r=-1;
	while(inputfile >>N){
		r++;
		cout<< echo(N)<<endl;
		echo(N, r);
	}
	inputfile.close();
	string u="My self";
	return 0;
}
string echo(string reader)
{
	return reader;
}
string echo(string reader, int r)
{
	if(r%2==0)
	{
		cout<<reader<<r<<endl;
	}
	else
	{
		cout<<r<<reader<<endl;
	}
	
}
