#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <iomanip>

using namespace std;

int main()
{
	int x=0;
	int y;
	int z;
	string number;
	string filename;
	string halt="stop";
	string frmFile;
	string str1;
	int w;
	
	cout <<"Enter the file name: ";
	cin >>filename;
	
	ifstream linesFile;
	linesFile.open(filename.c_str());
	
	while(!linesFile.eof())
	{
		if( linesFile >> number)
		{
			w=number.find(halt);
			if( w != string::npos ){
				cout<<"File reading stopped"<<endl;
				break;
			}
			
			for(int t=1;t<2;t++)
			{
				istringstream ss (number);
				ss>>z;
				y=z+x;
				cout<<y<<endl;
				x=z;
			}

		}
		
	}
	
	linesFile.close();
	return 0;
	
}