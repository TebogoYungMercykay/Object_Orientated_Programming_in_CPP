#include <iostream>
#include <fstream> 
#include <iostream>
#include <sstream>
using namespace std;

void outputFunction(int myReturnArray[], int subscript1, int subscript2)
{
	cout<<"itr1:"<<subscript1<<" itr2:"<<subscript2<<" array:"<<myReturnArray[0]<<","<<myReturnArray[1]<<","<<myReturnArray[2]<<","<<myReturnArray[3]<<endl;
}

int* recursiveSort(int myReturnArray[], int subscript1, int subscript2)
{
	if(subscript1 == 4 || subscript2 == 4)
	{
		return myReturnArray;
	}
	else
	{
		outputFunction(myReturnArray, subscript1, subscript2);
		if(!(myReturnArray[subscript1] < myReturnArray[subscript2]))
		{
			swap(myReturnArray[subscript2],myReturnArray[subscript1]);
		}
		subscript2++;
		if(subscript2 == 4)
		{
			subscript1 += 1; subscript2 = 0;
		}
		recursiveSort(myReturnArray, subscript1, subscript2);
	}
	return myReturnArray;
}

int main()
{
	string myString = "";
	int myReturnArray[4];
	int subscript1 = 0, subscript2 = 0;

	cout<<"Enter 4 integer values: ";
	getline(cin, myString);
	stringstream s_stream (myString);
	int x_iterator = 0;

	while(x_iterator < 4 && getline(s_stream, myString, ' '))
	{
		stringstream second_s_stream (myString);
		second_s_stream >> myReturnArray[x_iterator++];
		second_s_stream.clear();
	}
	int *myReturnedArray = recursiveSort(myReturnArray, subscript1, subscript2);
    return 0;
}