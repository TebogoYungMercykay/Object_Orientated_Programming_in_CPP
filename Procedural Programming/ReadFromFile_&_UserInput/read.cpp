#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

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
			getline(linesFile,number);
			
			w=number.find(halt);
			
			if( w != string::npos ){
				cout<<"File reading stopped"<<endl;
				break;
			}
			for(int t=0;t<number.length();++t)
			{
				if(isdigit(number[t]))
				{
					y=stoi(number);
					z=y+x;
					cout<<z<<endl;
					x=z;
				}
			}

		}
		
	}
	
	linesFile.close();
	return 0;
	
}