#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
	int number;
	char symbol;
	
	cout<<"Enter a pair: ";
	cin>>symbol;
	cin.ignore(1);
	cin>>number;
	int d=number+1;
	
	int y =number;
	if( symbol == '-'){
		for( int r = number; r >0; r--){
			y -= number;
		}
		cout<<"Result: "<< y<<endl;
	}
	else if( symbol == '+'){
		for( int r = number; r >0; r--){
			y += number;
		}
		cout<<"Result: "<< y<<endl;
	}
 	else if( symbol == '*'){
		for( int r = 2; r >1; r--){
			y =pow(number,d);
		}
		cout<<"Result: "<< y<<endl;
	}
	else{
		cout<<"Result: "<< "0"<<endl;
	}
	
	return 0;
}