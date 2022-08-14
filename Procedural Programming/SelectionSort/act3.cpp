#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string SelectionSort(double array[8])
{
	string LastReturn="",value;
	int minIndex,minValue;
	
	for(int start=0;start<7;start++)
	{
		minIndex=start;
		minValue=array[start];
		for(int index=start+1;index<8;index++){
			if(array[index]<minValue){
				minValue=array[index];
				minIndex=index;
			}
		}
		swap(array[minIndex],array[start]);
	}
	for(int p=0;p<8;p++)
	{
		string a;
		stringstream dubtostr;
		dubtostr<<array[p];
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
		cout<<SelectionSort(arr)<<endl;
	}
	search.close();
	return 0;
}
