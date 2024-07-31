// is_strictly_palindromic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

string static convertIntToBase(int num, int base) {
	string result = "";
	int remainder = num;
	while (num > 0)
	{
		remainder = num % base;
		result.insert(0, to_string(remainder));
		num /= base;
	}

	return result;
}

bool static isStrictlyPalindromic(int n) {
	int base_num, num_of_bases = n - 2 <= 2 ? 2 : n - 2;

	if (num_of_bases == 10 && n < 0) return false;

	int j, i, mid;
	for (base_num = 2; base_num <= num_of_bases; base_num++) {

		string num = convertIntToBase(n, base_num);
		mid = num.length() / 2;
		for (i = 0, j = num.length() - 1; i <= mid && mid <= j; i++, j--) {
			if (num[i] != num[j]) {
				return false;
			}
		}

	}

	return true;
}

int main()
{

	cout << isStrictlyPalindromic(9) << endl;
	cout << isStrictlyPalindromic(4) << endl;

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
