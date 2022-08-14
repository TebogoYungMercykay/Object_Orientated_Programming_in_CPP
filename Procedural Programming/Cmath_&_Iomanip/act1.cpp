
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
	
	double x;
	double pi_value = 3.141592654;
	cout << "Enter a value of x: ";
	cin >> x;
	
	double a;
	a = (cos(pow(x, 3)) / (18+2*ppi_value)) + (sin(pow(x, 2)) / (19+3*pi_value)) + (tan(x) / (20+4*pi_value));
	cout << "The answer is: " << setprecision(6) << a << endl; 
	
	return 0;
}