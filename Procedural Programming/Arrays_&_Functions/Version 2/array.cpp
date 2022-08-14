#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main()
{
	ifstream Str("values.txt");
	if(!Str.is_open()){
		cout<<"File failed to open"<<endl;
		return 0;
	}
	int bin[5]={0,0,0,0,0};
	int a,b,c,d,e;
	string firstName;
	string ect;
	while(getline(Str, ect))
	{
		istringstream ss (ect);
		getline(ss, firstName, ',');
		istringstream aa (firstName);
		aa>>a;
		getline(ss, firstName, ',');
		istringstream bb (firstName);
		bb>>b;
		getline(ss, firstName, ',');
		istringstream cc (firstName);
		cc>>c;
        getline(ss, firstName, ',');
        istringstream dd (firstName);
		dd>>d;
        getline(ss, firstName, ',');
        istringstream ee (firstName);
		ee>>e;

        bin[0]+=a;
        bin[1]+=b;
        bin[2]+=c;
        bin[3]+=d;
        bin[4]+=e;
	}
	for(int k=0;k<5;k++){
        cout<<bin[k]<<endl;
	}
	Str.close();

	return 0;

}
