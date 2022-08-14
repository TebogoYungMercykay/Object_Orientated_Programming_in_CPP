#include <iostream>

using namespace std;

int main()
{
    int store1;
    int store2;
    int store3;
    int store4;
    int store5;

    cout<<"Enter today's sales for store 1: ";
    cin>>store1;
    cout<<"Enter today's sales for store 2: ";
    cin>>store2;
    cout<<"Enter today's sales for store 3: ";
    cin>>store3;
    cout<<"Enter today's sales for store 4: ";
    cin>>store4;
    cout<<"Enter today's sales for store 5: ";
    cin>>store5;
    cout<<endl;

    cout<<"SALES BAR CHAT"<<endl;
    cout<<"(Each * = $100)"<<endl;
    cout<<"Store 1: ";
    while(store1>0){
        cout<<"*";
        store1 -=100;
    }cout<<endl;
    cout<<"Store 2: ";
    while(store2>0){
        cout<<"*";
        store2 -=100;
    }cout<<endl;
    cout<<"Store 3: ";
    while(store3>0){
        cout<<"*";
        store3 -=100;
    }cout<<endl;
    cout<<"Store 4: ";
    while(store4>0){
        cout<<"*";
        store4 -=100;
    }cout<<endl;
    cout<<"Store 5: ";
    while(store5>0){
        cout<<"*";
        store5 -=100;
    }cout<<endl;


}
