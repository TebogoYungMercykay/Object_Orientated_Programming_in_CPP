#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;
int findNumberofWords(string fileName);
int countC = 0;
int stringToInt(string);
string fileName = "building.data", rtrt;

string ** arrayOI = NULL;
int * ColSizes = NULL;
int * OrderedColSizes = NULL;
int main()
{
	fstream anotherStream("building.data");
	while(getline(anotherStream,rtrt)){
		countC+=1;
	}
	int numRows = (countC-1)/2;
	ColSizes = new int[numRows];
	OrderedColSizes = new int[numRows];
	arrayOI = new string*[numRows];
	rtrt="";
	int skip = 0, index = 0;
	anotherStream.close();
	anotherStream.open("building.data");
	while(getline(anotherStream,rtrt)){
		countC=0;
		if(skip == 2){
			countC = findNumberofWords(rtrt);
			ColSizes[index++]=countC;
			// cout<<countC<<endl;
			skip-=2;
		} 
		countC+=1;
		skip+=1;
	}
	// for(int k = 0; k<numRows;k++){
	// 	cout<<ColSizes[k]<<" ";
	// }
	string temp, temp2, temp3;
	anotherStream.close();
	anotherStream.open("building.data");
	getline(anotherStream,temp3);
	index = 0;
	while(getline(anotherStream,temp)){
		getline(anotherStream,temp2);
		stringstream dg (temp);
		stringstream dg45 (temp2);
		getline(dg,temp,':');
		int floor = 0, cols = 0;
		dg>>floor;
		arrayOI[floor] = new string[ColSizes[index]];
		OrderedColSizes[floor] = ColSizes[index];
		while(getline(dg45,rtrt,',')){
			arrayOI[floor][cols]=rtrt;
			// cout<<rtrt<<" ";
			cols +=1;
		}
		// cout<<endl;
		index++;
	}
	stringstream dggg (temp3);
	for(int k=0;k<numRows&&getline(dggg,rtrt,',');k++){
		// rtrt="";
		int pot;
		// getline(dggg,rtrt,',');
		pot = stringToInt(rtrt);
		for(int y=OrderedColSizes[pot]-1;y>=0;y--){
			cout<<arrayOI[pot][y];
			if(y>0){
				cout<<",";
			}
		}
		cout<<endl;
	}
	anotherStream.close();
    for(int k_iterator = 0;k_iterator<numRows;k_iterator++){
		if(arrayOI[k_iterator]){
			delete [] arrayOI[k_iterator];
			arrayOI[k_iterator] = NULL;
		}
	}
	delete [] arrayOI;
	delete [] ColSizes;
	delete [] OrderedColSizes;
	arrayOI = NULL;
	ColSizes = NULL;
	OrderedColSizes = NULL;
}

int stringToInt(string line)
{
	stringstream s1(line);
	int temp=0;
	s1>>temp;
	return temp;
}

int findNumberofWords(string fileName)
{
	stringstream ss (fileName);
	string name;
	int count = 0;
	while(getline(ss,name,','))
	{
		count++;
	}
	return count;
}