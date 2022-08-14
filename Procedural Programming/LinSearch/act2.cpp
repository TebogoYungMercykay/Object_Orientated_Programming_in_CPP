#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

string linSearch(double arr[10], double search[8])
{
	string TheReturnedString="",value;
	string theResult;
	string finalresult;
	for(int i=0;i<8;i++)
	{
		string TheReturnedString="";
		string position;
		int b;
		b=6;
		for(int r =0;r<10;r++){
			if(arr[r]==search[i]){
				b+=20;
				position=to_string(r);
				stringstream Success (position);
				Success>>(theResult);
				finalresult+=theResult+'\n';
				
			}
		}
		if(b<15){
			string Fail= "NA";
			stringstream NotApplicable (Fail);
			NotApplicable>>(theResult);
			finalresult+=theResult+'\n';
		}
	}
	return finalresult;
}
int main()
{
	const int k=10;
	double arr[k];
	const int f=8;
	double search[f];
	const int z=20;
	string eff[z];
	string Sawtt;
	int count=-1;
	int bubble=0;
	fstream linearSech ("search.txt");
	while(!linearSech.eof()){
		for(int count=0;count<10;count++){
			if(count<9){
				
				(getline(linearSech,Sawtt,','));
				stringstream ss (Sawtt);
				ss>>eff[bubble];
				bubble+=1;
			}
			else if(count==9){
				(getline(linearSech,Sawtt));
				stringstream ss (Sawtt);
				ss>>eff[bubble];
				bubble+=1;
			}
		}
	}
	for(int g=0;g<10;g++){
		stringstream ss (eff[g]);
		ss>>arr[g];
	}
	for(int p=10;p<11;p++){
		//stringstream gg (eff[p]);
		//int L=0;
		//gg>>search[L];
		//searchL+=1;
		//^method failed!!^
		stringstream dd (eff[10]);
		dd>>search[0];
		stringstream zz (eff[11]);
		zz>>search[1];
		stringstream bb (eff[12]);
		bb>>search[2];
		stringstream xx (eff[13]);
		xx>>search[3];
		stringstream vv (eff[14]);
		vv>>search[4];
		stringstream mm (eff[15]);
		mm>>search[5];
		stringstream nn (eff[16]);
		nn>>search[6];
		stringstream ss (eff[17]);
		ss>>search[7];
	}
	cout<<linSearch(arr,search);
	
	linearSech.close();
	return 0;
}
