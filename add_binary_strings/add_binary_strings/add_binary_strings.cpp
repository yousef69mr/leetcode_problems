// add_binary_strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>

using namespace std;


string addBinary(string a, string b) {
	string result = "";
	int maxLength = std::max(a.length(), b.length());
	int carry = 0;

	// Pad the shorter string with leading zeros
	int diff = maxLength - a.length();
	for (int i = 0; i < diff; ++i) {
		a = '0' + a;
	}
	diff = maxLength - b.length();
	for (int i = 0; i < diff; ++i) {
		b = '0' + b;
	}

	for (int i = maxLength - 1; i >= 0; --i) {
		int sum = carry + (a[i] - '0') + (b[i] - '0');
		carry = sum / 2;
		result.insert(0, std::to_string(sum % 2));
	}

	// Handle remaining carry
	if (carry == 1) {
		result.insert(0, "1");
	}

	return result;
}

int main()
{
	cout << addBinary("11", "1") << endl;
	cout << addBinary("1010", "1011");
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
