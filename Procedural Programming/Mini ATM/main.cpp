#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iomanip>

using namespace std;

int Bank_Statement(int k){
    cout<<endl;
    cout<<endl;
    cout<<"Terminal         :Hatfield Plaza 2"<<"\t\t\t\t"<<"Terminal No:7464848"<<endl;
    cout<<"Date             :2020/08/06"<<"\t\t\t\t"<<"Time     :10:44:13"<<endl;
    cout<<"Sequence Number  :983345"<<endl;
    cout<<"Card Number      :***********5676"<<"\n\n";

    cout<<"Mr/Mrs  "<<"Somebody"<<endl;
    cout<<"Stand No 778"<<endl;
    cout<<"Eastwood Village"<<endl;
    cout<<"Acardia, 828"<<endl;
    cout<<"Hatfiel"<<endl;
    cout<<"Account Number   :547565746557"<<endl;
    cout<<"Statement For Period 2019/12/09 - 2020/08/12"<<endl;
    cout<<"Date     Transaction         Reference       Amount      Balance"<<endl;
    cout<<"06082020 ATM withdrawal      Hatfield ATM    R2900.54    -R89.67"<<endl;
    cout<<"11082020 Deposit             Pta North ATM   R100.00     R"<<100-89.67<<endl;
    cout<<"For 2020 Pricing & Benefits visit Bank.co.za from 1 january to get more Details "<<endl;
    cout<<endl;
    cout<<"\t\t\t\t"<<"End Of Statement"<<endl;
    return 0;
}

int main()
{
    int password = 2020;
    int enterpassword;
    int limitpassword = 3;
    int count = 0;
    bool outofpassword = false;
    int choice;
    int balance = 900500;
    int deposit;
    int amount;
    int withdrawal= 900500;
    int opt1 = 1,opt2= 2;
    int num;
    string user="Somebody";

    cout <<"Please insert a card"<<endl;
    cout <<"Welcome,Please enter a password: ";
    cin >>enterpassword;

    while(password != enterpassword){
        if (count < (limitpassword)){
            cout <<"Invalid Password,Enter a valid password!!: "<<endl;
            cin >>enterpassword;
            count ++;
        }
        else
        {
            cout <<"Thank You,Pleaase take your card off and GO!!"<<endl;
            break;
        }
    }
    if(password==enterpassword){
        cout<<"_____________________________________________________"<<endl;
        cout<<"_____________________________________________________"<<endl;
        cout<<"__________________....LOADING....____________________"<<endl;
        cout<<"______________--Select An Option--___________________"<<endl;
        cout<<"_____________________________________________________"<<endl;
        cout<< setw(40) << "1.BALANCE"<<endl;
        cout<< setw(40) << "2.DEPOSIT"<<endl;
        cout<< setw(40) << "3.WITHDRAWAL"<<endl;
        cout<< setw(40) << "4.MORE OPTIONS"<<endl;
        cout<<"_____________________________________________________"<<endl;
        cout<<"                                                     "<<endl;
        cout<<"Please select your option: ";
        cin>>choice;

        switch(choice){
        case 1:
            cout <<"Your balance is R"<<balance<<endl;
            break;
        case 2:
            cout<<"Make a deposit: ";
            cin>>deposit;
            cout<<"You made a deposit of R"<<deposit<<endl;
            cout<<"Your New balance is R"<<balance+deposit<<endl;
            cout<<"Thank You For using SKHADOH EFFECT Bank"<<endl;
            break;
        case 3:
            cout <<"Please enter an amount: ";
            cin>> amount;
            cout<<endl;
            cout<<"You made a Withdrawal of R"<<amount<<endl;
            cout<<"Your available balance is R"<<withdrawal-amount<<endl;
            cout<<"Thank you for using SKHADOH EFFECT Bank"<<endl;
            break;
        case 4:
            cout<< "1. A4 Bank Statement\n";
            cout<< "2.Cancel\n";
            cin>>num;
            if(num== 1){
                Bank_Statement(num);
            }
            else if(num == 2){
                break;
            }
            break;
        default :
            cout<< "sorry Kaffirr,The option You Entered is not available"<<endl;
            cout<< "Please Enter a valid Option next time,THANK YOU"<<endl;

        }

    }
    return 0;
}
