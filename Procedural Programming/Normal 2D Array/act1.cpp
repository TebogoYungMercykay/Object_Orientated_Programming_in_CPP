#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main()
{
	int Array[4][4];
	int p,r,y,m;
	int row=-1;
	int collector=0;
	ifstream B;
	B.open("values.txt");
	string first,Sec,Last,Third;
	string K;
	if(!B.eof())
	{
		while(getline(B, K))
		{
			row+=1;
			istringstream ss (K);
			getline(ss, first, ',');
			istringstream st(first);
			st>>p;
			getline(ss, Sec, ',');
			istringstream sts(Sec);
			sts>>r;
			getline(ss, Third, ',');
			istringstream stdt(Third);
			stdt>>y;
			getline(ss, Last, ',');
			istringstream stdtd(Last);
			stdtd>>m;

			Array[row][0]=p;
			Array[row][1]=r;
			Array[row][2]=y;
			Array[row][3]=m;
			collector+=p+r+y+m;
		}
	}
	cout<<"Row Total 1: "<<Array[0][0]+Array[0][1]+Array[0][2]+Array[0][3]<<endl;
	cout<<"Row Total 2: "<<Array[1][0]+Array[1][1]+Array[1][2]+Array[1][3]<<endl;
	cout<<"Row Total 3: "<<Array[2][0]+Array[2][1]+Array[2][2]+Array[2][3]<<endl;
	cout<<"Row Total 4: "<<Array[3][0]+Array[3][1]+Array[3][2]+Array[3][3]<<endl;
	cout<<"Col Total 1: "<<Array[0][0]+Array[1][0]+Array[2][0]+Array[3][0]<<endl;
	cout<<"Col Total 2: "<<Array[0][1]+Array[1][1]+Array[2][1]+Array[3][1]<<endl;
	cout<<"Col Total 3: "<<Array[0][2]+Array[1][2]+Array[2][2]+Array[3][2]<<endl;
	cout<<"Col Total 4: "<<Array[0][3]+Array[1][3]+Array[2][3]+Array[3][3]<<endl;
	int ave=collector/16;
	cout<<"Array Average: "<<ave<<endl;
	B.close();
	return 0;
}
