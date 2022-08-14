#include <iostream>
using namespace std;

bool isPrime(int number){
    for (int n = 2; n <= number/2 ; n++)
    {
        if(number % n == 0)
        {
            return false;
        }
    }
    return true;
}
int main(){
    int number,n;
    // bool isPrime = true;
    string again;
    do
    {
        /*User input*/
        cout << "Enter a number to check: ";
        cin >> number;
        /*Check prime alg yeah*/
        /*cout if its prime or nah*/
        if(isPrime(number)==true)
            cout << "The number is prime.\n";
        else
            cout << "The number is not prime.\n";
        /*Loop prompt*/
        cout << "Execute check again (yes/no): ";
        cin >> again;
    }
    while(again == "yes" || again == "YES");
    return 0;
}