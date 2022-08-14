#include <iostream>
#include <fstream> 
#include <sstream>
using namespace std;


int *arr3 = new int[4];

void print_F(int arr[], int K, int K2);

void swap_F(int arr[], int K, int K2);

int* recursiveSort(int arr[], int K, int K2);

void print_array_F(int arr[], int K, int K2);

void construct_array();

int main()
{
	construct_array();
	// cout<<"The returned array is as Follows: ";
	int *array = recursiveSort(arr3,0,0);
	// cout<<endl;
	// cout<<endl;
	// cout<<"The Sorted Array Values Are: ";
	// for(int k = 0;k<4;k++){
	// 	cout<<array[k]<<"  ";
	// }
	// cout<<endl;
	// int temp_Array[] = recursiveSort(arr3,0,0);
    return 0;
}

void print_array_F(int arr[], int K, int K2)
{
	cout<<arr[0]<<","<<arr[1]<<","<<arr[2]<<","<<arr[3];
}

void print_F(int arr[], int K, int K2)
{
	cout<<"itr1:"<<K;
	cout<<" itr2:"<<K2;
	cout<<" array:";
	print_array_F(arr,K,K2);
	cout<<endl;
}

void swap_F(int arr[], int K, int K2)
{
	int temp= arr[K];
	arr[K]=arr[K2];
	arr[K2]=temp;
}

int* recursiveSort(int arr[], int K, int K2)
{
	if(K == 4 || K2 == 4)
	{
		if(K==4)
		{
			return arr;/*exit(0);*/
		}
		else
		{
			return arr;
		}
	}
	else
	{
		print_F(arr,K,K2);
		if(arr[K] > arr[K2])
		{
			swap_F(arr,K,K2);
		}
		K2++;
		if(K2==4)
		{
			K++;
			K2=0;
		}
		recursiveSort(arr,K,K2);
	}
	return arr;
}
// int * array

void construct_array(){
	string myString = "";
	cout<<"Enter 4 integer values: ";
	getline(cin,myString);
	stringstream s_stream (myString);

	int x_iterator=0;
	if(x_iterator<4)
	{
		getline(s_stream, myString, ' ');
		stringstream second_s_stream (myString);
		second_s_stream>>arr3[x_iterator];
		x_iterator++;
	}
	if(x_iterator<4)
	{
		getline(s_stream, myString, ' ');
		stringstream second_s_stream (myString);
		second_s_stream>>arr3[x_iterator];
		x_iterator++;
	}
	if(x_iterator<4)
	{
		getline(s_stream, myString, ' ');
		stringstream second_s_stream (myString);
		second_s_stream>>arr3[x_iterator];
		x_iterator++;
	}
	if(x_iterator<4)
	{
		getline(s_stream, myString, ' ');
		stringstream second_s_stream (myString);
		second_s_stream>>arr3[x_iterator];
		x_iterator++;
	}
}