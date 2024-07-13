// power_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double myPow(double x, int n) {
	if (n == 0 || x == 1) return 1;
	if (n == 1) return x;

	unsigned int power = abs(n);
	bool isPowerEven = power % 2 == 0;

	if (x == -1) { return isPowerEven ? 1 : -1; }

	bool isPowerNegative = n > 0 ? false : true;
	double theshold = 0.00000000000001;



	double result = 1;
	//cout << power;
	for (int i = 0; i < power; i++) {

		if (isPowerNegative) {
			result *= (1 / x);
			if (abs(result) < theshold) {
				break;
			}

		}
		else {
			result *= x;
		}
	}


	return isPowerEven ? abs(result) : result;

}
int main()
{
	//cout << myPow(2.00000, 10) << endl;
	//cout << myPow(2.10000, 3) << endl;
	//cout << myPow(2.00000, -2) << endl;
	//cout << myPow(2.00000, -2147483648) << endl;
	//cout << myPow(-3, -5) << endl;
	cout << myPow(-1.00000, -2147483648) << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
