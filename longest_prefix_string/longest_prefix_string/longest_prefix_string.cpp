// longest_prefix_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<vector>

using namespace std;


string static longestCommonPrefix(vector<string>& strs) {

	if (strs.empty()) return "";

	string prefix = strs[0];
	int i, prefix_len = prefix.length();

	string str;

	for (i = 1; i < strs.size(); i++) {
		str = strs[i];

		while (prefix_len > str.length() || prefix != str.substr(0, prefix_len)) {
			prefix_len--;

			if (prefix_len == 0) return "";

			prefix = prefix.substr(0, prefix_len);
		}
	}

	return prefix;
}
int main()
{
	vector<string> strs = { "flower","flow","flight" };
	vector<string> strs_2 = { "dog","racecar","car" };

	cout << longestCommonPrefix(strs) << endl;
	cout << longestCommonPrefix(strs_2) << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
