// is_palindrome_number.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(int x) {

	if (x < 0) return false;

	string num = to_string(x);
	int j, i, mid = num.length() / 2;
	for (i = 0, j = num.length() - 1; i <= mid && mid <= j; i++, j--) {
		if (num[i] != num[j]) {
			return false;
		}
	}

	return true;
}

int main()
{
	cout << isPalindrome(121) << endl;
	cout << isPalindrome(-121) << endl;
	cout << isPalindrome(10) << endl;

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
