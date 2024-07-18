// find_index_first_occurence_in_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int static strStr(string haystack, string needle) {
	int index = -1, i, haystackSize = haystack.size(), needleSize = needle.size();

	for (i = 0; i < haystackSize; i++) {

		if (i + needleSize > haystackSize) {
			break;
		}

		if (haystack.substr(i, needleSize) == needle) {
			index = i;
			break;
		}

	}



	return index;
}
int main()
{
	cout << strStr("a", "a") << endl;
	cout << strStr("sadbutsad", "sad") << endl;
	cout << strStr("leetcode", "leeto") << endl;
	cout << strStr("mississippi", "issip") << endl;

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
