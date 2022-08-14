#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string bubSort(double arr[8])
{
	string LastReturn="",value;
	int bubby;
	for(int i=0;i<7;i++)
	{
		bubby=0;
		double temporary;
		for(int j=0;j<(8-i)-1;j++){
			if(arr[j]>arr[j+1])
			{
				temporary=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temporary;
				bubby+=1;
			}
		}
		while(bubby==0){
			break;
		}
	}
	for(int p=0;p<8;p++)
	{
		string a;
		stringstream dubtostr;
		dubtostr<<arr[p];
		dubtostr>>(value);
		LastReturn+=","+value;
	}
	return LastReturn.substr(1);
}
int main()
{
	const int k=8;
	double arr[k];
	string Sawtt;
	string one,two,three,four,five,six,seven,eight;
	double first,second,third,fourth,fifth,sixth,seventh,eighth;
	int count=-1;
	int bubble;
	fstream search ("list.txt");
	while(!search.eof()){
		for(int count=0;count<8;count++ )
		{
			if(count<7){
				(getline(search,Sawtt,','));
				stringstream ss (Sawtt);
				ss>>arr[count];
			}
			else if(count==7){
				(getline(search,Sawtt));
				stringstream ss (Sawtt);
				ss>>arr[count];
			}
		}
		cout<<bubSort(arr)<<endl;
	}
	search.close();
	return 0;
}
