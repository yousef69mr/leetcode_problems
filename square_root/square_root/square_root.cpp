// square_root.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int static mySqrt(int x) {
	if (x < 0) return 0;
	if (x == 0 || x == 1) return x;

	int start = 1, mid = -1, end = x;
	long long y = static_cast<long long>(x);
	while (start <= end) {

		mid = start + (end - start) / 2;

		long long square = static_cast<long long>(mid) * mid;


		if (y == square) return mid;
		else if (y < square) end = mid - 1;
		else if (y > square) start = mid + 1;
	}

	return static_cast<int>(round(end));
}

int main()
{
	cout << mySqrt(8) << endl;
	cout << mySqrt(4) << endl;
	cout << mySqrt(16) << endl;

	return 0;
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
