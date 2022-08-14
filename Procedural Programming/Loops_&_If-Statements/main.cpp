#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int numYears;
    int NumOfMonths = 12;
    double average;
    double total;
    double monthlyrainfall;
    cout<< fixed << showpoint << setprecision(2);

    cout<<"This program calculates the average rainfall for a certain number of years"<<"\n\n";

    cout<<"Enter the number of Years you wish to average the inches of rainfall for: ";
    cin >>numYears;
    while(numYears < 1){
        cout<<"Enter appropriate number of years you wish to average the inches of rainfall for: ";
        cin>>numYears;
    }
    cout<<endl;

    for(int year = 1;year<=numYears;year++)
    {
        total = 0.0;
        for(int month=1;month<=NumOfMonths;month++)
        {
            cout<<"Enter the inches of rainfall for month "<<month<<" for year "<<year<<": ";
            cin>>monthlyrainfall;
            while(monthlyrainfall<0){
                cout<<"Enter the appropriate inches of rainfall for month "<<month<<" for year "<<year<<": ";
                cin>>monthlyrainfall;
            }
            total+=monthlyrainfall;
        }
    average=total/NumOfMonths;
    cout<<endl;
    cout<<"The number of months of rainfall experienses is "<<NumOfMonths<<endl;
    cout<<"The total inches of rainfall is "<<total<<endl;
    cout<<"The average rainfall per month for the entire period of year "<<year<<" is "<<average<<"\n\n";
    }
    return 0;
}
