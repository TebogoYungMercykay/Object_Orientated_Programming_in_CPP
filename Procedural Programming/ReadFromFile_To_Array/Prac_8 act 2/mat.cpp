#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	
	string Storage;
	fstream Values_txt;
	Values_txt.open("matrix.txt");
	int Row_length=0;
	(getline(Values_txt,Storage, ','));
	istringstream Row_len (Storage);
	Row_len >>Row_length;
	int Col_length=0;
	(getline(Values_txt,Storage));
	istringstream Col_len (Storage);
	Col_len >>Col_length;
	
	const int rr=Row_length;
	const int pp=Col_length;
	int **My_Array;
	My_Array=new int*[Row_length];
	for(int h=0;h<Row_length;h++){
		*(My_Array+h)= new int [Col_length];
	}
	My_Array[rr][pp];
	string Accomodation;
	while(!Values_txt.eof()){
		for(int Hello=0;Hello<Row_length;Hello++){
			for(int hiiey=0;hiiey<Col_length;hiiey++){
				if(hiiey<(Col_length-1)){
					(getline(Values_txt,Accomodation, ','));
					istringstream First_Values (Accomodation);
					First_Values >>My_Array[Hello][hiiey];
				}
				else
				{
					(getline(Values_txt,Accomodation));
					istringstream Last_value (Accomodation);
					Last_value>>My_Array[Hello][hiiey];
				}
			}
		}
	}
	int Lowest_Value=1000;
	for(int kk=0;kk<Row_length;kk++){
		for(int vv=0;vv<Col_length;vv++){
			if(My_Array[kk][vv]<Lowest_Value){
				Lowest_Value=My_Array[kk][vv];
			}
		}
	}
	int Largest=-1000;
	for(int hh=0;hh<Row_length;hh++){
		for(int gg=0;gg<Col_length;gg++){
			if(My_Array[hh][gg]>Largest){
				Largest=My_Array[hh][gg];
			}
		}
	}
	int odds=0;
	int evens=0;
	for(int pp=0;pp<Row_length;pp++){
		for(int ll=0;ll<Col_length;ll++){
			int *pter=&My_Array[pp][ll];
			if(*pter%2==0){
				evens+=1;
			}
			else
				odds+=1;
		}
	}
	cout<<"Count Odd: "<<odds<<endl;
	cout<<"Count Even: "<<evens<<endl;
	cout<<"Largest Number: "<<Largest<<endl;
	cout<<"Smallest Number: "<<Lowest_Value<<endl;

	return 0;
}


